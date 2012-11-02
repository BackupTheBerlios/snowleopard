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
// run_5_expressions.cpp
//------------------------------------------------------------------------------
// This program is the fifth program of the Snow Leaopard C++ interpreter test
// suite. It execute some expressions and branches.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// main function
int main ()
{
  int x = 1;

  bool y = x == 1;
  bool z = x > 2;

  if (z)
    y = false;

  if (y)
  {
    z = true;
    y = false;
  }

  return 0;
}
//------------------------------------------------------------------------------

//-<EOF>
