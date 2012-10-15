/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
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
// source_position.c
//------------------------------------------------------------------------------
// Source position information for the compiler front end.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdlib.h>

#include "source_file.h"
#include "source_position.h"
#include "source_string.h"

//------------------------------------------------------------------------------
// NoSourcePosition const
//
const slcc_source_position NoSourcePosition = SLCC_NO_SOURCE_POSITION;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sp_new_with_file function
//
// Initialize a source position object with a file.
//
slcc_source_position sp_new_with_file (
				       slcc_source_file* file,
				       size_t line,
				       size_t pos
				       )
{
  slcc_position* n_pos = malloc (sizeof (slcc_position));

  n_pos->source_type = ST_SOURCE_FILE;
  n_pos->source.file = file;
  n_pos->line = line;
  n_pos->position = pos;
  n_pos->count = 1;

  slcc_source_position s_pos;
  s_pos.pos = n_pos;
  s_pos.line = line;
  s_pos.position = pos;

  return s_pos;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sp_new_with_string function
//
// Initialize a source position object with a source string.
//
slcc_source_position sp_new_with_string (
					 slcc_source_string* str,
					 size_t line,
					 size_t pos
					 ) 
{
  slcc_position* n_pos = malloc (sizeof (slcc_position));

  n_pos->source_type = ST_SOURCE_STRING;
  n_pos->source.string = str;
  n_pos->line = line;
  n_pos->position = pos;
  n_pos->count = 1;

  slcc_source_position s_pos;
  s_pos.pos = n_pos;
  s_pos.line = line;
  s_pos.position = pos;

  return s_pos;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sp_delete function
//
// Destroy a source position object.
//
void sp_delete (slcc_source_position s_pos) 
{
  if (s_pos.pos == NULL)
    return;

  if (s_pos.pos->source_type == ST_SOURCE_FILE)
    sf_delete (s_pos.pos->source.file);
  else
    ss_delete (s_pos.pos->source.string);

  if (s_pos.pos->count == 1)
    free (s_pos.pos);
  else
    s_pos.pos->count--;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sp_copy function
//
// Copy a source position object.
//
slcc_source_position sp_copy (const slcc_source_position s_pos) 
{
  slcc_source_position new_s_pos;

  new_s_pos.pos = s_pos.pos;

  new_s_pos.line = s_pos.pos->line;
  new_s_pos.position = s_pos.pos->position;

  return new_s_pos;
}
//------------------------------------------------------------------------------

//-<EOF>
