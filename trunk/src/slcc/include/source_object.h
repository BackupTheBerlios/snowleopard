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
// source_object.h
//------------------------------------------------------------------------------
// Source object for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SOURCE_OBJECT_H__
#define __SL_SLCC_SOURCE_OBJECT_H__

#include <types.h>

//------------------------------------------------------------------------------
// slcc_source_oject struct
//
// Stores one source object and all it's dependents.
//
struct slcc_source_object
{
  symtab_key_t key;
};

typedef struct slcc_source_object slcc_source_object;
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SOURCE_OBJECT_H__ */

//-<EOF>
