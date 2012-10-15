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

#include "error.h"
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

//------------------------------------------------------------------------------
// Error list array
slcc_error_array* error_list_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// err_initialize function
//
// Initializes the error handler.
//
bool err_initialize ()
{
  if ((error_list_ = tc_array_new_ea ()) == NULL)
    return false;

  err_store (EC_NO_ERROR, NULL, NULL, NULL);

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// err_cleanup function
//
// Cleanup the error handler.
//
void err_cleanup ()
{
  tc_array_delete_ea (error_list_);
}
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

//------------------------------------------------------------------------------
// err_get_fatal_first_error function
//
// Get the error code for the first error that caused the compilation to be 
// aborted.
//
slcc_error_code err_get_code_of_first_fatal_error ()
{
  slcc_error* error = err_get_first_error_of_type (ET_FATAL);
  if (error->code == EC_NO_ERROR)
    error = err_get_first_error_of_type (ET_INTERNAL);

  return error->code;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// err_get_first_error_of_type function
//
// Returns the error object of the first error of the type given.
//
slcc_error* err_get_first_error_of_type (slcc_error_type type)
{
  for (size_t i = 0; i < error_list_->used_; i++)
    if (error_description_list_[error_list_->data_[i]->code].type == type)
      return error_list_->data_[i];

  return error_list_->data_[0];
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
  error->arg1 = arg1 == NULL ? NULL : tc_copy_string (arg1);
  error->arg2 = arg2 == NULL ? NULL : tc_copy_string (arg2);
  error->arg3 = arg3 == NULL ? NULL : tc_copy_string (arg3);

  tc_array_add_ea (error_list_, error);

  return error;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
