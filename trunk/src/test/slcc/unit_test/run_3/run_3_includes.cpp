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
// run_3_includes.c
//------------------------------------------------------------------------------
// This program is the third program of the Snow Leaopard C++ interpreter test
// suite. It includes some headers and perform a branch on a boolean value.
//------------------------------------------------------------------------------

#include <cstdbool>
#include <cstddef>
#include <cstdlib>

//------------------------------------------------------------------------------
// main function
//
int main () 
{
  int i = EXIT_FAILURE;
  bool ok = i == EXIT_SUCCESS;

  if (ok)
    return EXIT_SUCCESS;

  return EXIT_FAILURE;
}
//------------------------------------------------------------------------------

//-<EOF>
