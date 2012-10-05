/*==============================================================================
  Snow Leopard Standard C Library
  
  Copyright (C) 2008-2012 Roel Sergeant
  
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
// mm_types.h
//------------------------------------------------------------------------------
// Defines types used by the memory manager
//------------------------------------------------------------------------------

#ifndef __SL_STDC_PRIVATE_MM_TYPES_H__
#define __SL_STDC_PRIVATE_MM_TYPES_H__

#include <sl/config/config.h>

#include <stddef.h>

//------------------------------------------------------------------------------
// sl_mm_page struct
struct sl_mm_page {
  void* ptr_;
  size_t size_;
};

typedef struct sl_mm_page sl_mm_page;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sl_mm_block struct
struct sl_mm_block {
  sl_mm_page page_;
  void* ptr_;
  size_t size_;
};

typedef struct sl_mm_block sl_mm_block;
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_PRIVATE_MM_TYPES_H__ */

//-<EOF>
