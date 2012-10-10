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
// driver.h
//------------------------------------------------------------------------------
// Driver for the front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SETTINGS_H__
#define __SL_SLCC_SETTINGS_H__

#include <stdbool.h>
#include <stddef.h>

//------------------------------------------------------------------------------
// slcc_settings structure
//
// Structure for storing the user/system settings applicable to the front end.
//
struct slcc_settings 
{
  size_t n_include_paths;
  char** include_paths;
  size_t n_library_paths;
  char** library_paths;
  size_t n_source_paths;
  char** source_paths;
};

typedef struct slcc_settings slcc_settings;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Settings functions.
bool add_include_path (char* path);
bool add_library_path (char* path);
bool add_source_path (char* path);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SETTINGS_H__ */

//-<EOF>
