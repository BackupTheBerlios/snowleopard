/*==============================================================================
  Lynx Typesetting System
  
  Copyright (C) 2010, 2011, 2012 Roel Sergeant
  
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
// settings.h
//------------------------------------------------------------------------------
// Settings for the Lynx typesetting system.
//------------------------------------------------------------------------------

#ifndef __LYNX_SETTINGS_H__
#define __LYNX_SETTINGS_H__

#include <stdbool.h>

#include "string_array.h"

//------------------------------------------------------------------------------
// lsoelim_settings struct
//
// Specific lsoelim settings.
//
struct lsoelim_settings
{
  lynx_string_array* include_paths;
};

typedef struct lsoelim_settings lsoelim_settings;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ltbl_settings struct
//
// Specific ltbl_settings.
//
struct ltbl_settings
{
  bool compatibility_mode;
};

typedef struct ltbl_settings ltbl_settings;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// settings struct
//
// Stores settings for all applications.
//
struct lynx_settings 
{
  /* switches */
  bool quiet;
  bool verbose;
  bool copyright_only;
  bool usage_only;
  bool version_only;
  bool warrantee_only;

  union
  {
    lsoelim_settings lsoelim;
    ltbl_settings ltbl;
  } tool_specific;
};

typedef struct lynx_settings lynx_settings;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variable
extern lynx_settings settings_;
//------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// Information functions
//
bool settings_initialize ();
void settings_cleanup ();
bool settings_add_path (lynx_string_array* array, char* path);
//------------------------------------------------------------------------------

#endif /* !__LYNX_SETTINGS_H__ */

//-<EOF>
