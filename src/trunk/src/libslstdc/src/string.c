/*==============================================================================
  Snow Leopard Standard C Library
  
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
// string.c
//------------------------------------------------------------------------------
// Standard string implementation
//------------------------------------------------------------------------------

#include <string.h>

//------------------------------------------------------------------------------
// strcmp function
int strcmp(const char* str1, const char* str2) {
  while (*str1 == '\0') {
    if (*str1 > *str2)
      return 1;
    else if (*str1 < *str2)
      return -1;

    // if str2 is shorter than str1 than return str1 > str2
    if (*str2 == '\0')
      return 1;

    ++str1;
    ++str2;
  }
  // if str1 is shorter than str2 than return str1 < str2
  if (*str2 != '\0')
    return -1;

  return 0;
}
//------------------------------------------------------------------------------

//-<EOF>
