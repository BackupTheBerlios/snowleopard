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
#include <stdlib.h>
#include <string.h>

#include "error_codes.h"
#include "error_handling.h"
#include "file_functions.h"
#include "settings.h"
#include "string_array.h"

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
  NULL,    /* include_paths */
  NULL,    /* library_paths */
  NULL,    /* source_paths */
  false    /* use_export */
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings_initialize function
//
// Initialize settings object.
//
bool settings_initialize ()
{
  settings_.include_paths = tc_array_new_sa ();
  settings_.library_paths = tc_array_new_sa ();
  settings_.source_paths = tc_array_new_sa ();

  if (settings_.include_paths == 0 
      || settings_.library_paths == 0
      || settings_.source_paths == 0)
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings_cleanup function
//
// Cleans up arrays and pointers used in the settings object.
//
void settings_cleanup ()
{
  free (settings_.out_file);
  
  if (settings_.include_paths != 0)
    tc_array_delete_sa (settings_.include_paths);

  if (settings_.library_paths != 0)
    tc_array_delete_sa (settings_.library_paths);

  if (settings_.source_paths != 0)
    tc_array_delete_sa (settings_.source_paths);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// add_path function
//
// Add a path to the list of paths to search. Priority is given as follows 
// (paths are build up in this order):
//   1) Path given at command line.
//   2) Path given in environment variable SLCC_<object>_PATH.
//   3) Path given in configuration file.
//   4) System/Compiler defined path.
//
bool add_path (slcc_path_type type, char* path)
{
  if (!tc_path_exists (path))
    {
      err_report_and_exit_1 (EC_PATH_NOT_FOUND, path);
      return false;
    }

  slcc_string_array* array;

  switch (type) {
  case PT_INCLUDE :
    array = settings_.include_paths;
    break;

  case PT_LIBRARY :
    array = settings_.library_paths;
    break;

  case PT_SOURCE :
    array = settings_.source_paths;
    break;

  default:
    return false;
  }

  for (size_t i = 0; i < array->used_; i++)
    if (strcmp (array->data_[i], path))
      {
	err_report_1 (
		      EC_W_DUPLICATE_INCLUDE_PATH,
		      path
		      );
	return false;
      }

  tc_array_add_sa (array, path);
  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// set_outfile function
//
// If there is already an outfile specified, report and ignore this new file.
//
bool set_out_file (char* file)
{
  if (settings_.out_file == NULL)
    {
      settings_.out_file = file;
      return true;
    }

  err_report_2 (EC_W_MULTIPLE_OUT_FILES_SPECIFIED, settings_.out_file, file);
  return false;
}
//------------------------------------------------------------------------------

//-<EOF>
