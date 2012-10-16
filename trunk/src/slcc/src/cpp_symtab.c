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
// cpp_symtab.c
//------------------------------------------------------------------------------
// C++ symbol table for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "cpp_symtab.h"
#include "error_codes.h"
#include "error_handling.h"
#include "hash_function.h"
#include "symbol_table.h"

//------------------------------------------------------------------------------
// Global variables.
//
slcc_symtab cpp_symtab;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// cpp_symtab_new function
//
// Initializes the C++ symbol table.
//
bool cpp_symtab_new () 
{
  cpp_symtab = symtab_new (
			   &hash_get_cpp_char_hash_value, 
			   MaxCppHashTableEntries
			   );

  if (cpp_symtab.size == 0)
    return false;

  if (!load_cpp_built_in_types ()) 
    {
      err_report_and_exit_0 (EC_SYMTAB_LOAD_BUILT_IN_FAILED);
      return false;
    }
	
  if (!load_cpp_built_in_identifiers ())
    {
      err_report_and_exit_0 (EC_SYMTAB_LOAD_BUILT_IN_FAILED);
      return false;
    }

  if (!load_cpp_built_in_namespaces ())
    {
      err_report_and_exit_0 (EC_SYMTAB_LOAD_BUILT_IN_FAILED);
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// cpp_symtab_delete function
// 
// Destroys the C++ symbol table.
//
void cpp_symtab_delete () {
  symtab_delete (&cpp_symtab);
}
//------------------------------------------------------------------------------

//-<EOF>
