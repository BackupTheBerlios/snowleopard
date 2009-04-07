
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
#include <stdlib.h>

/* Snow Leopard headers */
#include "sl/slci/source_file.h"
#include "sl/slci/source_position.h"
#include "sl/slci/source_string.h"

/*
 * NoSourcePosition constant
 */
const slci_source_position NoSourcePosition = {
	ST_SOURCE_FILE,
	{0},
	0,
	0
};

/*
 * Initialize a source position object with a file.
 */
slci_source_position*
initialize_source_position_with_file (
	slci_source_file* file,
	size_t line,
	      size_t position
	)
{
	slci_source_position* pos = malloc (sizeof (slci_source_position));

	pos->source_type = ST_SOURCE_FILE;
	pos->file = file;
	pos->line = line;
	pos->position = position;

	return pos;
}

/*
 * Initialize a source position object with a source string.
 */
slci_source_position*
initialize_source_position_with_string (
	slci_source_string* string,
	size_t line,
	size_t position
	)
{
	slci_source_position* pos = malloc (sizeof (slci_source_position));

	pos->source_type = ST_SOURCE_STRING;
	pos->string = string;
	pos->line = line;
	pos->position = position;

	return pos;
}

/*
 * Destroy a source position object.
 */
void
destroy_source_position (slci_source_position* position)
{
	if (position->source_type == ST_SOURCE_FILE)
		destroy_source_file (position->file);
	else
		destroy_source_string (position->string);

	free (position);
}

/*
 * Copy a source position object.
 */
slci_source_position
copy_source_position (const slci_source_position* pos)
{
	slci_source_position new_pos;

	new_pos.source_type = pos->source_type;

	if (pos->source_type == ST_SOURCE_FILE)
		new_pos.file = pos->file;
	else
		new_pos.string = pos->string;

	new_pos.line = pos->line;
	new_pos.position = pos->position;

	return new_pos;
}

/*>- EOF -<*/
