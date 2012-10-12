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
// run_1_private_linked_list_1.c
//------------------------------------------------------------------------------
// Tests for linked list component.
//------------------------------------------------------------------------------

#include <stdio.h>

#include "run_1_private_linked_list_1.h"

//------------------------------------------------------------------------------
// Defined linked list types
//
#define TC_LL_TYPE open_files
#define TC_LL_NODE_TYPE FILE*
#define TC_LL_FUNCTION_SUFFIX of
#define TC_LL_IS_PRIVATE
//------------------------------------------------------------------------------

#include "linked_list.c.h"

//------------------------------------------------------------------------------ 
// tc_ll_nodes_equal function
//
bool sl_concat_3(tc_ll_nodes_equal,_,TC_LL_FUNCTION_SUFFIX) (
                                                             TC_LL_NODE_TYPE n1,
                                                             TC_LL_NODE_TYPE n2
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
#undef TC_LL_TYPE
#undef TC_LL_NODE_TYPE
#undef TC_LL_FUNCTION_SUFFIX
#undef TC_LL_IS_PRIVATE
#undef TC_LL_HEAD
#undef TC_LL_NODE
//------------------------------------------------------------------------------

//-<EOF>
