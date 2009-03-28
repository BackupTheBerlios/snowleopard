
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
 * MaxCppHashTableEntries constant. Contains the maxinum number of entries allowed
 * in the C++ hash table.
 */
const size_t MaxCppHashTableEntries = 128000;

/*
 * MaxPreHashTableEntries constant. Contains the maxinum number of entries allowed
 * in the Preprocessor hash table.
 */
const size_t MaxPreHashTableEntries = 32000;

/*
 * generate_cpp_hash_key function. Generates a hash key for a C++ identifier.
 */
size_t
generate_cpp_hash_key (const char* key_value)
{
	return generate_hash_key (
		&get_cpp_char_hash_value,
		MaxCppHashTableEntries,
		key_value
		);
}

/*
 * generate_pre_hash_key function. Generates a hash key for a preprocessor
 * macro.
 */
size_t
generate_pre_hash_key (const char* key_value)
{
	return generate_hash_key (
		&get_pre_char_hash_value,
		MaxCppHashTableEntries,
		key_value
		);
}

/*
 * generate_hash_key function. This function generates a hash key based on the string
 * and the configuration parameters given.
 *
 * Hashing is done as follows:
 *    1) For each character a number is generated using the supplied function pointer.
 *    2) This value for each character is multiplied by the position in the string.
 *    3) The obtained values are summed. If this sum overflows we ignore it.
 *    4) The remainder of the sum divided by the hash_table_size parameter is the
 *       hash_key.
 */
size_t
generate_hash_key (
	hash_function_ptr hash_function,
	size_t hash_table_size,
	const char* key_value
	)
{
	size_t key = 0;
	size_t pos = 0;

	while (*key_value != '\0')
	{
		pos++;
		key += hash_function (*key_value) * pos;
		key_value++;
	}

	return key % hash_table_size;
}

/*
 * This function calculates the character value for a valid C++ character to hash.
 * Allowed characters are:
 *   space = 0
 *   @     = 1
 *   (     = 2
 *   #     = 3
 *   <     = 4
 *   >     = 5
 *   0-9   = 8  + c - '0'
 *   a-z   = 20 + c - 'a'
 *   A-Z   = 50 + c - 'A'
 *   _     = 83
 */
size_t
get_cpp_char_hash_value (char c)
{
	if (c == ' ')
		return 0;
	else if (c == '@')
		return 1;
	else if (c == '(')
		return 2;
	else if (c == '#')
		return 3;
	else if (c == '<')
		return 4;
	else if (c == '>')
		return 5;
	else if (c >= '0' && c <= '9')
		return 8 + c - '0';
	else if (c >= 'A' && c <= 'Z')
		return 20 + c - 'A';
	else if (c >= 'a' && c <= 'z')
		return 50 + c - 'a';
	else if (c == '_')
		return 83;
	else
		return MaxCppHashTableEntries;
}

/*
 * This function calculates the character value for a valid C++ character to hash.
 * Allowed characters are:
 *   space = 0
 *   0-9   = 1  + c - '0'
 *   a-z   = 15 + c - 'a'
 *   A-Z   = 45 + c - 'A'
 *   _     = 83
 */
size_t
get_pre_char_hash_value (char c)
{
	if (c == ' ')
		return 0;
	else if (c >= '0' && c <= '9')
		return 1 + c - '0';
	else if (c >= 'A' && c <= 'Z')
		return 15 + c - 'A';
	else if (c >= 'a' && c <= 'z')
		return 45 + c - 'a';
	else if (c == '_')
		return 83;
	else
		return MaxPreHashTableEntries;
}

/*>- EOF -<*/
