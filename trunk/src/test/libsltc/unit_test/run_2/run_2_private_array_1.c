/*==============================================================================
  Snow Leopard Typed Component Library
  
  Copyright (C) 2011, 2012 Roel Sergeant
  
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
// run_2_private_array_1.c
//------------------------------------------------------------------------------
// Tests for array component.
//------------------------------------------------------------------------------

#include <stdio.h>

#include "run_2_private_array_1.h"

//------------------------------------------------------------------------------
// Defined linked list types
//
#define TC_ARRAY_TYPE_NAME open_files
#define TC_ARRAY_ELEMENT_TYPE FILE*
#define TC_ARRAY_FUNCTION_SUFFIX of
#define TC_ARRAY_IS_PRIVATE
#define TC_ARRAY_INITIAL_SIZE 512
//------------------------------------------------------------------------------

#include "array.c.h"

//------------------------------------------------------------------------------ 
// tc_array_elements_equal function
//
bool sl_concat_3(tc_array_elements_equal,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_ELEMENT_TYPE n1,
 TC_ARRAY_ELEMENT_TYPE n2
 )
{
  if(n1 == NULL)
    return false;
  if(n1 == n2)
    return true;
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Undefines
//
#undef TC_ARRAY_TYPE_NAME
#undef TC_ARRAY_ELEMENT_TYPE
#undef TC_ARRAY_FUNCTION_SUFFIX
#undef TC_ARRAY_IS_PRIVATE
#undef TC_ARRAY_INITIAL_SIZE
#undef TC_ARRAY_TYPE
//------------------------------------------------------------------------------

//-<EOF>
