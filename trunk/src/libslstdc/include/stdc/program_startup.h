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
// program_startup.h
//------------------------------------------------------------------------------
// Program startup routines for the standard library.
//------------------------------------------------------------------------------

#ifndef __SL_STDC_PROGRAM_STARTUP_H__
#define __SL_STDC_PROGRAM_STARTUP_H__

#include <stdc/private/program_globals.h>

//------------------------------------------------------------------------------
// Startup parameters
int __SL_NoStandardStreams;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Library prototypes
int _SL_Main();
int _SL_Terminate(int retval);
void _SL_Startup_InitializeStandardStreams();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// main function prototype
int main(int argc, char** argv);
//------------------------------------------------------------------------------

#endif /* _SL_STDC_PROGRAM_STARTUP_H_ */

//-<EOF>
