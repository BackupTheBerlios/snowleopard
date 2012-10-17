/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// token_functions.c
//------------------------------------------------------------------------------
// Token information functions for the compiler front end.
//------------------------------------------------------------------------------

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "source_position.h"
#include "strings.h"
#include "token.h"

#include "integer_functions.h"

//------------------------------------------------------------------------------
// token_new_built_in function
//
// This function returns a token for a built-in.
//
slcc_token token_new_built_in (char* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_BUILT_IN;
  token.pos = pos;

  token.value.built_in = s;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_char function
//
// This function returns a character token.
//
slcc_token token_new_char (char c, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_UNSIGNED_CHAR;
  token.value.literal.value.uchar_value = c;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// char16_token function
//
// This function returns a char16_t token.
//
slcc_token char16_token (char16_t c, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_CHAR16_T;
  token.value.literal.value.char16_t_value = c;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// char32_token function
//
// This function returns a char32_t token.
//
slcc_token char32_token (char32_t c, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_CHAR32_T;
  token.value.literal.value.char32_t_value = c;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_comment function
//
// This function returns a comment token.
//
slcc_token token_new_comment (const slcc_string* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_COMMENT;
  token.pos = pos;
  token.value.comment = str_get_c_string (s);

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_empty function
//
// This function returns an empty token.
//
slcc_token token_new_empty (slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_EMPTY;
  token.pos = pos;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_eof function
//
// This function return an eof token.
//
slcc_token token_new_eof () 
{
  slcc_token token;

  token.type = TT_EOF;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_float function
//
// This function returns a floating point token. All literals are returned as 
// double, unless the type is specified.
//
slcc_token token_new_float(
			   slcc_string* s, 
			   slcc_source_position pos, 
			   bool type_float,
			   bool type_long_double
			   ) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  /* float type requested */
  if (type_float)
    {
      float f = strtof (s->value, NULL);
      token.value.literal.type = LT_FLOAT;
      token.value.literal.value.float_value = f;
    }

  /* long double type requested */
  else if (type_long_double)
    {
      long double ld = strtold (s->value, NULL);
      token.value.literal.type = LT_LONG_DOUBLE;
      token.value.literal.value.long_double_value = ld;
    }

  /* Default to double type */
  else
    {
      double d = strtod (s->value, NULL);
      token.value.literal.type = LT_DOUBLE;
      token.value.literal.value.long_double_value = d;
    }

  token.value.literal.lexeme = str_get_c_string(s);

  str_delete (s);

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_identifier function
//
// This function returns an identifier token.
//
slcc_token token_new_identifier (const slcc_string* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_IDENTIFIER;

  token.pos = pos;

  token.value.identifier = str_get_c_string (s);

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_int function
//
// This function returns a numeric token. The parameters are defined as follows:
//   - force_signed: Value is forced to be signed (for example by adding 'U' to 
//                   the end of the literal).
//   - type_long: Value is type long, due to l/L suffix.
//   - type_long_long: Value is type long long, due to ll/LL suffix.
//
slcc_token token_new_int (
			  slcc_string* s, 
			  slcc_source_position pos,
			  bool is_octal,
			  bool is_hexadecimal,
			  bool is_unsigned,
			  bool type_long,
			  bool type_long_long
			  ) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  if (is_octal)
    {
      token.value.literal.type = LT_UNSIGNED_LONG;
      token.value.literal.value.ulong_value = tc_convert_oct_to_dec (s->value);
    }
  else if (is_hexadecimal)
    {
      token.value.literal.type = LT_UNSIGNED_LONG;
      token.value.literal.value.ulong_value = tc_convert_hex_to_dec (s->value);
    }
  else if (s->value[0] == '-' && !is_unsigned) 
    {
      long long signed_value = atoll(s->value);
      if (type_long_long) 
	{
	  token.value.literal.type = LT_SIGNED_LONG_LONG;
	  token.value.literal.value.slong_long_value = signed_value;
	}
      else if (type_long)
	{
	  token.value.literal.type = LT_SIGNED_LONG;
	  token.value.literal.value.slong_value = (signed long)signed_value;
	}
      else if (signed_value < LONG_MIN || signed_value > LONG_MAX) 
	{
	  token.value.literal.type = LT_SIGNED_LONG_LONG;
	  token.value.literal.value.slong_long_value = signed_value;
	}
      else if (signed_value < INT_MIN || signed_value > INT_MAX) 
	{
	  token.value.literal.type = LT_SIGNED_LONG;
	  token.value.literal.value.slong_value = (long)signed_value;
	}
      else if (signed_value < SHRT_MIN || signed_value > SHRT_MAX) 
	{
	  token.value.literal.type = LT_SIGNED_INT;
	  token.value.literal.value.sint_value = (int)signed_value;
	}
      else if (signed_value < SCHAR_MIN || signed_value > SCHAR_MAX) 
	{
	  token.value.literal.type = LT_SIGNED_SHORT;
	  token.value.literal.value.sshort_value = (short)signed_value;
	}
      else 
	{
	  token.value.literal.type = LT_SIGNED_CHAR;
	  token.value.literal.value.schar_value = (signed char)signed_value;
	}
    } 
  else 
    {
      unsigned long long unsigned_value = strtoull(s->value, NULL, 10);
      if (type_long_long)
	{
	  token.value.literal.type = LT_UNSIGNED_LONG_LONG;
	  token.value.literal.value.ulong_long_value = unsigned_value;
	}
      else if (type_long)
	{
	  token.value.literal.type = LT_UNSIGNED_LONG;
	  token.value.literal.value.ulong_value = (unsigned long)unsigned_value;
	}
      else if (unsigned_value > ULONG_MAX) 
	{
	  token.value.literal.type = LT_UNSIGNED_LONG_LONG;
	  token.value.literal.value.ulong_long_value = unsigned_value;
	}
      else if (unsigned_value > UINT_MAX) 
	{
	  token.value.literal.type = LT_UNSIGNED_LONG;
	  token.value.literal.value.slong_value = (unsigned long)unsigned_value;
	}
      else if (unsigned_value > SHRT_MAX) 
	{
	  token.value.literal.type = LT_UNSIGNED_INT;
	  token.value.literal.value.sint_value = (unsigned int)unsigned_value;
	}
      else if (unsigned_value > CHAR_MAX) 
	{
	  token.value.literal.type = LT_UNSIGNED_SHORT;
	  token.value.literal.value.sshort_value = (unsigned short)unsigned_value;
	}
      else 
	{
	  token.value.literal.type = LT_UNSIGNED_CHAR;
	  token.value.literal.value.schar_value = (char)unsigned_value;
	}
    } 
  token.value.literal.lexeme = str_get_c_string(s);

  str_delete (s);

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_keyword function
//
// This function returns a keyword token.
//
slcc_token token_new_keyword (slcc_keyword keyword, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_KEYWORD;

  token.pos = pos;

  token.value.keyword = keyword;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_preprocessor function
//
// This function returns a preprocessor token.
//
slcc_token token_new_preprocessor (
				   const slcc_string* s, 
				   slcc_source_position pos
				   ) 
{
  slcc_token token;

  token.type = TT_PREPROCESSOR;
  token.pos = pos;

  token.value.preprocessor = str_get_c_string (s);

  /* Cut last character from string (it's \n) */
  token.value.preprocessor[strlen (token.value.preprocessor) - 1] = '\0';

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_preprocessor_built_in function
//
// This function returns a preprocessor built in token.
//
slcc_token token_new_preprocessor_built_in (char* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_PREPROCESSOR_BUILT_IN;
  token.pos = pos;

  token.value.preprocessor = s;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_punctuation function
//
// This function returns a punctuation token.
//
slcc_token token_new_punctuation (
				  slcc_punctuation punctuation,
				  slcc_source_position pos
				  ) 
{
  slcc_token token;

  token.type = TT_PUNCTUATION;

  token.pos = pos;

  token.value.punctuation = punctuation;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_raw_string function
//
// This function returns a raw string token.
//
slcc_token token_new_raw_string (char* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_RAW_STRING;

  token.value.literal.value.raw_string.size = strlen (s);
  token.value.literal.value.raw_string.value = s;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_string function
//
// This function returns a string token.
//
slcc_token token_new_string (slcc_string* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_STRING;

  token.value.literal.value.string.size = s->size;
  token.value.literal.value.string.value = str_get_c_string (s);

  str_delete (s);

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_string16 function
//
// This function returns a string16 token.
//
slcc_token token_new_string16 (slcc_string16* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_STRING16;

  token.value.literal.value.string16.size = s->size;
  token.value.literal.value.string16.value = str_get_c16_string (s);

  str_delete_16 (s);

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_string32 function
//
// This function returns a string32 token.
//
slcc_token token_new_string32 (slcc_string32* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_STRING32;

  token.value.literal.value.string32.size = s->size;
  token.value.literal.value.string32.value = str_get_c32_string (s);

  str_delete_32 (s);

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_wchar function
//
// This function returns a wcharacter token.
//
slcc_token token_new_wchar (wchar_t c, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_WCHAR_T;
  token.value.literal.value.wchar_t_value = c;

  return token;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_new_wstring function.
//
// This function returns a wstring token.
//
slcc_token token_new_wstring (slcc_wstring* s, slcc_source_position pos) 
{
  slcc_token token;

  token.type = TT_LITERAL;
  token.pos = pos;

  token.value.literal.type = LT_WSTRING;

  token.value.literal.value.wstring.size = s->size;
  token.value.literal.value.wstring.value = str_get_wc_string (s);

  str_delete_w (s);

  return token;
}
//------------------------------------------------------------------------------

//-<EOF>
