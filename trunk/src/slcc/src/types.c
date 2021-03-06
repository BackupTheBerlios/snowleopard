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
// types.c
//------------------------------------------------------------------------------
// Types and type definitions for the compiler front end.
//------------------------------------------------------------------------------

#include <stddef.h>

#include "types.h"

//------------------------------------------------------------------------------
// Global constants
const size_t MaxErrorMessageSize = 1024;
const size_t MaxLineSize = 256;
const size_t MaxSizeT = (size_t)-1;
const symtab_key_t MaxSymtabKeyT = (size_t)-1;
//------------------------------------------------------------------------------

//-<EOF>
