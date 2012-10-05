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
// assert.h
//------------------------------------------------------------------------------
// Standard assertion implementation
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// If assert was previously inserted, undefine it.
#ifdef __SL_STDC_IMPL_ASSERT_H__

# undef __SL_STDC_IMPL_ASSERT_H__
# undef assert

#endif /* __SL_STDC_IMPL_ASSERT_H__ */
//------------------------------------------------------------------------------

#define __SL_STDC_IMPL_ASSERT_H__

#include <sl/config/config.h>

#include <stddef.h>

//------------------------------------------------------------------------------
// __assert_fail function
void __assert_fail(
    const char* assertion,
    const char* file,
    size_t line,
    const char* function
                   );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// assert macro (TODO)
#ifdef NDEBUG
# define assert(ignore) ((void)0)
#else /* NDEBUG */
# define assert(expr)                           \
  ((void)                                       \
   ((expr) ? 0 :                                \
    (__assert_fail (__STRING(expr),             \
                    __FILE__,                   \
                    __LINE__,                   \
                    __func__),                  \
     0)))
#endif /* NDEBUG */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// static_assert macro
#define static_assert _Static_assert
//------------------------------------------------------------------------------

//-<EOF>

