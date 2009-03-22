
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
#include "sl/slci/lexer_functions.h"
#include "sl/slci/reader.h"
#include "sl/slci/string.h"

/*
 * Private variables
 */
slci_string current_token_string;

/*
 * get_current_token_string function. Returns the current_token_string.
 */
char*
get_current_token_string ()
{
	return get_c_string (current_token_string);
}

/*
 * is_whitespace function. Skip over all whitespace not inside a lexeme.
 */
bool
is_whitespace (char c)
{
	switch (c)
	{
	case ' ':
	case '\n':
	case '\r':
	case '\t':
		return true;
		
	default:
		return false;
	}
}

/*
 * lex_single_character function. Lexes a single character and returns it.
 */
char
lex_single_character ()
{
	/* Get character */
	char c = lex_get_next_char (false, true);

	/* If character is escaped */
	if (c == '\\')
	{
		char c = lex_get_next_char (false, true);

		switch (c)
		{
		case 'a':
			c = '\a';
			break;

		case 'b':
			c = '\b';
			break;

		case 'f':
			c = '\f';
			break;

		case 'n':
			c = '\n';
			break;

		case 'r':
			c = '\r';
			break;

		case 't':
			c = '\t';
			break;

		case 'v':
			c = '\v';
			break;

		case '\\':
			c = '\\';
			break;

		case '\?':
			c = '\?';
			break;

		case '\'':
			c = '\'';
			break;

		case '\"':
			c = '\"';
			break;

		case '0':
			/* TODO - Octal constants */
			break;

		case 'x':
			/* TODO - Hexadecimal constants */
			break;

		default:
			/* TODO - Report invalid character literal */ ;
			break;			
		}
	}

	return c;
}

/*
 * lex_get_next_char function. Gets the next character in the input stream and keep track of the current token.
 */
char
lex_get_next_char (bool start, bool store)
{
	char c = get_next_char ();

	if (start)
		reset_string (current_token_string);

	if (store)
		append_string (current_token_string, c);
	
	return c;
}

/*
 * skip_to_char function. This function skips until the character given is found.
 */
void
skip_to_char (char c)
{
	while (lex_get_next_char (true, false) == c)
		;
}

/*>- EOF -<*/
