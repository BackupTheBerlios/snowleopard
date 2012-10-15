/*==============================================================================
  Snow Leopard C++ Interpreter
  
  Copyright (C) 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// source_string.c
//------------------------------------------------------------------------------
// Source string for the compiler front end.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "source_string.h"

//------------------------------------------------------------------------------
// ss_new function
//
// This function initializes a source_string object.
//
slcc_source_string* ss_new (char* orig_src, char* preprocessed_src) 
{
  slcc_source_string* n_str = malloc (sizeof (slcc_source_string));

  n_str->original_source = orig_src;
  n_str->preprocessed_source = preprocessed_src;
  n_str->current_pos = 0;
	
  return n_str;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ss_delete function
//
// This function destroys a source_string object.
//
void ss_delete (slcc_source_string* str) 
{
  free (str->original_source);
  free (str->preprocessed_source);

  free (str);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ss_copy function
//
// This function copies a source_string object.
//
slcc_source_string* ss_copy (const slcc_source_string* str) 
{
  slcc_source_string* n_str = malloc (sizeof (slcc_source_string));

  n_str->original_source = str->original_source;
  n_str->preprocessed_source = str->preprocessed_source;

  return n_str;
}
//------------------------------------------------------------------------------

//-<EOF>
