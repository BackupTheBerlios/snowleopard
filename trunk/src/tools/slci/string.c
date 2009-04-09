
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
#include <string.h>
#include <wchar.h>

/* Snow Leopard headers */
#include "sl/slci/misc.h"
#include "sl/slci/string.h"
#include "sl/slci/types.h"

/*
 * Private variables
 */
const size_t InitialStringSize = 256;

/*
 * initialize_string function. Initialize a new string object.
 */
slci_string
initialize_string ()
{
	slci_string s;

	s.size = 0;
	s.reserved = InitialStringSize;

	s.value = malloc (sizeof (char[InitialStringSize]));
	s.value[0] = '\0';

	return s;
}

/*
 * initialize_string_with_data function. Initialize a string object
 * with data.
 */
slci_string
initialize_string_with_data (const char* data)
{
	size_t i;
	slci_string string  = initialize_string ();

	for (i = 0; data[i] != '\0'; ++i)
		append_string (&string, data[i]);

	return string;

}

/*
 * initialize_wstring function. Initialize a new wstring object.
 */
slci_wstring
initialize_wstring ()
{
	slci_wstring s;

	s.size = 0;
	s.reserved = InitialStringSize;

	s.value = malloc (sizeof (wchar_t[InitialStringSize]));
	s.value[0] = '\0';

	return s;
}

/*
 * destroy_string function. Destroy string object.
 */
void
destroy_string (slci_string* s)
{
	free (s->value);
}

/*
 * destroy_wstring function. Destroy wstring object.
 */
void
destroy_wstring (slci_wstring* s)
{
	free (s->value);
}

/*
 * first_none_whitespace function. Returns position of the first none whitespace
 * character after the given position.
 */
size_t
first_none_whitespace (const slci_string* s, size_t after_pos)
{
	for (/* No initializer needed */ ; after_pos != s->size; ++after_pos)
		if (!is_whitespace (s->value[after_pos]))
			return after_pos;

	return MaxSizeT;
}

/*
 * append_string function. Append character to the string.
 */
bool
append_string (slci_string* s, char c)
{
	/* Check if string needs to be extended */
	if ((s->size + 1) > s->reserved)
	{
		char* old = s->value;
		s->reserved += InitialStringSize;
		s->value = malloc (sizeof (char[s->reserved]));
		if (s->value != 0)
		{
			if (old != 0)
				strcpy (s->value, old);
			else
				s->value[0] = '\0';

			free (old);
		}
		else
			s->value[0] = '\0';
	}

	s->value[s->size] = c;
	s->value[++s->size] = '\0';

	return true;
}

/*
 * append_wstring function. Append wchar_t to the wstring.
 */
bool
append_wstring (slci_wstring* s, wchar_t c)
{
	/* Check if wstring needs to be extended */
	if ((s->size + 1) > s->reserved)
	{
		wchar_t* old = s->value;
		s->reserved += InitialStringSize;
		s->value = malloc (sizeof (wchar_t[s->reserved]));
		if (s->value != 0)
		{
			if (old != 0)
				wcscpy (s->value, old);
			else
				s->value[0] = '\0';

			free (old);
		}
		else
			s->value[0] = '\0';
	}

	s->value[s->size] = c;
	s->value[++s->size] = '\0';

	return true;
}

/*
 * get_char_from_string function. Get the character at position from the string.
 */
char
get_char_from_string (const slci_string* s, size_t pos)
{
	if (pos > s->size)
		return '\0';

	return s->value[pos];
}

/*
 * get_c_string function. Returns a copy of the string as C string.
 */
char*
get_c_string (const slci_string* s)
{
	char* cstr = malloc (sizeof (char[s->size + 1]));

	strcpy (cstr, s->value);

	return cstr;
}

/*
 * get_c_string_between function. Returns a copy of the part of the string
 * between the two delimiters as C string.
 */
char*
get_c_string_between (const slci_string* s, char d_begin, char d_end)
{
	size_t bpos;
	size_t epos;

	for (bpos = epos = 0; epos != s->size; ++epos)
	{
		if (bpos == 0 && s->value[epos] == d_begin)
			bpos = epos + 1;
		else if (bpos != 0 && s->value[epos] == d_end)
		{
			break;
		}
	}

	if (bpos == 0 || epos == s->size)
		return 0;
	
	char* cstr = malloc (sizeof (char[epos - bpos + 1]));

	strncpy (cstr, s->value + bpos, epos - bpos);
	cstr[epos - bpos] = '\0';
	    
	return cstr;
}

/*
 * get_wc_string function. Returns a copy of the wstring as wide character string.
 */
wchar_t*
get_wc_string (const slci_wstring* s)
{
	wchar_t* wcstr = malloc (sizeof (wchar_t[s->size + 1]));

	wcscpy (wcstr, s->value);

	return wcstr;
}

/*
 * reset_string function. Reset the string to an empty string.
 */
bool
reset_string (slci_string* s)
{
	if (s->size != 0)
	{
		s->value[0] = '\0';
		s->size = 0;
	}

	return true;
}

/*
 * reset_wstring function. Reset the wstring to an empty wstring.
 */
bool
reset_wstring (slci_wstring* s)
{
	if (s->size != 0)
	{
		s->value[0] = '\0';
		s->size = 0;
	}

	return true;
}

/*>- EOF -<*/
