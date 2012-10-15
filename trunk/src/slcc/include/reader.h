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
// reader.h
//------------------------------------------------------------------------------
// Reader for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_READER_H__
#define __SL_SLCC_READER_H__

#include <stdbool.h>

#include "source_file.h"
#include "source_position.h"
#include "source_string.h"

//------------------------------------------------------------------------------
// Initialize functions
//
bool rdr_new_with_file (char* file);
bool rdr_new_with_string (char* orig_src, char* preprocessed_src);
void rdr_delete ();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Reader functions
//
char rdr_get_next_char ();
char rdr_get_current_char ();
char rdr_get_previous_char ();
bool rdr_put_back_char (char c);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Nested files funtions
//
bool rdr_set_nested_file (char* file);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Source position functions
//
slcc_source_file* rdr_get_current_source_file ();
slcc_source_position rdr_get_current_source_position ();
slcc_source_string* rdr_get_current_source_string ();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include/Source path functions
//
char* rdr_get_full_path_for_file (char* file);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_READER_H__ */

//-<EOF>
