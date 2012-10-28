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
// tolower.c
//------------------------------------------------------------------------------
// Standard character type implementation. This file contains the tolower
// function.
//------------------------------------------------------------------------------

#include <ctype.h>

//------------------------------------------------------------------------------
// tolower function
//
// If the character is upper case, convert it to lower case.
//
int (tolower) (int c)
{
  return _ToLower[c];
}
//------------------------------------------------------------------------------

//-<EOF>
