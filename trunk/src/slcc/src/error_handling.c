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
// error_handling.c
//------------------------------------------------------------------------------
// Error handling for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "error_array.h"
#include "error_codes.h"
#include "error_handling.h"
#include "string_functions.h"

//------------------------------------------------------------------------------
// Private functions
slcc_error* err_store (
		       slcc_error_code code, 
		       char* arg1, 
		       char* arg2, 
		       char* arg3
		       );
//------------------------------------------------------------------------------
// Error list array
slcc_error_array* error_list_;
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// err_report function
//
// Report error with up to 3 arguments. If the error is not internal, also store 
// it.
//
slcc_error* err_report (
			slcc_error_code code, 
			char* arg1, 
			char* arg2, 
			char* arg3, 
			bool store
			)
{
  slcc_error* error = NULL;

  if (error_description_list_[code].type != ET_WARNING 
      && error_description_list_[code].type != ET_INTERNAL
      && error_description_list_[code].type != ET_FATAL
      && store == false)
    error = err_store (code, arg1, arg2, arg3);

  if (arg1 == NULL)
    fprintf (stderr, error_description_list_[code].desc);
  else if (arg2 == NULL)
    fprintf (stderr, error_description_list_[code].desc, arg1);
  else if (arg3 == NULL)
    fprintf (stderr, error_description_list_[code].desc, arg1, arg2);
  else
    fprintf (stderr, error_description_list_[code].desc, arg1, arg2, arg3);

  return error;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// err_report_and_exit function
//
// Report error with up to 3 arguments and exit.
//
void err_report_and_exit (
			  slcc_error_code code, 
			  char* arg1, 
			  char* arg2, 
			  char* arg3
			  )
{
  err_report (code, arg1, arg2, arg3, false);

  exit (code);
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// err_store function
//
// Creates an error object and stores it in the error list.
//
slcc_error* err_store (
		       slcc_error_code code,
		       char* arg1,
		       char* arg2,
		       char* arg3
		       )
{
  slcc_error* error = malloc (sizeof (slcc_error));

  error->code = code;
  error->arg1 = arg1 == NULL ? NULL : copy_string (arg1);
  error->arg2 = arg2 == NULL ? NULL : copy_string (arg2);
  error->arg3 = arg3 == NULL ? NULL : copy_string (arg3);

  return error;
}
//------------------------------------------------------------------------------

//-<EOF>
