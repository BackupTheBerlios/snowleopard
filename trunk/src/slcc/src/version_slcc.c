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
// version_slcc.c
//------------------------------------------------------------------------------
// Version information for the compiler front end.
//------------------------------------------------------------------------------

#include "config_slcc.h"

#include <stdio.h>

#include "version.h"

//------------------------------------------------------------------------------
// Include global version numbers
#include sl_include_config(version.c.h)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Build number.
const unsigned int Build = 1;
//------------------------------------------------------------------------------

//-<EOF>
