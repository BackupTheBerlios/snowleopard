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
// limits.h
//------------------------------------------------------------------------------
// Standard limits implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_LIMITS_H_
#define _SL_STDC_IMPL_LIMITS_H_

#include <sl/config/config.h>

//------------------------------------------------------------------------------
// Character types
#define CHAR_BIT SL_CHAR_BITS
#define SCHAR_MIN SL_SCHAR_MIN
#define SCHAR_MAX SL_SCHAR_MAX
#define UCHAR_MAX SL_UCHAR_MAX
#if SL_CHAR_IS_SIGNED == 0
# define CHAR_MIN SCHAR_MIN
# define CHAR_MAX SCHAR_MAX
#else /* SL_CHAR_IS_SIGNED == 0 */
# define CHAR_MIN 0
# define CHAR_MAX UCHAR_MAX
#endif /* SL_CHAR_IS_SIGNED == 0 */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Maximum bytes in multibyte character
#define MB_LEN_MAX SL_WCHAR_MAX_BYTES
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Integer types
#define SHRT_MIN SL_SHRT_MIN
#define SHRT_MAX SL_SHRT_MAX
#define USHRT_MAX SL_USHRT_MAX
#define INT_MIN SL_INT_MIN
#define INT_MAX SL_INT_MAX
#define UINT_MAX SL_UINT_MAX
#define LONG_MIN SL_LONG_MIN
#define LONG_MAX SL_LONG_MAX
#define ULONG_MAX SL_ULONG_MAX
#define LLONG_MIN SL_LLONG_MIN
#define LLONG_MAX SL_LLONG_MAX
#define ULLONG_MAX SL_ULLONG_MAX
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_LIMITS_H_ */

//-<EOF>
