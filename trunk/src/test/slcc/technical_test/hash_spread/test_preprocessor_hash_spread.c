/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version
  
  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
  details.
  
  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>
  ============================================================================*/

//------------------------------------------------------------------------------
// test_preprocessor_hash_spread.c
//------------------------------------------------------------------------------
// This program is for testing the spread of the hashing algorithm used in the
// interpreter. It uses the file preprocessor_identifiers to build up a hash
// table and returns which keys have been generated multiple times.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_function.h"

//------------------------------------------------------------------------------
// main function
//
int main () 
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
  input_file = fopen ("preprocessor_identifiers", "r");

  if (input_file == 0) 
    {
      fprintf (stderr, "File not found\n");
      exit (EXIT_FAILURE);
    }

  /*
   * Loop thru file preprocessor_identifiers and register for each 
   * what it's hash key is
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
//------------------------------------------------------------------------------

//-<EOF>
