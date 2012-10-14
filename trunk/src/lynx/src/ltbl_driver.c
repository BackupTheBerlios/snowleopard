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
// ltbl_driver.c
//------------------------------------------------------------------------------
// Driver functions for the Lynx typesetting system.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <string.h>

#include "driver.h"
#include "settings.h"

//------------------------------------------------------------------------------
// drv_initialize_tool_specific_settings function
//
// This function initializes the tool specific settings.
//
bool drv_initialize_tool_specific_settings ()
{
  settings_.tool_specific.ltbl.compatibility_mode = false;

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

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_parse_tool_specific_argument function
//
// Parses the command line arguments and stores the settings.
//
bool drv_parse_tool_specific_argument (int* i, char** argv) 
{
  /* Argument -I<path> */
  if (argv[*i][1] == 'I')
    return settings_.tool_specific.ltbl.compatibility_mode = true;

  /* Argument --include_path <path> */
  else if (strcmp (argv[*i], "--compatibility_mode") == 0)
    return settings_.tool_specific.ltbl.compatibility_mode = true;

  else
    return false;
}
//------------------------------------------------------------------------------

//-<EOF>
