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
#include "settings.h"
#include "string_array.h"

#include "file_functions.h"

//------------------------------------------------------------------------------
// Global variables
//
slcc_settings settings_ = {
  false,    /* quiet */
  false,    /* verbose */
  false,    /* copyright_only */
  false,    /* license_only */
  false,    /* usage_only */
  false,    /* warrantee_only */
  false,    /* compile_only */
  false,    /* dependencies_only */
  false,    /* preprocess_only */
  false,    /* debug_info */
  NULL,     /* out_file */
  NULL,     /* source_file */
  SFT_NONE, /* source_file_type */
  NULL,     /* object_files */
  NULL,     /* library_files */
  L_NONE,   /* language */
  LS_NONE,  /* standard */
  false,    /* use_deprecated */
  NULL,     /* defines */
  NULL,     /* undefines */
  true,     /* use_stdlib */
  NULL,     /* include_paths */
  NULL,     /* library_paths */
  NULL,     /* source_paths */
  false,    /* use_concepts */
  false,    /* use_export */
  OF_NONE,  /* optimize_flags */
  WT_MOST,  /* warnings */
  false
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings_new function
//
// Initialize settings object.
//
bool settings_new ()
{
  settings_.object_files = tc_array_new_str ();
  settings_.library_files = tc_array_new_str ();
  settings_.defines = tc_array_new_str ();
  settings_.undefines = tc_array_new_str ();
  settings_.include_paths = tc_array_new_str ();
  settings_.library_paths = tc_array_new_str ();
  settings_.source_paths = tc_array_new_str ();

  if (settings_.object_files == NULL
      || settings_.library_files == NULL
      || settings_.defines == NULL
      || settings_.undefines == NULL
      || settings_.include_paths == NULL 
      || settings_.library_paths == NULL
      || settings_.source_paths == NULL)
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings_delete function
//
// Cleans up arrays and pointers used in the settings object.
//
void settings_delete ()
{
  free (settings_.out_file);
  
  if (settings_.object_files != NULL)
    tc_array_delete_str (settings_.object_files);

  if (settings_.library_files != NULL)
    tc_array_delete_str (settings_.library_files);

  if (settings_.defines != NULL)
    tc_array_delete_str (settings_.defines);

  if (settings_.undefines != NULL)
    tc_array_delete_str (settings_.undefines);

  if (settings_.include_paths != NULL)
    tc_array_delete_str (settings_.include_paths);

  if (settings_.library_paths != NULL)
    tc_array_delete_str (settings_.library_paths);

  if (settings_.source_paths != NULL)
    tc_array_delete_str (settings_.source_paths);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// add_file_or_path function
//
// This functions has 2 goals:
//
// 1) Add an object or library file to the files to use for linking.
//
// 2) Add a path to the list of paths to search. Priority is given as follows 
//    (paths are build up in this order):
//      1) Path given at command line.
//      2) Path given in environment variable SLCC_<object>_PATH.
//      3) Path given in configuration file.
//      4) System/Compiler defined path.
//
bool add_file_or_path (slcc_path_type type, char* file)
{
  if (type == PT_INCLUDE
      || type == PT_LIBRARY
      || type == PT_SOURCE)
    {
      if (!tc_path_exists (file))
	{
	  err_report_and_exit_1 (EC_PATH_NOT_FOUND, file);
	  return false;
	}
    }
  else
    {
      if (!tc_file_exists (file))
	{
	  err_report_and_exit_1 (EC_FILE_NOT_FOUND, file);
	  return false;
	}
    }

  slcc_string_array* array;

  switch (type) {
  case PT_INCLUDE :
    array = settings_.include_paths;
    break;

  case PT_LIBRARY :
    array = settings_.library_paths;
    break;

  case PT_LIBRARY_FILE :
    array = settings_.library_files;
    break;

  case PT_OBJECT_FILE :
    array = settings_.object_files;
    break;

  case PT_SOURCE :
    array = settings_.source_paths;
    break;

  default:
    return false;
  }

  for (size_t i = 0; i < array->used_; i++)
    if (strcmp (array->data_[i], file))
      {
	err_report_1 (
		      EC_W_DUPLICATE_INCLUDE_PATH,
		      file
		      );
	return false;
      }

  tc_array_add_str (array, file);
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
