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
#include "source_position.h"
#include "types.h"

#include "string_functions.h"

//------------------------------------------------------------------------------
// Private functions
//
char* err_prepare_compiler_message (
				    slcc_error_code code,
				    char* arg1,
				    char* arg2,
				    char* arg3
				    );
slcc_error* err_store (
		       slcc_error_code code, 
		       slcc_source_position pos, 
		       char* arg1, 
		       char* arg2, 
		       char* arg3
		       );
char* src_err_prepare_source_message (
				      slcc_error_code code,
				      slcc_source_position pos,
				      char* arg1,
				      char* arg2,
				      char* arg3
				      );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error list array
//
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

  err_store (EC_NO_ERROR, NoSourcePosition, NULL, NULL, NULL);

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
      && error_description_list_[code].type != ET_UNIMPLEMENTED
      && store == false)
    error = err_store (code, NoSourcePosition, arg1, arg2, arg3);

  char* message = err_prepare_compiler_message (code, arg1, arg2, arg3);

  if (message == NULL)
    {
      char* s_code = malloc (sizeof (char) * MaxErrorMessageSize);
      sprintf (s_code, "%u", code);
      message = err_prepare_compiler_message (
					      EC_NO_ERROR_MESSAGE, 
					      s_code, 
					      arg2, 
					      arg3
					      );
      free (s_code);
    }

  fprintf (stderr, "%s\n", message);

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

//------------------------------------------------------------------------------
// src_err_report function
//
// Reports a source code error and includes a source position.
//
slcc_error* src_err_report (
			    slcc_error_code code,
			    slcc_source_position pos,
			    char* arg1,
			    char* arg2,
			    char* arg3
			    )
{
  slcc_error* error = NULL;

  if (error_description_list_[code].type != ET_WARNING 
      && error_description_list_[code].type != ET_INTERNAL
      && error_description_list_[code].type != ET_FATAL)
    error = err_store (code, pos, arg1, arg2, arg3);

  char* message = src_err_prepare_source_message (code, pos, arg1, arg2, arg3);

  if (message == NULL)
    {
      char* s_code = malloc (sizeof (char) * MaxErrorMessageSize);
      sprintf (s_code, "%u", code);
      message = err_prepare_compiler_message (
					      EC_NO_ERROR_MESSAGE, 
					      s_code, 
					      arg2, 
					      arg3
					      );
      free (s_code);
    }

  fprintf (stderr, "%s\n", message);

  if (error_description_list_[code].type == ET_PREPROCESS_FATAL)
    exit (code);

  return error;  
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// err_prepare_compiler_message function
//
// Prepares the message string for reporting a non source code error.
//
char* err_prepare_compiler_message (
				    slcc_error_code code,
				    char* arg1,
				    char* arg2,
				    char* arg3
				    )
{
  char* format = malloc (sizeof (char) * MaxErrorMessageSize);
  char* message = malloc (sizeof (char) * MaxErrorMessageSize);

  if (format == NULL || message == NULL)
    return NULL;

  snprintf (
	    format,
	    MaxErrorMessageSize,
	    "%s: %s\n", 
	    error_type_list_[error_description_list_[code].type],
	    error_description_list_[code].desc
	    );
	    
  if (arg1 == NULL)
    snprintf (message, MaxErrorMessageSize, format);
  else if (arg2 == NULL)
    snprintf (message, MaxErrorMessageSize, format, arg1);
  else if (arg3 == NULL)
    snprintf (message, MaxErrorMessageSize, format, arg1, arg2);
  else
    snprintf (message, MaxErrorMessageSize, format, arg1, arg2, arg3);

  free (format);

  return message;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// err_store function
//
// Creates an error object and stores it in the error list.
//
slcc_error* err_store (
		       slcc_error_code code,
		       slcc_source_position pos,
		       char* arg1,
		       char* arg2,
		       char* arg3
		       )
{
  slcc_error* error = malloc (sizeof (slcc_error));

  if (error == NULL)
    {
      err_report_and_exit_0 (EC_ERROR_HANDLING_ERROR);
      return NULL;
    };

  error->code = code;
  error->pos = pos;
  error->arg1 = arg1 == NULL ? NULL : tc_copy_string (arg1);
  error->arg2 = arg2 == NULL ? NULL : tc_copy_string (arg2);
  error->arg3 = arg3 == NULL ? NULL : tc_copy_string (arg3);

  tc_array_add_ea (error_list_, error);

  return error;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// src_err_prepare_source_message function
//
// Prepares the message string for reporting a source code error.
// <TODO: Report position + relevant source code>
//
char* src_err_prepare_source_message (
				  slcc_error_code code,
				  slcc_source_position pos,
				  char* arg1,
				  char* arg2,
				  char* arg3
				  )
{
  char* format = malloc (sizeof (char) * MaxErrorMessageSize);
  char* message = malloc (sizeof (char) * MaxErrorMessageSize);

  if (format == NULL || message == NULL)
    return NULL;

  /* Type of source */
  if (pos.pos->type == ST_SOURCE_FILE)
    /* Source file */
    snprintf (
	      format,
	      MaxErrorMessageSize,
	      "%s:%zu:%zu %s: %s\n",
	      pos.pos->source.file->file,
	      pos.line,
	      pos.position,
	      error_type_list_[error_description_list_[code].type],
	      error_description_list_[code].desc
	      );
  else
    /* Source string */
    snprintf (
	      format,
	      MaxErrorMessageSize,
	      "%s:%zu:%zu %s: %s\n",
	      "STRING",
	      pos.line,
	      pos.position, 
	      error_type_list_[error_description_list_[code].type],
	      error_description_list_[code].desc
	      );

    
  if (arg1 == NULL)
    snprintf (message, MaxErrorMessageSize, format);
  else if (arg2 == NULL)
    snprintf (message, MaxErrorMessageSize, format, arg1);
  else if (arg3 == NULL)
    snprintf (message, MaxErrorMessageSize, format, arg1, arg2);
  else
    snprintf (message, MaxErrorMessageSize, format, arg1, arg2, arg3);

  free (format);

  return message;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
