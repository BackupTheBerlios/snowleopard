/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2012 Roel Sergeant
  
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
// error_codes.c
//------------------------------------------------------------------------------
// Error codes for the compiler front end.
//------------------------------------------------------------------------------

#include "error_codes.h"

//------------------------------------------------------------------------------
// Error type description list.
char* error_type_list_[] = {
  "No error occured",
  "FATAL ERROR",
  "INTERNAL COMPILER ERROR", 
  "Unimplemented Feature",
  "Preprocessor Error",
  "Source Error",
  "Code Generation Error", 
  "Runtime Error"
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error descriptions list.
slcc_error_description error_description_list_[] = {

  /* No error occured */
  {"No error occured", 0, ET_NO_ERROR},

  /* Compiler runtime error */		
  {"Invalid arguments provided", 0, ET_FATAL}

  /* Preprocessor errors */
  
  /* Compile errors */
  
  /* Code generation errors */
  
  /* Executor runtime errors */

};
//------------------------------------------------------------------------------

//-<EOF>
