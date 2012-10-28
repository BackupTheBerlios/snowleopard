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
// xtoupper.c
//------------------------------------------------------------------------------
// Standard character type implementation. This file implements the globals
// needed for the toupper function.
//------------------------------------------------------------------------------

#include <ctype.h>
#include <limits.h>
#include <stdio.h>

//------------------------------------------------------------------------------
// Check if the table is valid for this environment.
//
#if EOF != -1
# error _ToUpper is incorrect for this environment ( sl_str(EOF) != -1)
#endif

#if UCHAR_MAX != 255
# error _ToUpper is incorrect for this environment
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// CType macros
//
#define CT_XDI (_CT_DI | _CT_XD)
#define CT_XLO (_CT_LO | _CT_XD)
#define CT_XUP (_CT_UP | _CT_XD)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ctype_ table
//
// This table contains for all characters the correct mapping from upper to 
// lower case.
//
static const short ctype_[257] = 
  {
    0, /* EOF */
    _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, 
    _CT_BB, _CT_CN, _CT_CN, _CT_CN, _CT_CN, _CT_CN, _CT_BB, _CT_BB, 
    _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, 
    _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, _CT_BB, 
    _CT_SP, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, 
    _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, 
    CT_XDI, CT_XDI, CT_XDI, CT_XDI, CT_XDI, CT_XDI, CT_XDI, CT_XDI, 
    CT_XDI, CT_XDI, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, 
    _CT_PU, CT_XUP, CT_XUP, CT_XUP, CT_XUP, CT_XUP, CT_XUP, _CT_UP, 
    _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, 
    _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, _CT_UP, 
    _CT_UP, _CT_UP, _CT_UP, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_PU, 
    _CT_PU, CT_XLO, CT_XLO, CT_XLO, CT_XLO, CT_XLO, CT_XLO, _CT_LO, 
    _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, 
    _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, _CT_LO, 
    _CT_LO, _CT_LO, _CT_LO, _CT_PU, _CT_PU, _CT_PU, _CT_PU, _CT_BB
  };
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _CType pointer
//
// Pointer into the ctype_ table.
//
const short* _CType = &ctype_[1];
//------------------------------------------------------------------------------

//-<EOF>
