/*==============================================================================
  Snow Leopard Standard C Library
  
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
// ll_open_files.c
//------------------------------------------------------------------------------
// Private linked list for storing open files.
//------------------------------------------------------------------------------

#include <sl/config/config.h>

#include <sl/stdc/private/ll_open_files.h>

#include <sl/stdc/stdio_types.h>

//------------------------------------------------------------------------------
// Define open files linked list
#define SL_LL_TYPE sl_ll_of
#define SL_LL_NODE_TYPE FILE*
#define SL_LL_FUNCTION_SUFFIX of
#define SL_LL_IS_PRIVATE

#include <sl/stdc/private/linked_list.c.h>

//------------------------------------------------------------------------------
// sl_ll_nodes_equal function
bool sl_concat_3(sl_ll_nodes_equal,_,SL_LL_FUNCTION_SUFFIX) (
							     SL_LL_NODE_TYPE n1, 
							     SL_LL_NODE_TYPE n2
							     ) 
{
  if(n1 == NULL)
    return false;
  if(n1 == n2)
    return true;
  return false;
}
//------------------------------------------------------------------------------

#undef SL_LL_TYPE
#undef SL_LL_NODE_TYPE
#undef SL_LL_FUNCTION_SUFFIX
#undef SL_LL_IS_PRIVATE
#undef SL_LL_HEAD
#undef SL_LL_NODE
//------------------------------------------------------------------------------

//-<EOF>
