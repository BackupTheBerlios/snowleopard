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
// file_functions.c
//------------------------------------------------------------------------------
// File functions for the typed component library.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>

#include "file_functions.h"

//------------------------------------------------------------------------------
// tc_file_exists function
//
// Check if the file exists, it is a file and it is readable.
//
bool tc_file_exists (char* filename)
{
  struct stat buffer;

  /* File does not exist */
  if (stat (filename, &buffer) == -1)
    return false;

  /* File is not a file */
  if (!S_ISREG (buffer.st_mode))
    return false;

  /* File is readable */
  FILE* file = fopen (filename, "r");
  if (file == NULL)
    return false;
  else 
    fclose (file);

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_path_exists function
//
// Check if the path exists and that it is a path.
//
bool tc_path_exists (char* path)
{
  struct stat buffer;

  /* Path does not exist */
  if (stat (path, &buffer) == -1)
    return false;

  /* Path is not a directory */
  if (!S_ISDIR (buffer.st_mode))
    return false;

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
