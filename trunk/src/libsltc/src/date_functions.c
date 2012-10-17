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
// date_functions.c
//------------------------------------------------------------------------------
// Date functions for the typed component library.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#include "date_functions.h"

//------------------------------------------------------------------------------
// tc_get_datetime function
//
// Returns the current datetime formatted in the format given.
//
char* tc_get_datetime(size_t length, char* format)
{
  char* ts = malloc (sizeof (char[length]));
  time_t t = time (0);
  struct tm* t_s = localtime (&t);

  if (t_s == 0)
    {
      /* No time available */
      ts = "";
    }
  else if (strftime (ts, length, format, t_s) == 0)
    {
      ts = "";
    }

  return ts;
}
//------------------------------------------------------------------------------

//-<EOF>
