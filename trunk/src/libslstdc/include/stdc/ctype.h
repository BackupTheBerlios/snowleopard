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

#include <sl/config/config.h>

//------------------------------------------------------------------------------
// Character classification functions.
int isalnum(int c);
int isalpha(int c);
int isblank(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Character case mapping functions.
int tolower(int c);
int toupper(int c);
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_CTYPE_H_ */

//-<EOF>
