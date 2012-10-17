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
// lexer_functions.h
//------------------------------------------------------------------------------
// Lexer functions for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_LEXER_FUNCTIONS_H__
#define __SL_SLCC_LEXER_FUNCTIONS_H__

#include "config_slcc.h"

#include <stdbool.h>

#include sl_os_fixinclude(uchar.h)

#include "strings.h"

//------------------------------------------------------------------------------
// Function prototypes
const slcc_string* lex_get_current_token_string ();
char lex_char ();
char16_t lex_char16_t ();
char32_t lex_char32_t ();
char lex_get_char ();
bool lex_store_char (bool start);
char lex_store_and_get_char (bool start);
void lex_skip_to_char (char to_c);
wchar_t lex_wchar_t ();
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_LEXER_FUNCTIONS_H__ */

//-<EOF>
