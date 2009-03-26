
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
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/hash_function.h"

/*
 * This program tests the hash-spread of a hashing algorithm for valid C++
 * identifiers.
 */
int
main ()
{
	/* Initialize array to keep results */
	bool next = true;
	char* key_value = malloc (sizeof (char[MaxPreHashTableEntries]));
	FILE* input_file;
	size_t i;
	size_t* array = malloc (sizeof (size_t[MaxPreHashTableEntries]));

	printf ("==> Initialize array\n");
	for (i = 0; i != MaxPreHashTableEntries; ++i)
		array[i] = 0;

	/* Open file */
	input_file = fopen ("pre_identifiers.txt", "r");

	if (input_file == 0)
	{
		fprintf (stderr, "File not found\n");
		exit (EXIT_FAILURE);
	}
	
	/*
	 * Loop thru file identifiers.txt and register for each what it's hash
	 * key is
	 */
	
	/* Read identifier */
	fgets (key_value, MaxPreHashTableEntries, input_file);
	key_value[strlen (key_value) - 1] = '\0';
	
	if (feof (input_file))
		next = false;
	
	while (next)
	{
		printf (
			"%d is key for %s\n",
			generate_pre_hash_key (key_value),
			key_value
			);
		
		/* Generate hash_key and add to table */
		array[generate_pre_hash_key (key_value)]++;

		/* Read identifier */
		fgets (key_value, MaxPreHashTableEntries, input_file);
		key_value[strlen (key_value) - 1] = '\0';

		if (feof (input_file))
			next = false;

	}

	/* Loop thru array and print hit count if <> 0 */
	for (i = 0; i != MaxPreHashTableEntries; ++i)
		if (array[i] > 1)
			printf ("%d appears %d times\n", i, array[i]);

	free (array);
	free (key_value);
	fclose (input_file);
	
	return EXIT_SUCCESS;
}

/*>- EOF -<*/
