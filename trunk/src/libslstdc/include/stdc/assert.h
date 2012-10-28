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
// assert.h
//------------------------------------------------------------------------------
// Standard assertion implementation
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// If assert was previously inserted, undefine it.
//
#ifdef __SL_STDC_IMPL_ASSERT_H__

# undef __SL_STDC_IMPL_ASSERT_H__
# undef assert

#endif /* __SL_STDC_IMPL_ASSERT_H__ */
//------------------------------------------------------------------------------

#define __SL_STDC_IMPL_ASSERT_H__

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// Private functions
//
_Noreturn void _Assert (const char* msg);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// __assert_fail macro
//
#define __assert_fail(assertion,file,line,function)		\
  _Assert (file ":" sl_str(line) ":" function " " assertion)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// assert macro
//
// If the assertion fails, the __assert_fail macro is used to call the private
// assertion function _Assert.
//
#ifdef NDEBUG
# define assert(ignore) ((void)0)
#else /* NDEBUG */
# define assert(expr)                           \
  ((void)                                       \
   ((expr)					\
    ? 0						\
    : (__assert_fail (sl_str(expr),		\
		      __FILE__,			\
		      __LINE__,			\
		      __func__),		\
       0)))
#endif /* NDEBUG */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// static_assert macro
//
#define static_assert _Static_assert
//------------------------------------------------------------------------------

//-<EOF>
