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
// source_position.h
//------------------------------------------------------------------------------
// Source file position for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SOURCE_POSITION_H__
#define __SL_SLCC_SOURCE_POSITION_H__

#include <stddef.h>
#include <stdio.h>

#include "source_file.h"
#include "source_string.h"

//------------------------------------------------------------------------------
// slcc_source_type enum
//
// Types of sources for compilation.
//
enum slcc_source_type 
  {
    ST_SOURCE_FILE,
    ST_SOURCE_STRING
  };

typedef enum slcc_source_type slcc_source_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_position struct
//
// Position in the source.
//
struct slcc_position 
{
  slcc_source_type type;

  union 
  {
    slcc_source_file* file;
    slcc_source_string* string;
  } source;
  size_t line;
  size_t position;
  size_t count;
};

typedef struct slcc_position slcc_position;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_source_position struct
//
// Source position object.
//
struct slcc_source_position 
{
  slcc_position* pos;
  size_t line;
  size_t position;
};

typedef struct slcc_source_position slcc_source_position;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
//
#define SLCC_NO_SOURCE_POSITION {NULL, 0, 0}
extern const slcc_source_position NoSourcePosition;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initializer functions
//
slcc_source_position sp_new_with_file (
				       slcc_source_file* file,
				       size_t line,
				       size_t pos
				       );
slcc_source_position sp_new_with_string (
					 slcc_source_string* str,
					 size_t line,
					 size_t pos
					 );
void sp_delete (slcc_source_position s_pos);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Source position functions
slcc_source_position sp_copy (const slcc_source_position s_pos);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SOURCE_POSITION_H__ */

//-<EOF>
