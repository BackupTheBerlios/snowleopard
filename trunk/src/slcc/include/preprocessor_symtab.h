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
// preprocessor_symtab.h
//------------------------------------------------------------------------------
// Preprocessor symbol table for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_PREPROCESSOR_SYMBOL_TABLE_H__
#define __SL_SLCC_PREPROCESSOR_SYMBOL_TABLE_H__

#include "symbol_table.h"

//------------------------------------------------------------------------------
// Global variables
//
extern slcc_symtab pp_symtab_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialization functions
//
bool pp_symtab_new ();
void pp_symtab_delete ();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Get functions
//
symtab_key_t pp_symtab_get_macro_position (const slcc_string* token);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Load built in macros
//
bool pp_symtab_load_built_in_macros ();
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_PREPROCESSOR_SYMBOL_TABLE_H__ */

//-<EOF>
