
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
#include <stddef.h>
#include <stdlib.h>

/* Snow Leopard headers */
#include "sl/slci/source_string.h"

/*
 * initialize_source_string function. This function initializes a source_string object.
 */
slci_source_string*
initialize_source_string (char* original_source, char* preprocessed_source)
{
	slci_source_string* new_string = malloc (sizeof (slci_source_string));

	new_string->original_source = original_source;
	new_string->preprocessed_source = preprocessed_source;
	new_string->current_pos = 0;
	
	return new_string;
}

/*
 * destroy_source_string function. This function destroys a source_string object.
 */
void
destroy_source_string (slci_source_string* string)
{
	free (string->original_source);
	free (string->preprocessed_source);

	free (string);
}

/*
 * copy_source_string function. This function copies a source_string object.
 */
slci_source_string
copy_source_string (const slci_source_string* string)
{
	slci_source_string new_string;

	new_string.original_source = string->original_source;
	new_string.preprocessed_source = string->preprocessed_source;

	return new_string;
}

/*>- EOF -<*/
