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
// preprocessor_symtab.c
//------------------------------------------------------------------------------
// Preprocessor symbol table for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "error_codes.h"
#include "error_handling.h"
#include "hash_function.h"
#include "preprocessor_symtab.h"
#include "symbol_table.h"

//------------------------------------------------------------------------------
// Global variables
//
slcc_symtab pp_symtab_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_symtab_new function
//
// Initializes the preprocessor symbol table.
//
bool pp_symtab_new () 
{
  pp_symtab_ = symtab_new (
			   HT_PREPROCESSOR,
			   MaxPreHashTableEntries
			   );
  
  if (pp_symtab_.size == 0)
    return false;

  if (!pp_symtab_load_built_in_macros ()) 
    {
      err_report_and_exit_0 (EC_SYMTAB_LOAD_BUILT_IN_FAILED);
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_symtab_delete function
//
// Destroys the preprocessor symbol table.
//
void pp_symtab_delete () 
{
  symtab_delete (&pp_symtab_);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pre_symtab_get_macro_position function
//
// This function returns the position of a macro in the symbol table.
//
symtab_key_t pp_symtab_get_macro_position (const slcc_string* token) 
{
  symtab_key_t macro = hash_generate_pp_key (str_get_c_string (token));

  if (pp_symtab_.data[macro].key == 0)
    return MaxSymtabKeyT;

  return macro;
}
//------------------------------------------------------------------------------

//-<EOF>
