
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
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/cpp_symtab.h"
#include "sl/slci/driver.h"
#include "sl/slci/error_handling.h"
#include "sl/slci/parser.h"
#include "sl/slci/settings.h"
#include "sl/slci/misc.h"

/*
 * Private global variables.
 */
bool parser_is_initialized;

/*
 * Initialize driver.
 */
bool
initialize_driver ()
{
	parser_is_initialized = false;

	return true;
}

/*
 * Destroy driver object.
 */
void
destroy_driver ()
{
	destroy_settings ();
	destroy_cpp_symtab ();
	if (parser_is_initialized)
		destroy_parser ();
}

/*
 * parse_command_line function. Function parses the command-line arguments
 * provided by the user.
 */
bool
parse_command_line (int argc, char** argv)
{
	bool ok = true;
	int i;
	slci_settings* settings = initialize_settings ();
	
	if (argc == 1)
	{
		/* At least one parameter is required. */
		raise_and_display_program_error_0 (
			ERR_NO_SOURCE_FILE
			);
		return false;
	}
	
	for (i = 1; i != argc; ++i)
	{
		if (strcmp (argv[i], "-i") == 0)
			/* Interactive [-i] */
			settings->interactive = true;
		else if (strcmp (argv[i], "-l") == 0)
			/* License [-l] */
			settings->license = true;
		else if (strcmp (argv[i], "-M") == 0)
			/* Produce make rules [-M] */
			settings->make_rules_only = true;
		else if (strcmp (argv[i], "-P") == 0)
			/* Preprocess only [-P] */
			settings->preprocess_only = true;
		else if (strcmp (argv[i], "-v") == 0)
			/* Verbose [-v] */
			settings->verbose = true;
		else if (strcmp (argv[i], "-w") == 0)
			/* Warrantee [-w] */
			settings->warrantee = true;
		else
		{
			/* Path variables */
			char* paths = argv[i];

			if (paths[0] == '-')
			{
				if (paths[1] == 'I')
				{
					/* Source paths [-Ipaths] */
					add_include_path (argv[i] + 2);
				}
				else if (paths[1] == 'S')
				{
					/* Source paths [-Spaths] */
					add_source_path (argv[i] + 2);
				}
				else
				{
					/* Invalid option */
					raise_and_display_program_error_1 (
						ERR_INVALID_ARGUMENT,
						argv[i]
						);
					ok = false;
				}
			}
			else
				/* Source file */
				settings->source_file = copy_string (argv[i]);
		}
	}

	if (ok && settings->source_file == 0)
	{
		/* At least one parameter is required. */
		raise_and_display_program_error_0 (
			ERR_NO_SOURCE_FILE
			);
		return false;
	}
	
	return ok;
}

/*
 * Starts the interpretion process and returns true is finished. It returns false
 * when a fatal error is encountered.
 */
bool
start ()
{
	if (!parser_is_initialized)
	{
		if (initialize_parser (settings->source_file))
		{
			parser_is_initialized = true;

			if (!initialize_cpp_symtab ())
			{
				/* TODO - Display error */
				destroy_parser ();
				return false;
			}
		}
		else
		{
			/* TODO - Display error */
			return false;
		}
	}

	if (!parse ())
	{
		/* TODO - Display error */ ;
		return false;
	}
	
	return true;
}

/*
 * This function returns the return value of the interpreted program, if there is
 * none zero is returned.
 */
int
get_return_value ()
{
	return 0;
}

/*>- EOF -<*/
