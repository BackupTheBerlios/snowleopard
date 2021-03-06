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

#ifndef __SL_STDC_PRIVATE_SHARED_MACROS_H__
#define __SL_STDC_PRIVATE_SHARED_MACROS_H__

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// NULL macro
//
#ifdef __cplusplus
# define NULL 0
#else /* __cplusplus */
# define NULL ((void*) 0)
#endif /* __cplusplus */
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_PRIVATE_SHARED_MACROS_H__ */

//-<EOF>
