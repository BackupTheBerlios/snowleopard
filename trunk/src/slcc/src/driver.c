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
// Private functions
//
bool drv_check_arguments (); 
bool drv_process_argument (char* argument, int* position);
bool drv_process_file_argument (char* file);
//------------------------------------------------------------------------------

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
  bool ok = true;
  char* s;
  int i = 0;

  while (i < argc)
    {
      s = argv[i++];
      
      if (s[0] != '-')
	ok = drv_process_file_argument (s);
      else
	ok = drv_process_argument (s, &i);
    }

  ok = drv_check_arguments ();

  return ok;
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

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// drv_check_arguments function
//
// Check the following:
//   - Was a source file provided.
//   - Is the language standard given compatibel with the language provided.
//
bool drv_check_arguments ()
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_argument function
//
// Process the argument given. If the argument is not a single argument, it
// will pick up the next arguments.
//
bool drv_process_argument (char* argument, int* position)
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_file_argument function
//
// Process the file given as parameter. This function checks the following:
//   - Does the file exist.
//   - Is it a recognized extension?
//         c/h                     - C source file
//         cpp/cxx/hpp/hxx/C/H/ipp - C++ source file
//
bool drv_process_file_argument (char* file)
{

  return false;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
