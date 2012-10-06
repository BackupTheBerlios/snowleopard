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
// ll_mm_pages.h
//------------------------------------------------------------------------------
// Private linked list for storing memory page information
//------------------------------------------------------------------------------

#ifndef __SL_STDC_PRIVATE_LL_MM_PAGES_H__
#define __SL_STDC_PRIVATE_LL_MM_PAGES_H__

#include <sl/config/config.h>

#include <stdc/private/mm_types.h>

//------------------------------------------------------------------------------
// Define open files linked list
#define SL_LL_TYPE sl_ll_mm_pages
#define SL_LL_NODE_TYPE sl_mm_page
#define SL_LL_FUNCTION_SUFFIX mp
#define SL_LL_IS_PRIVATE
#define SL_LL_NO_FIND

#include <stdc/private/linked_list.h>

#undef SL_LL_TYPE
#undef SL_LL_NODE_TYPE
#undef SL_LL_FUNCTION_SUFFIX
#undef SL_LL_IS_PRIVATE
#undef SL_LL_NO_FIND
#undef SL_LL_HEAD
#undef SL_LL_NODE
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_PRIVATE_LL_MM_PAGES_H__ */

//-<EOF>
