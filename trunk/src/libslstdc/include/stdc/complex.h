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
// complex.h
//------------------------------------------------------------------------------
// Standard complex numbers implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_COMPLEX_H__
#define __SL_STDC_IMPL_COMPLEX_H__

#include <sl/config/config.h>

//------------------------------------------------------------------------------
// complex macro
#define complex __SL_COMPLEX_T
#define _Complex_I __SL_COMPLEX_I
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// imaginary macro
#ifdef __SL_IMAGINARY_T
# define imaginary __SL_IMAGINARY_T
# define _Imaginary_I __SL_IMAGINARY_I
#endif /* __SL_IMAGINARY_T */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// I macro
#ifdef __SL_IMAGINARY_T
# define I _Imaginary_I
#else /* __SL_IMAGINARY_T */
# define I _Complex_I
#endif /* __SL_IMAGINARY_T */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// CX_LIMITED_RANGE pragma
#pragma STDC CX_LIMITED_RANGE __SL_CX_LIMITED_RANGE
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Trigonometric functions
//
// cacos functions
double complex cacos(double complex z);
float complex cacosf(float complex z);
long double complex cacosl(long double complex z);
// casin functions
double complex casin(double complex z);
float complex casinf(float complex z);
long double complex sasinl(long double complex z);
// catan functions
double complex catan(double complex z);
float complex catanf(float complex z);
long double complex catanl(long double complex z);
// ccos functions
double complex ccos(double complex z);
float complex ccosf(float complex z);
long double complex ccosl(long double complex z);
// csin functions
double complex csin(double complex z);
float complex csinf(float complex z);
long double complex csinl(long double complex z);
// ctan functions
double complex ctan(double complex z);
float complex ctanf(float complex z);
long double complex ctanl(long double complex z);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Hyperbolic functions
//
// cacosh functions
double complex cacosh(double complex z);
float complex cacoshf(float complex z);
long double complex cacoshl(long double complex z);
// casinh functions
double complex casinh(double complex z);
float complex casinhf(float complex z);
long double complex sasinhl(long double complex z);
// catanh functions
double complex catanh(double complex z);
float complex catanhf(float complex z);
long double complex catanhl(long double complex z);
// ccosh functions
double complex ccosh(double complex z);
float complex ccoshf(float complex z);
long double complex ccoshl(long double complex z);
// csinh functions
double complex csinh(double complex z);
float complex csinhf(float complex z);
long double complex csinhl(long double complex z);
// ctanh functions
double complex ctanh(double complex z);
float complex ctanhf(float complex z);
long double complex ctanhl(long double complex z);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exponential and logarithmic functions
//
// cexp functions
double complex cexp(double complex z);
float complex cexpf(float complex z);
long double complex cexpl(long double complex z);
// clog functions
double complex clog(double complex z);
float complex clogf(float complex z);
long double complex clogl(long double complex z);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Power and absolute functions
//
// cabs functions
double complex cabs(double complex z);
float complex cabsf(float complex z);
long double complex cabsl(long double complex z);
// cpow functions
double complex cpow(double complex x, double complex y);
float complex cpowf(float complex x, float complex y);
long double complex cpowl(long double complex x, long double complex y);
// csqrt functions
double complex csqrt(double complex z);
float complex csqrtf(float complex z);
long double complex csqrtl(long double complex z);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Manipulation functions
//
// carg functions
double carg(double complex z);
float cargf(float complex z);
long double cargl(long double complex z);
// cimag functions
double cimag(double complex z);
float cimagf(float complex z);
long double cimagl(long double complex z);
// CMPLX macros
#define CMPLX(x,y) ((double complex)((double)(x)+                       \
                                     _Imaginary_I * (double)(y)))
#define CMPLXF(x,y) ((float complex)((float)(x)+                        \
                                     _Imaginary_I * (float)(y)))
#define CMPLXL(x,y) ((long double complex)((long double)(x)+            \
                                           _Imaginary_I * (long double)(y)))
// conj functions
double complex conj(double complex z);
float complex conjf(float complex z);
long double complex conjl(long double complex z);
// cproj functions
double complex cproj(double complex z);
float complex cprojf(float complex z);
long double complex cprojl(long double complex z);
// creal functions
double creal(double complex z);
float crealf(float complex z);
long double creall(long double complex z);
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_COMPLEX_H__ */

//-<EOF>
