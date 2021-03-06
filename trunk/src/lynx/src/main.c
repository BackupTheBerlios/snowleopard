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
// lynx_main.c
//------------------------------------------------------------------------------
// main function of the lynx program of the Lynx typesetting system.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "driver.h"
#include "info.h"

//------------------------------------------------------------------------------
// main function
//
// This program is the main driver for the Lynx typesetting system. This program
// first checks the input files and parameters and call the appropriate programs
// to typeset a TROFF document.
//
int main (int argc, char** argv)
{
  if (!drv_initialize ())
    return EXIT_FAILURE;

  if (!drv_parse_command_line (argc, argv))
    {
      drv_cleanup ();
      return EXIT_FAILURE;
    }

  inf_display_program_info ();
  
  if (!drv_start ())
    return EXIT_FAILURE;

  drv_cleanup ();

  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//-<EOF>
