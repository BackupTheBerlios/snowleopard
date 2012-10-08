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
// config.h
//------------------------------------------------------------------------------
// Macros for including os specific header fixes.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_OS_FIXINCLUDE_H__
#define __SL_CONFIG_OS_FIXINCLUDE_H__

//------------------------------------------------------------------------------
// Misc macro functions
#define sl_os_str(s) sl_str(s)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// OS family specific include
#if __SL_OS_FAMILY == __SL_FAMILY_BSD
# ifdef __SL_NO_SL_STDLIB
#  define sl_os_fixinclude(os_include) sl_os_str(os/bsd/os_include)
# else /* __SL_NO_SL_STDLIB */
#  define sl_os_fixinclude(os_include) sl_os_str(os/bsd/os_include)
# endif /* __SL_NO_SL_STDLIB */
#elif __SL_OS_FAMILY == __SL_FAMILY_Linux
# ifdef __SL_NO_SL_STDLIB
#  define sl_os_fixinclude(os_include) sl_os_str(os/linix/os_include)
# else /* __SL_NO_SL_STDLIB */
#  define sl_os_fixinclude(os_include) sl_os_str(os/linux/os_include)
# endif /* __SL_NO_SL_STDLIB */
#else
# error "Unknown OS family, please rerun the configuration."
#endif /* __SL_OS_FAMILY == __SL_OS_BSD */
//------------------------------------------------------------------------------

#endif /* __SL_CONFIG_OS_FIXINCLUDE_H__ */

//-<EOF>
