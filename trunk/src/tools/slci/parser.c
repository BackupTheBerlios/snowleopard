
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
#include <stddef.h>

/* Snow Leopard headers */
#include "sl/slci/cpp_symtab.h"
#include "sl/slci/lexer.h"
#include "sl/slci/parse_tree.h"
#include "sl/slci/parser.h"
#include "sl/slci/string.h"
#include "sl/slci/token.h"
#include "sl/slci/types.h"

/*
 * Private function prototypes.
 */
static void parse_class ();
static void parse_definition ();
static void parse_function ();
static void parse_statement ();
static void parse_template ();
static void parse_translation_unit ();
static symtab_key_t store_identifier (char*, slci_token);

/*
 * initialize_parser function. It initializes the lexer using the file.
 */
bool
initialize_parser (char* file)
{
	if (!initialize_lexer (file))
		return false;

	if (!initialize_parse_tree ())
	{
		destroy_lexer ();
		return false;
	}

	return true;
}

/*
 * destroy_parser function. Destroys the parser.
 */
void
destroy_parser ()
{
	destroy_lexer ();
	destroy_parse_tree ();
}

/*
 * parse function. Parse the translation unit.
 */
bool
parse ()
{
	slci_token token = get_next_token ();
	size_t i = 0;

	while (token.type != TT_EOF)
	{
		if (token.type != TT_EOF && token.type != TT_EMPTY
		    && token.type != TT_COMMENT && token.type != TT_PREPROCESSOR
		    && token.type != TT_KEYWORD && token.type != TT_PUNCTUATION
		    && token.type != TT_LITERAL && token.type != TT_IDENTIFIER)
			return false;

		if (token.type != TT_COMMENT)
		{
			print_token (i, token);
			++i;
		}
		
		token = get_next_token ();
	}

	return true;
}

/*
 * parse_class function. Parses a class definition.
 */
void
parse_class ()
{

}

/*
 * parse_definition function. Parses a definition.
 */
void
parse_definition ()
{

}

/*
 * parse_function function. Parses a function definition.
 */
void
parse_function ()
{

}

/*
 * parse_statement function. Parses a statement.
 */
void
parse_statement ()
{

}

/*
 * parse_template function. Parses a template defintion.
 */
void
parse_template ()
{

}

/*
 * parse_translation_unit function. Parses a translation unit.
 */
void
parse_translation_unit ()
{

}

/*
 * store_identifier function. Function stores an identifier in the symbol table.
 */
symtab_key_t
store_identifier (char* identifier, slci_token token)
{
	symtab_key_t hash_key = generate_cpp_hash_key (identifier);

	if (!set_symtab_entry (
		    &cpp_symtab,
		    identifier,
		    token,
		    token.pos,
		    0
		    ))
		/* TODO - Report error */ ;

	return hash_key;
}

/*>- EOF -<*/
