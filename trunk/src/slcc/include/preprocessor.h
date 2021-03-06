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
// preprocessor.h
//------------------------------------------------------------------------------
// Preprocessor for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_PREPROCESSOR_H__
#define __SL_SLCC_PREPROCESSOR_H__

#include <stdbool.h>

#include "strings.h"

//------------------------------------------------------------------------------
// Initialization functions
bool pp_initialize ();
void pp_cleanup ();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Preprocessor functions
bool pp_is_skipping_code ();
bool pp_is_function (const slcc_string* identifier);
bool pp_is_symbol (const slcc_string* identifier);
bool pp_process_directive (const slcc_string* s);
void pp_process_function (const slcc_string* s);
void pp_process_string (const slcc_string* s);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_PREPROCESSOR_H__ */

//-<EOF>
