
/*-
 * Copyright (c) 2009 Roel Sergeant.
 * All rights reserved.
 *
 * This code is derived from software contributed to the Snow Leopard
 * project.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Standard C headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/error_codes.h"
#include "sl/slci/error_handling.h"
#include "sl/slci/hash_function.h"
#include "sl/slci/misc.h"
#include "sl/slci/symbol_table.h"
#include "sl/slci/types.h"
#include "sl/slci/type_info.h"

/*
 * Private function prototypes.
 */
void destroy_symtab_entry ();

/*
 * initialize_symtab function. This function initializes a symbol table.
 */
slci_symtab
initialize_symtab (hash_function_ptr hash_function, size_t size)
{
	size_t i;
	slci_symtab symtab;

	symtab.hash_function = hash_function;
	symtab.data = malloc (sizeof (slci_symtab_entry[size]));
	symtab.size = size;

	for (i = 0; i != symtab.size; ++i)
		symtab.data[i].key = 0;

	return symtab;
}

/*
 * clear_symtab function. Clear a symbol table.
 */
void
clear_symtab (slci_symtab* symtab)
{
	size_t i;

	for (i = 0; i != symtab->size; ++i)
		if (symtab->data[i].key != 0)
			destroy_symtab_entry (&symtab->data[i]);
}

/*
 * destroy_symtab function. Destroys a symbol table.
 */
void
destroy_symtab (slci_symtab* symtab)
{
	size_t i;

	for (i = 0; i != symtab->size; ++i)
		if (symtab->data[i].key != 0)
			destroy_symtab_entry (&symtab->data[i]);

	free (symtab->data);
}

/*
 * destroy_symtab_entry function. Destroys a symbol table entry.
 */
void
destroy_symtab_entry (slci_symtab_entry* entry)
{
	/* Do not free memory for built-in types */
	if (entry->token.type != TT_BUILT_IN
	    && entry->token.type != TT_PREPROCESSOR_BUILT_IN)
		free (entry->key);
	
	entry->key = 0;
	
	destroy_type_info (&entry->type_info);
}

/*
 * get_symtab_entry_by_lexeme function. Get a symbol table entry from the table.
 * The function returns 0 when the symbol is not found.
 */
slci_symtab_entry*
get_symtab_entry_by_lexeme (const slci_symtab* symtab, const char* lexeme)
{
	symtab_key_t hash_key = generate_cpp_hash_key (lexeme);

	if (strcmp (symtab->data[hash_key].key, lexeme))
		return &symtab->data[hash_key];
	
	return 0;
}

/*
 *
 */
slci_symtab_entry*
get_symtab_entry_by_key (const slci_symtab* symtab, const symtab_key_t key)
{
	return &symtab->data[key];
}

/*
 * set_symtab_entry function. Sets a symbol table entry.
 */
bool
set_symtab_entry (
	slci_symtab* symtab,
	char* key,
	slci_token token,
	slci_source_position pos
	)
{
	symtab_key_t hash_key = generate_cpp_hash_key (key);

	/* Set entry key if it doesn't exist yet */
	if (symtab->data[hash_key].key == 0)
		symtab->data[hash_key].key = key;
	else
	{
		/* Is the key the same as the given key */
		if (strcmp (symtab->data[hash_key].key, key) != 0)
		{
			raise_and_display_program_error_1 (
				ERR_SYMTAB_DUPLICATE,
				create_string_3 (
					symtab->data[hash_key].key,
					"!=",
					key
					)
				);
			return false;
		}
	}
	    
	/* Replace the symbol table entry with new data */
	symtab->data[hash_key].token = token;
	symtab->data[hash_key].position = pos;

	return true;
}

/*
 * set_symtab_type_info function. Sets the type info for a symbol table entry.
 */
bool
set_symtab_type_info (
	slci_symtab* symtab,
	symtab_key_t hash_key,
	slci_type_info type_info
	)
{
	if (symtab->data[hash_key].key == 0)
		return false;

	symtab->data[hash_key].type_info = type_info;

	return true;
}

/*>- EOF -<*/
