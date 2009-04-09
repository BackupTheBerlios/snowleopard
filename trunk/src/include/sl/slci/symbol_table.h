
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

#ifndef _SL_SLCI_SYMBOL_TABLE_H_
#define _SL_SLCI_SYMBOL_TABLE_H_

/* Standard C headers */
#include <stdbool.h>
#include <stddef.h>

/* Snow Leopard headers */
#include "sl/slci/hash_function.h"
#include "sl/slci/source_position.h"
#include "sl/slci/token.h"
#include "sl/slci/types.h"
#include "sl/slci/type_info.h"

/*
 * Symbol table entry.
 */
struct slci_symtab_entry
{
	char* key;
	slci_token token;
	slci_source_position position;
	slci_type_info type_info;
	char* value;
};

typedef struct slci_symtab_entry slci_symtab_entry;

/*
 * Symbol table.
 */
struct slci_symtab
{
	hash_function_ptr hash_function;
	slci_symtab_entry* data;
	size_t size;
};

typedef struct slci_symtab slci_symtab;

/*
 * Initialize functions.
 */
slci_symtab initialize_symtab (hash_function_ptr, size_t);
void clear_symtab (slci_symtab*);
void destroy_symtab (slci_symtab*);

/*
 * Get symbol table entry.
 */
slci_symtab_entry* get_symtab_entry_by_lexeme (const slci_symtab*, const char*);
slci_symtab_entry* get_symtab_entry_by_key (const slci_symtab*, const symtab_key_t);
bool is_in_symtab (const slci_symtab*, const char*);

/*
 * Set symbol table entry.
 */
bool set_symtab_entry (slci_symtab*, char*, slci_token, slci_source_position, char*);
bool set_symtab_type_info (slci_symtab*, symtab_key_t, slci_type_info);

#endif /* !_SL_SLCI_SYMBOL_TABLE_H_ */

/*>- EOF -<*/
