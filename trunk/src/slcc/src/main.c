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

#include "debug.h"
#include "driver.h"
#include "error_handling.h"
#include "info.h"
#include "settings.h"

//------------------------------------------------------------------------------
// main function
//
int main (int argc, char** argv)
{
  int exit_status = EXIT_SUCCESS;

  /* Initialize error handler */
  if (!err_initialize ())
    {
      err_cleanup ();
      return EXIT_FAILURE;
    }

  /* Initialize driver */
  if (!drv_initialize ())
    {
      drv_cleanup ();
      err_cleanup ();
      return EXIT_FAILURE;
    }

  /* 
   * Parsing the command line arguments will not return if an invalid
   * argument is given, as compilation will be aborted.
   */
  drv_parse_command_line (argc, argv);

  __SLCC_DEBUG_PRINT_0(__SLCC_DEBUG_SETTINGS,debug_print_settings);

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
    exit_status = err_get_code_of_first_fatal_error ();

  /* Cleanup error handler */
  err_cleanup ();

  return exit_status;
}
//------------------------------------------------------------------------------

//-<EOF>
