/*==============================================================================
  Lynx Typesetting System
  
  Copyright (C) 2010, 2011, 2012 Roel Sergeant
  
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
// Settings for the Lynx typesetting system.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "file_functions.h"
#include "settings.h"
#include "string_array.h"

//------------------------------------------------------------------------------
// Global variables
//
lynx_settings settings_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings_initialize function
//
// Initializes the settings object.
//
bool settings_initialize ()
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings_cleanup function
//
// Cleans up pointers and arrays in the settings object.
//
void settings_cleanup ()
{

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings_add_path function
//
// Adds a path to the array given as parameter.
//
bool settings_add_path (lynx_string_array* array, char* path)
{
  if (!path_exists (path))
    {
      /* TODO: Error reporting */
      return false;
    }

  tc_array_add_l (array, path);
  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
