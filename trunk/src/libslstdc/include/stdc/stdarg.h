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
// stdarg.h
//------------------------------------------------------------------------------
// Standard argument implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STDARG_H__
#define __SL_STDC_IMPL_STDARG_H__

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// va_list type
//
// va_list is defined in private/shared_types.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// variable argument macros
//
#define va_arg(ap,type) (__SL_VA_ARG(ap,type))
#define va_copy(dest,src) (__SL_VA_COPY(dest,src))
#define va_end(ap) (__SL_VA_END(ap))
#define va_start(ap,parm_n) (__SL_VA_COPY(ap,parm_n))
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_STDARG_H__ */

//-<EOF>
