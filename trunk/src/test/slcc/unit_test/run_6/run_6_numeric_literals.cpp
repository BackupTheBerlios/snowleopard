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
// run_6_numeric_literals.cpp
//------------------------------------------------------------------------------
// This program is the sixth program of the Snow Leaopard C++ interpreter test
// suite. It tests some integer and floating point literals.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// main function
//
int main ()
{
  int i1 = 0;
  int i2 = 012;
  int i3 = 123;
  int i4 = -123123;
  unsigned long i5 = 1234123412341234;
  unsigned long long i6 = 1234512345123451234512345;

  float x1 = 1.2;
  float x2 = -1.2;
  float x3 = 1.23e34;
  double x4 = 13.34E452;

  return 0;
}
//------------------------------------------------------------------------------

//-<EOF>
