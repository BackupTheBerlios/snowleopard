
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
#include "sl/slci/error_handling.h"
#include "sl/slci/lexer_functions.h"
#include "sl/slci/misc.h"
#include "sl/slci/reader.h"
#include "sl/slci/string.h"

/*
 * Private variables
 */
slci_string current_token_string = {
	0,
	0,
	0
};

/*
 * get_current_token_string function. Returns the current_token_string.
 */
const slci_string*
get_current_token_string ()
{
	return &current_token_string;
}

/*
 * is_hexadecimal function. If character is a hexadecimal return true.
 */
bool
is_hexadecimal (char c)
{
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
		return true;
		break;
		
	default:
		return false;
		break;
	}
}
		
/*
 * is_whitespace function. If character is whitespace return true.
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
		break;
		
	default:
		return false;
		break;
	}
}

/*
 * lex_narrow_character function. Lexes a single character and returns it.
 */
char
lex_narrow_character ()
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
		{
			int i = 0;
			c = lex_get_next_char (false, true);
			if (is_hexadecimal (c))
				i = get_hex_value (c);
			else
			{
				raise_and_display_error (
					ERR_INVALID_CHARACTER_HEXADECIMAL_LITERAL,
					get_current_source_position (),
					get_c_string (get_current_token_string ())
					);
				return 0;
			}
			c = lex_get_next_char (false, true);
			if (is_hexadecimal (c))
				i = i * 16 + get_hex_value (c);
			else
			{
				raise_and_display_error (
					ERR_INVALID_CHARACTER_HEXADECIMAL_LITERAL,
					get_current_source_position (),
					get_c_string (get_current_token_string ())
					);
				return 0;
			}
			c = i;
		}
		break;

		default:
			/* TODO - Report invalid character literal */ ;
			break;			
		}
	}

	return c;
}

/*
 * lex_wide_character function. Lexes a single character and returns it.
 */
wchar_t
lex_wide_character ()
{
	wchar_t c;

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
		reset_string (&current_token_string);

	if (store)
		append_string (&current_token_string, c);
	
	return c;
}

/*
 * skip_to_char function. This function skips until the character given is found.
 */
void
skip_to_char (char c)
{
	while (lex_get_next_char (false, true) != c)
		;
}

/*>- EOF -<*/
