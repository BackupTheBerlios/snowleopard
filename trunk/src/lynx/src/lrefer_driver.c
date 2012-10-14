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
// lrefer_driver.c
//------------------------------------------------------------------------------
// Driver functions for the Lynx typesetting system.
//------------------------------------------------------------------------------

#include <string.h>

#include "driver.h"

//------------------------------------------------------------------------------
// parse_command_line function
//
// Parses the command line arguments and stores the settings.
//
bool drv_parse_command_line (int argc, char** argv) 
{
  for(int i = 1; i < argc; i++)
    {
      if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
	{
	  /* Display help */
	}
    }

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
