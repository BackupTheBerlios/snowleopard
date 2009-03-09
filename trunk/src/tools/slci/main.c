
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
#include "sl/slci/driver.h"
#include "sl/slci/error_handling.h"
#include "sl/slci/info.h"

/*
 * This program is a C++ interpreter, mainly used for bootstrapping the Snow
 * Leopard C++ compiler. Initially it will only implement the C++ subset
 * needed to interpret the compiler source code, including the standard
 * C++ library.
 */
int
main (int argc, char** argv)
{
	print_program_info ();

	initialize_driver ();
	
	if (!parse_command_line (argc, argv))
	{
		/*
		 * An incorrect parameter was specified.
		 */
		print_program_usage ();
		return get_first_fatal_error ();
	}

	if (settings->license == true)
		/* Print license info. */
		print_license ();
	else if (settings->warrantee == true)
		/* Print warrantee info. */
		print_warrantee ();
	else if (start ())
	{
		/*
		 * When start_program returns, the program has finished. All that
		 * remains is returning it's return value to the shell.
		 */
		return get_return_value ();
	}
	else
	{
		/*
		 * A fatal error occured. Print contact information.
		 */
		print_contact_developer ();
		return get_first_fatal_error ();
	}

	return (EXIT_SUCCESS);
}

/*>- EOF -<*/
