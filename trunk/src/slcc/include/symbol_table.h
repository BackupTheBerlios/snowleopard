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
// symbol_table.h
//------------------------------------------------------------------------------
// Symbol table for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SYMBOL_TABLE_H__
#define __SL_SLCC_SYMBOL_TABLE_H__

#include <stdbool.h>
#include <stddef.h>

//#include "slci/built_in_types.h"
#include "definitions.h"
#include "hash_function.h"
#include "source_position.h"
#include "token.h"
#include "types.h"

//------------------------------------------------------------------------------
// slcc_symtab_entry struct
//
// Symbol table entry.
//
struct slcc_symtab_entry
{
  char* key;
  slcc_token token;
  slcc_source_position position;
  slcc_definition* definition;
  char* value;
};

typedef struct slcc_symtab_entry slcc_symtab_entry;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_symtab struct
//
// Symbol table.
//
struct slcc_symtab
{
  slcc_hash_type hash_type;
  slcc_symtab_entry* data;
  size_t size;
};

typedef struct slcc_symtab slcc_symtab;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialize functions
//
slcc_symtab symtab_new (slcc_hash_type hash_type, size_t size);
void symtab_clear (slcc_symtab* symtab);
void symtab_delete (slcc_symtab* symtab);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Get symbol table entry
//
slcc_symtab_entry* symtab_get_entry_by_lexeme (
					       const slcc_symtab* symtab, 
					       const char* lexeme
					       );
slcc_symtab_entry* symtab_get_entry_by_key (
					    const slcc_symtab* symtab, 
					    const symtab_key_t hash_key
					    );
symtab_key_t symtab_get_key_by_lexeme (
				       const slcc_symtab* symtab, 
				       const char* lexeme
				       );
bool symtab_is_in (const slcc_symtab* symtab, const char* key);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Set symbol table entry
//
symtab_key_t symtab_set_entry (
			       slcc_symtab* symtab, 
			       char* key, 
			       slcc_token token, 
			       slcc_source_position pos,
			       char* value
			       );
bool symtab_set_definition (
			    slcc_symtab* symtab, 
			    symtab_key_t hash_key, 
			    slcc_definition* definition
			    );
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SYMBOL_TABLE_H__ */

//-<EOF>
