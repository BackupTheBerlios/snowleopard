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
// stdint.h
//------------------------------------------------------------------------------
// Standard integer implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_STDINT_H_
#define _SL_STDC_IMPL_STDINT_H_

#include <sl/config/config.h>

//------------------------------------------------------------------------------
// Exact width integer types
typedef __SL_ConfigNamespace sl_int8_t int8_t;
typedef __SL_ConfigNamespace sl_uint8_t uint8_t;
typedef __SL_ConfigNamespace sl_int16_t int16_t;
typedef __SL_ConfigNamespace sl_uint16_t uint16_t;
typedef __SL_ConfigNamespace sl_int32_t int32_t;
typedef __SL_ConfigNamespace sl_uint32_t uint32_t;
typedef __SL_ConfigNamespace sl_int64_t int64_t;
typedef __SL_ConfigNamespace sl_uint64_t uint64_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Minimum width integer types
typedef __SL_ConfigNamespace sl_int8_t int_least8_t;
typedef __SL_ConfigNamespace sl_uint8_t uint_least8_t;
typedef __SL_ConfigNamespace sl_int16_t int_least16_t;
typedef __SL_ConfigNamespace sl_uint16_t uint_least16_t;
typedef __SL_ConfigNamespace sl_int32_t int_least32_t;
typedef __SL_ConfigNamespace sl_uint32_t uint_least32_t;
typedef __SL_ConfigNamespace sl_int64_t int_least64_t;
typedef __SL_ConfigNamespace sl_uint64_t uint_least64_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Fastest minimum width integer types
typedef __SL_ConfigNamespace sl_int_fast_t int_fast8_t;
typedef __SL_ConfigNamespace sl_uint_fast_t uint_fast8_t;
typedef __SL_ConfigNamespace sl_int_fast_t int_fast16_t;
typedef __SL_ConfigNamespace sl_uint_fast_t uint_fast16_t;
typedef __SL_ConfigNamespace sl_int_fast_t int_fast32_t;
typedef __SL_ConfigNamespace sl_uint_fast_t uint_fast32_t;
typedef __SL_ConfigNamespace sl_int_fast_t int_fast64_t;
typedef __SL_ConfigNamespace sl_uint_fast_t uint_fast64_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Integers for storing object pointers
typedef __SL_ConfigNamespace sl_diff_t intptr_t;
typedef __SL_ConfigNamespace sl_size_t uintptr_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Greatest width integer types
typedef __SL_ConfigNamespace sl_int64_t intmax_t;
typedef __SL_ConfigNamespace sl_uint64_t uintmax_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Limits
#include <sl/stdc/stdint_limits.h>
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Macros for minimum width constants
#define INT8_C(c) c ## SL_INT8_SUFFIX
#define UINT8_C(c) c ## SL_UINT8_SUFFIX
#define INT16_C(c) c ## SL_INT16_SUFFIX
#define UINT16_C(c) c ## SL_UINT16_SUFFIX
#define INT32_C(c) c ## SL_INT32_SUFFIX
#define UINT32_C(c) c ## SL_UINT32_SUFFIX
#define INT64_C(c) c ## SL_INT64_SUFFIX
#define UINT64_C(c) c ## SL_UINT64_SUFFIX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Macros for greatest-width constants
#define INTMAX_C(c) c ## SL_INT64_SUFFIX
#define UINTMAX_C(c) c ## SL_UINT64_SUFFIX
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_STDINT_H_ */

//-<EOF>
