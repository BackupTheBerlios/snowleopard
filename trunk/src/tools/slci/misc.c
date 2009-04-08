
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
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/misc.h"

/*
 * copy_string function. This function copies a C string.
 */
char*
copy_string (char* str)
{
	char* new_str = malloc (strlen (str) + 1);

	strcpy (new_str, str);

	return new_str;
}

/*
 * create_string_3 function. Creates a string from the 3 given strings.
 */
char*
create_string_3 (const char* first, const char* second, const char* third)
{
	char* buffer = malloc (sizeof (char[
			strlen (first) + strlen (second) + strlen (third) + 3
			]));

	sprintf (buffer, "%s %s %s", first, second, third);

	return buffer;
}

/*
 * create_string_from_format_1 function. Create a string from a format with 1
 * parameter.
 */
char*
create_string_from_format_1 (const char* fmt, const char* param1)
{
	char* buffer = malloc (sizeof (char[
			strlen (fmt) + strlen (param1) + 1
			]));

	sprintf (buffer, fmt, param1);

	return buffer;
}

/*
 * file_exists function. Check if a file exists.
 */
bool
file_exists(const char * file)
{
	FILE* f;

	if (f = fopen(file, "r"))
	{
		fclose(f);
		return true;
	}

	return false;
}

/*
 * get_hex_value function. If character is a hexadecimal return it, otherwise
 * return -1.
 */
int
get_hex_value (char c)
{
	switch (c)
	{
	case '0':
		return 0;
		break;

	case '1':
		return 1;
		break;

	case '2':
		return 2;
		break;

	case '3':
		return 3;
		break;

	case '4':
		return 4;
		break;

	case '5':
		return 5;
		break;

	case '6':
		return 6;
		break;

	case '7':
		return 7;
		break;

	case '8':
		return 8;
		break;

	case '9':
		return 9;
		break;

	case 'A':
	case 'a':
		return 10;
		break;

	case 'B':
	case 'b':
		return 11;
		break;

	case 'C':
	case 'c':
		return 12;
		break;

	case 'D':
	case 'd':
		return 13;
		break;

	case 'E':
	case 'e':
		return 14;
		break;

	case 'F':
	case 'f':
		return 15;
		break;

	default:
		return -1;
		break;
	}
}

/*
 * get_oct_value function. If character is a octal return it, otherwise
 * return -1.
 */
int
get_oct_value (char c)
{
	switch (c)
	{
	case '0':
		return 0;
		break;

	case '1':
		return 1;
		break;

	case '2':
		return 2;
		break;

	case '3':
		return 3;
		break;

	case '4':
		return 4;
		break;

	case '5':
		return 5;
		break;

	case '6':
		return 6;
		break;

	case '7':
		return 7;
		break;

	default:
		return -1;
		break;
	}
}

/*
 * is_hexadecimal function. If character is a hexadecimal return true.
 */
bool
is_hexadecimal (char c)
{
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
		return true;
		break;

	default:
		return false;
		break;
	}
}

/*
 * is_whitespace function. If character is whitespace return true.
 */
bool
is_whitespace (char c)
{
	switch (c)
	{
	case ' ':
	case '\0':
	case '\n':
	case '\r':
	case '\t':
		return true;
		break;

	default:
		return false;
		break;
	}
}

/*>- EOF -<*/
