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
// strings.h
//------------------------------------------------------------------------------
// Dynamic strings for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_STRING_H__
#define __SL_SLCC_STRING_H__

#include "config_slcc.h"

#include <stdbool.h>
#include <stddef.h>
#include <wchar.h>

#include sl_os_fixinclude(uchar.h)

//------------------------------------------------------------------------------
// slcc_string struct
//
struct slcc_string 
{
  size_t size;
  size_t reserved;
  char* value;
};

typedef struct slcc_string slcc_string;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_string16 struct
//
struct slcc_string16 
{
  size_t size;
  size_t reserved;
  char16_t* value;
};

typedef struct slcc_string16 slcc_string16;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_string32 struct
//
struct slcc_string32
{
  size_t size;
  size_t reserved;
  char32_t* value;
};

typedef struct slcc_string32 slcc_string32;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_wstring struct
//
struct slcc_wstring 
{
  size_t size;
  size_t reserved;
  wchar_t* value;
};

typedef struct slcc_wstring slcc_wstring;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialization functions
//
slcc_string* str_new ();
slcc_string* str_new_with_data (const char*);
slcc_string16* str_new_16 ();
slcc_string32* str_new_32 ();
slcc_wstring* str_new_w ();
void str_delete (slcc_string*);
void str_delete_16 (slcc_string16*);
void str_delete_32 (slcc_string32*);
void str_delete_w (slcc_wstring*);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// String functions
//
bool str_append (slcc_string*, char);
bool str_append_16 (slcc_string16*, char16_t);
bool str_append_32 (slcc_string32*, char32_t);
bool str_append_w (slcc_wstring*, wchar_t);
char str_get_char_from_string (const slcc_string*, size_t);
char* str_get_c_string (const slcc_string*);
char* str_get_c_string_after (const slcc_string*, const char*);
char* str_get_c_string_all_after (const slcc_string*, const char*);
char* str_get_c_string_between (const slcc_string*, char, char);
char16_t* str_get_c16_string (const slcc_string16*);
char32_t* str_get_c32_string (const slcc_string32*);
size_t str_get_first_none_whitespace (const slcc_string*, size_t);
char* str_get_last_word_in_string (const slcc_string*);
wchar_t* str_get_wc_string (const slcc_wstring*);
bool str_reset (slcc_string*);
bool str_reset_16 (slcc_string16*);
bool str_reset_32 (slcc_string32*);
bool str_reset_w (slcc_wstring*);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_STRING_H__ */

//-<EOF>
