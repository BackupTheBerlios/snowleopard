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
// settings.c
//------------------------------------------------------------------------------
// Settings for the front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

#include "settings.h"

//------------------------------------------------------------------------------
// Global variables
//
slcc_settings settings_ = {
  false,   /* quiet */
  false,   /* verbose */
  false,   /* copyright_only */
  false,   /* usage_only */
  false,   /* warrantee_only */
  false,   /* compile_only */
  false,   /* preprocess_only */
  "a.out", /* out_file */
  L_C,     /* language */
  LS_C11,  /* standard */
  true,    /* use_stdlib */
  0,       /* n_include_paths */
  NULL,    /* include_paths */
  0,       /* n_library_paths */
  NULL,    /* library_paths */
  0,       /* n_source_paths */
  NULL,    /* source_paths */
  false    /* use_export */
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// add_include_path function
//
// Add an include path to the list of paths to search. Priority is given as 
// follows (paths are build up in this order):
//   1) Path given at command line.
//   2) Path given in environment variable SLC_INCLUDE_PATH.
//   3) Path given in configuration file.
//   4) System/Compiler defined path.
//
bool add_include_path (char* path)
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// add_library_path function
//
// Add an library path to the list of paths to search. Priority is given as 
// follows (paths are build up in this order):
//   1) Path given at command line.
//   2) Path given in environment variable SLC_LIBRARY_PATH.
//   3) Path given in configuration file.
//   4) System/Compiler defined path.
//
bool add_library_path (char* path)
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// add_source_path function
//
// Add an source path to the list of paths to search. Priority is given as 
// follows (paths are build up in this order):
//   1) Path given at command line.
//   2) Path given in environment variable SLC_SOURCE_PATH.
//   3) Path given in configuration file.
//   4) System/Compiler defined path.
//
bool add_source_path (char* path)
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// set_outfile function
//
//
//
bool set_outfile (char* file)
{

  return false;
}
//------------------------------------------------------------------------------

//-<EOF>
