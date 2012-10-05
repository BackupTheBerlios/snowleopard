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
// threads.h
//------------------------------------------------------------------------------
// Standard threads implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_THREADS_H_
#define _SL_STDC_IMPL_THREADS_H_

#include <sl/config/config.h>

#include <time.h>

//------------------------------------------------------------------------------
// thread_local macro
#define thread_local _Thread_local
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ONCE_FLAG_INIT/TSS_DTOR_ITERATIONS macros
#define ONCE_FLAG_INIT __SL_ONCE_FLAG_INIT
#define TSS_DTOR_ITERATIONS __SL_TSS_DTOR_ITERATIONS
//------------------------------------------------------------------------------


#endif /* !_SL_STDC_IMPL_THREADS_H_ */

//-<EOF>
