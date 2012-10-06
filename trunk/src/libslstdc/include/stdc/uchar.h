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
// uchar.h
//------------------------------------------------------------------------------
// Standard Unicode character implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_UCHAR_H__
#define __SL_STDC_IMPL_UCHAR_H__

#include <config/config.h>

#include <stddef.h>

//------------------------------------------------------------------------------
// Restartable multibyte/wide conversion functions
size_t mbrtoc16(
		char16_t* restrict pc16,
		const char* restrict s,
		size_t n,
		mbstate_t* restrict ps
		);
size_t c16rtomb(char * restrict s, char16_t c16, mbstate_t * restrict ps);
size_t mbrtoc32(
		char32_t* restrict pc32,
		const char* restrict s,
		size_t n,
		mbstate_t* restrict ps
		);
size_t c32rtomb(char * restrict s, char32_t c16, mbstate_t * restrict ps);
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_UCHAR_H__ */

//-<EOF>
