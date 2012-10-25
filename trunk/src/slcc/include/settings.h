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
// settings.h
//------------------------------------------------------------------------------
// Settings for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SETTINGS_H__
#define __SL_SLCC_SETTINGS_H__

#include <stdbool.h>
#include <stddef.h>

#include "features.h"
#include "optimize_flags.h"
#include "string_array.h"
#include "warnings.h"

//------------------------------------------------------------------------------
// slcc_language enumeration
//
// Languages handled by the compiler.
//
enum slcc_language
  {
    L_NONE, /* Not specified */
    L_C,    /* C - Default */
    L_CXX   /* C++ */
  };

typedef enum slcc_language slcc_language;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_language_standard enumeration
//
// Language standards supported by the compiler.
//
enum slcc_language_standard
  {
    LS_NONE,  /* Not specified */
    LS_C89,   /* C 89 */
    LS_C99,   /* C 99 */
    LS_C11,   /* C 11 - Default for C */
    LS_C1Y,   /* Experimental C */
    LS_CXX98, /* C++ 98 */
    LS_CXX11, /* C++ 11 - Default for C++ */
    LS_CXX1Y  /* Experimental C++, also includes concepts and export */
  };

typedef enum slcc_language_standard slcc_language_standard;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_path_type enum
//
// Path types and object types used in the compiler settings.
//
enum slcc_path_type
  {
    PT_INCLUDE,      /* Include path */
    PT_LIBRARY,      /* Library path */
    PT_LIBRARY_FILE, /* Library file */
    PT_OBJECT_FILE,  /* Object file */
    PT_SOURCE        /* Source path */
  };

typedef enum slcc_path_type slcc_path_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_source_file_type enum
//
// Source file types used in the compiler settings.
//
enum slcc_source_file_type
  {
    SFT_NONE,           /* Not specified */
    SFT_ASSEMBLER,      /* Assembler file (.s/.S/.asm ) */
    SFT_HEADER,         /* Header file (.h/.hpp/.hxx/.H) */
    SFT_IMPLEMENTATION, /* Implementation file (.c.h/.ipp) */
    SFT_SOURCE          /* Source file (.c/.cpp/.cxx/.C) */
  };

typedef enum slcc_source_file_type slcc_source_file_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_settings structure
//
// Structure for storing the user/system settings applicable to the front end.
//
struct slcc_settings 
{
  /* switches */
  bool quiet;
  bool verbose;
  bool copyright_only;
  bool license_only;
  bool usage_only;
  bool warrantee_only;

  /* compile options */
  bool compile_only;
  bool dependencies_only;
  bool preprocess_only;
  bool debug_info;
  char* out_file;
  char* source_file;
  slcc_source_file_type source_type;
  slcc_string_array* object_files;
  slcc_string_array* library_files;

  /* language options */
  slcc_language language;
  slcc_language_standard standard;
  unsigned long long features;
  bool use_deprecated;

  /* Preprocessor options */
  slcc_string_array* defines;
  slcc_string_array* undefines;

  /* C/C++ options */
  bool use_stdlib;
  slcc_string_array* include_paths;
  slcc_string_array* library_paths;
  slcc_string_array* source_paths;

  /* C++ options */
  bool use_concepts;
  bool use_export;

  /* Code generation options */
  unsigned long long optimize_flags;

  /* Errors/warnings */
  unsigned long long warnings;
  bool warnings_as_errors;
};

typedef struct slcc_settings slcc_settings;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables.
extern slcc_settings settings_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Settings functions.
bool settings_new ();
void settings_delete ();
bool add_file_or_path (slcc_path_type type, char* file);
bool set_out_file (char* file);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SETTINGS_H__ */

//-<EOF>
