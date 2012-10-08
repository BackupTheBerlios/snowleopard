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
// config_float.h
//------------------------------------------------------------------------------
// Configuration applicable to all flaoting point C code.
//    - lynx
//    - slcc
//    - slsh
//    - libslstdc
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_FLOAT_H__
#define __SL_CONFIG_CONFIG_FLOAT_H__

//------------------------------------------------------------------------------
// __SL_FLOAT_ROUNDS
//
// Values: -1 undeterminable
//         0  towards zero
//         1  to nearest
//         2  towards positive infinity
//         3  towards negative infinity
// Default: 1
//
#define __SL_FLOAT_ROUNDS 1
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// __SL_FLOAT_EVAL_METHOD
//
// Values: -1 undeterminable
//         0  float/double
//         1  double/double
//         2  long double/long double
// Default: 2
//
#define __SL_FLOAT_EVAL_METHOD 0
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// __SL_FLOAT_<type>_HAS_SUBNORM
#define __SL_FLOAT_FLOAT_HAS_SUBNORM 0
#define __SL_FLOAT_DOUBLE_HAS_SUBNORM 0
#define __SL_FLOAT_LONG_DOUBLE_HAS_SUBNORM 0
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// General floating point specs
#define __SL_FLOAT_G_RADIX 2
#define __SL_FLOAT_G_DECIMAL_DIG 21
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// float specs
#define __SL_FLOAT_MANT_DIG 24
#define __SL_FLOAT_DECIMAL_DIG 6
#define __SL_FLOAT_DIG 6
#define __SL_FLOAT_MAX_DECIMAL_DIG 9
#define __SL_FLOAT_MIN_EXP (-125)
#define __SL_FLOAT_MIN_10_EXP (-37)
#define __SL_FLOAT_MAX_EXP 128
#define __SL_FLOAT_MAX_10_EXP 38
#define __SL_FLOAT_EPSILON 1.19209290e-07F
#define __SL_FLOAT_ROUND_ERROR 0.5F
#define __SL_FLOAT_MIN 1.17549435e-38F
#define __SL_FLOAT_MAX 3.40282347e+38F
#define __SL_FLOAT_TRUE_MIN __SL_FLOAT_MIN
#define __SL_FLOAT_LOWEST -3.40282347e+38F
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// double specs
#define __SL_DOUBLE_MANT_DIG 53
#define __SL_DOUBLE_DECIMAL_DIG 15
#define __SL_DOUBLE_DIG 15
#define __SL_DOUBLE_MAX_DECIMAL_DIG 17
#define __SL_DOUBLE_MIN_EXP (-1021)
#define __SL_DOUBLE_MIN_10_EXP (-307)
#define __SL_DOUBLE_MAX_EXP 1024
#define __SL_DOUBLE_MAX_10_EXP 308
#define __SL_DOUBLE_EPSILON 2.2204460492503131e-16
#define __SL_DOUBLE_ROUND_ERROR 0.5
#define __SL_DOUBLE_MIN 2.2250738585072014e-308
#define __SL_DOUBLE_MAX 1.7976931348623157e+308
#define __SL_DOUBLE_TRUE_MIN __SL_DOUBLE_MIN
#define __SL_DOUBLE_LOWEST -1.7976931348623157e+308
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// long double specs
#define __SL_LDOUBLE_MANT_DIG 64
#define __SL_LDOUBLE_DECIMAL_DIG 18
#define __SL_LDOUBLE_DIG 18
#define __SL_LDOUBLE_MAX_DECIMAL_DIG 21
#define __SL_LDOUBLE_MIN_EXP (-16381)
#define __SL_LDOUBLE_MIN_10_EXP (-4931)
#define __SL_LDOUBLE_MAX_EXP 16384
#define __SL_LDOUBLE_MAX_10_EXP 4932
#define __SL_LDOUBLE_EPSILON 1.08420217248550443401e-19L
#define __SL_LDOUBLE_ROUND_ERROR 0.5L
#define __SL_LDOUBLE_MIN 3.36210314311209350626e-4932L
#define __SL_LDOUBLE_MAX 1.18973149535723176502e+4932L
#define __SL_LDOUBLE_TRUE_MIN __SL_LDOUBLE_MIN
#define __SL_LDOUBLE_LOWEST -1.18973149535723176502e+4932L
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// __SL_FLOAT_HUGE_VAL
#define __SL_FLOAT_HUGE_VAL __SL_FLOAT_MAX
#define __SL_FLOAT_HUGE_VALF __SL_DOUBLE_MAX
#define __SL_FLOAT_HUGE_VALL __SL_LDOUBLE_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// INFINITY
#define __SL_FLOAT_HAS_INFINITY
#define __SL_FLOAT_INFINITY 1.0/0.0 /* TO DO */
#define __SL_FLOAT_INFINITYF 1.0/0.0 /* TO DO */
#define __SL_FLOAT_INFINITYL 1.0/0.0 /* TO DO */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// NAN
#define __SL_FLOAT_HAS_NAN
#define __SL_FLOAT_NAN 0 /* TO DO */
#define __SL_FLOAT_NANF 0 /* TO DO */
#define __SL_FLOAT_NANL 0 /* TO DO */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SUBNORMAL
#define __SL_FLOAT_SUBNORMAL  0 /* TO DO */
#define __SL_FLOAT_SUBNORMALF 0 /* TO DO */
#define __SL_FLOAT_SUBNORMALL 0 /* TO DO */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// math_errhandling
//
// Values: MATH_ERRNO
//         MATH_ERREXCEPT
//         (MATH_ERRNO | MATH_ERREXCEPT)
#define __SL_FLOAT_MATH_ERRHANDLING (MATH_ERRNO | MATH_ERREXCEPT)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// FP_CONTRACT pragma
#define __SL_FLOAT_CONTRACT DEFAULT
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_CONFIG_FLOAT_H__ */

//-<EOF>
