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
// run_1_A7_headers_main.c
//------------------------------------------------------------------------------
// Header example adapted from Unix System Programming - Appendix Example A.7. 
// Program run and output a string. 
//------------------------------------------------------------------------------

//##############################################################################
// SLTST - Config
//
// [build]  = [strict]
// [source] = run_1_A7_headers_main.c run_1_A7_headers_changenum.c
// [result] = [run][no_assert][stdout("num is 20")]
//##############################################################################

#include <stdio.h>

#include "run_1_A7_headers_changenum.h"

//------------------------------------------------------------------------------
// main function
//
int main (void)
{
  num = 10;
  changenum ();

  printf ("num is %d\n", num);

  return 0;
}
//------------------------------------------------------------------------------

//-<EOF>
