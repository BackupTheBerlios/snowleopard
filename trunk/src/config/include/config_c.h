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
// config_c.h
//------------------------------------------------------------------------------
// Configuration applicable to all C code.
//    - lynx
//    - puma
//    - slcc
//    - slsh
//    - libslstdc
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_C_H__
#define __SL_CONFIG_CONFIG_C_H__

//------------------------------------------------------------------------------
// General project constants
//
#define __SL_COPYRIGHT_YEAR 2012
//------------------------------------------------------------------------------

//==============================================================================
// Standard C library constants
//

//------------------------------------------------------------------------------
// General constants
//
#define __SL_STDC__ 1
#define __SL_STDC_HOSTED__ 0
#define __SL_STDC_ISO_10646__ 201103L
#define __SL_STDC_MB_MIGHT_NEQ_WC__ 1
#define __SL_STDC_UTF_16__ 1
#define __SL_STDC_UTF_32__ 1
#define __SL_STDC_IEC_559__ 1
#define __SL_STDC_IEC_559_COMPLEX__ 1
#define __SL_STDC_NO_VLA__ 0
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Standard C99 specific
//
#define __SL_C99_STDC_VERSION__ 199901L
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Standard C11 specific
//
#define __SL_C11_STDC_VERSION__ 201112L
#define __SL_C11_STDC_ANALYZABLE__ 1
#define __SL_C11_STDC_LIB_EXT1__ 201112L
#define __SL_C11_STDC_NO_ATOMICS__ 0
#define __SL_C11_STDC_NO_THREADS__ 0
//------------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// Standard C++ library constants
//

//------------------------------------------------------------------------------
// Standard C++03 specific
//
#define __SL_CPP03_cplusplus__ 199901L
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Standard C++11 specific
//
#define __SL_CPP11_cplusplus__ 201103L
//------------------------------------------------------------------------------

//==============================================================================

//------------------------------------------------------------------------------
// Platform
//
#define __SL_x86_64 1
#define __SL_POWER 2
#define __SL_PLATFORM __SL_x86_64
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Platform dependent configuration
//
//#define SL_PLATFORM_HAS_FLOAT_MULTIPLY_ADD /* uncomment if platform has
//                                            * hardware multiply add
//                                            */    
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// OS
//
#define __SL_OS_NetBSD 0
#define __SL_OS_MacOSX 1
#define __SL_OS_Linux 2
#define __SL_FAMILY_BSD 0
#define __SL_FAMILY_Linux 1
#define __SL_OS SL_OS_NetBSD
#define __SL_OS_FAMILY __SL_OS_BSD
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Enable non standard features
//
#define __SL_ENABLE_NON_STANDARD_FEATURES
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Visibility attribute
//
#define _SL_Hidden /* __attribute__((visibility("hidden"))) */
//------------------------------------------------------------------------------

//==============================================================================
// Integer/character configuration
//
#include sl_include_config(config_int_char.h)
//==============================================================================

//==============================================================================
// Floating point configuration
//
#include sl_include_config(config_float.h)
//==============================================================================

//==============================================================================
// Complex number configuration
//
#include sl_include_config(config_complex.h)
//==============================================================================

//==============================================================================
// Input/output configuration
//
#include sl_include_config(config_io.h)
//==============================================================================

//==============================================================================
// Error numbers
//
#include sl_include_config(config_errno.h)
//==============================================================================

//==============================================================================
// Variable argument configuration
//

//------------------------------------------------------------------------------
// List type
//
#define __SL_VA_LIST_TYPE char*
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Built in macros
//
#define __SL_UP_BOUND 1
#define __SL_DOWN_BOUND 1
#define __SL_Bound(arg,bound)			\
  (sizeof(arg) + (bound) & ~(bound))
#define __SL_VA_ARG(ap,type)				\
  (*(type *)(((ap) += _Bnd(type, __SL_UP_BOUND)) -	\
	     _Bnd(type, __SL_DOWN_BOUND)))
#define __SLVA_COPY(dest,src)			\
  (dest) = (src)
#define __SL_VA_END(ap)				\
  (void)0
#define __SL_VA_START(ap,parm_n)					\
  (void)((ap) = (char *)&(parm_n) + __SL_Bound(ap, __SL_UP_BOUND))
//------------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// C specific configuration
// 
// Excluded if C++
//
#ifndef __cplusplus

//------------------------------------------------------------------------------
// Boolean type
//
// If compiler support C11, use _Bool, otherwise short.
//
typedef short sl_boolean;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _Noreturn function specifier
//
// If compiler support C11, use _Noreturn, otherwise define it to be empty.
//
#define _Noreturn
//------------------------------------------------------------------------------

#endif /* !__cplusplus */

//==============================================================================

//==============================================================================
// Thread/process parameters
//

//------------------------------------------------------------------------------
// Maximum at_exit functions
//
#define __SL_STDC_MAX_ATEXIT_FUNCTIONS __SL_UINT8_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Thread iteration parameters
//
#define __SL_ONCE_FLAG_INIT 1
#define __SL_TSS_DTOR_ITERATIONS 1
//------------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// Implementation limits
//

//------------------------------------------------------------------------------
// Compiler/Interpreter limits
//
#define __SL_MAX_ARGUMENTS __SL_UINT8_MAX
#define __SL_MAX_ERRORS __SL_UINT16_MAX
//------------------------------------------------------------------------------

//==============================================================================

#endif /* !__SL_CONFIG_CONFIG_C_H__ */

//-<EOF>
