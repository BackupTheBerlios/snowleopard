/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2012 Roel Sergeant
  
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
// parser.h
//------------------------------------------------------------------------------
// Parser for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_PARSER_H__
#define __SL_SLCC_PARSER_H__

#include <stdbool.h>

//------------------------------------------------------------------------------
// Parser functions.
bool parser_initialize ();
void parser_cleanup ();
bool parser_start ();
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_PARSER_H__ */

//-<EOF>