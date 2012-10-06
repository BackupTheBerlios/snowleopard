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
// stdint_limits.h
//------------------------------------------------------------------------------
// Standard integer limits implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_STDINT_LIMITS_H_
#define _SL_STDC_IMPL_STDINT_LIMITS_H_

#include <config/config.h>

//------------------------------------------------------------------------------
// Exact width integer types
#define INT8_MIN SL_INT8_MIN
#define INT8_MAX SL_INT8_MAX
#define UINT8_MAX SL_UINT8_MAX
#define INT16_MIN SL_INT16_MIN
#define INT16_MAX SL_INT16_MAX
#define UINT16_MAX SL_UINT16_MAX
#define INT32_MIN SL_INT32_MIN
#define INT32_MAX SL_INT32_MAX
#define UINT32_MAX SL_UINT32_MAX
#define INT64_MIN SL_INT64_MIN
#define INT64_MAX SL_INT64_MAX
#define UINT64_MAX SL_UINT64_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Mininum width integer types
#define INT_LEAST8_MIN SL_INT8_MIN
#define INT_LEAST8_MAX SL_INT8_MAX
#define UINT_LEAST8_MAX SL_UINT8_MAX
#define INT_LEAST16_MIN SL_INT16_MIN
#define INT_LEAST16_MAX SL_INT16_MAX
#define UINT_LEAST16_MAX SL_UINT16_MAX
#define INT_LEAST32_MIN SL_INT32_MIN
#define INT_LEAST32_MAX SL_INT32_MAX
#define UINT_LEAST32_MAX SL_UINT32_MAX
#define INT_LEAST64_MIN SL_INT64_MIN
#define INT_LEAST64_MAX SL_INT64_MAX
#define UINT_LEAST64_MAX SL_UINT64_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exact width integer types
#define INT_FAST8_MIN SL_INT8_MIN
#define INT_FAST8_MAX SL_INT8_MAX
#define UINT_FAST8_MAX SL_UINT8_MAX
#define INT_FAST16_MIN SL_INT16_MIN
#define INT_FAST16_MAX SL_INT16_MAX
#define UINT_FAST16_MAX SL_UINT16_MAX
#define INT_FAST32_MIN SL_INT32_MIN
#define INT_FAST32_MAX SL_INT32_MAX
#define UINT_FAST32_MAX SL_UINT32_MAX
#define INT_FAST64_MIN SL_INT64_MIN
#define INT_FAST64_MAX SL_INT64_MAX
#define UINT_FAST64_MAX SL_UINT64_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Integer types for holding pointers
#define INTPTR_MIN SL_DIFF_MIN
#define INTPTR_MAX SL_DIFF_MAX
#define UINTPTR_MAX SL_SIZE_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Limits of the greatest integer types
#define INTMAX_MIN SL_LLONG_MIN
#define INTMAX_MAX SL_LLONG_MAX
#define UINTMAX_MAX SL_ULLONG_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Limits of other integer types
// ptrdiff_t
#define PTRDIFF_MIN SL_DIFF_MIN
#define PTRDIFF_MAX SL_DIFF_MAX
// sig_atomic_t
#define SIG_ATOMIC_MIN SL_ATOMIC_MIN
#define SIG_ATOMIC_MAX SL_ATOMIC_MAX
// size_t
#define SIZE_MAX SL_SIZE_MAX
// rsize_t
#define RSIZE_MAX SL_SIZE_MAX
// wchar_t
#define WCHAR_MIN SL_WCHAR_MIN
#define WCHAR_MAX SL_WCHAR_MAX
// wint_t
#define WINT_MIN SL_WINT_MIN
#define WINT_MAX SL_WINT_MAX
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_STDINT_LIMITS_H_ */

//-<EOF>
