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
// binary_search.c
//------------------------------------------------------------------------------
// Binary search for the compiler front end.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <string.h>

#include "binary_search.h"
#include "strings.h"
#include "types.h"

//------------------------------------------------------------------------------
// binary_search function
//
// This function performs a binary search for the string search_key in the array
// given as parameter.
//
size_t binary_search (char** array, size_t size, const slcc_string* search_key) 
{
  size_t low = 0;
  size_t high = size;
  size_t mid;
  
  while (low < high) 
    {
      int r;
      mid = low + ((high - low) / 2);

      r = strcmp (array[mid], search_key->value);
      if (r == 0)
	return mid;
      else if (r < 0)
	low = mid + 1;
      else
	high = mid;
    }

  if ((low < size) && (strcmp (array[low], search_key->value) == 0))
    return low;
  else
    return MaxSizeT;
}
//------------------------------------------------------------------------------

//-<EOF>
