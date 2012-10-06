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
// program_startup.c.h
//------------------------------------------------------------------------------
// In the file containing the main function, the compiler will include this
// file so proper initialization is performed before main is called. If a file
// containing main is compiled with SL_NO_PROGRAM_STARTUP, the developer needs
// to define the following functions
//    - int _SL_Main()
//    - int _SL_Terminate()
// and optionally all functions defined in this file.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// If SL_NO_STANDARD_STREAMS is defined, do not initialize standard streams.
#ifndef __SL_NO_STANDARD_STREAMS__
  __SL_NoStandardStreams = 1;
#else
  __SL_NoStandardStreams = 0;
#endif /* !__SL_NO_STANDARD_STREAMS__ */
//------------------------------------------------------------------------------

//-<EOF>
