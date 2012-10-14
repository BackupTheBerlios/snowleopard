/*==============================================================================
  Lynx Typesetting System
  
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
// lsoelim_driver.c
//------------------------------------------------------------------------------
// Driver functions for the lsoelim.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <string.h>

#include "driver.h"
#include "settings.h"
#include "string_array.h"

//------------------------------------------------------------------------------
// Private functions
//
bool drv_process_include_path (char* path, bool attached);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_initialize_tool_specific_settings function
//
// This function initializes the tool specific settings.
//
bool drv_initialize_tool_specific_settings ()
{
  lynx_string_array* array = tc_array_new_l ();

  settings_.tool_specific.lsoelim.include_paths 
    = array;

  if (array == NULL)
    {
      /* <TODO: Error reporting */
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_cleanup_tool_specific_settings function
//
// Clean up tool specific settings.
//
void drv_cleanup_tool_specific_settings ()
{
  if (settings_.tool_specific.lsoelim.include_paths != NULL)
    tc_array_delete_l (settings_.tool_specific.lsoelim.include_paths);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_parse_tool_specific_argument function
//
// Parses tool specific arguments. Returns false if this function didn't pick 
// the argument.
//
bool drv_parse_tool_specific_argument (int* i, char** argv)
{
  /* Argument -I<path> */
  if (argv[*i][1] == 'I')
    return drv_process_include_path (argv[*i], true);

  /* Argument --include_path <path> */
  else if (strcmp (argv[*i], "--include_path") == 0)
    {
      (*i)++;
      return drv_process_include_path (argv[*i], false);
    }

  else
    return false;
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// drv_process_include_path function
//
// Process an include path parameter and stores the value.
//
bool drv_process_include_path (char* path, bool attached)
{
  if (attached)
    if (&path == '\0')
      return false;
    else
      return settings_add_path (
				settings_.tool_specific.lsoelim.include_paths, 
				path
				);

  else
    return settings_add_path (
			      settings_.tool_specific.lsoelim.include_paths, 
			      path+2
			      );

  return false;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
