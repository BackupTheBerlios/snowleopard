/*==============================================================================
  Snow Leopard Typed Component Library
  
  Copyright (C) 2012 Roel Sergeant
  
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
// string_functions.c
//------------------------------------------------------------------------------
// String functions for the typed component library.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "string_functions.h"

//------------------------------------------------------------------------------
// tc_append_string function
//
// Appends the second string to the first string, returning a new string as
// result. If it fails it returns NULL.
//
char* tc_append_string (const char* str1, const char* str2)
{
  char* n_str = malloc(sizeof (char) * (strlen(str1) + strlen(str2) + 1));

  if (n_str == NULL)
    return NULL;

  strcpy (n_str, str1);
  strcat (n_str, str2);

  return n_str;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_copy_string function
//
// Creates and returns the copy of the string given.
//
char* tc_copy_string (const char* str)
{
  if (str == NULL)
    return NULL;

  char* n_str = malloc (strlen (str) + 1);

  strcpy (n_str, str);

  return n_str;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_get_str_after_nth_last function
//
// Returns the string after the last count occurrence of the delim character.
// If no count last is found, NULL is returned.
//
char* tc_get_str_after_nth_last (const char* str, const char delim, int count)
{
  size_t i = strlen (str);

  /* Search position of the count-last occurence of delim. */
  while (true)
    {
      /* Lower count if delim is found. */
      if (str[i] == delim)
	count--;

      /* The target delim is found. */
      if (count == 0)
	break;

      /* The end of the string is reached. */
      if (i == 0)
	return NULL;

      i--;
    }

  /* Return copy of string excluding the first delim */
  return tc_copy_string (str+i+1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_replace_in_string function
//
// Function replaces to_replace with replacement at all occurences in the 
// string and returns a new string containing these replacements. It returns
// NULL if it fails.
//
char* tc_replace_in_string (
			    const char* str1,
			    const char* to_replace,
			    const char* replacement
			    )
{
  char* ptr =  strstr (str1, to_replace);
  const char* o_str = str1;
  char* n_str = (char*)str1;

  while (ptr != NULL)
    {
      n_str = malloc (sizeof (char) * (strlen (o_str) 
				       - strlen (to_replace)
				       + strlen (replacement)
				       + 1)
		      );

      /* Copy by part */
      strncpy (n_str, o_str, ptr - o_str);
      strcpy (n_str + (ptr - o_str), replacement);
      strcpy (
	      n_str + (ptr - o_str + strlen (replacement)), 
	      ptr + strlen (to_replace)
	      );

      /* Do new search */
      ptr = strstr (n_str, to_replace);
      if (ptr != NULL)
	{
	  if (o_str != str1)
	    free ((char*) o_str);
	  o_str = n_str;
	}
    }

  return n_str;
}
//------------------------------------------------------------------------------

//-<EOF>
