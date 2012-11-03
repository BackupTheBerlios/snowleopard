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
// driver_arguments.c
//------------------------------------------------------------------------------
// Driver argument handling functions for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <string.h>

#include "driver.h"
#include "error.h"
#include "error_codes.h"
#include "error_handling.h"
#include "macros_slcc.h"
#include "optimize_flags.h"
#include "settings.h"
#include "warnings.h"

#include "file_functions.h"
#include "string_functions.h"

//------------------------------------------------------------------------------
// Private functions
//
bool drv_check_arguments (); 
bool drv_check_optimize_flag (char* flag);
bool drv_process_argument (char** argv, int* pos);
bool drv_process_file_argument (char* file);
bool drv_process_language_standard (char* argument);
bool drv_process_out_file (char* argument);
bool drv_process_path (slcc_path_type type, char* argument);
bool drv_store_define (char* define);
bool drv_store_undefine (char* undefine);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_parse_command_line function
//
// Parses the command line, checks arguments supplied and applies settings to
// the compiler.
//
bool drv_parse_command_line (int argc, char** argv)
{
  bool ok = true;
  char* arg;
  int i = 1; /* First parameter is the program name */

  while (i < argc)
    {
      arg = argv[i];
      
      if (arg[0] != '-')
	/* Source file */
	ok = drv_process_file_argument (arg);
      else
	/* Other arguments */
	ok = drv_process_argument (argv, &i);
      i++;
    }

  if (!ok)
    {
      err_report_and_exit_0 (EC_INVALID_ARG);
      return ok;
    }

  ok = drv_check_arguments ();

  return ok;
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// drv_check_arguments function
//
// Check the following:
//   - Was a source file provided?
//   - Are language options compatible with language provided?
//   - Are the feature flags compatible with the language/standard selected?
//
bool drv_check_arguments ()
{
  /* quiet takes priority over verbose, silently change this */
  if (settings_.quiet && settings_.verbose)
    settings_.verbose = false;

  /* 
   * if called for an information function, all others are irrelevant but we
   * do reset quiet.
   */
  if (settings_.copyright_only 
      || settings_.license_only 
      || settings_.usage_only 
      || settings_.warrantee_only)
    {
      settings_.quiet = false;
      return true;
    }

  /* 
   * if source required and not provided, report error, display usage and 
   * exit.
   */
  if (settings_.source_file == NULL 
      && (settings_.compile_only 
	  || settings_.dependencies_only 
	  || settings_.preprocess_only))
    {
      err_report_and_exit_0 (EC_NO_SOURCE_FILE);
      return false;
    }

  /* if there is no source file, report error, display usage and exit */
  if (settings_.source_file == NULL 
      && settings_.object_files->used_ == 0
      && settings_.library_files->used_ == 0)
    {
      err_report_and_exit_0 (EC_NO_OBJECT_OR_SOURCE_FILES);
      return false;
    }

  /* Are the language options provided compatible with the language provided */
  if (settings_.language == L_C 
      && (settings_.use_concepts || settings_.use_export))
    {
      err_report_and_exit_0 (EC_CPP_ONLY_OPTION_ON_C_SOURCE);
      return false;
    }
  
  /* <TODO: Are features selected compatible with language/standard selected */

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_argument function
//
// Process the argument given. If the argument is not a single argument, it
// will pick up the next arguments.
//
bool drv_process_argument (char** argv, int* pos)
{
  char* arg = argv[*pos];

  switch (arg[1]) {
  case '-' :
    {
      /* Argument --compile */
      if_equal_execute (arg,				
			"--compile",			
			return settings_.compile_only = true);

      /* Argument --copyright */
      if_equal_execute (arg,				
			"--copyright",			
			return settings_.copyright_only = true);

      /* Argument --debug_info */
      if_equal_execute (arg,
			"--debug_info",
			return settings_.debug_info = true);

      /* Argument --define <name=value> */
      if_equal_execute (arg,
			"--define",
			return drv_store_define (argv[++(*pos)]));

      /* Argument --feature <feature flag> */
      if_equal_execute (arg,
			"--feature",
			return check_feature_flag (argv[++(*pos)]));

      /* Argument --help */
      if_equal_execute (arg,			
			"--help",			
			return settings_.usage_only = true);

      /* Argument --include_path <path> */
      if_equal_execute (arg,					
			"--include_path",				 
			return drv_process_path (PT_INCLUDE, 
						 argv[++(*pos)]));

      /* Argument --library_path <path> */
      if_equal_execute (
			arg,					
			"--library_path",				
			return drv_process_path (PT_LIBRARY, 
						 argv[++(*pos)]));

      /* Argument --make_dependencies */
      if_equal_execute (arg,
			"--make_dependencies",
			return settings_.dependencies_only = true);

      /* Argument --no_stdlib */
      if_equal_execute (arg,				
			"--no_stdlib",			
			return !(settings_.use_stdlib = false));

      /* Argument --optimize <flag> */
      if_equal_execute (arg,
			"--optimize",
			return check_optimize_flag (argv[++(*pos)]));

      /* Argument --outfile <path> */
      if_equal_execute (arg,				
			"--outfile",			
			return drv_process_out_file (argv[++(*pos)]));

      /* Argument --preprocess */
      if_equal_execute (arg,				
			"--preprocess",			
			return settings_.preprocess_only = true);

      /* Argument --source_path <path> */
      if_equal_execute (arg,					
			"--source_path",				
			return drv_process_path (PT_SOURCE, 
						 argv[++(*pos)]));

      /* Argument --undefine <name> */
      if_equal_execute (arg,
			"--undefine",
			return drv_store_undefine (argv[++(*pos)]));

      /* Argument --usage */
      if_equal_execute (arg,			
			"--usage",			
			return settings_.usage_only = true);

      /* Argument --use_concepts */
      if_equal_execute (arg,
			"--use_concepts",
			return settings_.use_concepts = true);

      /* Argument --use_deprecated */
      if_equal_execute (arg,
			"--use_deprecated",
			return settings_.use_deprecated = true);

      /* Argument --use_export */
      if_equal_execute (arg,
			"--use_export",
			return settings_.use_export = true);

      /* Argument --warning <warning flag> */
      if_equal_execute (arg,					
			"--warning",				
			return check_warning_flag (argv[++(*pos)]));

      /* Argument --warrantee */
      if_equal_execute (arg,				
			"--warrantee",			
			return settings_.warrantee_only = true);
    }
    break;

  case 'D' :
    {
      /* Argument -D<name=value> [define <name=value>] */
      return drv_store_define (arg + 2);
    }
    break;

  case 'E' :
    {
      /* Argument -E [preprocess] */
      if_equal_execute (arg,				
			"-E",				
			return settings_.preprocess_only = true);
    }
    break;

  case 'I' :
    {
      /* Argument -I<path> [include_path <path>] */
      if_equal_execute (arg,					
			"-I",
			return drv_process_path (PT_INCLUDE, arg + 2));
    }
    break;

  case 'L' :
    {
      /* Argument -L<path> [library_path <path>] */
      if_equal_execute (arg,					
			"-L",					
			return drv_process_path (PT_LIBRARY, arg + 2));
    }
    break;

  case 'M' :
    {
      /* Argument -M [make_dependencies] */
      if_equal_execute (arg, "-M", return settings_.dependencies_only = true);
    }
    break;

  case 'O' :
    {
      /* Argument -O<optimize flag> [optimize <optimize flag>] */
      check_optimize_flag (arg + 2);
    }
    break;

  case 'S' :
    {
      /* Argument -S<path> [source_path <path>] */
      if_equal_execute (arg,					
			"-S",					
			return drv_process_path (PT_SOURCE, arg + 2));
    }
    break;

  case 'W' :
    {
      /* Argument -W<warning flag> [warning <warning flag>] */
      return check_warning_flag (arg + 2);
    }
    break;

  case 'U' :
    {
      /* Argument -U<name> [undefine <name>] */
      return drv_store_undefine (arg + 2);
    }
    break;

  case 'c' :
    {
      /* Argument -c [compile] */
      if_equal_execute (arg,"-c", return settings_.compile_only = true);
    }
    break;

  case 'f' :
    {
      /* Argument -f <feature flag> [feature <feature flag>] */
      return check_feature_flag (arg + 2);
    }
    break;

  case 'g' :
    {
      /* Argument -g [debug_info] */
      if_equal_execute (arg, "-g", return settings_.debug_info = true);
    }
    break;

  case 'h' :
    {
      /* Argument -h [help] */
      if_equal_execute (arg,"-h", return settings_.usage_only = true);
    }
    break;

  case 'q' :
    {
      /* Argument -q [quiet] */
      if_equal_execute (arg,"-q", return settings_.quiet = true);
    }
    break;

  case 'o' :
    {
      /* Argument -o <file> [outfile <path>] */
      if_equal_execute (arg,				
			"-o",				
			return drv_process_out_file (argv[++(*pos)]));
    }
    break;

  case 's' :
    {
      /* Argument -std=<c89|c99|c11|cpp98|cpp11> */
      if_equal_execute (arg,					
			"-std=",					
			return drv_process_language_standard (arg + 5));
    }
    break;

  case 'v' :
    {
      /* Argument -v [verbose] */
      if_equal_execute (arg,"-v", return settings_.verbose = true);
    }
    break;
	
  default :
    break;
  }

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_file_argument function
//
// Process the file given as parameter. This function checks the following:
//   - Does the file exist.
//   - Is it a recognized extension?
//         c/h/c.h                 - C source file
//         s/S/asm/                - Treated as C source file
//         cpp/cxx/hpp/hxx/C/H/ipp - C++ source file
//         o/obj/out               - Object file
//         a/lib                   - Library file
//   - Deduce the source file type as it dictates what the compiler should do
//     with the file.
//
bool drv_process_file_argument (char* file)
{
  if (!tc_file_exists (file))
    {
      err_report_and_exit_1 (EC_SOURCE_FILE_NOT_FOUND, file);
      return false;
    }

  char* ext1 = tc_get_str_after_nth_last (file, '.', 1);
  char* ext2 = tc_get_str_after_nth_last (file, '.', 2);
  slcc_language lang = L_C;
  
  /* C source file */
  if (strcmp (ext1, "c") == 0)
    {
      settings_.source_type = SFT_SOURCE;
      settings_.source_file = file;
    }

  /* C header file / C implementation file */
  else if (strcmp (ext1, "h") == 0)
    {
      if (strcmp (ext2, "c.h") == 0)
	settings_.source_type = SFT_IMPLEMENTATION;
      else
	settings_.source_type = SFT_HEADER;
      settings_.source_file = file;
    }

  /* Assembler file */
  else if (strcmp (ext1, "s") == 0
	   || strcmp (ext1, "S") == 0
	   || strcmp (ext1, "asm") == 0)
    {
      settings_.source_type = SFT_ASSEMBLER;
      settings_.source_file = file;
    }

  /* Object file */
  else if (strcmp (ext1, "o") == 0
	   || strcmp (ext1, "obj") == 0
	   || strcmp (ext1, "out") == 0)
    add_file_or_path (PT_OBJECT_FILE, file);

  /* Library file */
  else if (strcmp (ext1, "a") == 0
	   || strcmp (ext1, "lib") == 0)
    add_file_or_path (PT_LIBRARY_FILE, file);

  /* C++ source file */
  else if (strcmp (ext1, "cpp") == 0
	   || strcmp (ext1, "cxx") == 0
	   || strcmp (ext1, "C") == 0)
    {
      lang = L_CXX;
      settings_.source_type = SFT_SOURCE;
      settings_.source_file = file;
    }

  /* C++ header file */
  else if (strcmp (ext1, "hpp") == 0
	   || strcmp (ext1, "hxx") == 0
	   || strcmp (ext1, "H") == 0)
    {
      lang = L_CXX;
      settings_.source_type = SFT_HEADER;
      settings_.source_file = file;
    }

  /* C++ implementation file */
  else if (strcmp (ext1, "ipp") == 0)
    {
      lang = L_CXX;
      settings_.source_type = SFT_IMPLEMENTATION;
      settings_.source_file = file;
    }

  /* No valid file extension */
  else
    {
      if (ext1 != NULL)
	free (ext1);
      if (ext2 != NULL)
	free (ext2);
      err_report_and_exit_1 (EC_INVALID_SOURCE_FILE_TYPE, file);
      return false;
    }

  /* Cleanup temporary objects */
  if (ext1 != NULL)
    free (ext1);
  if (ext2 != NULL)
    free (ext2);

  /* Check language setting */
  settings_.language = (settings_.language == L_CXX ? L_CXX : lang);

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_language_standard function
//
// Check language standard and set settings correctly.
//
bool drv_process_language_standard (char* arg)
{
  if (strncmp (arg, "c89", 3) == 0)
    {
      settings_.language = L_C;
      settings_.standard = LS_C89;
    }
  else if (strncmp (arg, "c99", 3) == 0)
    {
      settings_.language = L_C;
      settings_.standard = LS_C99;
    }
  else if (strncmp (arg, "c11", 3) == 0)
    {
      settings_.language = L_C;
      settings_.standard = LS_C11;
    }
  else if (strncmp (arg, "c1y", 3) == 0)
    {
      settings_.language = L_C;
      settings_.standard = LS_C1Y;
    }
  else if (strncmp (arg, "cpp98", 5) == 0)
    {
      settings_.language = L_CXX;
      settings_.standard = LS_CXX98;
    }
  else if (strncmp (arg, "cpp11", 5) == 0)
    {
      settings_.language = L_CXX;
      settings_.standard = LS_CXX11;
    }
  else if (strncmp (arg, "cpp1y", 5) == 0)
    {
      settings_.language = L_CXX;
      settings_.standard = LS_CXX1Y;
    }
  else
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_out_file function
//
// Set out_file.
//
bool drv_process_out_file (char* arg)
{
  if (*arg == '\0')
    return false;
  else
    return set_out_file (arg);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_path function
//
// Set include path.
//
bool drv_process_path (slcc_path_type type, char* arg)
{
  if (*arg == '\0')
    return false;
  else
    return add_file_or_path (type, arg);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_store_define function
//
// Stores the argument of the define setting for later processing.
//
bool drv_store_define (char* define)
{
  if (define == NULL)
    /* <TODO: report error and exit> */
    return false;

  if (tc_array_add_str (settings_.defines, define) > 0)
    return true;

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_store_undefine function
//
// Stores the argument of the undefine setting for later processing.
//
bool drv_store_undefine (char* undefine)
{
  if (undefine == NULL)
    /* <TODO: report error and exit> */
    return false;

  if (tc_array_add_str (settings_.undefines, undefine) > 0)
    return true;

  return false;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
