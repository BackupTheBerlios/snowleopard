/*==============================================================================
  Lynx Typesetting System
  
  Copyright (C) 2010-2012 Roel Sergeant
  
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
// ltbl_main.cpp
//------------------------------------------------------------------------------
// main function of the ltbl program of the Lynx typesetting system.
//------------------------------------------------------------------------------

#include <cstdlib>

#include "driver.hpp"

//------------------------------------------------------------------------------
// main function
//
// This program is the main driver for the Lynx typesetting system. This program
// first checks the input files and parameters and call the appropriate programs
// to typeset a TROFF document.
int main (int argc, char** argv)
{
  using lynx::driver;

  driver d_ (argc, argv);

  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//-<EOF>
