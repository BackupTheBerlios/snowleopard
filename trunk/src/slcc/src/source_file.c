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
// source_file.c
//------------------------------------------------------------------------------
// Source file handling for the compiler front end.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "source_file.h"

//------------------------------------------------------------------------------
// sf_new function
//
// This function initializes a source_file object.
//
slcc_source_file* sf_new (char* file) 
{
  slcc_source_file* n_file = malloc (sizeof (slcc_source_file));

  n_file->file = file;
  n_file->stream = fopen (file, "r");
  n_file->eof = false;
	
  return n_file;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sf_delete function
//
// This function destroys a source_file object.
//
void sf_delete (slcc_source_file* file) 
{
  if (file->eof) 
    {
      if (file->file != NULL)
	free (file->file);
	
      if (file->stream != NULL)
	fclose (file->stream);

      free (file);
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sf_copy function
//
// This function copies a source_file object.
//
slcc_source_file* sf_copy (const slcc_source_file* file) 
{
  slcc_source_file* n_file = malloc (sizeof (slcc_source_file));

  n_file->file = file->file;
  n_file->stream = file->stream;
  n_file->eof = file->eof;

  return n_file;
}
//------------------------------------------------------------------------------

//-<EOF>
