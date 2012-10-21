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
// reader.c
//------------------------------------------------------------------------------
// Reader for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "settings.h"
#include "source_position.h"

#include "file_functions.h"

//------------------------------------------------------------------------------
// Initial reader stack size.
//
const size_t InitialStackSize = 10;
const size_t InitialStackDepth = (size_t) - 1;
const size_t MaxPathStringSize = 65536;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private function prototypes.
//
static void rdr_push_file_stack (slcc_source_position);
static slcc_source_position rdr_pop_file_stack ();
static slcc_source_position rdr_top_file_stack ();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private global variables.
slcc_source_position* file_stack;
size_t file_stack_reserved;
size_t file_stack_depth;

int current_char;
int previous_char;
slcc_source_position current_position;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_initialize_with_file function
//
// Initialize reader with file.
//
bool rdr_initialize_with_file (char* file) 
{
  /* Initialize file stack */
  file_stack_reserved = InitialStackSize;
  file_stack =
    malloc (sizeof (slcc_source_position[file_stack_reserved]));
  file_stack_depth = InitialStackDepth;

  /* Add first file */
  rdr_push_file_stack (sp_new_with_file (sf_new (file), 1, 0));

  /* Set previous character */
  current_char = 0;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_initialize_with_string function
//
// Initialize reader with file.
//
bool rdr_initialize_with_string (char* orig_src, char* preprocessed_src) 
{
  /* Initialize file stack */
  file_stack_reserved = InitialStackSize;
  file_stack =
    malloc (sizeof (slcc_source_position[file_stack_reserved]));
  file_stack_depth = InitialStackDepth;

  /* Add first string */
  rdr_push_file_stack (sp_new_with_string (ss_new (
						   orig_src,
						   preprocessed_src
						   ),
					   1,
					   0
					   )
		       );

  /* Set previous character */
  current_char = 0;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_cleanup function
//
// Destroy reader.
//
void rdr_cleanup () 
{
  size_t i;

  for (i = file_stack_depth; i != 0; --i) {
    sp_delete (file_stack[i - 1]);
    file_stack[i - 1] = NoSourcePosition;
  }
  free (file_stack);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_get_next_char function
//
// Returns the next character in the current file.
//
char rdr_get_next_char () 
{
  previous_char = current_char;

  slcc_source_position file = rdr_top_file_stack ();

  if (file.pos == NoSourcePosition.pos) 
    return EOF;

  if (file.pos->type == ST_SOURCE_FILE)
    current_char = fgetc (file.pos->source.file->stream);
  else
    current_char
      = file.pos->source.string->preprocessed_source
      [
       file.pos->source.string->current_pos++
       ];

  current_position = sp_copy (file);

  if (current_char != '\n') 
    {
      file.pos->position++;
      file.position++;
    }
  else 
    {
      file.pos->line++;
      file.line++;
      file.pos->position = 0;
      file.position = 0;
    }

  if (current_char == EOF) 
    {
      current_position.pos->source.file->eof = true;

      if (file_stack_depth == 0)
	return EOF;

      slcc_source_position file = rdr_pop_file_stack ();
      if (file.pos != NoSourcePosition.pos)
	sp_delete (file);

      current_char = '\n';

      return rdr_get_next_char ();
    }

  return current_char;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_get_current_char function
//
// Returns the last read character again.
//
char rdr_get_current_char () 
{
  return current_char;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_get_previous_char function
//
// Returns the previously read character.
//
char rdr_get_previous_char () 
{
  return previous_char;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_put_back_char function
//
// Puts the character back into the input stream.
//
bool rdr_put_back_char (char c) 
{
  /* <TODO: Revert input stream to pretend the last character was not read> */
  c++;

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_set_nested_file function
//
// Sets up a nested file (include or source) to be read * by the reader. It
// leaves it so the next get_next_char will read the first character of this
// file.
//
bool rdr_set_nested_file (char* file) 
{
  size_t orig_depth = file_stack_depth;

  /* Add first file */
  rdr_push_file_stack (sp_new_with_file (sf_new (file), 1, 0));

  if (orig_depth + 1 == file_stack_depth)
    return true;
  else
    return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_get_current_source_file function
//
// Returns the currently read file.
//
slcc_source_file* rdr_get_current_source_file () 
{
  return current_position.pos->source.file;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// get_current_source_position function
//
// Returns the currently read source position.
//
slcc_source_position rdr_get_current_source_position () 
{
  return current_position;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// get_current_source_string function
//
// Returns the currently read string.
//
slcc_source_string* rdr_get_current_source_string () 
{
  return current_position.pos->source.string;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_get_full_path_for_file function
//
// Returns the full path for the file name given.
//
// Search is performed as follows:
//  1) Search in include paths given at the command line.
//  2) Search in current directory.
//  3) Search in /usr/include /usr/include/g++ /usr/local/include
//
char* rdr_get_full_path_for_file (char* file) 
{
  size_t i;
  char* path = malloc (sizeof (char[MaxPathStringSize]));

  /* Try each of the include paths given at the command line */
  for (i = 0; i != settings_.include_paths->used_; i++) 
    {
      size_t size = strlen (settings_.include_paths->data_[i]);
      strcpy (path, settings_.include_paths->data_[i]);
      strcpy (path + size, file);
      if (tc_file_exists (path))
	return path;
    }

  /* Try each of the source paths given at the command line */
  for (i = 0; i != settings_.source_paths->used_; ++i) 
    {
      size_t size = strlen (settings_.source_paths->data_[i]);
      strcpy (path, settings_.source_paths->data_[i]);
      strcpy (path + size, file);
      if (tc_file_exists (path))
	return path;
    }

  /* Try the current directory */
  strcpy (path, file);
  if (tc_file_exists (path))
    return path;

  /* Try /usr/include */
  strcpy (path, "/usr/include/");
  strcpy (path + 13, file);
  if (tc_file_exists (path))
    return path;

  /* Try /usr/include/g++ */
  strcpy (path, "/usr/include/g++/");
  strcpy (path + 17, file);
  if (tc_file_exists (path))
    return path;
 
  /* Try /usr/local/include */
  strcpy (path, "/usr/local/include/");
  strcpy (path + 19, file);
  if (tc_file_exists (path))
    return path;

  free (path);

  return 0;
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// rdr_push_file_stack function
//
// Push new element on file stack.
//
void rdr_push_file_stack (slcc_source_position file) 
{
  size_t i;

  if (file_stack_depth == (size_t) - 1)
    file_stack_depth = 0;
  else
    file_stack_depth++;

  if (file_stack_depth >= file_stack_reserved) 
    {
      /* Expand stack */
      file_stack_reserved += 10;
      slcc_source_position* old = file_stack;
      file_stack 
	= malloc (sizeof (slcc_source_position[file_stack_reserved]));

      for (i = 0; i != file_stack_depth - 1; ++i)
	file_stack[i] = old[i];

      free (old);
    }

  file_stack[file_stack_depth] = file;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_pop_file_stack function
//
// Pop file from file stack.
//
slcc_source_position rdr_pop_file_stack () 
{
  if (file_stack_depth == InitialStackDepth)
    return NoSourcePosition;

  slcc_source_position file = file_stack[file_stack_depth];
  file_stack_depth--;

  return file;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// rdr_top_file_stack function
//
// Return current file from file stack.
//
slcc_source_position rdr_top_file_stack () 
{
  if (file_stack_depth == InitialStackDepth)
    return NoSourcePosition;
  else
    return file_stack[file_stack_depth];
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
