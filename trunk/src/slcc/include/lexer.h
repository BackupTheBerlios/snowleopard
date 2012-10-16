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
// lexer.h
//------------------------------------------------------------------------------
// Lexer for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_LEXER_H__
#define __SL_SLCC_LEXER_H__

#include <stdbool.h>

#include "source_position.h"
#include "token.h"

//------------------------------------------------------------------------------
// Global variables
//
extern slcc_token current_token;
extern slcc_token previous_token;
extern slcc_source_position* current_source_position;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialize functions
//
bool lexer_initialize (char*);
void lexer_cleanup ();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Lexer functions
//
slcc_token lex_get_next_token (bool);
slcc_token lex_get_previous_token ();
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_LEXER_H__ */

//-<EOF>
