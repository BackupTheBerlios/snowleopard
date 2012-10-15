/*==============================================================================
  Snow Leopard C Source Component Library
  
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
// error_array.h
//------------------------------------------------------------------------------
// Error array for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_ERROR_ARRAY_H__
#define __SL_SLCC_ERROR_ARRAY_H__

#include "error.h"

//------------------------------------------------------------------------------
// Define array structure
//
#define TC_ARRAY_TYPE_NAME slcc_error_array
#define TC_ARRAY_ELEMENT_TYPE slcc_error*
#define TC_ARRAY_FUNCTION_SUFFIX ea
#define TC_ARRAY_INITIAL_SIZE 256
#define TC_ARRAY_NO_FIND
//------------------------------------------------------------------------------

#include "array.h"

//------------------------------------------------------------------------------
// Undef array structure
//
#undef TC_ARRAY_TYPE_NAME
#undef TC_ARRAY_ELEMENT_TYPE
#undef TC_ARRAY_FUNCTION_SUFFIX
#undef TC_ARRAY_INITIAL_SIZE
#undef TC_ARRAY_NO_FIND
#undef TC_ARRAY_TYPE
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_ERROR_ARRAY_H__ */

//-<EOF>
