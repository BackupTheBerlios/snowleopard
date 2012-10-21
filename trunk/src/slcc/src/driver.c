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

#include "codegen.h"
#include "driver.h"
#include "error.h"
#include "error_codes.h"
#include "error_handling.h"
#include "parser.h"
#include "settings.h"

//------------------------------------------------------------------------------
// drv_initialize function
//
// Initialize all components before the compilation starts.
//
bool drv_initialize ()
{
  if (!parser_initialize ())
    {
      err_report_0 (EC_PARSER_INITIALIZATION_FAILED);
      return false;
    }

  if (!codegen_initialize ())
    {
      err_report_0 (EC_CODEGEN_INITIALIZATION_FAILED);
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_cleanup function
//
// Cleans up all components when the compilation process has finished.
//
void drv_cleanup ()
{
  settings_delete ();
  parser_cleanup ();
  codegen_cleanup ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_start function
//
// Starts the compilation process.
//
bool drv_start ()
{
  if (!parser_start ())
    return false;

  if (!codegen_start ())
      return false;

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
