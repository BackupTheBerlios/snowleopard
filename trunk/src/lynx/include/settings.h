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
// settings struct
//
// Stores settings for all applications.
//
struct settings 
{
  /* switches */
  bool quiet;
  bool verbose;
  bool copyright_only;
  bool usage_only;
  bool version_only;
  bool warrantee_only;

  /* paths */
  lynx_string_array* include_paths;
};

typedef struct settings settings;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variable
extern settings settings_;
//------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// Information functions
//
bool settings_initialize ();
void settings_cleanup ();
//------------------------------------------------------------------------------

#endif /* !__LYNX_INFO_H__ */

//-<EOF>
