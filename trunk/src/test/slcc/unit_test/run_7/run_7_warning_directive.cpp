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
// run_7_warning_directive.c
//------------------------------------------------------------------------------
// This program is the third program of the Snow Leaopard C++ interpreter test
// suite. It is created for testing the #warning directive and handling it in
// the preprocessor.
//------------------------------------------------------------------------------

#warning Before main
//------------------------------------------------------------------------------
// main function
//
int main () 
{
#warning Begin main

#ifdef __SLCC__
# warning We are using slcc
#else
# warning We are not using slcc
#endif

#warning End main
}
//------------------------------------------------------------------------------

//-<EOF>
