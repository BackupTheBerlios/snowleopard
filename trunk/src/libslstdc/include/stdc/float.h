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
// float.h
//------------------------------------------------------------------------------
// Standard float implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_FLOAT_H__
#define __SL_STDC_IMPL_FLOAT_H__

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// FLT_ROUNDS
//
#define FLT_ROUNDS __SL_FLOAT_ROUNDS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// FLT_EVAL_METHOD
//
#define FLT_EVAL_METHOD __SL_FLOAT_EVAL_METHOD
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// <type>_HAS_SUBNORM
//
#define FLT_HAS_SUBNORM __SL_FLOAT_FLOAT_HAS_SUBNORM
#define DBL_HAS_SUBNORM __SL_FLOAT_DOUBLE_HAS_SUBNORM
#define LDBL_HAS_SUBNORM __SL_FLOAT_LONG_DOUBLE_HAS_SUBNORM
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Floating point specs
//
#define FLT_RADIX __SL_FLOAT_G_RADIX
#define DECIMAL_DIG __SL_FLOAT_G_DECIMAL_DIG
//
// float
//
#define FLT_MANT_DIG __SL_FLOAT_MANT_DIG
#define FLT_DECIMAL_DIG __SL_FLOAT_DECIMAL_DIG
#define FLT_DIG __SL_FLOAT_DIG
#define FLT_MIN_EXP __SL_FLOAT_MIN_EXP
#define FLT_MIN_10_EXP __SL_FLOAT_MIN_10_EXP
#define FLT_MAX_EXP __SL_FLOAT_MAX_EXP
#define FLT_MAX_10_EXP __SL_FLOAT_MAX_10_EXP
#define FLT_EPSILON __SL_FLOAT_EPSILON
#define FLT_MIN __SL_FLOAT_MIN
#define FLT_MAX __SL_FLOAT_MAX
#define FLT_TRUE_MIN __SL_FLOAT_TRUE_MIN
//
// double
//
#define DBL_MANT_DIG __SL_DOUBLE_MANT_DIG
#define DBL_DECIMAL_DIG __SL_DOUBLE_DECIMAL_DIG
#define DBL_DIG __SL_DOUBLE_DIG
#define DBL_MIN_EXP __SL_DOUBLE_MIN_EXP
#define DBL_MIN_10_EXP __SL_DOUBLE_MIN_10_EXP
#define DBL_MAX_EXP __SL_DOUBLE_MAX_EXP
#define DBL_MAX_10_EXP __SL_DOUBLE_MAX_10_EXP
#define DBL_EPSILON __SL_DOUBLE_EPSILON
#define DBL_MIN __SL_DOUBLE_MIN
#define DBL_MAX __SL_DOUBLE_MAX
#define DBL_TRUE_MIN __SL_DOUBLE_TRUE_MIN
//
// long double
//
#define LDBL_MANT_DIG __SL_LDOUBLE_MANT_DIG
#define LDBL_DECIMAL_DIG __SL_LDOUBLE_DECIMAL_DIG
#define LDBL_DIG __SL_LDOUBLE_DIG
#define LDBL_MIN_EXP __SL_LDOUBLE_MIN_EXP
#define LDBL_MIN_10_EXP __SL_LDOUBLE_MIN_10_EXP
#define LDBL_MAX_EXP __SL_LDOUBLE_MAX_EXP
#define LDBL_MAX_10_EXP __SL_LDOUBLE_MAX_10_EXP
#define LDBL_EPSILON __SL_LDOUBLE_EPSILON
#define LDBL_MIN __SL_LDOUBLE_MIN
#define LDBL_MAX __SL_LDOUBLE_MAX
#define LDBL_TRUE_MIN __SL_LDOUBLE_TRUE_MIN
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_FLOAT_H__ */

//-<EOF>
