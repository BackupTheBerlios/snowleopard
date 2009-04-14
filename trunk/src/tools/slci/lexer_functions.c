
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
 * is_punctuation_char function. Returns true for an punctuation character.
 */
bool
is_punctuation_char (char c)
{
	switch (get_previous_char ())
	{
	/* These tokens always appear alone */
	case '(':
	case ')':
	case '[':
	case ']':
	case '{':
	case '}':
		return false;
		break;
	}
	
	switch (c)
	{
	case '^':
	case '-':
	case ',':
	case '=':
	case '>':
	case ';':
	case ':':
	case '!':
	case '?':
	case '.':
	case '/':
	case '&':
	case '#':
	case '%':
	case '<':
	case '|':
	case '~':
		return true;
		break;

	/* Special handling for double pointers */
	case '*':
		return get_previous_char () != '*';
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

		case '0': /* Octal character constant */
		        {
				int i = 0;
				c = lex_get_next_char (false, true);
				if (c >= '0' && c <= '3')
					i = get_oct_value (c);
				else
				{
					raise_and_display_error_0 (
						ERR_INVALID_CHARACTER_OCTAL_LITERAL,
						get_current_source_position (),
						get_c_string (get_current_token_string ())
						);
					return 0;
				}
				c = lex_get_next_char (false, true);
				if (c >= '0' && c <= '7')
					i = i * 8 + get_oct_value (c);
				else
				{
					raise_and_display_error_0 (
						ERR_INVALID_CHARACTER_OCTAL_LITERAL,
						get_current_source_position (),
						get_c_string (get_current_token_string ())
						);
					return 0;
				}
				c = lex_get_next_char (false, true);
				if (c >= '0' && c <= '7')
					i = i * 8 + get_oct_value (c);
				else
				{
					raise_and_display_error_0 (
						ERR_INVALID_CHARACTER_OCTAL_LITERAL,
						get_current_source_position (),
						get_c_string (get_current_token_string ())
						);
					return 0;
				}
				c = i;	
			}
			break;

		case 'x': /* Hexadecimal character constant */
		        {
				int i = 0;
				c = lex_get_next_char (false, true);
				if (is_hexadecimal (c))
					i = get_hex_value (c);
				else
				{
					raise_and_display_error_0 (
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
					raise_and_display_error_0 (
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

	/* TODO - Added lexing of wide characters */
	
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
