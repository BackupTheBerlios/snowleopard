
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
#include <stdio.h>
#include <stdlib.h>

/* Snow Leopard headers */
#include "sl/slci/error_codes.h"
#include "sl/slci/error_handling.h"
#include "sl/slci/misc.h"

/*
 * Private functions.
 */
slci_error_code get_first_error_of_type (slci_error_type);

/*
 * Return the error code for the first error. If there are none, 0 is returned.
 */
slci_error_code
get_first_error ()
{
	slci_error_code c = get_first_error_of_type (ET_COMPILE);

	if (c == 0)
		c = get_first_error_of_type (ET_RUNTIME);

	return c;
}

/*
 * Return the error code for the first fatal error encountered. It return 0 if
 * no fatal errors where encountered.
 */
slci_error_code
get_first_fatal_error ()
{
	return get_first_error_of_type (ET_FATAL);
}

/*
 * display_error function. Format and print the error.
 */
void
display_error (slci_error* error)
{
	slci_error_description* ed = &error_description_list[error->code];
	
	if (ed->nr_of_arguments == 0)
		fprintf (
			stderr,
			"%s: %s\n",
			error_type_list[ed->type],
			ed->description
			);
	
	else if (ed->nr_of_arguments == 1)
		fprintf (
			stderr,
			"%s: %s\n",
			error_type_list[ed->type],
			create_string_from_format_1 (
				ed->description,
				error->param1
				)
			);
	
	else
		;
}

/*
 * raise_error function. Raise and store an error.
 */
slci_error*
raise_error (
	slci_error_code code,
	slci_source_position position,
	char* token,
	char* param1,
	char* param2,
	char* param3,
	char* param4
	)
{
	slci_error* error = malloc (sizeof (slci_error));

	error->code = code;
	error->position = position;
	error->token = token;
	error->param1 = param1;
	error->param2 = param2;
	error->param3 = param3;
	error->param4 = param4;
	
	return error;
}

/*
 * raise_and_display_error function. Raise and store an error and afterwards
 * format and display it.
 */
void
raise_and_display_error_0 (
	slci_error_code code,
	slci_source_position position,
	char* token
	)
{
	display_error (
		raise_error (code, position, token, 0, 0, 0, 0)
		);
}

/*
 * raise_and_display_program_error function. Raise, store and display a program
 * error.
 */
void
raise_and_display_program_error_0 (slci_error_code code)
{
	display_error (
		raise_error (code, NoSourcePosition, 0, 0, 0, 0, 0)
		);
}

/*
 * raise_and_display_program_error_1 function. Raise, store and display a
 * program error.
 */
void
raise_and_display_program_error_1 (slci_error_code code, char* param1)
{
	display_error (
		raise_error (code, NoSourcePosition, 0, param1, 0, 0, 0)
		);
}

/*
 * get_first_error_of_type function. Returns the first error encountered of the
 * given type.
 */
slci_error_code
get_first_error_of_type (slci_error_type type)
{
	return ERR_NO_ERROR;
}

/*>- EOF -<*/
