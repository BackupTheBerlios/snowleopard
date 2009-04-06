
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

/* Snow Leopard headers */
#include "sl/slci/hash_function.h"
#include "sl/slci/preprocessor_symtab.h"
#include "sl/slci/types.h"

slci_symtab preprocessor_symtab;

/*
 * initialize_preprocessor_symtab function. Initializes the C++ symbol table.
 */
bool
initialize_preprocessor_symtab ()
{
	preprocessor_symtab = initialize_symtab (
		&get_pre_char_hash_value,
		MaxPreHashTableEntries
		);

	if (preprocessor_symtab.size == 0)
		return false;

	return true;
}

/*
 * destroy_preprocessor_symtab function. Destroys the C++ symbol table.
 */
void
destroy_preprocessor_symtab ()
{
	destroy_symtab (&preprocessor_symtab);
}

/*
 * get_macro_position function. This function returns the position of a macro
 * in the symbol table.
 */
symtab_key_t
get_macro_position (const slci_string* token)
{
	symtab_key_t macro = generate_pre_hash_key (get_c_string (token));

	if (preprocessor_symtab.data[macro].key == 0)
		return MaxSymtabKeyT;

	return macro;
}

/*>- EOF -<*/
