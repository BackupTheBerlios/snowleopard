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
// driver.c
//------------------------------------------------------------------------------
// Driver functions for the front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "error_codes.h"
#include "settings.h"

//------------------------------------------------------------------------------
// Global variables
//
slcc_settings settings_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_parse_command_line function
//
// Parses the command line, checks arguments supplied and applies settings to
// the compiler.
//
bool drv_parse_command_line (int argc, char** argv)
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_start function
//
// Starts the compilation process.
//
bool drv_start ()
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_get_first_error function
//
// Get the first error produced.
//
slcc_error_code drv_get_first_error ()
{

  return EC_NO_ERROR;
};
//------------------------------------------------------------------------------

//-<EOF>
