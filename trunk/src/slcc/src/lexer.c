/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version
  
  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
  details.
  
  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>
  ============================================================================*/

//------------------------------------------------------------------------------
// lexer.c
//------------------------------------------------------------------------------
// Lexer for the interpreter.
//------------------------------------------------------------------------------

#include "config_slcc.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include sl_os_fixinclude(uchar.h)

#include "binary_search.h"
#include "error_codes.h"
#include "error_handling.h"
#include "lexer.h"
#include "lexer_functions.h"
#include "literal.h"
#include "preprocessor.h"
#include "preprocessor_symtab.h"
#include "reader.h"
#include "settings.h"
#include "source_position.h"
#include "strings.h"
#include "token.h"

#include "char_functions.h"

//------------------------------------------------------------------------------
// Private function prototypes
static size_t lex_get_keyword_pos (const slcc_string* token);
static slcc_token lex_char_literal ();
static slcc_token lex_char_string ();
static slcc_token lex_char16_t_literal ();
static slcc_token lex_char16_t_string ();
static slcc_token lex_char32_t_literal ();
static slcc_token lex_char32_t_string ();
static slcc_token lex_character (slcc_literal_type type);
static slcc_token lex_comment ();
static slcc_token lex_identifier_or_keyword ();
static slcc_token lex_number ();
static slcc_token lex_preprocessor_directive ();
static slcc_token lex_preprocessor_substitute (const slcc_string* lexeme);
static slcc_token lex_punctuation ();
static slcc_token lex_raw_string ();
static slcc_token lex_string (slcc_literal_type type);
static slcc_token lex_wchar_t_literal ();
static slcc_token lex_wchar_t_string ();
static size_t lex_get_punctuation_pos (const slcc_string* token);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
slcc_token current_token_;
slcc_token previous_token_;
slcc_source_position begin_source_position_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lexer_initialize function
//
// Function initializes the lexer by giving it the first filename.
//
bool lexer_initialize () 
{
  if (!rdr_initialize_with_file (settings_.source_file))
    return false;

  if (!pp_initialize ()) 
    {
      rdr_cleanup ();
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lexer_cleanup function
//
// Function terminates the lexer and cleans up open files and buffers.
//
void lexer_cleanup () 
{
  pp_cleanup ();
  rdr_cleanup ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_get_next_token function
//
// Function gets the next token from the stream.
//
slcc_token lex_get_next_token (bool macro_skip) 
{
  previous_token_ = current_token_;

  char c = rdr_get_current_char ();

  /* Skip over whitespace and if in macro_skip mode */
  while (true)
    {
      if (!tc_is_whitespace (c))
	{
	  /* If not in macro skip mode, a none whitespace needs to be
	     parsed. */
	  if (!macro_skip)
	    break;
	  
	  /* If in macro skip mode we do need to parse preprocessor
	     statements as they might end macro skip. */
	  if (c == '#' && rdr_get_previous_char () == '\n')
	    break;
	}
      c = lex_get_char ();
    }
  
  /* Take care of NULL character */
  if (c == '\0') 
    {
      slcc_token token = token_new_empty (rdr_get_current_source_position ());
      lex_get_char ();
      return token;
    }
  
  /* Take care of EOF character */
  if (c == EOF) 
    {
      return token_new_eof ();
    }
  
  /* Store the beginning of the source position */
  begin_source_position_ = rdr_get_current_source_position ();
  
  /* Get next token */
  if (tc_is_alpha_or_underscore (c))
    return lex_identifier_or_keyword ();
  else if (tc_is_decimal_digit (c))
    return lex_number ();
  else if (c == '#' && rdr_get_previous_char () == '\n')
    return lex_preprocessor_directive ();
  else if (c == '/')
    return lex_comment ();
  else
    return lex_punctuation ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_get_previous_token function
//
// Function gets the previous token. This is not relexed, it is just a variable
// return to the caller.
//
slcc_token lex_get_previous_token () 
{
  return previous_token_;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_get_keyword_pos function
//
// Function returns position of the keyword. It searches the current token in
// the keywords array.
//
size_t lex_get_keyword_pos (const slcc_string* token) 
{
  return binary_search(
		       keyword_list_,
		       keyword_list_length_,
		       token
                       );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char_literal function
//
// Lexes a character literal.
//
slcc_token lex_char_literal ()
{
  char c;
  char d;

  /* Lex character */
  c = lex_char ();
  
  /* Get ending quote */
  d = lex_get_char ();

  if (d != '\'') {
    /* Skip to end of token and report error */
    lex_skip_to_char ('\'');
    src_err_report_1 (
		      EC_C_INVALID_CHAR_LITERAL,
		      begin_source_position_,
		      str_get_c_string (lex_get_current_token_string ())
		      );
    return token_new_empty (begin_source_position_);
  }
  
  return token_new_char (c, begin_source_position_);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char_string function
//
// Lexes a character string.
//
slcc_token lex_char_string ()
{
  char c;
  char prev_c = '"';
  slcc_string* s = str_new ();
    
  /* Get second token delimiter */
  c = lex_char ();
  for (;;) 
    {
      if (c == '"' && prev_c != '\\')
	break;
      else
	str_append (s, c);
      c = lex_char ();
    }

  return token_new_string (s, rdr_get_current_source_position ());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char16_t_literal function
//
// Lexes a char16_t or UTF-16 character literal.
//
slcc_token lex_char16_t_literal ()
{
  /* Lex UTF-16 character literal */
  return token_new_empty (begin_source_position_);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char16_t_string function
//
// Lexes a UTF-16 character string.
//
slcc_token lex_char16_t_string ()
{
  char16_t c;
  char16_t prev_c = '"';
  slcc_string16* s = str_new_16 ();
    
  /* Get second token delimiter */
  c = lex_char16_t ();
  for (;;) 
    {
      if (c == '"' && prev_c != '\\')
	break;
      else
	str_append_16 (s, c);
      c = lex_char16_t ();
    }

  return token_new_string16 (s, rdr_get_current_source_position ());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char32_t_literal function
//
// Lexes a char32_t or UTF-32 character literal.
//
slcc_token lex_char32_t_literal ()
{
  /* TODO - Lex UTF-32 character literal */
  return token_new_empty (begin_source_position_);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char32_t_string function
//
// Lexes a UTF-32 character string.
//
slcc_token lex_char32_t_string ()
{
  char32_t c;
  char32_t prev_c = '"';
  slcc_string32* s = str_new_32 ();
    
  /* Get second token delimiter */
  c = lex_char32_t ();
  for (;;) 
    {
      if (c == '"' && prev_c != '\\')
	break;
      else
	str_append_32 (s, c);
      c = lex_char32_t ();
    }

  return token_new_string32 (s, rdr_get_current_source_position ());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_character function
//
// This function lexes a single character literal. We don't need to get the
// opening single quote, because we already got that.
//
slcc_token lex_character (slcc_literal_type type) 
{
  switch (type) {

    /* Char literals are unsigned */
  case LT_UNSIGNED_CHAR :
    return lex_char_literal ();
    break;

  case LT_CHAR16_T :
    return lex_char16_t_literal ();
    break;

  case LT_CHAR32_T :
    return lex_char32_t_literal ();
    break;

  case LT_WCHAR_T :
    return lex_wchar_t_literal ();
    break;

  default:
    /* TODO: Report error invalid character literal */
    return token_new_empty (begin_source_position_);
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_comment function
//
// This function lexes a comment or punctuation token. It handles both single
// line and multi line comments. If the second character is not / or *, 
// the token is considered punctuation.
//
slcc_token lex_comment ()
{
  char c = lex_store_and_get_char (true);

  /* Multi line comment */
  if (c == '*')
    {
      size_t nesting = 0;
      
      c = lex_store_and_get_char (false);
      while (true)
	{
	  if (c == '/' && rdr_get_previous_char () == '*')
	    {
	      if (nesting == 0)
		{
		  lex_store_and_get_char (false);
		  break;
		}
	      else 
		nesting --;
	    }
	  else if (c == '*' && rdr_get_previous_char () == '/')
	    nesting++;

	  c = lex_store_and_get_char (false);
	}
    }

  /* Single line comment. */
  else if (c == '/')
    {
      while (lex_store_and_get_char (false) != '\n')
	;

      /* Do not store \n in token string */
      lex_get_char ();
    }

  /* Token / or /= */
  else if (c == '=')
    {
      lex_store_and_get_char (false);
      return token_new_punctuation 
	(
	 lex_get_punctuation_pos (lex_get_current_token_string ()),
	 begin_source_position_
	 );
    }
  else
    return token_new_punctuation 
      (
       lex_get_punctuation_pos (lex_get_current_token_string ()),
       begin_source_position_
       );

  /* Comment found */
  return token_new_comment (
			    lex_get_current_token_string (),
			    begin_source_position_
			    );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_identifier_or_keyword function
//
// Lexes all tokens starting with a-zA-Z_. This include the following none
// identifier/keyword types:
//   - Wide character literals (starting with L or l)
//   - Wide character strings (starting with u/u8/U/L/l)
//   - Raw strings (starting with R/uR/u8R/UR/LR/lR)
//
slcc_token lex_identifier_or_keyword ()
{
  char c = lex_store_and_get_char (true);

  /* Is it a wide/utf16 or utf32 character literal */
  if (c == '\'')
    if (rdr_get_previous_char () == 'L' || rdr_get_previous_char () == 'l')
      return lex_character (LT_WCHAR_T);
    else if (rdr_get_previous_char () == 'u')
      return lex_character (LT_CHAR16_T);
    else if (rdr_get_previous_char () == 'U')
      return lex_character (LT_CHAR32_T);
    else
      {
	/* TODO: Invalid character literal: Report/Skip to ' */
	return token_new_empty (begin_source_position_);
      }

  /* Is it a raw/wide character/utf16 or utf32 string literal */
  else if (c == '"')
    switch (rdr_get_previous_char ()) {

      /* It's a wide character string, which matches a UTF-8 string */
    case 'L' :
    case 'l' :
      return lex_string (LT_WSTRING);
      break;

    case 'R' :
      return lex_string (LT_RAW_STRING);
      break;

    case 'u' :
      return lex_string (LT_STRING16);
      break;
      
    case 'U' :
      return lex_string (LT_STRING32);
      break;

    default :
      /* TODO Invalid string literal: Report/Skip to '"' */
      return token_new_empty (begin_source_position_);
      break;
    }
  
  /* So it is something else, check that it is still an identifier/keyword */
  else if (!tc_is_alpha_or_underscore (c) || tc_is_decimal_digit (c))
    return
      lex_preprocessor_substitute (lex_get_current_token_string ());

  c = lex_store_and_get_char (false);
  
  /* Is it a character literal. It can be u8. */
  if (c == '\'')
    {
      char* s = str_get_c_string (lex_get_current_token_string ());
      if (strcmp (s, "u8") == 0)
	{
	  free (s);
	  return lex_character (LT_WCHAR_T);
	}
      else 
	{
	  /* TODO Invalid string literal: Report/Skip to '"' */
	  free (s);
	  return token_new_empty (begin_source_position_);
	}
    }

  /* Is this a string literal, it can be u8/uR/UR/LR/lR */
  else if (c == '"')
    {
      char* s = str_get_c_string (lex_get_current_token_string ());
      if (strcmp (s, "u8") == 0)
	{
	  free (s);
	  return lex_string (LT_WSTRING);
	}
      else if (strcmp (s, "uR") == 0 || strcmp (s, "UR") == 0
	       || strcmp (s, "LR") == 0 || strcmp (s, "lR") == 0)
	{
	  free (s);
	  return lex_string (LT_RAW_STRING);
	}
      else 
	{
	  /* TODO Invalid string literal: Report/Skip to '"' */
	  free (s);
	  return token_new_empty (begin_source_position_);
	}
    }
  /* Is it still an identifier/keyword */
  else if (!tc_is_alpha_or_underscore (c) || tc_is_decimal_digit (c))
    return
      lex_preprocessor_substitute (lex_get_current_token_string ());

  c = lex_store_and_get_char (false);

  /* This can be a string, namely u8R */
  if (c == '"')
    if (strcmp (str_get_c_string (lex_get_current_token_string ()), "u8R") == 0)
      return lex_string (LT_RAW_STRING);
    else 
      {
	/* TODO Invalid string literal: Report/Skip to '"' */
	return token_new_empty (begin_source_position_);
      }

  /* Is this still an identifier/keyword */
  else if (!tc_is_alpha_or_underscore (c))
    return
      lex_preprocessor_substitute (lex_get_current_token_string ());

  while(tc_is_alpha_or_underscore (lex_store_and_get_char (false)))
    ;

  return lex_preprocessor_substitute (lex_get_current_token_string ());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_number function
//
// This function lexes a numeric literal of any of the supported numeric
// literals.
//
slcc_token lex_number() {
  slcc_string* s = str_new ();
  bool has_decimal_point = false;
  bool has_exponent = false;
  bool is_unsigned = false;
  bool is_float = false;
  bool is_long = false;
  bool is_long_long = false;
  bool is_octal = false;
  bool is_binary = false;
  bool is_hexadecimal = false;

  bool has_error = false;

  char c;
  char prev_c = rdr_get_current_char();

  /* Get second character */
  c = rdr_get_next_char ();
    
  /* Octal */
  if (prev_c == '0')
    if (c == 'b' || c == 'B')
      {
	is_binary = true;
	c = rdr_get_next_char ();
      }
    else if (c == 'x' || c == 'X')
      {
	is_hexadecimal = true;
	c = rdr_get_next_char ();
      }
    else
      is_octal = true;
  else 
    str_append(s, prev_c);

  for (;;) 
    {
      /* Octal number */
      if (is_octal)
	if (tc_is_octal_digit (c))
	  str_append(s, c);
	else
	  has_error = true;

      /* Binary number */
      else if (is_binary)
	if (c == '0' || c == '1')
	  str_append(s, c);
	else
	  has_error = true;

      /* Hexadecimal number */
      else if (is_hexadecimal)
	if (tc_is_hexadecimal_digit (c))
	  str_append(s, c);
	else 
	  has_error = true;

      /* Other numbers */
      else if (tc_is_decimal_digit (c))
	str_append(s, c);
      else if(c == '.')
	if(has_decimal_point)
	  has_error = true;
	else 
	  {
	    str_append(s, c);
	    has_decimal_point = true;
	  }
      else if(c == 'E' || c == 'e')
	if(has_exponent) 
	  has_error = true;
	else 
	  {
	    str_append(s, c);
	    has_exponent = true;
	  }
      else if (c == 'u' || c == 'U')
	is_unsigned = true;
      else if (c == 'l' || c == 'L')
	if (rdr_get_previous_char () == 'l' || rdr_get_previous_char () == 'L')
	  {
	    is_long = false;
	    is_long_long = true;
	  }
	else
	  is_long = true;
      else if (c == 'f' || c == 'F')
	is_float = true;
      else
	break;
      c = rdr_get_next_char ();
    }
  
  if(has_error) 
    {
      /* TODO report error. An error occured during lexing */ 
    }

  if (is_float && is_long)
    {
      /* TODO report error. Literal defined as float and as long double */
    }
  else if (is_float && is_long_long)
    {
      /* TODO report error. Literal defined as float and as long long */
    }
  else if ((has_decimal_point || has_exponent) 
	   && (is_long_long 
	       || is_unsigned 
	       || is_octal || is_hexadecimal || is_binary))
    {
      /* TODO report error. Literal can't be float and integer at the same 
       * time 
       */
    } 

  if(has_decimal_point || has_exponent)
    return token_new_float (
			    s, 
			    begin_source_position_, 
			    is_float,
			    is_long
			    );
  else 
    return token_new_int (
			  s, 
			  rdr_get_current_source_position(),
			  is_binary, 
			  is_octal,
			  is_hexadecimal,
			  is_unsigned,
			  is_long,
			  is_long_long
			  );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_preprocessor_directive function
//
// This function lexes a preprocessor directive.
//
slcc_token lex_preprocessor_directive () 
{
  char c = lex_store_and_get_char (true);

  while (true) 
    {
      if (c == '\n' && rdr_get_previous_char () != '\\')
	{
	  pp_process_directive (lex_get_current_token_string ());
	  return lex_get_next_token (pp_is_skipping_code ());
	}
      c = lex_store_and_get_char (false);
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// preprocess_token function
//
// Function preprocesses a lexeme and if it is a preprocessor definition or 
// function it handles accordingly.
//
slcc_token lex_preprocessor_substitute (const slcc_string* lexeme) 
{
  if (!pp_is_symbol (lexeme))
    {
      size_t p = lex_get_keyword_pos (lex_get_current_token_string ());
      if (p != 0)
	return token_new_keyword (p, begin_source_position_);
      else 
	return token_new_identifier (
				     lex_get_current_token_string (),
				     begin_source_position_
				     );
    }

  else if (pp_is_function (lexeme))
    {
      char c = lex_store_and_get_char (false);
      if (c == '(')
	{
	  size_t nesting = 0;
	  c = lex_store_and_get_char (false);
	  while (true)
	    {
	      if (c == ')')
		if (nesting == 0)
		  break;
		else
		  nesting--;
	      else if (c == '(')
		nesting++;
	      c = lex_store_and_get_char (false);
	    }
	}
      else 
	{
	  /* TODO: Report invalid macro function call */
	  return token_new_empty (begin_source_position_);
	}
      pp_process_function (lex_get_current_token_string ());
    }
  
  else
    {
      pp_process_string (lex_get_current_token_string ());
    }

  lex_store_and_get_char (false);

  return lex_get_next_token (false);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_punctuation function
//
// This function lexes a punctuation token. That is a token that 
// doesn't start with an alpha, _, #, or number. As such it also handles 
// string literals that start with " or character literals that start with '.
//
slcc_token lex_punctuation ()
{
  char c = rdr_get_current_char ();

  /* String literal */
  if (c == '"')
    return lex_string (LT_STRING);

  /* Character literal */
  else if (c == '\'')
    return lex_character (LT_UNSIGNED_CHAR);

  /* Token [, ], (, ), {, }, ~, ?, , or ; */
  else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '~' || c == '?' 
	   || c == ',' || c == ';')
    lex_store_and_get_char (true);

  /* Token : or :: */
  else if (c == ':')
    {
      if (lex_store_and_get_char (true) == ':') 
	lex_store_and_get_char (false);
    }

  /* Token ., .* or ... */
  else if (c == '.') 
    {
      c = lex_store_and_get_char (true);
      if (c == '*')
	lex_store_and_get_char (false);
      else if (c == '.')
	{
	  if (lex_store_and_get_char (false) == '.')
	    lex_store_and_get_char (false);
	  else
	    {
	      /* TODO Report error on ..<> token */
	      return lex_get_next_token (false);
	    }
	}
    }

  /* Token -, --, -=, -> or ->*. If '-' and the next character is numeric, lex
     this token as number */
  else if (c == '-')
    {
      c = lex_store_and_get_char (true);
      if (tc_is_decimal_digit (c))
	return lex_number ();
      else if (c == '-' || c == '=')
	lex_store_and_get_char (false);
      else if (c == '>')
	if (lex_store_and_get_char (false) == '*')
	  lex_store_and_get_char (false);
    }

  /* Token + or  ++ */
  else if (c == '+')
    {
      c = lex_store_and_get_char (true);
      if (c == '+' || c == '=')
	lex_store_and_get_char (false);
    }

  /* Token ! and != */
  else if (c == '!')
    {
      if (lex_store_and_get_char (true) == '=')
	lex_store_and_get_char (false);
    }

  /* Token &, && and &= */
  else if (c == '&')
    {
      c = lex_store_and_get_char (true);
      if (c == '&' || c == '=')
	lex_store_and_get_char (false);
    }

  /* Token * or *= */
  else if (c == '*')
    {
      if (lex_store_and_get_char (true) == '=')
	lex_store_and_get_char (false);
    }

  /* Token % or %= */
  else if (c == '%')
    {
      if (lex_store_and_get_char (true) == '=')
	lex_store_and_get_char (false);
    }

  /* Token <, <<, <= or <<= */
  else if (c == '<')
    {
      c = lex_store_and_get_char (true);
      if (c == '=')
	lex_store_and_get_char (false);
      else if (c == '<')
	if (lex_store_and_get_char (false) == '=')
	  lex_store_and_get_char (false);
    }

  /* Token >, >>, >= or >>= */
  else if (c == '>')
    {
      c = lex_store_and_get_char (true);
      if (c == '=')
	lex_store_and_get_char (false);
      else if (c == '>')
	if (lex_store_and_get_char (false) == '=')
	  lex_store_and_get_char (false);
    }

  /* Token = or == */
  else if (c == '=')
    {
      if (lex_store_and_get_char (true) == '=')
	lex_store_and_get_char (false);
    }

  /* Token [ or [[ */
  else if (c == '[') 
    {
      if (lex_store_and_get_char (true) == '[') 
        lex_store_and_get_char (false);
    }

  /* Token ] or ]] */
  else if (c == ']') 
    {
      if (lex_store_and_get_char (true) == ']')
        lex_store_and_get_char (false);
    }

  /* Token ^ or ^= */
  else if (c == '^')
    {
      if (lex_store_and_get_char (true) == '=')
	lex_store_and_get_char (false);
    }

  /* Token |, || or |= */
  else if (c == '|')
    {
      c = lex_store_and_get_char (true);
      if (c == '|' || c == '=')
	lex_store_and_get_char (false);
    }

  return token_new_punctuation 
    (
     lex_get_punctuation_pos (lex_get_current_token_string ()),
     begin_source_position_
     );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_raw_string function
//
// Lexes a raw character string.
//
slcc_token lex_raw_string ()
{
  char c;
  char prev_c = '"';
  slcc_string* s = str_new ();
    
  /* Get second token delimiter */
  c = lex_char ();
  for (;;) 
    {
      if (c == '"' && prev_c != '\\')
	break;
      else
	str_append (s, c);
      c = lex_char ();
    }

  char* cstr = str_get_c_string (s);

  str_delete (s);

  return token_new_raw_string (cstr, rdr_get_current_source_position ());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_string function
//
// This function lexes a string literal.
//
slcc_token lex_string (slcc_literal_type type) 
{
  switch (type) {

    /* Char literals are unsigned */
  case LT_STRING :
    return lex_char_string ();
    break;

  case LT_STRING16 :
    return lex_char16_t_string ();
    break;

  case LT_STRING32 :
    return lex_char32_t_string ();
    break;

  case LT_WSTRING :
    return lex_wchar_t_string ();
    break;

  case LT_RAW_STRING :
    return lex_raw_string ();
    break;

  default:
    /* TODO: Report error invalid string literal */
    return token_new_empty (begin_source_position_);
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_wchar_t_literal function
//
// Lexes a wide character or UTF-8 literal.
//
slcc_token lex_wchar_t_literal ()
{
  wchar_t c;
  char d;

  /* Lex character */
  c = lex_wchar_t ();

  /* Get ending quote */
  d = lex_get_char ();

  if (d != '\'') 
    {
      /* Skip to end of token and report error */
      lex_skip_to_char ('\'');
      src_err_report_1 (
			EC_C_INVALID_WCHAR_LITERAL,
			begin_source_position_,
			str_get_c_string (lex_get_current_token_string ())
			);
      return token_new_empty (begin_source_position_);
    }
  
  return token_new_wchar (c, rdr_get_current_source_position ());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_wchar_t_string function
//
// Lexes a wchar_t or UTF-8 string.
//
slcc_token lex_wchar_t_string ()
{
  wchar_t c;
  wchar_t prev_c = '"';
  slcc_wstring* s = str_new_w ();

  /* Get second token delimiter */
  c = lex_wchar_t ();
  for (;;) 
    {
      if (c == '"' && prev_c != '\\')
	break;
      else
	str_append_w (s, c);
      c = lex_wchar_t ();
    }

  return token_new_wstring (s, rdr_get_current_source_position ());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_get_punctuation_pos function
//
// Function returns position of the punctuation. It searches the current token
// in the punctuation array.
//
size_t lex_get_punctuation_pos (const slcc_string* token) 
{
  return binary_search (
			punctuation_list_,
			punctuation_list_length_,
			token
                        );
}
//------------------------------------------------------------------------------

//-<EOF>
