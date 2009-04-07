
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
#include "sl/slci/reader.h"
#include "sl/slci/source_file.h"
#include "sl/slci/source_position.h"
#include "sl/slci/source_string.h"

/*
 * Initial reader stack size.
 */
const size_t InitialStackSize = 10;
const size_t InitialStackDepth = (size_t)-1;

/*
 * Private function prototypes.
 */
static void push_file_stack (slci_source_position*);
static slci_source_position* pop_file_stack ();
static slci_source_position* top_file_stack ();

/*
 * Private global variables.
 */
slci_source_position** file_stack;
size_t file_stack_reserved;
size_t file_stack_depth;

int current_char;
int previous_char;
slci_source_position current_position;

/*
 * Initialize reader with file.
 */
bool
initialize_reader_with_file (char* file)
{
	/* Initialize file stack */
	file_stack_reserved = InitialStackSize;
	file_stack =
	    malloc (sizeof (slci_source_position* [file_stack_reserved]));
	file_stack_depth = InitialStackDepth;

	/* Add first file */
	push_file_stack (
		initialize_source_position_with_file (
			initialize_source_file (file),
			0,
			0
			)
		);

	/* Set previous character */
	current_char = 0;

	return true;
}

/*
 * Initialize reader with file.
 */
bool
initialize_reader_with_string (char* original_source, char* preprocessed_source)
{
	/* Initialize file stack */
	file_stack_reserved = InitialStackSize;
	file_stack =
	    malloc (sizeof (slci_source_position* [file_stack_reserved]));
	file_stack_depth = InitialStackDepth;

	/* Add first file */
	push_file_stack (
		initialize_source_position_with_string (
			initialize_source_string (original_source, preprocessed_source),
			0,
			0
			)
		);

	/* Set previous character */
	current_char = 0;

	return true;
}

/*
 * Destroy reader.
 */
void
destroy_reader ()
{
	size_t i;

	for (i = file_stack_depth; i != 0; --i)
	{
		destroy_source_position (file_stack[i - 1]);
		file_stack[i - 1] = 0;
	}
	free (file_stack);
}

/*
 * get_next_char function. Returns the next character in the current file.
 */
char
get_next_char ()
{
	previous_char = current_char;

	if (current_char == EOF)
		return EOF;

	slci_source_position* file = top_file_stack ();

	if (file == 0)
		return EOF;

	if (file->source_type == ST_SOURCE_FILE)
		current_char = fgetc (file->file->stream);
	else
		current_char = file->string->preprocessed_source[file->string->current_pos++];

	current_position = copy_source_position (file);

	if (current_char != '\n')
		file->position++;
	else
	{
		file->line++;
		file->position = 0;
	}

	return current_char;
}

/*
 * get_current_char function. Returns the last read character again.
 */
char
get_current_char ()
{
	return current_char;
}

/*
 * get_previous_char function. Returns the previously read character.
 */
char
get_previous_char ()
{
	return previous_char;
}

/*
 * get_current_source_file function. Returns the currently read file.
 */
slci_source_file*
get_current_source_file ()
{
	return current_position.file;
}

/*
 * get_current_source_position function. Returns the currently read source position.
 */
slci_source_position
get_current_source_position ()
{
	return current_position;
}

/*
 * get_current_source_string function. Returns the currently read string.
 */
slci_source_string*
get_current_source_string ()
{
	return current_position.string;
}

/*
 * Puts the character back into the input stream.
 */
bool
put_back_char (char c)
{
	return false;
}

/*
 * Push new element on file stack.
 */
void
push_file_stack (slci_source_position* file)
{
	size_t i;

	if (file_stack_depth == (size_t)-1)
		file_stack_depth = 0;
	else
		file_stack_depth++;

	if (file_stack_depth >= file_stack_reserved)
	{
		/* Expand stack */
		file_stack_reserved += 10;
		slci_source_position** old = file_stack;
		file_stack =
		    malloc (sizeof (slci_source_position* [file_stack_reserved]));

		for (i = 0; i != file_stack_depth - 1; ++i)
			file_stack[i] = old[i];

		free (old);
	}
	file_stack[file_stack_depth] = file;
}

/*
 * Pop file from file stack.
 */
slci_source_position*
pop_file_stack ()
{
	if (file_stack_depth == InitialStackDepth)
		return 0;

	slci_source_position* file = file_stack[file_stack_depth];
	file_stack[file_stack_depth] = 0;
	file_stack_depth--;

	return file;
}

/*
 * Return current file from file stack.
 */
slci_source_position*
top_file_stack ()
{
	if (file_stack_depth == InitialStackDepth)
		return 0;
	else
		return file_stack[file_stack_depth];
}

/*>- EOF -<*/
