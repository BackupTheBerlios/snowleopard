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
// lexer_functions.c
//------------------------------------------------------------------------------
// Lexer functions for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "error_codes.h"
#include "error_handling.h"
#include "lexer_functions.h"
#include "reader.h"
#include "strings.h"

#include "char_functions.h"
#include "integer_functions.h"

//------------------------------------------------------------------------------
// Private variables
//
slcc_string current_token_string = {
  0,
  0,
  NULL
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_get_current_token_string function
//
// Returns the current_token_string.
//
const slcc_string* lex_get_current_token_string () 
{
  return &current_token_string;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char function
//
// Lexes a single character and returns it.
//
char lex_char () 
{
  /* Get character */
  char c = lex_store_and_get_char (true);

  /* If character is escaped */
  if (c == '\\') 
    {
      c = lex_store_and_get_char (false);

      switch (c) {
      case 'a':
        c = '\a';
        break;

      case 'b':
        c = '\b';
        break;

      case 'f':
        c = '\f';
        break;

      case 'n':
        c = '\n';
        break;

      case 'r':
        c = '\r';
        break;

      case 't':
        c = '\t';
        break;

      case 'v':
        c = '\v';
        break;

      case '\\':
        c = '\\';
        break;

      case '\?':
        c = '\?';
        break;

      case '\'':
        c = '\'';
        break;

      case '\"':
        c = '\"';
        break;

      case '0' : /* Octal character constant */
        {
          int i = 0;
	  c = lex_store_and_get_char (false);
          if (c >= '0' && c <= '3')
            i = tc_get_oct_value (c);
          else
	    {
	      src_err_report_1 
		(
		 EC_C_INVALID_OCTAL_CHAR_LITERAL,
		 rdr_get_current_source_position (),
		 str_get_c_string (lex_get_current_token_string ())
		 );
	      return 0;
	    }
	  c = lex_store_and_get_char (false);
          if (c >= '0' && c <= '7')
            i = i * 8 + tc_get_oct_value (c);
          else
	    {
	      src_err_report_1 
		(
		 EC_C_INVALID_OCTAL_CHAR_LITERAL,
		 rdr_get_current_source_position (),
		 str_get_c_string (lex_get_current_token_string ())
		 );
	      return 0;
	    }
          c = lex_store_and_get_char (false);
          if (c >= '0' && c <= '7')
            i = i * 8 + tc_get_oct_value (c);
          else
	    {
	      src_err_report_1
		(
		 EC_C_INVALID_OCTAL_CHAR_LITERAL,
		 rdr_get_current_source_position (),
		 str_get_c_string (lex_get_current_token_string ())
		 );
	      return 0;
	    }
          c = i;	
        }
        break;

      case 'x' : /* Hexadecimal character constant */
        {
          int i = 0;
	  c = lex_store_and_get_char (false);
          if (tc_is_hexadecimal_digit (c))
            i = tc_get_hex_value (c);
          else
	    {
	      src_err_report_1 
		(
		 EC_C_INVALID_HEX_CHAR_LITERAL,
		 rdr_get_current_source_position (),
		 str_get_c_string (lex_get_current_token_string ())
		 );
	      return 0;
	    }
	  c = lex_store_and_get_char (false);
          if (tc_is_hexadecimal_digit (c))
            i = i * 16 + tc_get_hex_value (c);
          else
	    {
	      src_err_report_1 
		(
		 EC_C_INVALID_HEX_CHAR_LITERAL,
		 rdr_get_current_source_position (),
		 str_get_c_string (lex_get_current_token_string ())
		 );
	      return 0;
	    }
          c = i;
        }
        break;

      case 'u' : /* \u hex-quad */
      case 'U' : /* \U hex_quad hex_quad */
	{
	  bool double_hex_quad = c == 'U' ? true : false;
	  unsigned long universal_char = 0;

	  /* Get first hex-quad */
	  for (int i = 0; i < 4; i++)
	    universal_char 
	      = universal_char * 16 
	      + tc_get_hex_value (lex_store_and_get_char (false));

	  /* Get second hex_quad */
	  if (double_hex_quad)
	      for (int i = 0; i < 4; i++)
		universal_char
		  = universal_char * 16
		  + tc_get_hex_value (lex_store_and_get_char (false));
	  
	  c = tc_get_char_from_universal_char (universal_char);
	}
	break;

      default :
	src_err_report_1
	  (
	   EC_C_INVALID_CHAR_IN_CHAR_LITERAL,
	   rdr_get_current_source_position (),
	   str_get_c_string (lex_get_current_token_string ())
	   );       
	break;			
      }
    }
  
  return c;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char16_t function
//
// Lexes a single character and returns it.
//
char16_t lex_char16_t () 
{
  char16_t c = ' ';

  /* <TODO: Added lexing of char16_t characters> */
  err_report_and_exit_0 (EC_U_CHAR16_T_HANDLING);
  
  return c;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_char32_t function
//
// Lexes a single character and returns it.
//
char32_t lex_char32_t () 
{
  char32_t c = ' ';

  /* <TODO: Added lexing of char32_t characters> */
  err_report_and_exit_0 (EC_U_CHAR32_T_HANDLING);
	
  return c;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_get_char function
//
// Gets the next character in the input stream and keep track of the current
// token.
//
char lex_get_char() 
{
  return rdr_get_next_char ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_store_char function
//
// Stores the current character read. 
//
bool lex_store_char (bool start)
{
  if (start)
    str_reset (&current_token_string);
  
  str_append (&current_token_string, rdr_get_current_char ());

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_store_and_get_char function
//
// Stores the current character and reads a new from the input stream.
//
char lex_store_and_get_char (bool start)
{
  lex_store_char (start);

  return lex_get_char ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_skip_to_char function
//
// Skip the character between the current and the character given as argument.
//
void lex_skip_to_char (char to_c)
{
  while (lex_get_char () != to_c)
    ;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lex_wchar_t function
//
// Lexes a single character and returns it.
//
wchar_t lex_wchar_t () 
{
  wchar_t c = ' ';

  /* <TODO: Added lexing of wide characters> */
  err_report_and_exit_0 (EC_U_WCHAR_T_HANDLING);
	
  return c;
}
//------------------------------------------------------------------------------

//-<EOF>
