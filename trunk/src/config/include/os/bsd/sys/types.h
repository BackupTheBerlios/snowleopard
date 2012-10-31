/*==============================================================================
  Snow Leopard Compiler Project
  
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
// os/bsd/sys/types.h
//------------------------------------------------------------------------------
// Handle BSD sys/types.h
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_OS_BSD_SYS_TYPES_H__
#define __SL_CONFIG_OS_BSD_SYS_TYPES_H__

//------------------------------------------------------------------------------
// Avoid duplicate size_t definition
//
#define _GCC_SIZE_T __SL_ConfigNamespace sl_size_t
#define _BSD_SIZE_T_ __SL_ConfigNamespace sl_size_t 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Avoid duplicate time_t definition
//
#define _BSD_TIME_T_ __SL_ConfigNamespace sl_time_t
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include system header
//
#include <sys/types.h>
//------------------------------------------------------------------------------

#endif /* __SL_CONFIG_OS_BSD_SYS_TYPES_H__ */

//-<EOF>
