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
// float.h
//------------------------------------------------------------------------------
// Standard float implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_FLOAT_H_
#define _SL_STDC_IMPL_FLOAT_H_

#include <sl/config/config.h>

//------------------------------------------------------------------------------
// FLT_ROUNDS
#define FLT_ROUNDS SL_FLOAT_ROUNDS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// FLT_EVAL_METHOD
#define FLT_EVAL_METHOD SL_FLOAT_EVAL_METHOD
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// <type>_HAS_SUBNORM
#define FLT_HAS_SUBNORM SL_FLOAT_FLOAT_HAS_SUBNORM
#define DBL_HAS_SUBNORM SL_FLOAT_DOUBLE_HAS_SUBNORM
#define LDBL_HAS_SUBNORM SL_FLOAT_LONG_DOUBLE_HAS_SUBNORM
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Floating point specs
#define FLT_RADIX SL_FLOAT_G_RADIX
#define DECIMAL_DIG SL_FLOAT_G_DECIMAL_DIG
// float
#define FLT_MANT_DIG SL_FLOAT_MANT_DIG
#define FLT_DECIMAL_DIG SL_FLOAT_DECIMAL_DIG
#define FLT_DIG SL_FLOAT_DIG
#define FLT_MIN_EXP SL_FLOAT_MIN_EXP
#define FLT_MIN_10_EXP SL_FLOAT_MIN_10_EXP
#define FLT_MAX_EXP SL_FLOAT_MAX_EXP
#define FLT_MAX_10_EXP SL_FLOAT_MAX_10_EXP
#define FLT_EPSILON SL_FLOAT_EPSILON
#define FLT_MIN SL_FLOAT_MIN
#define FLT_MAX SL_FLOAT_MAX
#define FLT_TRUE_MIN SL_FLOAT_TRUE_MIN
// double
#define DBL_MANT_DIG SL_DOUBLE_MANT_DIG
#define DBL_DECIMAL_DIG SL_DOUBLE_DECIMAL_DIG
#define DBL_DIG SL_DOUBLE_DIG
#define DBL_MIN_EXP SL_DOUBLE_MIN_EXP
#define DBL_MIN_10_EXP SL_DOUBLE_MIN_10_EXP
#define DBL_MAX_EXP SL_DOUBLE_MAX_EXP
#define DBL_MAX_10_EXP SL_DOUBLE_MAX_10_EXP
#define DBL_EPSILON SL_DOUBLE_EPSILON
#define DBL_MIN SL_DOUBLE_MIN
#define DBL_MAX SL_DOUBLE_MAX
#define DBL_TRUE_MIN SL_DOUBLE_TRUE_MIN
// long double
#define LDBL_MANT_DIG SL_LDOUBLE_MANT_DIG
#define LDBL_DECIMAL_DIG SL_LDOUBLE_DECIMAL_DIG
#define LDBL_DIG SL_LDOUBLE_DIG
#define LDBL_MIN_EXP SL_LDOUBLE_MIN_EXP
#define LDBL_MIN_10_EXP SL_LDOUBLE_MIN_10_EXP
#define LDBL_MAX_EXP SL_LDOUBLE_MAX_EXP
#define LDBL_MAX_10_EXP SL_LDOUBLE_MAX_10_EXP
#define LDBL_EPSILON SL_LDOUBLE_EPSILON
#define LDBL_MIN SL_LDOUBLE_MIN
#define LDBL_MAX SL_LDOUBLE_MAX
#define LDBL_TRUE_MIN SL_LDOUBLE_TRUE_MIN
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_FLOAT_H_ */

//-<EOF>
