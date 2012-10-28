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
// isprint.c
//------------------------------------------------------------------------------
// Standard character type implementation. This file contains the isprint
// function.
//------------------------------------------------------------------------------

#include <ctype.h>

//------------------------------------------------------------------------------
// isprint function
//
// Test is a character is a printable character.
//
int (isprint) (int c)
{
  return (_CType[c] & (_CT_DI | _CT_LO | _CT_PU | _CT_SP | _CT_UP | _CT_XA));
}
//------------------------------------------------------------------------------

//-<EOF>
