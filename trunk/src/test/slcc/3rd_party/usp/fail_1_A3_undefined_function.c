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
// fail_1_A3_undefined_function.c
//------------------------------------------------------------------------------
// Undefined function example adapted from Unix System Programming - Appendix 
// Example A.3. Compilation fails because of an undefined function. 
//------------------------------------------------------------------------------

//##############################################################################
// SLTST - Config
//
// [build]  = [strict]
// [result] = [fail][link:undefined_function (serr)]
//##############################################################################

void serr (char *msg);

//------------------------------------------------------------------------------
// main function
//
int main (void)
{
  serr ("This program does not do much!\n");
  return 0;
}
//------------------------------------------------------------------------------

//-<EOF>
