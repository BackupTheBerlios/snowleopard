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
// source_file.h
//------------------------------------------------------------------------------
// Source file for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SOURCE_FILE_H__
#define __SL_SLCC_SOURCE_FILE_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

//------------------------------------------------------------------------------
// slcc_source_file struct
//
// Structure for storing a source file.
//
struct slcc_source_file 
{
  char* file;
  FILE* stream;
  bool eof;
};

typedef struct slcc_source_file slcc_source_file;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initializer functions
//
slcc_source_file* sf_new (char* file);
void sf_delete (slcc_source_file* file);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Source position functions
//
slcc_source_file* sf_copy (const slcc_source_file* file);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SOURCE_FILE_H__ */

//-<EOF>
