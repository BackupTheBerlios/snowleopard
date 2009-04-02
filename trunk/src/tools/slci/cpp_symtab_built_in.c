
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
#include "sl/slci/built_in_types.h"
#include "sl/slci/cpp_symtab.h"
#include "sl/slci/source_position.h"
#include "sl/slci/symbol_table.h"
#include "sl/slci/token.h"

/*
 * Private functions.
 */
bool create_built_in_type (slci_cpp_built_in_type, char*);

/*
 * load_built_in_types function. Loads the built in types into the symbol table.
 */
bool
load_built_in_types ()
{
	bool ok = true;

	ok = create_built_in_type (BT_VOID, "void");
	ok = create_built_in_type (BT_BOOL, "bool");
	ok = create_built_in_type (BT_UNSIGNED_CHAR, "unsigned char");
	ok = create_built_in_type (BT_SIGNED_CHAR, "signed char");
	ok = create_built_in_type (BT_UNSIGNED_CHAR, "char");
	ok = create_built_in_type (BT_CHAR16_T, "char16_t");
	ok = create_built_in_type (BT_CHAR32_T, "char32_t");
	ok = create_built_in_type (BT_WCHAR_T, "wchar_t");
	ok = create_built_in_type (BT_UNSIGNED_SHORT, "unsigned short");
	ok = create_built_in_type (BT_SIGNED_SHORT, "signed short");
	ok = create_built_in_type (BT_SIGNED_SHORT, "short");	
	ok = create_built_in_type (BT_UNSIGNED_INT, "unsigned int");
	ok = create_built_in_type (BT_SIGNED_INT, "signed int");
	ok = create_built_in_type (BT_SIGNED_INT, "int");
	ok = create_built_in_type (BT_UNSIGNED_LONG, "unsigned long");
	ok = create_built_in_type (BT_SIGNED_LONG, "signed long");
	ok = create_built_in_type (BT_SIGNED_LONG, "long");
	ok = create_built_in_type (BT_UNSIGNED_LONG_LONG, "unsigned long long");
	ok = create_built_in_type (BT_SIGNED_LONG_LONG, "signed long long");
	ok = create_built_in_type (BT_SIGNED_LONG_LONG, "long long");
	ok = create_built_in_type (BT_FLOAT, "float");
	ok = create_built_in_type (BT_DOUBLE, "double");
	ok = create_built_in_type (BT_LONG_DOUBLE, "long double");

	return ok;
}

/*
 * create_built_in_type function. Create a built-in type symbol table entry.
 */
bool
create_built_in_type (slci_cpp_built_in_type type, char* token)
{
	if (!set_symtab_entry (
		    &cpp_symtab,
		    token,
		    built_in_token (token, NoSourcePosition),
		    NoSourcePosition
		    ))
		return false;
	
	return true;
}

/*>- EOF -<*/
