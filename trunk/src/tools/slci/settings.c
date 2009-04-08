
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
#include <stdlib.h>
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/settings.h"

/*
 * Private function prototypes.
 */
static size_t add_path (char***, size_t, const char*);

/*
 * Global variables.
 */
slci_settings* settings;

/*
 * Initialize a settings object.
 */
slci_settings*
initialize_settings ()
{
	char* current_include = "./";
	char* current_source = "./";

	settings = malloc (sizeof (slci_settings));

	settings->interactive = false;
	settings->license = false;
	settings->make_rules_only = false;
	settings->preprocess_only = false;
	settings->verbose = false;
	settings->warrantee = false;

	settings->source_file = 0;
	settings->source_paths = malloc (sizeof (char* [1]));
	settings->source_paths[0] = current_source;
	settings->size_source_paths = 1;
	settings->include_paths = malloc (sizeof (char* [1]));
	settings->include_paths[0] = current_include;
	settings->size_include_paths = 1;

	return settings;
}

/*
 * Destroy a setting object.
 */
void
destroy_settings ()
{
	size_t i;

	if (settings == 0)
		/* There is nothing to do */
		return;

	/* Free memory for source_file */
	if (settings->source_file != 0)
		free (settings->source_file);

	/* Free source_paths */
	if (settings->size_source_paths > 1)
	{
		for (i = settings->size_source_paths; i != 1; --i)
			free (settings->source_paths[i - 1]);
		free (settings->source_paths);
	}

	/* Free include_paths */
	if (settings->size_include_paths > 1)
	{
		for (i = settings->size_include_paths; i != 1; --i)
			free (settings->include_paths[i - 1]);
		free (settings->include_paths);
	}

	/* Free object */
	free (settings);
}

/*
 * Add a new include path to the settings object.
 */
void
add_include_path (const char* path)
{
	settings->size_include_paths =
	    add_path (
		    &settings->include_paths,
		    settings->size_include_paths,
		    path);
}

/*
 * Add a new source path to the settings object.
 */
void
add_source_path (const char* path)
{
	settings->size_source_paths =
	    add_path (
		    &settings->source_paths,
		    settings->size_source_paths,
		    path);
}

/*
 * Add path to array and returns the new size of the array.
 */
size_t
add_path (char*** array, const size_t size, const char* path)
{
	size_t i;
	size_t path_size = strlen(path);

	/* Copy new path (add ending / if neccessary) */
	char* new_path = malloc (path_size + 1);
	strcpy (new_path, path);
	if (new_path[path_size - 1] != '/')
	{
		new_path[path_size] = '/';
		new_path[path_size + 1] = '\0';
	}

	/* Copy old array */
	char** old = *array;

	/* Create new array */
	char** new = malloc (sizeof (char* [size + 1]));
	for (i = 0; i != size; ++i)
		new[i] = (*array)[i];

	/* Add new path */
	new[size] = new_path;
	i = size + 1;

	/* Set new array */
	*array = new;

	/* Delete old array */
	free (old);

	return i;
}

/*>- EOF -<*/
