
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
#include "sl/slci/source_position.h"

/*
 * Initial reader stack size.
 */
const size_t InitialStackSize = 10;

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
slci_source_position current_pos;

/*
 * Initialize reader.
 */
bool
initialize_reader (char* file)
{
	/* Initialize file stack */
	file_stack_reserved = InitialStackSize;
	file_stack =
	    malloc (sizeof (slci_source_position* [file_stack_reserved]));
	file_stack_depth = (size_t)-1;

	/* Add first file */
	push_file_stack (initialize_source_position (file, 0, 0));
	
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
 * Returns the next character in the current file.
 */
char
get_next_char ()
{
	if (current_char == EOF)
		return '\0';
	
	slci_source_position* file = top_file_stack ();
	
	if (file == 0)
		return '\0';
	
	current_char = fgetc (file->stream);
	current_pos = copy_source_position (file);

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
 * Returns the last read character again.
 */
char
get_current_char ()
{
	return current_char;
}

/*
 * Returns the last source position.
 */
slci_source_position
get_current_source_position ()
{
	return current_pos;
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
	if (file_stack_depth == 0)
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
	if (file_stack_depth == 0)
		return 0;
	else
		return file_stack[file_stack_depth];
}

/*>- EOF -<*/
