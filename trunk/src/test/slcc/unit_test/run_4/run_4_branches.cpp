/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
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
// run_4_branches.c
//------------------------------------------------------------------------------
// This program is the fourth program of the Snow Leaopard C++ interpreter test
// suite. It execute some expressions and branches.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// main function
//
int main () 
{
  int x = 2 + 1;
  x = x - 1;

  int y = 12 * x;

  if (y > x)
    y = x;

  if (x == y)
    x = 3;

  if (y > x)
    x = 1;

  return 0;
}
//------------------------------------------------------------------------------

//-<EOF>
