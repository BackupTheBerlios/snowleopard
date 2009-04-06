
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
#include <stdio.h>
#include <stdlib.h>

/* Snow Leopard headers */
#include "sl/slci/binary_search.h"
#include "sl/slci/cpp_symtab.h"
#include "sl/slci/error_handling.h"
#include "sl/slci/lexer.h"
#include "sl/slci/lexer_functions.h"
#include "sl/slci/preprocessor.h"
#include "sl/slci/preprocessor_symtab.h"
#include "sl/slci/reader.h"
#include "sl/slci/string.h"
#include "sl/slci/symbol_table.h"
#include "sl/slci/token.h"
#include "sl/slci/types.h"

/*
 * Private function prototypes.
 */
static size_t keyword_position (const slci_string*);
static slci_token lex_character ();
static slci_token lex_comment ();
static slci_token lex_macro ();
static slci_token lex_number ();
static slci_token lex_other ();
static slci_token lex_punctuation ();
static slci_token lex_string ();
static slci_token preprocess_token (slci_string*);
static size_t punctuation_position (const slci_string*);
static slci_token store_identifier (const slci_string*);

/*
 * Global variables.
 */
slci_token current_token;
slci_token previous_token;
slci_source_position* current_source_position;
slci_source_position begin_source_position;

/*
 * initialize_lexer function. Function initializes the lexer by giving it the
 * first filename.
 */
bool
initialize_lexer (char* file)
{
	if (!initialize_reader (file))
		return false;

	if (!initialize_preprocessor ())
	{
		destroy_reader ();
		return false;
	}
	
	return true;
}

/*
 * destroy_lexer function. Function terminates the lexer and cleans up open
 * files and buffers.
 */
void
destroy_lexer ()
{
	destroy_preprocessor ();
	destroy_reader ();
}

/*
 * get_next_token function. Function gets the next token from the stream.
 */
slci_token
get_next_token ()
{
	char c = get_current_char ();
	previous_token = current_token;

	/* Skip over whitespace */
	while (is_whitespace (c))
		c = lex_get_next_char (true, true);
	
	if (c == '\0')
		return empty_token (get_current_source_position ());

	if (c == EOF)
		return eof_token ();

	/* Store the beginning of the source position */
	begin_source_position = get_current_source_position ();

	/* Lex next token */
        if (c >= '0' && c <= '9')
		current_token = lex_number ();
	else if (c == '\'')
		current_token = lex_character ();
	else if (c == '"')
		current_token = lex_string ();
	else if (c == '/')
		current_token = lex_comment ();
	else if (c == '#' && get_previous_char () == '\n')
		current_token = lex_macro ();
	else
		current_token = lex_other ();
	
	return current_token;
}

/*
 * get_prev_token function. Function gets the previous token. This is not
 * relexed, it is just a variable return to the caller.
 */
slci_token
get_prev_token ()
{
	return previous_token;
}

/*
 * put_back_token function. Function puts the current token (the one
 * returned by get_next_token) back so the next call to get_next_token
 * will return the previous token.
 */
bool
put_back_token ()
{
	return false;
}

/*
 * keyword_position function. Function returns position of the keyword. It
 * searches the current token in the keywords array.
 */
size_t
keyword_position (const slci_string* token)
{
	return binary_search (
		keyword_list,
		keyword_list_length,
	        token
		);
}

/*
 * lex_character function. This function lexes a single character literal.
 * We don't need to get the opening single quote, because we already got that.
 */
slci_token
lex_character ()
{
	/* Wide character literal */
	if (get_previous_char () == 'L')
	{
		wchar_t c;
		char d;

		/* Lex character */
		c = lex_wide_character ();
	
		/* Get ending quote */
		d = lex_get_next_char (false, true);

		if (d != '\'')
		{
			/* Skip to end of token and report error */
			skip_to_char ('\'');
			raise_and_display_error_0 (
				ERR_INVALID_WCHARACTER_LITERAL,
				begin_source_position,
				get_c_string (get_current_token_string ())
				);
		}
		
		return wcharacter_token (c, get_current_source_position ());
	}
	else
	{
		char c;
		char d;

		/* Lex character */
		c = lex_narrow_character ();
	
		/* Get ending quote */
		d = lex_get_next_char (false, true);

		if (d != '\'')
		{
			/* Skip to end of token and report error */
			skip_to_char ('\'');
			raise_and_display_error_0 (
				ERR_INVALID_CHARACTER_LITERAL,
				begin_source_position,
				get_c_string (get_current_token_string ())
				);
		}
		
		return character_token (c, get_current_source_position ());
	}
}

/*
 * lex_comment function. This function lexes both single and multi-line
 * comments. 
 */
slci_token
lex_comment ()
{
	char c = lex_get_next_char (false, true);
	bool single_line = c == '/' ? true : false;

	for (;;)
	{
		if (single_line && c == '\n')
			break;
		else if (!single_line && c == '*')
		{
			c = lex_get_next_char (false, true);
			if (c == '/')
				break;
		}

		c = lex_get_next_char (false, true);
	}

	slci_token token = comment_token (
		get_current_token_string (),
		get_current_source_position ()
		);
	
	/* Read the next character */
	c = lex_get_next_char (true, true);
	
	return token;
}

/*
 * lex_macro function. This function lexes a macro.
 */
slci_token
lex_macro ()
{
	char c;
	
	for (;;)
	{
		c = lex_get_next_char (false, true);

		if (c == '\n' && get_previous_char () != '\\')
			break;
	}

	return preprocess_macro_definition (
		get_current_token_string ()
		);
}

/*
 * lex_number function. This function lexes a numeric literal of any of the
 * supported numeric literals.
 */
slci_token
lex_number ()
{

}

/*
 * lex_other function. This function lexes a token that is not a literal or
 * a comment.
 */
slci_token
lex_other ()
{
	if (is_first_char_of_identifier (get_current_char ()))
	{
		size_t pos = 0;
		symtab_key_t macro_pos = 0;
		slci_string lexeme = initialize_string ();
		slci_token token;
		append_string (&lexeme, get_current_char ());

		while (is_other_char_of_identifier (
			    lex_get_next_char (false, true)))
			append_string (&lexeme, get_current_char ());	

		macro_pos = get_macro_position (&lexeme);
		if (macro_pos != MaxSizeT)
			token = preprocess_token (&lexeme);
		else {
			pos = keyword_position (&lexeme);
			if (pos != MaxSizeT)
				token = keyword_token (pos, begin_source_position);
			else
				token = store_identifier (&lexeme);
		}
		
		destroy_string (&lexeme);
		
		return token;
	}
	else
		return lex_punctuation ();
}

/*
 * lex_punctuation function. This function lexes a punctuation literal.
 */
slci_token
lex_punctuation ()
{
	size_t pos = 0;
	slci_string lexeme = initialize_string ();
	slci_token token;

	append_string (&lexeme, get_current_char ());

	while (is_punctuation_char (lex_get_next_char (false, true)))
		append_string (&lexeme, get_current_char ());	

	pos = punctuation_position (&lexeme);
	if (pos != MaxSizeT)
		token = punctuation_token (pos, begin_source_position);
	else
		/* TODO - Report error */ ;
	
	destroy_string (&lexeme);
		
	return token;
}

/*
 * lex_string function. This function lexes a string literal.
 */
slci_token
lex_string ()
{
	/* Wide character string */
	if (get_previous_char () == 'L')
	{
		wchar_t c;
		wchar_t prev_c = '"';
		slci_wstring s = initialize_wstring ();
	
		/* Get second token delimiter */
		c = lex_wide_character ();
		for (;;)
		{
			if (c == '"' && prev_c != '\\')
				break;
			else
				append_wstring (&s, c);
			c = lex_wide_character ();
		}
		
		return wstring_token (&s, get_current_source_position ());
	}
	else
	{
		/* Narrow character string */
		char c;
		char prev_c = '"';
		slci_string s = initialize_string ();
	
		/* Get second token delimiter */
		c = lex_narrow_character ();
		for (;;)
		{
			if (c == '"' && prev_c != '\\')
				break;
			else
				append_string (&s, c);
			c = lex_narrow_character ();
		}
		
		return string_token (&s, get_current_source_position ());
	}
}

/*
 * preprocess_token function. Function preprocesses the preprocessor token
 * given as parameter and returns a string containing the preprocessed token.
 */
slci_token
preprocess_token (slci_string* lexeme)
{
	slci_token token;

	return token;
}

/*
 * punctuation_position function. Function returns position of the punctuation.
 * It searches the current token in the punctuation array.
 */
size_t
punctuation_position (const slci_string* token)
{
	return binary_search (
		punctuation_list,
		punctuation_list_length,
	        token
		);
}

/*
 * store_identifier function. Function stores an identifier in the symbol table.
 */
slci_token
store_identifier (const slci_string* identifier)
{
	symtab_key_t hash_key = generate_cpp_hash_key (get_c_string (identifier));
	
	slci_token token = identifier_token (
		hash_key,
		begin_source_position
		);

	if (set_symtab_entry (
		    &cpp_symtab,
		    get_c_string (identifier),
		    token,
		    begin_source_position))
		/* TODO - Report error */ ;

	return token;
}

/*>- EOF -<*/
