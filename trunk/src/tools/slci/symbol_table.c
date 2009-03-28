
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

/* Snow Leopard headers */
#include "sl/slci/hash_function.h"
#include "sl/slci/symbol_table.h"

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
	slci_symtab symtab;

	symtab.hash_function = hash_function;
	symtab.data = malloc (sizeof (slci_symtab_entry[size]));
	symtab.size = size;

	return symtab;
}

/*
 * destroy_symtab function. Destroys a symbol table.
 */
void
destroy_symtab (slci_symtab* symtab)
{
	size_t i;

	for (i = 0; i != symtab->size; ++i)
		destroy_symtab_entry (symtab->data[i]);

	free (symtab->data);
	symtab->data = 0;
}

/*
 * destroy_symtab_entry function. Destroys a symbol table entry.
 */
void
destroy_symtab_entry ()
{

}

/*>- EOF -<*/
