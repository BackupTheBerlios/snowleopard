
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
	
	if (ed->nbr_of_arguments == 0)
		fprintf (
			stderr,
			"%s: %s\n",
			error_type_list[ed->type],
			ed->description
			);
	else
		;
}

/*
 * raise_error function. Raise and store an error.
 */
slci_error*
raise_error (slci_error_code code, slci_source_position position, char* s)
{
	slci_error* error = malloc (sizeof (slci_error));

	error->code = code;
	error->position = position;
	error->token = s;

	return error;
}

/*
 * raise_and_display_error function. Raise and store an error and afterwards format and display it.
 */
void
raise_and_display_error (slci_error_code code, slci_source_position position, char* s)
{
	display_error (
		raise_error (code, position, s)
		);
}

/*
 * raise_and_display_program_error function. Raise, store and display a program error.
 */
void
raise_and_display_program_error (slci_error_code code, char* s)
{
	display_error (
		raise_error (code, NoSourcePosition, s)
		);
}

/*
 * get_first_error_of_type function. Returns the first error encountered of the given type.
 */
slci_error_code
get_first_error_of_type (slci_error_type type)
{
	return ERR_NO_ERROR;
}

/*>- EOF -<*/
