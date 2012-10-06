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
// math_classification.h
//------------------------------------------------------------------------------
// Standard math implementation: Classification/comparison macros
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_MATH_CLASSIFICATION_H__
#define __SL_STDC_IMPL_MATH_CLASSIFICATION_H__

#include <config/config.h>
#include <config/typed_call_macros.h>

//------------------------------------------------------------------------------
// Number classification macros
#define FP_INFINITE  0
#define FP_NAN       1
#define FP_NORMAL    2
#define FP_SUBNORMAL 3
#define FP_ZERO      4
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// fpclassify macro
#define fpclassify(x)           \
  x == 0.0 ? FP_ZERO            \
      : isnan(x) ? FP_NAN       \
      : isinf(x) ? FP_INFINITE  \
      : isnormal(x) ? FP_NORMAL \
      : FP_SUBNORMAL
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Untyped macros
#define isfinite(arg0) sl_fp_typed_call_1_arg(isfinite,arg0)
#define isinf(arg0) sl_fp_typed_call_1_arg(isinf,arg0)
#define isnan(arg0) sl_fp_typed_call_1_arg(isnan,arg0)
#define isnormal(arg0) sl_fp_typed_call_1_arg(isnormal,arg0)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Typed macros
// float macros
#define isfinitef(x) ((x != __SL_FLOAT_INFINITYF) && (x != __SL_FLOAT_NANF))
#define isinff(x) (x == __SL_FLOAT_INFINITYF)
#define isnanf(x) (x == __SL_FLOAT_NANF)
#define isnormalf(x) (x != __SL_FLOAT_SUBNORMALF)
// double macros
#define isfinited(x) ((x != __SL_FLOAT_INFINITY) && (x != __SL_FLOAT_NAN))
#define isinfd(x) (x == __SL_FLOAT_INFINITY)
#define isnand(x) (x == __SL_FLOAT_NAN)
#define isnormald(x) (x != __SL_FLOAT_SUBNORMAL)
// long double macros
#define isfinitel(x) ((x != __SL_FLOAT_INFINITYL) && (x != __SL_FLOAT_NANL))
#define isinfl(x) (x == __SL_FLOAT_INFINITYL)
#define isnanl(x) (x == __SL_FLOAT_NANL)
#define isnormall(x) (x != __SL_FLOAT_SUBNORMALL)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// signbit macro
#define signbit(x) (x < 0.0)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isgreater macro
#define isgreater(x,y) ((x) > (y))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isgreaterequal macro
#define isgreaterequal(x,y) ((x) >= (y))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isless macro
#define isless(x,y) ((x) < (y))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// islessequal macro
#define islessequal(x,y) ((x) <= (y))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// islessgreater macro
#define islessgreater(x,y) (((x) < (y)) || ((x) > (y)))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isunordered macro
#define isunordered(x,y)       \
  (isnan(x) || isnan(y)) ? 0   \
  : (isinf(x) || isinf(y)) ? 0 \
  : 1
//------------------------------------------------------------------------------

#endif /* __SL_STDC_IMPL_MATH_CLASSIFICATION_H__ */

//-<EOF>
