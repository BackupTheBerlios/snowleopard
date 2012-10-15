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
// literal.h
//------------------------------------------------------------------------------
// Literal for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_LITERAL_H__
#define __SL_SLCC_LITERAL_H__

#include "config_slcc.h"

#include <stdbool.h>
#include <stddef.h>
#include <wchar.h>

#include sl_os_fixinclude(uchar.h)

//------------------------------------------------------------------------------
// slcc_literal_type enum
//
enum slcc_literal_type
  {
    LT_BOOL,               /* Boolean value */
    LT_UNSIGNED_CHAR,      /* Unsigned character */
    LT_SIGNED_CHAR,        /* Signed character */
    LT_CHAR16_T,           /* Char16_t character */
    LT_CHAR32_T,           /* Char32_t character */
    LT_WCHAR_T,            /* Wchar_t character */
    LT_UNSIGNED_SHORT,     /* Unsigned short */
    LT_SIGNED_SHORT,       /* Signed short */
    LT_UNSIGNED_INT,       /* Unsigned integer */
    LT_SIGNED_INT,         /* Signed integer */
    LT_UNSIGNED_LONG,      /* Unsigned long */
    LT_SIGNED_LONG,        /* Signed long */
    LT_UNSIGNED_LONG_LONG, /* Unsigned long long */
    LT_SIGNED_LONG_LONG,   /* Signed long long */
    LT_FLOAT,              /* Floating point number */
    LT_DOUBLE,             /* Double floating point number */
    LT_LONG_DOUBLE,        /* Long double floating point number */
    LT_STRING,             /* Character string value */
    LT_STRING16,           /* Char16_t string value */
    LT_STRING32,           /* Char32_t string value */
    LT_WSTRING,            /* Wchar_t string value */
    LT_RAW_STRING,         /* Any raw string value */
    LT_USER_DEFINED        /* User defined literal */
  };

typedef enum slcc_literal_type slcc_literal_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_char_string struct
//
struct slcc_char_string
{
  size_t size;
  char* value;
};

typedef struct slcc_char_string slcc_char_string;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_char16_string struct
//
struct slcc_char16_string
{
  size_t size;
  char16_t* value;
};

typedef struct slcc_char16_string slcc_char16_string;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_char32_string struct
//
struct slcc_char32_string
{
  size_t size;
  char32_t* value;
};

typedef struct slcc_char32_string slcc_char32_string;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_raw_string struct
//
struct slcc_raw_string
{
  size_t size;
  char* value;
};

typedef struct slcc_raw_string slcc_raw_string;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_wchar_string struct
//
struct slcc_wchar_string
{
  size_t size;
  wchar_t* value;
};

typedef struct slcc_wchar_string slcc_wchar_string;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_Literal struct
//
// Structure for storing a literal value of any type.
//
struct slcc_literal
{
  slcc_literal_type type;

  union 
  {
    bool bool_value;
    unsigned char uchar_value;
    signed char schar_value;
    char16_t char16_t_value;
    char32_t char32_t_value;
    wchar_t wchar_t_value;
    unsigned short ushort_value;
    signed short sshort_value;
    unsigned int uint_value;
    signed int sint_value;
    unsigned long ulong_value;
    signed long slong_value;
    unsigned long long ulong_long_value;
    signed long long slong_long_value;
    float float_value;
    double double_value;
    long double long_double_value;
    slcc_char_string string;
    slcc_char16_string string16;
    slcc_char32_string string32;
    slcc_wchar_string wstring;
    slcc_raw_string raw_string;
  } value;
  
  char* lexeme;
};

typedef struct slcc_literal slcc_literal;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialize function prototypes
void literal_delete (slcc_literal*);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_LITERAL_H__ */

//-<EOF>
