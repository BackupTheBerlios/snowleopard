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
// driver.h
//------------------------------------------------------------------------------
// Driver for the front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_DRIVER_H__
#define __SL_SLCC_DRIVER_H__

#include <stdbool.h>

#include "error_codes.h"

//------------------------------------------------------------------------------
// Driver functions.
bool drv_cleanup ();
bool drv_start ();
bool drv_parse_command_line (int argc, char** argv);
slcc_error_code drv_get_first_error ();
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_DRIVER_H__ */

//-<EOF>
