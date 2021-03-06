/*==============================================================================
  Snow Leopard Typed Components Library
  
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
// file_functions.h
//------------------------------------------------------------------------------
// File functions for the typed components library.
//------------------------------------------------------------------------------

#ifndef __SL_TC_FILE_FUNCTIONS_H__
#define __SL_TC_FILE_FUNCTIONS_H__

#include <stdbool.h>

//------------------------------------------------------------------------------
// String functions
//
bool tc_file_exists (char* file);
char* tc_get_absolute_path (char* file);
bool tc_path_exists (char* path);
//------------------------------------------------------------------------------

#endif /* !__SL_TC_FILE_FUNCTIONS_H__ */

//-<EOF>
