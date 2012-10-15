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
// copy_string function
//
// Creates and returns the copy of the string given.
//
char* tc_copy_string (char* str)
{
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
char* tc_get_str_after_nth_last (char* str, char delim, int count)
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

//-<EOF>
