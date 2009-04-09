
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
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/error_codes.h"
#include "sl/slci/error_handling.h"
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
 * Private functions.
 */
static bool check_condition (const slci_string*);
static bool check_preprocessor_command (const slci_string*, const char*);
static char* get_define (const slci_string*);
static bool process_define (const slci_string*);
static bool process_error (const slci_string*);
static bool process_include (const slci_string*);
static bool process_if (const slci_string*);
static bool process_pragma (const slci_string*);
static bool process_undef (const slci_string*);
static bool process_warning (const slci_string*);
static slci_string* skip_to_elif_endif ();
static slci_string* skip_to_endif ();
static slci_string* skip_to_else_elif_endif ();

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
 * check_preprocessor_command function. Check if the input string is the
 * preprocessor command given.
 */
bool
check_preprocessor_command (const slci_string* s, const char* command)
{
	size_t i;
	size_t offset;
	size_t size = s->size;

	/* Start over # and whitespace */
	for (i = 0; i != size; ++i)
		if (get_char_from_string (s, i) != '#'
		    && !is_whitespace (get_char_from_string (s, i)))
			break;

	offset = i;
	size = strlen (command);
	for (i = 0; i != size; ++i)
		if (get_char_from_string (s, i + offset) != command[i])
			return false;

	return true;
}

/*
 * get_define function. Get definition used in #IFNDEF or #IFDEF.
 */
char*
get_define (const slci_string* s)
{

	return 0;
}

/*
 * preprocess_macro_definition function. Processes a macro definition.
 */
slci_token
preprocess_macro_definition (const slci_string* s)
{
	bool ok = false;
	size_t pos = first_none_whitespace (s, 1);
	char c = get_char_from_string (s, pos);

	switch (c)
	{
	case 'd':
		ok = process_define (s);
		break;

	case 'e':
		ok = process_error (s);
		break;

	case 'i':
		if (get_char_from_string(s, pos + 1) == 'f')
			ok = process_if (s);
		else
			ok = process_include (s);
		break;

	case 'p':
		ok = process_pragma (s);
		break;

	case 'u':
		ok = process_undef (s);
		break;

	case 'w':
		ok = process_warning (s);
		break;

	default:
		last_error = ERR_INVALID_PREPROCESSOR_LINE;
		break;

	}

	if (!ok)
		/* TODO - Report last error */ ;

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
	if (!check_preprocessor_command (s, "include"))
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
	if (check_preprocessor_command (s, "ifndef")
	    || check_preprocessor_command (s, "if ! defined")
	    || (skipping_code && check_preprocessor_command (s, "elif ! defined")))
	{
		if (is_in_symtab (&preprocessor_symtab, get_define (s)))
			skip_to_else_elif_endif ();
		else
		    skipping_code = false;
	}
	else if (check_preprocessor_command (s, "ifndef")
	         || check_preprocessor_command (s, "if ! defined")
	         || (skipping_code && check_preprocessor_command (s, "elif ! defined")))
	{
		if (!is_in_symtab (&preprocessor_symtab, get_define (s)))
			skip_to_else_elif_endif ();
		else
			skipping_code = false;
	}
	else if (check_preprocessor_command (s, "if")
	         || (skipping_code && check_preprocessor_command (s, "elif")))
	{
		if (check_condition (s))
			skip_to_else_elif_endif ();
		else
			skipping_code = false;
	}
	else if (check_preprocessor_command (s, "else"))
	{
		if (skipping_code)
			skipping_code = false;
		else
			skip_to_endif ();
	}
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
 * skip_to_elif_endif function. Skip to next #ELIF or #ENDIF token at same nesting level.
 */
slci_string*
skip_to_elif_endif ()
{
	skipping_code = true;
}

/*
 * skip_to_endif function. Skip to next #ENDIF token at same nesting level.
 */
slci_string*
skip_to_endif ()
{
	skipping_code = true;
}

/*
 * skip_to_else_elif_endif function. Skip to next #ELSE, #ELIF and #ENDIF token at same nesting level.
 */
slci_string*
skip_to_else_elif_endif ()
{
	skipping_code = true;
}

/*>- EOF -<*/
