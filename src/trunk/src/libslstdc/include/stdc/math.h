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
// math.h
//------------------------------------------------------------------------------
// Standard math implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_MATH_H__
#define __SL_STDC_IMPL_MATH_H__

#include <config/config.h>

#include <float.h>

//------------------------------------------------------------------------------
// Define float_t and double_t
#if FLT_EVAL_METHOD == -1
typedef float float_t;
typedef double double_t;
#elif FLT_EVAL_METHOD == 0
typedef float float_t;
typedef double double_t;
#elif FLT_EVAL_METHOD == 1
typedef double float_t;
typedef double double_t;
#elif FLT_EVAL_METHOD == 2
typedef long double float_t;
typedef long double double_t;
#else
  /*
   * For all other values or if FLT_EVAL_METHOD is undefined, we assume it 
   * is 2. 
   */
# undef FLT_EVAL_METHOD
# define FLT_EVAL_METHOD 2
typedef long double float_t;
typedef long double double_t;
#endif /* FLT_EVAL_METHOD = 0 */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// HUGE_VAL definitions
#define HUGE_VAL  __SL_FLOAT_HUGE_VAL
#define HUGE_VALF __SL_FLOAT_HUGE_VALF
#define HUGE_VALL __SL_FLOAT_HUGE_VALL
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// INFINITY definitions
#ifdef __SL_FLOAT_HAS_INFINITY
# define INFINITY  __SL_FLOAT_INFINITY
# define INFINITYF __SL_FLOAT_INFINITYF
# define INFINITYL __SL_FLOAT_INFINITYL
#endif /* __SL_FLOAT_HAS_INFINITY */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// NAN definitions
#ifdef __SL_FLOAT_HAS_NAN
# define NAN  __SL_FLOAT_NAN
# define NANF __SL_FLOAT_NANF
# define NANL __SL_FLOAT_NANL
#endif /* __SL_FLOAT_HAS_NAN */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// If fast math is supported on this platform, define macros
#ifdef __SL_PLATFORM_HAS_FLOAT_MULTIPLY_ADD
# define FP_FAST_FMA
# define FP_FAST_FMAF
# define FP_FAST_FMAL
#endif /* __SL_PLATFORM_HAS_FLOAT_MULTIPLY_ADD */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ILOGB definitions
#define FP_ILOGB0   INT_MIN
#define FP_ILOGBNAN INT_MIN
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error handling
#define MATH_ERRNO     1
#define MATH_ERREXCEPT 2
extern const int math_errhandling;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// FP_CONTRACT pragma
#pragma STDC FP_CONTRACT __SL_FLOAT_CONTRACT
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Classification macros
#include <stdc/math_classification.h>
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions
#include <stdc/math_functions.h>
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_MATH_H__ */

//-<EOF>
