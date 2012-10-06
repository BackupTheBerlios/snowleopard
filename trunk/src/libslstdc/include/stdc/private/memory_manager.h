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
// memory_manager.h
//------------------------------------------------------------------------------
// Private memory manager
//
// The memory manager takes care of objects created on the heap, it is used by 
// all memory management functions (malloc/free/...) and by the allocators in 
// the C++ library.
//------------------------------------------------------------------------------

#ifndef __SL_STDC_PRIVATE_MEMORY_MANAGER_H__
#define __SL_STDC_PRIVATE_MEMORY_MANAGER_H__

#include <config/config.h>

#include <stdc/private/ll_mm_blocks.h>
#include <stdc/private/ll_mm_pages.h>
#include <stdc/private/mm_types.h>

//------------------------------------------------------------------------------
// Global variables
extern sl_ll_mm_blocks_head_* _SL_Hidden __SL_Alloc_Blocks;
extern sl_ll_mm_blocks_head_* _SL_Hidden __SL_Free_Blocks;
extern sl_ll_mm_pages_head_* _SL_Hidden __Pages;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialize functions

//------------------------------------------------------------------------------

#endif /* !__SL_STDC_PRIVATE_MEMORY_MANAGER_H__ */

//-<EOF>
