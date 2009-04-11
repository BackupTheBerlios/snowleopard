
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
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/error_codes.h"
#include "sl/slci/error_handling.h"
#include "sl/slci/lexer.h"
#include "sl/slci/misc.h"
#include "sl/slci/preprocessor_symtab.h"
#include "sl/slci/preprocessor.h"
#include "sl/slci/reader.h"
#include "sl/slci/string.h"
#include "sl/slci/token.h"

/*
 * Private global variables
 */
bool skipping_code;
size_t current_nesting;
slci_error_code last_error;

/*
 * Preprocessor command strings.
 */
const char* MacroDEFINED = "defined";
const char* MacroELIF = "elif";
const char* MacroELIFDEFINED = "elifdefined";
const char* MacroELIFNOTDEFINED = "elif!defined";
const char* MacroELSE = "else";
const char* MacroENDIF = "endif";
const char* MacroERROR = "error";
const char* MacroIF = "if";
const char* MacroIFDEF = "ifdef";
const char* MacroIFDEFINED = "ifdefined";
const char* MacroIFNDEF = "ifndef";
const char* MacroIFNOTDEFINED = "if!defined";
const char* MacroINCLUDE = "include";
const char* MacroPRAGMA = "pragma";
const char* MacroUNDEF = "undef";
const char* MacroWARNING = "warning";

/*
 * Private functions.
 */
static bool check_condition (const slci_string*);
static bool check_preprocessor_command (const char*, const char*);
static bool check_preprocessor_command_in_string (const slci_string*, const char*);
static char* get_define (const slci_string*);
static bool process_define (const slci_string*);
static bool process_endif (const slci_string*);
static bool process_error (const slci_string*);
static bool process_include (const slci_string*);
static bool process_if (const slci_string*);
static bool process_pragma (const slci_string*);
static bool process_undef (const slci_string*);
static bool process_warning (const slci_string*);
static void skip_to_endif ();
static void skip_to_else_elif_endif ();

/*
 * initialize_preprocessor function. Initializes the preprocessor.
 */
bool
initialize_preprocessor ()
{
	if (!initialize_preprocessor_symtab ())
	{
		/* TODO - Display error */
		return false;
	}

	skipping_code = false;
	current_nesting = 0;

	return true;
}

/*
 * destroy_preprocessor function. Destroys the preprocessor.
 */
void
destroy_preprocessor ()
{
	destroy_preprocessor_symtab ();
}

/*
 * check_condition function. Checks the condition in an #IF or #ELIF
 * statement.
 */
bool
check_condition (const slci_string* s)
{

	return false;
}

/*
 * check_preprocessor_command function. Checks if the input string is the
 * preprocessor command given.
 */
bool
check_preprocessor_command (const char* s, const char* command)
{
	size_t i;
	size_t j;
	size_t offset;
	size_t size = strlen (s);

	/* Start over # and whitespace */
	for (i = 0; i != size; ++i)
		if (s[i] != '#'
		    && !is_whitespace (s[i]))
			break;

	offset = i;
	size = strlen (command);
	for (i = j = 0; i != size; ++i, ++j)
	{
		char c = s[i + offset];

		/* If c is whitespace, skip */
		if (c != '\n' && is_whitespace (c))
			i++;
		/* Does c match character in valid command */
		else if (c != command[j])
			return false;
	}

	return true;
}

/*
 * check_preprocessor_comamnd_in_string function. Check if the input string is the
 * preprocessor command given.
 */
bool
check_preprocessor_command_in_string (const slci_string* s, const char* command)
{
	char* string = get_c_string (s);
	bool r = check_preprocessor_command (string, command);

	free (string);
	return r;
}

/*
 * get_define function. Get definition used in #IFNDEF or #IFDEF. This is the last
 * word in the token string.
 */
char*
get_define (const slci_string* s)
{
	return get_last_word_in_string (s);
}

/*
 * preprocess_macro_definition function. Processes a macro definition.
 */
slci_token
preprocess_macro_definition (const slci_string* s)
{
	/* If in skip mode, do not process tokens */
	if (!skipping_code)
	{
		bool ok = false;
		size_t pos = first_none_whitespace (s, 1);
		char c = get_char_from_string (s, pos);

		switch (c)
		{
		case 'd': /* #define */
			ok = process_define (s);
			break;

		case 'e': /* #endif or #error */
			if (get_char_from_string (s, pos + 1) == 'n')
				ok = process_endif (s);
			else
				ok = process_error (s);
			break;

		case 'i': /* #if (and variants) or #include */
			if (get_char_from_string (s, pos + 1) == 'f')
				ok = process_if (s);
			else
				ok = process_include (s);
			break;

		case 'p': /* #pragma */
			ok = process_pragma (s);
			break;

		case 'u': /* #undef */
			ok = process_undef (s);
			break;

		case 'w': /* #warning */
			ok = process_warning (s);
			break;

		default:
			last_error = ERR_INVALID_PREPROCESSOR_LINE;
			break;

		}

		if (!ok)
			/* TODO - Report last error */ ;

	}

	return preprocessor_token (
		s,
		get_current_source_position ()
		);
}

/*
 * process_define function. Processes a #define preprocessor line.
 */
bool
process_define (const slci_string* s)
{
	return false;
}

/*
 * process_endif function. Processes an #endif preprocessor line.
 */
bool
process_endif (const slci_string* s)
{
	/* Is this an #endif line */
	if (!check_preprocessor_command_in_string (s, MacroENDIF))
		return false;

	return true;
}

/*
 * process_error function. Processes an #error preprocessor line.
 */
bool
process_error (const slci_string* s)
{
	return false;
}

/*
 * process_include function. Processes an #include preprocessor line.
 */
bool
process_include (const slci_string* s)
{
	char* file;

	/* Is this an #include line */
	if (!check_preprocessor_command_in_string (s, MacroINCLUDE))
		return false;

	/* Get file name */
	if ((file = get_c_string_between (s, '\"', '\"')) == 0)
		if ((file = get_c_string_between (s, '<', '>')) == 0)
			return false;

	/* Get full path to file */
	file = get_full_path_for_file (file);
	if (file == 0)
		return false;

	/* Set file to be read for next token */
	if (!set_nested_file (file))
		return false;

	return true;
}

/*
 * process_if function. Processes an #if preprocessor line.
 */
bool
process_if (const slci_string* s)
{
	/* Handle #ifndef, #if !defined, #elif !defined macros */
	if (check_preprocessor_command_in_string (s, MacroIFNDEF)
	    || check_preprocessor_command_in_string (s, MacroIFNOTDEFINED)
	    || (skipping_code
		&& check_preprocessor_command_in_string (s, MacroELIFNOTDEFINED)))
	{
		if (is_in_symtab (&preprocessor_symtab, get_define (s)))
			skip_to_else_elif_endif ();
	}
	/* Handle #ifdef, #if defined, #elif defined macros */
	else if (check_preprocessor_command_in_string (s, MacroIFDEF)
	    || check_preprocessor_command_in_string (s, MacroIFDEFINED)
	    || (skipping_code
		&& check_preprocessor_command_in_string (s, MacroELIFDEFINED)))
	{
		if (!is_in_symtab (&preprocessor_symtab, get_define (s)))
			skip_to_else_elif_endif ();
	}
	/* Handle #if <condition>, #elif <condition> macros */
	else if (check_preprocessor_command_in_string (s, MacroIF)
	    || (skipping_code
		&& check_preprocessor_command_in_string (s, MacroELIF)))
	{
		if (check_condition (s))
			skip_to_else_elif_endif ();
	}
	/* Handle #else macros */
	else if (check_preprocessor_command_in_string (s, MacroELSE))
	{
		skip_to_endif ();
	}
	/* Invalid #if variant */
	else
		return false;

	return true;
}

/*
 * process_pragma function. Processes an #pragma preprocessor line.
 */
bool
process_pragma (const slci_string* s)
{
	return false;
}

/*
 * process_undef function. Processes an #undef preprocessor line.
 */
bool
process_undef (const slci_string* s)
{
	return false;
}

/*
 * process_warning function. Processes an #warning preprocessor line.
 */
bool
process_warning (const slci_string* s)
{
	return false;
}

/*
 * skip_to_endif function. Skip to next #ENDIF token at same nesting level.
 */
void
skip_to_endif ()
{
	slci_string s;
	slci_token token;

	skipping_code = true;

	for (;;)
	{
		token = get_next_token (true);
		
		if (token.type == TT_PREPROCESSOR)
		{
			if (check_preprocessor_command (
				    token.preprocessor,
				    MacroIF
				    )
				)
			        current_nesting++;
			else if (check_preprocessor_command (
				    token.preprocessor,
				    MacroENDIF
				    )
				)
			{
				if (current_nesting == 0)
					break;
				else
					current_nesting--;
			}
		}
	}

	/* Process the encountered preprocessor token */
	skipping_code = false;
	s = initialize_string_with_data (token.preprocessor);
	preprocess_macro_definition (&s);
	destroy_token (&token);

}

/*
 * skip_to_else_elif_endif function. Skip to next #ELSE, #ELIF and #ENDIF token at
 * same nesting level.
 */
void
skip_to_else_elif_endif ()
{
	slci_string s;
	slci_token token;

	skipping_code = true;

	for (;;)
	{
		token = get_next_token (true);

		if (token.type == TT_PREPROCESSOR)
		{
			if (check_preprocessor_command (
				    token.preprocessor,
				    MacroIF
				    )
				)
			        current_nesting++;
			else if (check_preprocessor_command (
				    token.preprocessor,
				    MacroELIF
				    )
			    && current_nesting == 0)
			        break;
			else if (check_preprocessor_command (
				    token.preprocessor,
				    MacroELSE
				    )
			    && current_nesting == 0)
			        break;
			else if (check_preprocessor_command (
				    token.preprocessor,
				    MacroENDIF
				    )
				)
			{
				if (current_nesting == 0)
					break;
				else
					current_nesting--;
			}
		}
	}

	/* Process the encountered preprocessor token */
	skipping_code = false;
	s = initialize_string_with_data (token.preprocessor);
	preprocess_macro_definition (&s);
	destroy_token (&token);
}

/*>- EOF -<*/
