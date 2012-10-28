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
// isblank.c
//------------------------------------------------------------------------------
// Standard character type implementation. This file contains the isblank
// function.
//------------------------------------------------------------------------------

#include <ctype.h>

//------------------------------------------------------------------------------
// isblank function
//
// Test is a character is whitespace.
//
int (isblank) (int c)
{
  return (_CType[c] & (_CT_CN | _CT_SP));
}
//------------------------------------------------------------------------------

//-<EOF>
