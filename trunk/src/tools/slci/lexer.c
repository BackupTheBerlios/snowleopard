
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
#include "sl/slci/error_handling.h"
#include "sl/slci/lexer.h"
#include "sl/slci/lexer_functions.h"
#include "sl/slci/preprocessor.h"
#include "sl/slci/reader.h"
#include "sl/slci/string.h"
#include "sl/slci/symbol_table.h"
#include "sl/slci/token.h"

/*
 * Private function prototypes.
 */
static slci_token lex_character ();
static slci_token lex_comment ();
static slci_token lex_number ();
static slci_token lex_other ();
static slci_token lex_reserved ();
static slci_token lex_string ();
static size_t keyword_position ();
static size_t punctuation_position ();
static char* preprocess_token ();

/*
 * Global variables.
 */
slci_token current_token;
slci_token previous_token;
slci_source_position* current_source_position;
slci_source_position begin_source_position;

/*
 * Function initializes the lexer by giving it the first filename.
 */
bool
initialize_lexer (char* file)
{
	if (!initialize_reader (file))
		return false;

	return true;
}

/*
 * Function terminates the lexer and cleans up open files and buffers.
 */
void
destroy_lexer ()
{
	destroy_reader ();
}

/*
 * Function gets the next token from the stream.
 */
slci_token
get_next_token ()
{
	char c;
	previous_token = current_token;

	/* Skip over whitespace */
	while (is_whitespace (c = get_next_char ()))
	{ }
	
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
	else
		current_token = lex_other ();
	
	return current_token;
}

/*
 * Function gets the previous token. This is not relexed, it is just a variable
 * return to the caller.
 */
slci_token
get_prev_token ()
{
	return previous_token;
}

/*
 * Function puts the current token (the one returned by get_next_token) back so
 * the next call to get_next_token will return the previous token.
 */
bool
put_back_token ()
{
	return false;
}

/*
 * Lex a character. This function lexes a single character literal. We don't
 * need to get the opening single quote, because we already got that.
 */
slci_token
lex_character ()
{
	char c;
	char d;

        /* Lex character */
	c = lex_single_character ();
	
	/* Get ending quote */
	d = get_next_char ();

	if (d != '\'')
		/* TODO - Report invalid character literal */ ;

	return character_token (c, get_current_source_position ());
}

/*
 * Lex a comment. This function lexes both single and multi-line comments. 
 */
slci_token
lex_comment ()
{
	
}

/*
 * Lex a number. This function lexes a numeric literal of any of the
 * supported numeric literals.
 */
slci_token
lex_number ()
{

}

/*
 * Lex another token. This function lexes a token that is not a literal or a
 * comment.
 */
slci_token
lex_other ()
{

}

/*
 * Lex a reserved token. It searches the list of keywords and punctuations and
 * if no match is found it searches the symbol table. If still no match, this
 * is a new identifier that needs to be entered in the symbol table.
 */
slci_token
lex_reserved ()
{

}

/*
 * Lex a string. This function lexes a string literal.
 */
slci_token
lex_string ()
{
	bool done = false;
	char c;
	char prev_c = '"';
	slci_string s = initialize_string ();
	
	/* Get second token delimiter */
	c = lex_single_character ();
	while (!done)
	{
		if (c == '"' && prev_c != '\\')
			done = true;
		else
			append_string (s, c);
		c = lex_single_character ();
	}

	return string_token (s, get_current_source_position ());
}

/*
 * Function returns position of the keyword. It searches the current token in
 * the keywords array.
 */
size_t
keyword_position ()
{

}

/*
 * Function returns position of the punctuation. It searches the current token
 * in the punctuation array.
 */
size_t
punctuation_position ()
{

}

/*
 * Function preprocesses the preprocessor token given as parameter and returns a
 * string containing the preprocessed token.
 */
char*
preprocess_token (slci_token token)
{

}

/*>- EOF -<*/
