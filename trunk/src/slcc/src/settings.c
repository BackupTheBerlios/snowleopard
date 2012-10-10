/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
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
// settings.c
//------------------------------------------------------------------------------
// Settings for the front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

#include "settings.h"

//------------------------------------------------------------------------------
// add_include_path function
//
// Add an include path to the list of paths to search. Priority is given as 
// follows (paths are build up in this order):
//   1) Path given at command line.
//   2) Path given in environment variable SLC_INCLUDE_PATH.
//   3) Path given in configuration file.
//   4) System/Compiler defined path.
//
bool add_include_path (char* path)
{

  return false;
}
//------------------------------------------------------------------------------

//-<EOF>
