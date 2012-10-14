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

//------------------------------------------------------------------------------
// drv_initialize function
//
// Initializes the driver.
//
bool drv_initialize ()
{
  return settings_initialize ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_cleanup function
//
// Cleans up after the elimination process has finished.
//
void drv_cleanup ()
{
  settings_cleanup ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_start function
// 
// Start the process.
//
bool drv_start ()
{
  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// parse_command_line function
//
// Parses the command line arguments and stores the settings.
//
bool drv_parse_command_line (int argc, char** argv) 
{
  for(int i = 1; i < argc; i++)
    {
      /* Argument --copyright */
      if (strcmp (argv[i], "--copyright") == 0)
	settings_.copyright_only = true;

      /* 
       * Argument --help
       *          -h
       *	  --usage
       */
      else if (strcmp (argv[i], "--help") == 0 
	  || strcmp (argv[i], "-h") == 0 
	  || strcmp (argv[i], "--usage") == 0)
	settings_.usage_only = true;

      /*
       * Argument -q 
       *          --quiet
       */
      else if (strcmp (argv[i], "-q") == 0
	       || strcmp (argv[i], "--quiet") == 0)
	settings_.quiet = true;

      /*
       * Argument -v
       *          --verbose
       */
      else if (strcmp (argv[i], "-v") == 0
	       || strcmp (argv[i], "--verbose") == 0)
	settings_.verbose = true;

      /* Argument --version */
      else if (strcmp (argv[i], "--version") == 0)
	settings_.version_only = true;

      /* Argument --warrantee */
      else if (strcmp (argv[i], "--warrantee") == 0)
	settings_.warrantee_only = true;

      /* Tool specific arguments */
      else if (drv_parse_tool_specific_argument (&i, argv))
	/* Argument parsed */ ;

      /* Argument not valid */
      else
	return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
