
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

/* Snow Leopard headers */
#include "sl/slci/error_codes.h"
#include "sl/slci/error_handling.h"
#include "sl/slci/preprocessor_symtab.h"
#include "sl/slci/preprocessor.h"
#include "sl/slci/reader.h"
#include "sl/slci/string.h"
#include "sl/slci/token.h"

/*
 * Private global variables
 */
size_t current_depth;
slci_error_code last_error;

/*
 * Private functions.
 */
static bool process_define (const slci_string*);
static bool process_error (const slci_string*);
static bool process_include (const slci_string*);
static bool process_if (const slci_string*);
static bool process_pragma (const slci_string*);
static bool process_undef (const slci_string*);
static bool process_warning (const slci_string*);

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
bool process_error (const slci_string* s)
{
	return false;
}

/*
 * process_include function. Processes an #include preprocessor line.
 */
bool process_include (const slci_string* s)
{
	return false;
}

/*
 * process_if function. Processes an #if preprocessor line.
 */
bool process_if (const slci_string* s)
{
	return false;
}

/*
 * process_pragma function. Processes an #pragma preprocessor line.
 */
bool process_pragma (const slci_string* s)
{
	return false;
}

/*
 * process_undef function. Processes an #undef preprocessor line.
 */
bool process_undef (const slci_string* s)
{
	return false;
}

/*
 * process_warning function. Processes an #warning preprocessor line.
 */
bool process_warning (const slci_string* s)
{
	return false;
}

/*>- EOF -<*/
