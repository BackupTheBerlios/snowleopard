
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
#include "sl/slci/info.h"
#include "sl/slci/version.h"

/*
 * Prints program name and version number.
 */
void
print_program_info ()
{
	char* buffer = malloc (sizeof (char[50]));

	get_version_string (buffer);
	
	printf (
		"%s - Snow Leopard C++ Interpreter - %s\n",
	        getprogname (), buffer
		);
	printf ("Copyright (c) 2009 Roel Sergeant. All rights reserved.\n\n");

	free (buffer);
}

/*
 * Prints program license information.
 */
void
print_license ()
{
	printf (
		"This code is derived from software contributed to the Snow Leopard\n"
		"project.\n\n"
		"Redistribution and use in source and binary forms, with or without\n"
		"modification, are permitted provided that the following conditions\n"
		"are met:\n"
		"1. Redistributions of source code must retain the above copyright\n"
		"   notice, this list of conditions and the following disclaimer.\n"
		"2. Redistributions in binary form must reproduce the above copyright\n"
		"   notice, this list of conditions and the following disclaimer in the\n"
		"   documentation and/or other materials provided with the distribution.\n\n"
		"THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY\n"
		"EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED\n"
		"WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE\n"
		"DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR\n"
		"ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
		"DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR\n"
		"SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER\n"
		"CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,\n"
		"OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
		"OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n");
}

/*
 * Prints program usage information.
 */
void
print_program_usage ()
{
	fprintf (
		stderr,
		"usage: %s [-ivlw] [-Ipaths] [-Spaths] source-file\n",
		getprogname ()
		);
}

/*
 * Prints information on how to contact the developer.
 */
void
print_contact_developer ()
{
	fprintf (
		stderr,
		"Please report the problem encountered to the developers. "
		"For more information, please check the file REPORTING_BUGS "
		"which was included in your distribution.\n"
		);
}

/*
 * Prints program warrantee information.
 */
void
print_warrantee ()
{

}

/*>- EOF -<*/
