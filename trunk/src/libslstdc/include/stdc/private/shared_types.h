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
// shared_types.h
//------------------------------------------------------------------------------
// Types shared by standard headers. Collected here to avoid duplication.
//------------------------------------------------------------------------------

#ifndef __SL_STDC_PRIVATE_SHARED_TYPES_H__
#define __SL_STDC_PRIVATE_SHARED_TYPES_H__

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// errno_t type
//
typedef __SL_ConfigNamespace sl_errno_t errno_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// intmax_t type
//
typedef __SL_ConfigNamespace sl_int64_t intmax_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// size_t type
//
typedef __SL_ConfigNamespace  sl_size_t size_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// va_list type
//
typedef __SL_VA_LIST_TYPE va_list;
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_PRIVATE_SHARED_TYPES_H__ */

//-<EOF>
