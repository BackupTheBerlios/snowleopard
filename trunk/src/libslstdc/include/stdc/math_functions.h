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
// math_functions.h
//------------------------------------------------------------------------------
// Standard math implementation: Function prototypes
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_MATH_FUNCTIONS_H__
#define __SL_STDC_IMPL_MATH_FUNCTIONS_H__

//------------------------------------------------------------------------------
// Trigonometric functions
//
// acos
double acos (double x);
float acosf (float x);
long double acosl (long double x);
// asin
double asin (double x);
float asinf (float x);
long double asinl (long double x);
// atan
double atan (double x);
float atanf (float x);
long double atanl (long double x);
// atan2
double atan2 (double y, double x);
float atan2f (float y, float x);
long double atan2l (long double y, long double x);
// cos
double cos (double x);
float cosf (float x);
long double cosl (long double x);
// sin
double sin (double x);
float sinf (float x);
long double sinl (long double x);
// tan
double tan (double x);
float tanf (float x);
long double tanl (long double x);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Hyperbolic functions
//
// acosh
double acosh (double x);
float acoshf (float x);
long double acoshl (long double x);
// asinh
double asinh (double x);
float asinhf (float x);
long double asinhl (long double x);
// atanh
double atanh (double x);
float atanhf (float x);
long double atanhl (long double x);
// cosh
double cosh (double x);
float coshf (float x);
long double coshl (long double x);
// sinh
double sinh (double x);
float sinhf (float x);
long double sinhl (long double x);
// tanh
double tanh (double x);
float tanhf (float x);
long double tanhl (long double x);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exponential and logarithmic functions
//
// exp
double exp (double x);
float expf (float x);
long double expl (long double x);
// exp2
double exp2 (double x);
float exp2f (float x);
long double exp2l (long double x);
// expm1
double expm1 (double x);
float expm1f (float x);
long double expm1l (long double x);
// frexp
double frexp (double value, int* exp);
float frexpf (float value, int* exp);
long double frexpl (long double value, int* exp);
// ilogb
int ilogb (double x);
int ilogbf (float x);
int ilogbl (long double x);
// ldexp
double ldexp (double x, int exp);
float ldexpf (float x, int exp);
long double ldexpl (long double x, int exp);
// log
double log (double x);
float logf (float x);
long double logl (long double x);
// log10
double log10 (double x);
float log10f (float x);
long double log10l (long double x);
// log1p
double log1p (double x);
float log1pf (float x);
long double log1pl (long double x);
// log2
double log2 (double x);
float log2f (float x);
long double log2l (long double x);
// logb
double logb (double x);
float logbf (float x);
long double logbl (long double x);
// modf functions
double modf (double value, double* iptr);
float modff (float value, float* iptr);
long double modfl (long double value, long double* iptr);
// scalbn
double scalbn (double x, int n);
float scalbnf (float x, int n);
long double scalbnl (long double x, int n);
// scalbln
double scalbln (double x, long n);
float scalblnf (float x, long n);
long double scalblnl (long double x, long n);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Power and absolute value functions
//
// cbrt
double cbrt (double x);
float cbrtf (float x);
long double cbrtl (long double x);
// fabs
double fabs (double x);
float fabsf (float x);
long double fabsl (long double x);
// hypot
double hypot (double x, double y);
float hypotf (float x, float y);
long double hypotl (long double x, long double y);
// pow
double pow (double x, double y);
float powf (float x, float y);
long double powl (long double x, long double y);
// sqrt
double sqrt (double x);
float sqrtf (float x);
long double sqrtl (long double x);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error and gamma functions
//
// erf
double erf (double x);
float erff (float x);
long double erfl (long double x);
// erfc
double erfc (double x);
float erfcf (float x);
long double erfcl (long double x);
// lgamma
double lgamma (double x);
float lgammaf (float x);
long double lgammal (long double x);
// tgamma
double tgamma (double x);
float tgammaf (float x);
long double tgammal (long double x);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Nearest integer functions
//
// ceil
double ceil (double x);
float ceilf (float x);
long double ceill (long double x);
// floor
double floor (double x);
float floorf (float x);
long double floorl (long double x);
// nearbyint
double nearbyint (double x);
float nearbyintf (float x);
long double nearbyintl (long double x);
// rint
double rint (double x);
float rintf (float x);
long double rintl (long double x);
// lrint
long lrint (double x);
long lrintf (float x);
long lrintl (long double x);
// llrint
long long llrint (double x);
long long llrintf (float x);
long long llrintl (long double x);
// round
double round (double x);
float roundf (float x);
long double roundl (long double x);
// lround
long lround (double x);
long lroundf (float x);
long lroundl (long double x);
// llround
long long llround (double x);
long long llroundf (float x);
long long llroundl (long double x);
// trunc
double trunc (double x);
float truncf (float x);
long double truncl (long double x);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Remainder functions
//
// fmod
double fmod (double x, double y);
float fmodf (float x, float y);
long double fmodl (long double x, long double y);
// remainder
double remainder (double x, double y);
float remainderf (float x, float y);
long double remainderl (long double x, long double y);
// remquo
double remquo (double x, double y, int* quo);
float remquof (float x, float y, int* quo);
long double remquol (long double x, long double y, int* quo);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Manipulation functions
//
// copysign
double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);
// nan
double nan(const char* tagp);
float nanf(const char* tagp);
long double nanl(const char* tagp);
// nextafter
double nextafter(double x, double y);
float nextafterf(float x, float y);
long double nextafterl(long double x, long double y);
// nexttoward
double nexttoward(double x, double y);
float nexttowardf(float x, float y);
long double nexttowardl(long double x, long double y);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Maximum, minimum and positive difference functions
//
// fdim
double fdim(double x, double y);
float fdimf(float x, float y);
long double fdiml(long double x, long double y);
// fmax
double fmax(double x, double y);
float fmaxf(float x, float y);
long double fmaxl(long double x, long double y);
// fmin
double fmin(double x, double y);
float fminf(float x, float y);
long double fminl(long double x, long double y);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Floating point multiply/add
//
// fma
double fma(double x, double y, double z);
float fmaf(float x, float y, float z);
long double fmal(long double x, long double y, long double z);
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_MATH_FUNCTIONS_H__ */

//-<EOF>
