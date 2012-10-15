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
// hash_function.h
//------------------------------------------------------------------------------
// Hash function for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_HASH_FUNCTION_H__
#define __SL_SLCC_HASH_FUNCTION_H__

#include <stddef.h>

#include "types.h"

//------------------------------------------------------------------------------
// Maxinum number of values in hash tables
extern const symtab_key_t MaxCppHashTableEntries;
extern const size_t MaxCppHashCharacterValue;
extern const symtab_key_t MaxPreHashTableEntries;
extern const size_t MaxPreHashCharacterValue;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Typdef for hash functions
//
typedef symtab_key_t (*hash_function_ptr) (char);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Hash function for C++ identifiers, used for hashing the keys for the
// compiler front end's symbol table
//
symtab_key_t hash_generate_cpp_key (const char*);
symtab_key_t hash_generate_pre_key (const char*);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_HASH_FUNCTION_H__ */

//-<EOF>
