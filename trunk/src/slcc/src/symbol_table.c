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
// symbol_table.c
//------------------------------------------------------------------------------
// Symbol table for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "definitions.h"
#include "error_codes.h"
#include "error_handling.h"
#include "hash_function.h"
#include "symbol_table.h"
#include "types.h"

//------------------------------------------------------------------------------
// Private function prototypes.
//
void symtab_delete_entry (slcc_symtab_entry* entry);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_generate_key macro
//
// Macro picks the correct hash key generation function based on the hash_type
// variable set in the symbol table.
//
#define symtab_generate_hash_key(key)				\
  symtab->hash_type == HT_CXX ? hash_generate_cxx_key (key)	\
                              : hash_generate_pp_key (key)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_new function
//
// This function initializes a symbol table.
//
slcc_symtab symtab_new (slcc_hash_type hash_type, size_t size) 
{
  size_t i;
  slcc_symtab symtab;

  symtab.hash_type = hash_type;
  symtab.data = malloc (sizeof (slcc_symtab_entry[size]));
  symtab.size = size;

  for (i = 0; i != symtab.size; ++i) 
    {
      symtab.data[i].key = NULL;
      symtab.data[i].value = NULL;
    }

  return symtab;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_clear function
//
// Clear a symbol table.
//
void symtab_clear (slcc_symtab* symtab) 
{
  size_t i;

  for (i = 0; i != symtab->size; ++i)
    if (symtab->data[i].key != NULL)
      symtab_delete_entry (&symtab->data[i]);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_delete function
//
// Destroys a symbol table.
//
void symtab_delete (slcc_symtab* symtab) 
{
  size_t i;

  for (i = 0; i != symtab->size; ++i)
    if (symtab->data[i].key != NULL)
      symtab_delete_entry (&symtab->data[i]);

  free (symtab->data);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_get_entry_by_lexeme function
//
// Get a symbol table entry from the table. The function returns 0 when the
// symbol is not found.
//
slcc_symtab_entry* symtab_get_entry_by_lexeme (
					       const slcc_symtab* symtab,
					       const char* lexeme
					       ) 
{
  symtab_key_t hash_key = symtab_generate_hash_key (lexeme);

  if (strcmp (symtab->data[hash_key].key, lexeme))
    return &symtab->data[hash_key];

  return NULL;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_get_entry_by_key function
//
// Returns the symtab entry for the key.
//
slcc_symtab_entry* symtab_get_entry_by_key (
					    const slcc_symtab* symtab,
					    const symtab_key_t hash_key
					    ) 
{
  return &symtab->data[hash_key];
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_get_key_by_lexeme function
//
// Get the key for the lexeme in the symbol table. The function returns the 
// maximum size_t if the key is not found.
//
symtab_key_t symtab_get_key_by_lexeme (
				       const slcc_symtab* symtab,
				       const char* lexeme
				       ) 
{
  symtab_key_t hash_key = symtab_generate_hash_key (lexeme);

  if (strcmp (symtab->data[hash_key].key, lexeme))
    return hash_key;

  return MaxSymtabKeyT;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_is_in function
//
// Returns true if token is in the symbol table.
//
bool symtab_is_in (const slcc_symtab* symtab, const char* key) 
{
  symtab_key_t hash_key = symtab_generate_hash_key (key);

  return symtab->data[hash_key].key != NULL;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_set_entry function
//
// Sets a symbol table entry.
//
symtab_key_t symtab_set_entry (
			       slcc_symtab* symtab,
			       char* key,
			       slcc_token token,
			       slcc_source_position pos,
			       char* value
			       ) 
{
  symtab_key_t hash_key = symtab_generate_hash_key (key);

  /* Set entry key if it doesn't exist yet */
  if (symtab->data[hash_key].key == NULL)
    symtab->data[hash_key].key = key;
  else if (strcmp (symtab->data[hash_key].key, key) != 0) 
    {
      /* Is the key the same as the given key */
      err_report_and_exit_2 (
			     EC_SYMTAB_DUPLICATE,
			     symtab->data[hash_key].key, 
			     key
			     );
      return MaxSymtabKeyT;
    }

  /* Replace the symbol table entry with new data */
  symtab->data[hash_key].token = token;
  symtab->data[hash_key].position = pos;
  symtab->data[hash_key].value = value;

  return hash_key;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// symtab_set_definition function
//
// Sets the type info for a symbol table entry.
//
bool symtab_set_definition (
			    slcc_symtab* symtab,
			    symtab_key_t hash_key,
			    slcc_definition* definition
			    ) 
{
  if (symtab->data[hash_key].key == 0)
    return false;

  symtab->data[hash_key].definition = definition;

  return true;
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// symtab_delete_entry function
//
// Destroys a symbol table entry.
//
void symtab_delete_entry (slcc_symtab_entry* entry) 
{
  /* Do not free memory for built-in types */
  if (entry->token.type != TT_BUILT_IN
      && entry->token.type != TT_PREPROCESSOR_BUILT_IN)
    {
      free (entry->key);
      if (entry->value != 0)
	free (entry->value);
    }

  entry->key = 0;
  entry->value = 0;

  def_delete (entry->definition);
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
