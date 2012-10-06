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
// os/bsd/uchar.h
//------------------------------------------------------------------------------
// uchar.h does not exist on NetBSD 5.1.2 with GCC 4.1.3.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_OS_BSD_UCHAR_H__
#define __SL_CONFIG_OS_BSD_UCHAR_H__

//------------------------------------------------------------------------------
// Define UTF-8 and UTF-16 character types.
typedef sl_uint16_t char16_t;
typedef sl_uint32_t char32_t;
//------------------------------------------------------------------------------

#endif /* __SL_CONFIG_OS_BSD_UCHAR_H__ */

//-<EOF>
