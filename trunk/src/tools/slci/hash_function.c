
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

/* Snow Leopard headers */
#include "sl/slci/hash_function.h"

/*
 * Private function prototypes.
 */
static size_t get_char_hash_value (char);

/*
 * MaxHashTableEntries constant. Contains the maxinum number of entries allowed in
 * the hash table.
 */
const size_t MaxHashTableEntries = 128000;

/*
 * This function generates a hash key based on the string given as input value.
 *
 * Hashing is done as follows:
 *    1) For each character a number between 0 and 64 is generated (there are 63
 *       valid characters for C++ identifiers, a space = 0 and : = 1).
 *    2) This value for each character is multiplied by the position in the string.
 *    3) The obtained values are summed. If this sum overflows we ignore it.
 *    4) The remainder of the sum divided by MaxHashTableEntries is the hash_key.
 */
size_t
generate_hash_key (const char* key_value)
{
	size_t key = 0;
	size_t pos = 0;
	
	while (*key_value != '\0')
	{
		pos++;
		key += get_char_hash_value (*key_value) * pos;	
		key_value++;
	}

	return key % MaxHashTableEntries;
}

/*
 * This function calculates the character value to hash. Allowed characters are:
 *   a-z   = 45 + c - 'a'
 *   A-Z   = 19 + c - 'A'
 *   0-9   = 9  + c - '0'
 *   _     = 1
 *   :     = 2
 *   <     = 3
 *   >     = 4
 *   (     = 5
 *   )     = 6
 *   ,     = 7
 *   space = 0
 */
size_t
get_char_hash_value (char c)
{
	if (c == '_')
		return 1;
	else if (c == ':')
		return 2;
	else if (c == ',')
		return 7;
	else if (c >= '0' && c <= '9')
		return 9 + c - '0';
	else if (c >= 'a' && c <= 'z')
		return 41 + c - 'a';
	else if (c >= 'A' && c <= 'Z')
		return 15 + c - 'A';
	else if (c == '<')
		return 3;
	else if (c == '>')
		return 4;
	else if (c == '(')
		return 5;
	else if (c == ')')
		return 6;
	else if (c == ' ')
		return 0;
	else
		return MaxHashTableEntries;
}

/*>- EOF -<*/
