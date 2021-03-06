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
// locale.h
//------------------------------------------------------------------------------
// Standard locale implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_LOCALE_H__
#define __SL_STDC_IMPL_LOCALE_H__

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// struct lconv
//
// Members related to numeric formatting
//
struct lconv 
{
  char* decimal_point;
  char* thousands_sep;
  char* grouping;
  char* mon_decimal_point;
  char* mon_thousands_sep;
  char* mon_grouping;
  char* positive_sign;
  char* negative_sign;
  char* currency_symbol;
  char frac_digits;
  char p_cs_precedes;
  char n_cs_precedes;
  char p_sep_by_space;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char* int_curr_symbol;
  char int_frac_digits;
  char int_p_cs_precedes;
  char int_n_cs_precedes;
  char int_p_sep_by_space;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};

typedef struct lconv lconv;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Locale macros
//  
#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Locale control functions
//
char* setlocale(int category, const char* locale);
lconv* localeconv();
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_LOCALE_H__ */

//-<EOF>
