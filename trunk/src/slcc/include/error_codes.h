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
// error_codes.h
//------------------------------------------------------------------------------
// Error codes for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_ERROR_CODES_H__
#define __SL_SLCC_ERROR_CODES_H__

#include <stddef.h>

//------------------------------------------------------------------------------
// slcc_error_type enum
//
enum slcc_error_type
  {
    ET_NO_ERROR = 0,  /* No error occured */

    /* Internal errors */
    ET_FATAL,         /* Fatal errors */
    ET_INTERNAL,      /* Internal compiler error */

    /* Compile errors */
    ET_UNIMPLEMENTED, /* Unimplemented feature */
    ET_PREPROCESS,    /* Preprocessor error */
    ET_COMPILE,       /* Compilation/Source analysis error */
    ET_CODEGEN,       /* Code generation error */
    ET_RUNTIME        /* Runtime error */      
  };

typedef enum slcc_error_type slcc_error_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// error_type_list array
//
// Error type descritpion list (Sorted in the order of the slci_error_type 
// enum)
//
extern char* error_type_list_[];
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slci_error_code enumeration
//
enum slcc_error_code 
  {

    /* No error occured */
    EC_NO_ERROR = 0,

    /* Compiler runtime errors */
    EC_INCOMPLETE_ARG,   /* Incomplete argument supplied */
    EC_INVALID_ARG,      /* Invalid argument supplied */
    EC_NO_SOURCE_FILE    /* No source file provided */

    /* Preprocessor errors */
    
    /* Compile errors */

    /* Code generation errors */
    
    /* Executor runtime errors */

  };

typedef enum slcc_error_code slcc_error_code;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_error_description struct
//
struct slcc_error_description
{
  char* description;
  size_t nr_of_arguments;
  slcc_error_type type;
};

typedef struct slcc_error_description slcc_error_description;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// error_description_list array
// 
// Error description list (Sorted in the order of the slci_error_code enum)
//
extern slcc_error_description error_description_list_[];
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_ERROR_CODES_H__ */

//-<EOF>