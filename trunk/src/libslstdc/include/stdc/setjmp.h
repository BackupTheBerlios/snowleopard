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
// setjmp.h
//------------------------------------------------------------------------------
// Standard setjmp implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_SETJMP_H_
#define _SL_STDC_IMPL_SETJMP_H_

#include <sl/config/config.h>
#include <sl/config/platform_include.h>

//------------------------------------------------------------------------------
// jmp_buf structure
//
// Include platform specific structure
#include sl_platform_include(jmp_buf.h)

typedef struct jmp_buf jmp_buf;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// setjmp function
int setjmp(jmp_buf env);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// longjmp function
_Noreturn void longjmp(jmp_buf env, int val);
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_SETJMP_H_ */

//-<EOF>
