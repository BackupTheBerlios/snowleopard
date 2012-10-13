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
// main.c
//------------------------------------------------------------------------------
// Main routine for the front end.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "driver.h"
#include "info.h"
#include "settings.h"

//------------------------------------------------------------------------------
// main function
//
int main (int argc, char** argv)
{
  int exit_status = EXIT_SUCCESS;

  if (!drv_initialize ())
    {
      drv_cleanup ();
      return EXIT_FAILURE;
    }

  /* 
   * Parsing the command line arguments will not return if an invalid
   * argument is given, as compilation will be aborted.
   */
  drv_parse_command_line (argc, argv);

  inf_display_program_info ();

  /* Information only */
  if (settings_.copyright_only)
    exit_status = EXIT_FAILURE;
  else if (settings_.usage_only)
    {
      inf_display_usage ();
      exit_status = EXIT_FAILURE;
    }
  else if (settings_.warrantee_only)
    {
      inf_display_warrantee ();
      exit_status = EXIT_FAILURE;
    }

  /* Start compilation */
  else if (drv_start ())
    {
      /* Cleanup after compilation */
      drv_cleanup ();
    }
  else 
    exit_status = EXIT_FAILURE;

  return exit_status;
}
//------------------------------------------------------------------------------

//-<EOF>
