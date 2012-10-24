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
// Driver for the front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SETTINGS_H__
#define __SL_SLCC_SETTINGS_H__

#include <stdbool.h>
#include <stddef.h>

#include "string_array.h"

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
// slcc_optimize_flags enum
//
// All optimizer flags used by the compiler. These are summed together, so their
// bit-pattern should not overlap.
//
// Seperate flags
//  OF_<name> = 000xxxx
//
// Collection flags
//   O0 = 001xxxx
//   O1 = 010xxxx
//   O2 = 011xxxx
//   O3 = 100xxxx
//
enum slcc_optimizer_flag
  {
    OF_NONE = 0         /* 0b00000, No optimization */
    OF_UNROLL_LOOPS = 1 /* 0b00001, Unroll loops aggressively */
    OF_REDUCE_LOOPS = 2 /* 0b00010, Move code out of the loops */
    OF_O0 = 5           /* 0b00101, Standard O0 optimizer setting */
    OF_O1 = 11          /* 0b01011, Standard O1 optimizer setting */
    OF_O2 = 15          /* 0b01111, Standard O2 optimizer setting */
    OF_O3 = 19          /* 0b10011, Standard O3 optimizer setting */
  };

typedef enum slcc_optimizer_flag slcc_optimizer_flag;
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
// slcc_warning_type
//
// Warning flags used by the compiler.
//
enum slcc_warning_type
  {
    WT_NONE = 0                  /* 0b000000, No warnings, only errors are 
                                    reported */
    WT_UNUSED_ARGS = 1           /* 0b000001, Warn on unused arguments */
    WT_UNUSED_FUNCTIONS = 2      /* 0b000010, Warn about unused functions */
    WT_NO_VIRTUAL_DESTRUCTOR = 4 /* 0b000100, No virtual destructor */
    WT_MOST = 9                  /* 0b001001, Most warnings. Default setting */
    WT_ALL = 23                  /* 0b010111, Use all regular warnings */ 
    WT_EXTRA = 24                /* 0b011000, Use all extra warnings */
    WT_CXX_EFFCXX = 32           /* 0b100000, Effective C++ warnings (C++) */
  };

typedef enum slcc_warning_type slcc_warning_type;
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
// set_optimize_flags macro
//
// Set optimize flags.
//
#define set_optimize_flags(optimize_flag)				\
  settings_.optimize_flags = settings_.optimize_flags | optimize_flag
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// set_warnings macro
//
// Set warning flags.
//
#define set_warnings(warning_flag)			\
  settings_.warnings = settings_.warnings | warning_flag
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// reset_optimize_flags macro
//
// Reset optimize flags.
//
#define reset_optimize(optimize_flag)			\
  settings_.optimize_flags = settings_.optimize_flags 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// reset_warnings macro
//
// Reset warning flags.
//
#define reset_warnings(warning_flag)			\
  settings_.warnings = warning_flag 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// check_optimize_flags macro
//
// Check optimize flags.
//
#define check_optimize_flags(optimize_flag)	\
  (settings_.optimize_flags & optimize_flag)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// check_warnings macro
//
// Check warning flags.
//
#define check_warnings(warning_flag)		\
  (settings_.warnings & warning_flag)
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
