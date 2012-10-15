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
// source_string.h
//------------------------------------------------------------------------------
// Source string for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SOURCE_STRING_H__
#define __SL_SLCC_SOURCE_STRING_H__

//------------------------------------------------------------------------------
// slcc_source_string struct
//
// Structure for storing a source string.
//
struct slcc_source_string 
{
  char* original_source;
  char* preprocessed_source;
  size_t current_pos;
};

typedef struct slcc_source_string slcc_source_string;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initializer functions
//
slcc_source_string* ss_new (char* orig_src, char* preprocessed_src);
void ss_delete (slcc_source_string* str);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Source position functions
slcc_source_string* ss_copy (const slcc_source_string* str);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SOURCE_STRING_H__ */

//-<EOF>
