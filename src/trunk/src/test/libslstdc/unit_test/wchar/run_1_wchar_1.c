/*==============================================================================
  Snow Leopard Standard C Library
  
  Copyright (C) 2011, 2012 Roel Sergeant
  
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
// run_1_wchar_1.c
//------------------------------------------------------------------------------
// Tests for cwchar header. These tests cover min & max
//------------------------------------------------------------------------------

#include <wchar.h>

int main ()
{
  mbstate_t x;

  x.count = 1;
  x.value.wch = 12;
  
  if (x.count == 1)
    x.value.wchb[0] = 24;
}

//-<EOF>

