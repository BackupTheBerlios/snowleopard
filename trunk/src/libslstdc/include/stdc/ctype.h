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
// ctype.h
//------------------------------------------------------------------------------
// Standard character type implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_CTYPE_H_
#define _SL_STDC_IMPL_CTYPE_H_

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// _CType bits
//
#define _CT_BB 0x80  /* None visible control characters (BEL, BS, ...) */
#define _CT_CN 0x40  /* Visible control characters (CR, FF, HT, NL, VT, ...) */
#define _CT_DI 0x20  /* Numeric digits */
#define _CT_XA 0x200 /* Extra alphabetic */
#define _CT_XS 0x100 /* Extra whitespace */
#define _CT_LO 0x10  /* Lowercase characters */
#define _CT_PU 0x8   /* Punctuation */
#define _CT_SP 0x4   /* Space */
#define _CT_UP 0x2   /* Uppercase characters */
#define _CT_XD 0x1   /* Hexadecimal characters */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
//
extern const short* _CType;
extern const short* _ToLower;
extern const short* _ToUpper;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Character classification functions
//
int isalnum (int c);
int isalpha (int c);
int isblank (int c);
int iscntrl (int c);
int isdigit (int c);
int isgraph (int c);
int islower (int c);
int isprint (int c);
int ispunct (int c);
int isspace (int c);
int isupper (int c);
int isxdigit (int c);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Character case mapping functions
//
int tolower (int c);
int toupper (int c);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Character classification macros
//
#define isalnum(c) (_CType[(int)(c)] & (_CT_DI | _CT_LO | _CT_UP | _CT_XA))
#define isalpha(c) (_CType[(int)(c)] & (_CT_LO | _CT_UP | _CT_XA))
#define isblank(c) (_CType[(int)(c)] & (_CT_CN | _CT_SP | _CT_XS))
#define iscntrl(c) (_CType[(int)(c)] & (_CT_BB | _CT_CN))
#define isdigit(c) (_CType[(int)(c)] & _CT_BI)
#define isgraph(c) (_CType[(int)(c)]					\
		    & (_CT_DI | _CT_LO | _CT_PU | _CT_UP | _CT_XA))
#define islower(c) (_CType[(int)(c)] & _CT_LO)
#define isprint(c) (_CType[(int)(c)]					\
		    & (_CT_DI | _CT_LO | _CT_PU | _CT_SP | _CT_UP | _CT_XA))
#define ispunct(c) (_CType[(int)(c)] & _CT_PU)
#define isspace(c) (isblank(c))
#define isupper(c) (_CType[(int)(c)] & _CT_UP)
#define isxdigit(c) (_CType[(int)(c)] & (_CT_XD)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Character case mapping macros
//
#define tolower(c) _ToLower[(int)(c)]
#define toupper(c) _ToUpper[(int)(c)]
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_CTYPE_H_ */

//-<EOF>
