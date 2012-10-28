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
// config_int_char.h
//------------------------------------------------------------------------------
// Configuration applicable to all integer/character C code.
//    - lynx
//    - puma
//    - slcc
//    - slsh
//    - libslstdc
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_INT_CHAR_H__
#define __SL_CONFIG_CONFIG_INT_CHAR_H__

//------------------------------------------------------------------------------
// Exact width integer types and limits
//
// Define integer types of a set number of bits and their limits.
// 
// 8 bit signed integer
typedef signed char sl_int8_t;
#define __SL_INT8_SUFFIX 
#define __SL_INT8_MIN -127
#define __SL_INT8_MAX 127
// 8 bit unsigned integer
typedef char sl_uint8_t;
#define __SL_UINT8_SUFFIX
#define __SL_UINT8_MAX 255
// 16 bit signed integer
typedef int sl_int16_t;
#define __SL_INT16_SUFFIX 
#define __SL_INT16_MIN -32767
#define __SL_INT16_MAX 32767
#define __SL_INT16_NON_SIGN_BITS 15
#define __SL_INT16_DIGITS10 4
#define __SL_INT16_MAX_DIGITS10 5
// 16 bit unsigned integer
typedef unsigned int sl_uint16_t;
#define __SL_UINT16_SUFFIX
#define __SL_UINT16_MAX 65535
#define __SL_UINT16_NON_SIGN_BITS 16
#define __SL_UINT16_DIGITS10 4
#define __SL_UINT16_MAX_DIGITS10 5
// 32 bit signed integer
typedef long sl_int32_t;
#define __SL_INT32_SUFFIX L
#define __SL_INT32_MIN -2147483647
#define __SL_INT32_MAX 2147483647
#define __SL_INT32_NON_SIGN_BITS 31
#define __SL_INT32_DIGITS10 9
#define __SL_INT32_MAX_DIGITS10 10
// 32 bit unsigned integer
typedef unsigned long sl_uint32_t;
#define __SL_UINT32_SUFFIX UL
#define __SL_UINT32_MAX 4294967295
#define __SL_UINT32_NON_SIGN_BITS 32
#define __SL_UINT32_DIGITS10 9
#define __SL_UINT32_MAX_DIGITS10 10
// 64 bit signed integer
typedef long long sl_int64_t;
#define __SL_INT64_SUFFIX LL
#define __SL_INT64_MIN -9223372036854775807LL
#define __SL_INT64_MAX 9223372036854775807LL
#define __SL_INT64_NON_SIGN_BITS 63
#define __SL_INT64_DIGITS10 18
#define __SL_INT64_MAX_DIGITS10 19
// 64 bit unsigned integer
typedef unsigned long long sl_uint64_t;
#define __SL_UINT64_SUFFIX ULL
#define __SL_UINT64_MAX 18446744073709551615ULL
#define __SL_UINT64_NON_SIGN_BITS 64
#define __SL_UINT64_DIGITS10 19
#define __SL_UINT64_MAX_DIGITS10 20
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Fastest integer type
typedef long long sl_int_fast_t;
typedef unsigned long long sl_uint_fast_t;
#define __SL_PRI_FAST_MACRO_d "%lld"
#define __SL_PRI_FAST_MACRO_i "%lli"
#define __SL_PRI_FAST_MACRO_o "%llo"
#define __SL_PRI_FAST_MACRO_u "%llu"
#define __SL_PRI_FAST_MACRO_x "%llx"
#define __SL_PRI_FAST_MACRO_X "%llX"
#define __SL_SCN_FAST_MACRO_d "%lld"
#define __SL_SCN_FAST_MACRO_i "%lli"
#define __SL_SCN_FAST_MACRO_o "%llo"
#define __SL_SCN_FAST_MACRO_u "%llu"
#define __SL_SCN_FAST_MACRO_x "%llx"
#define __SL_SCN_FAST_MACRO_X "%llX"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Integer type limits
//
// Integer types are: short / unsigned short
//                    int / unsigned int
//                    long / unsigned long
//                    long long / unsigned long long
// short limits
#define __SL_SHRT_MIN __SL_INT16_MIN
#define __SL_SHRT_MAX __SL_INT16_MAX
#define __SL_SHRT_NON_SIGN_BITS __SL_INT16_NON_SIGN_BITS
#define __SL_SHRT_DIGITS10 __SL_INT16_DIGITS10
#define __SL_SHRT_MAX_DIGITS10 __SL_INT16_MAX_DIGITS10
#define __SL_USHRT_MAX __SL_INT16_MAX
#define __SL_USHRT_NON_SIGN_BITS __SL_UINT16_NON_SIGN_BITS
#define __SL_USHRT_DIGITS10 __SL_UINT16_DIGITS10
#define __SL_USHRT_MAX_DIGITS10 __SL_UINT16_MAX_DIGITS10
// int limits
#define __SL_INT_MIN __SL_INT32_MIN
#define __SL_INT_MAX __SL_INT32_MAX
#define __SL_INT_NON_SIGN_BITS __SL_INT32_NON_SIGN_BITS
#define __SL_INT_DIGITS10 __SL_INT32_DIGITS10
#define __SL_INT_MAX_DIGITS10 __SL_INT32_MAX_DIGITS10
#define __SL_UINT_MAX __SL_UINT32_MAX
#define __SL_UINT_NON_SIGN_BITS __SL_UINT32_NON_SIGN_BITS
#define __SL_UINT_DIGITS10 __SL_UINT32_DIGITS10
#define __SL_UINT_MAX_DIGITS10 __SL_UINT32_MAX_DIGITS10
// long limits
#define __SL_LONG_MIN __SL_INT64_MIN
#define __SL_LONG_MAX __SL_INT64_MAX
#define __SL_LONG_NON_SIGN_BITS __SL_INT64_NON_SIGN_BITS
#define __SL_LONG_DIGITS10 __SL_INT64_DIGITS10
#define __SL_LONG_MAX_DIGITS10 __SL_INT64_MAX_DIGITS10
#define __SL_ULONG_MAX __SL_INT64_MAX
#define __SL_ULONG_NON_SIGN_BITS __SL_UINT64_NON_SIGN_BITS
#define __SL_ULONG_DIGITS10 __SL_UINT64_DIGITS10
#define __SL_ULONG_MAX_DIGITS10 __SL_UINT64_MAX_DIGITS10
// long long limits
#define __SL_LLONG_MIN __SL_INT64_MIN
#define __SL_LLONG_MAX __SL_INT64_MAX
#define __SL_LLONG_NON_SIGN_BITS __SL_INT64_NON_SIGN_BITS
#define __SL_LLONG_DIGITS10 __SL_INT64_DIGITS10
#define __SL_LLONG_MAX_DIGITS10 __SL_INT64_MAX_DIGITS10
#define __SL_ULLONG_MAX __SL_UINT64_MAX 
#define __SL_ULLONG_NON_SIGN_BITS __SL_UINT64_NON_SIGN_BITS
#define __SL_ULLONG_DIGITS10 __SL_UINT64_DIGITS10
#define __SL_ULLONG_MAX_DIGITS10 __SL_UINT64_MAX_DIGITS10
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// atomic integer type
typedef unsigned int sl_sig_atomic_t;
#define __SL_ATOMIC_MIN 0
#define __SL_ATOMIC_MAX __SL_UINT_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// size and difference types
typedef long sl_diff_t;
#define __SL_DIFF_MIN __SL_LONG_MIN
#define __SL_DIFF_MAX __SL_LONG_MAX
typedef unsigned long sl_size_t;
#define __SL_SIZE_MAX __SL_ULONG_MAX
#define __SL_PRI_PTR_MACRO_d "%ld"
#define __SL_PRI_PTR_MACRO_i "%li"
#define __SL_PRI_PTR_MACRO_o "%lo"
#define __SL_PRI_PTR_MACRO_u "%lu"
#define __SL_PRI_PTR_MACRO_x "%lx"
#define __SL_PRI_PTR_MACRO_X "%lX"
#define __SL_SCN_PTR_MACRO_d "%ld"
#define __SL_SCN_PTR_MACRO_i "%li"
#define __SL_SCN_PTR_MACRO_o "%lo"
#define __SL_SCN_PTR_MACRO_u "%lu"
#define __SL_SCN_PTR_MACRO_x "%lx"
#define __SL_SCN_PTR_MACRO_X "%lX"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// clock and time types
typedef unsigned int sl_clock_t;
typedef int sl_time_t;
#define __SL_CLOCKS_PER_SEC 1000000
#define __SL_UTC_TIME -1
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Char types
#define __SL_CHAR_BITS 8
#define __SL_CHAR_IS_SIGNED 1
#define __SL_SCHAR_MIN __SL_INT8_MIN
#define __SL_SCHAR_MAX __SL_INT8_MAX
#define __SL_UCHAR_MAX __SL_UINT8_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Wide character types
#ifndef __cplusplus
//------------------------------------------------------------------------------
// C++ has built in wchar_t type
typedef unsigned long long sl_wchar_t;
//------------------------------------------------------------------------------
#endif /* !__cplusplus */
#define __SL_WCHAR_MAX_BYTES 8
#define __SL_WCHAR_MIN 0
#define __SL_WCHAR_MAX __SL_ULONG_MAX
typedef unsigned long long sl_wint_t;
#define __SL_WINT_MIN __SL_WCHAR_MIN
#define __SL_WINT_MAX __SL_WHCAR_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Unicode character types
typedef sl_uint16_t sl_char16_t;
typedef sl_uint32_t sl_char32_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error number type
typedef int sl_errno_t;
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_CONFIG_INT_CHAR_H__ */

//-<EOF>
