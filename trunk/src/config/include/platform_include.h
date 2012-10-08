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
// platform_include.h
//------------------------------------------------------------------------------
// Macros for including platform specific headers.
//------------------------------------------------------------------------------

#include <config.h>

#include <macros.h>

#ifndef __SL_CONFIG_PLATFORM_INCLUDE_H__
#define __SL_CONFIG_PLATFORM_INCLUDE_H__

//------------------------------------------------------------------------------
// Misc macro functions
#define sl_platform_str(s) sl_str(s)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include platform specific headers
#if __SL_PLATFORM == __SL_PLATFORM_x86_64
# define sl_os_fixinclude(platform_include) sl_os_str(platform/x86_64/platform_include)
#elif __SL_PLATFORM == __SL_PLATFORM_POWER
# define sl_os_fixinclude(platform_include) sl_os_str(platform/power/platform_include)
#else
# error "Platform is undefined, please rerun the configuration."
#endif /* __SL_PLATFORM == __SL_PLATFORM_x86_64 */
//------------------------------------------------------------------------------

#endif /* __SL_CONFIG_PLATFORM_INCLUDE_H__ */

//-<EOF>
