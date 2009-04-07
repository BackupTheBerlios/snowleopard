
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

/* Snow Leopard headers */
#include "sl/slci/source_position.h"
#include "sl/slci/symbol_table.h"
#include "sl/slci/token.h"
#include "sl/slci/version.h"

/*
 * Private functions.
 */
bool create_built_in_macro (char*, char*);

/*
 * load_built_in_types function. Loads the built in types into the symbol table.
 */
bool
load_built_macros ()
{
	bool ok = true;
	char* buffer;
	
	/* Snow Leopard macros */
	char* buffer = malloc (sizeof (char[MaxVersionLabelSize]));
	buffer = get_version_string (buffer);
	ok = create_built_in_macro ("__SLCC__", buffer);
	free (buffer);
	
	/* Standard C macros */
	ok = create_built_in_macro ("__STDC__", "");

	/* Standard C++ macros */
	ok = create_built_in_macro ("__STDCPP__", "");
	
	return ok;
}

/*
 * create_built_in_type function. Create a built-in type symbol table entry.
 */
bool
create_built_in_macro (char* token, char* value)
{
	if (!set_symtab_entry (
		    &preprocessor_symtab,
		    token,
		    preprocessor_token (token, NoSourcePosition),
		    NoSourcePosition
		    ))
		return false;
	
	return true;
}

/*>- EOF -<*/
