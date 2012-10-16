/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// specifiers.c
//------------------------------------------------------------------------------
// Specifier handling for the compiler front end.
//------------------------------------------------------------------------------

#include "specifiers.h"
#include "types.h"

//------------------------------------------------------------------------------
// Global variables
//
slcc_cv_qualifier initial_cv_qualifier = CVQ_NONE;
slcc_storage_class initial_storage_class = {
  false,
  false,
  false,
  false,
  false
};
symtab_key_t initial_type_key = 0;
//------------------------------------------------------------------------------

//-<EOF>
