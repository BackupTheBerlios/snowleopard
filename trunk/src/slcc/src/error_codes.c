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
  "FATAL",
  "ICE", 
  "Warning",
  "Unimplemented Feature",
  "Preprocessor Error",
  "Preprocessor FATAL",
  "Preprocessor Warning", 
  "Source Error",
  "Source Warning", 
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
  {"Code generator initialization failed", 0, ET_FATAL},
  {"C++ option given on a C source file", 0, ET_FATAL},
  {"Driver initialization failed", 0, ET_FATAL},
  {"Error handling error", 0, ET_FATAL},
  {"File %s doesn't exist or is not accessible", 1, ET_FATAL},
  {"Incomplete argument provided", 0, ET_FATAL},
  {"Invalid argument provided", 0, ET_FATAL},
  {"Source file %s has no valid extension", 1, ET_FATAL},
  {"No error message is available for code %s", 0, ET_FATAL},
  {"No objects or source file provided", 0, ET_FATAL}, 
  {"No source file provided", 0, ET_FATAL},
  {"Path %s doesn't exist or is not accessible", 1, ET_FATAL},
  {"Parser initialization failed", 0, ET_FATAL},
  {"Source file %s doesn't exist or is not accessible", 1, ET_FATAL}, 
  {"Duplicate symbol table entry: \"%s\" != \"%s\"", 2, ET_INTERNAL},
  {"Load of symbol table built-ins failed", 0, ET_INTERNAL},
  {"The include path %s is used twice, this one is ignored", 1, ET_WARNING},
  {"Multiple output files: %s is used, %s is ignored", 2, ET_WARNING},

  /* Preprocessor errors */
  {"Error directive, aborting with \"%s\"", 1, ET_PREPROCESS_FATAL},
  {"Invalid preprocessor directive in \"%s\"", 1, ET_PREPROCESS},

  /* Compile errors */
  {"Invalid character in char literal \"%s\"", 1, ET_COMPILE},
  {"Invalid character literal \"%s\"", 1, ET_COMPILE},
  {"The hexadecimal literal '%s' is not a valid char literal", 1, ET_COMPILE},
  {"The octal literal '%s' is not a valid char literal", 1, ET_COMPILE}, 
  {"Invalid wide character literal \"%s\"", 1, ET_COMPILE},
  {"char16_t handling is not implemented", 1, ET_UNIMPLEMENTED},
  {"char32_t handling is not implemented", 1, ET_UNIMPLEMENTED},
  {"wchar_t handling is not implemented", 1, ET_UNIMPLEMENTED}

  /* Code generation errors */
  
  /* Executor runtime errors */

};
//------------------------------------------------------------------------------

//-<EOF>
