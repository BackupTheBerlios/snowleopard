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
// driver.c
//------------------------------------------------------------------------------
// Driver functions for the front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <string.h>

#include "codegen.h"
#include "driver.h"
#include "error.h"
#include "error_codes.h"
#include "error_handling.h"
#include "parser.h"
#include "settings.h"

#include "file_functions.h"
#include "string_functions.h"

//------------------------------------------------------------------------------
// Private functions
//
bool drv_check_arguments (); 
bool drv_check_warning (char* arg);
bool drv_process_argument (char** argv, int* pos);
bool drv_process_file_argument (char* file);
bool drv_process_language_standard (char* argument);
bool drv_process_out_file (char* argument);
bool drv_process_path (slcc_path_type type, char* argument, bool attached);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Helper macros
#define drv_check_arg(string1,string2,command)			\
  if (strlen (string1) < strlen (string2))			\
    if (strncmp (string1, string2, strlen (string2) -1))	\
      {								\
	command;						\
      }
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_initialize function
//
// Initialize all components before the compilation starts.
//
bool drv_initialize ()
{
  if (!settings_new ())
    {
      err_report_0 (EC_DRIVER_INITIALIZATION_FAILED);
      return false;
    }

  if (!parser_initialize ())
    {
      err_report_0 (EC_PARSER_INITIALIZATION_FAILED);
      return false;
    }

  if (!codegen_initialize ())
    {
      err_report_0 (EC_CODEGEN_INITIALIZATION_FAILED);
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_cleanup function
//
// Cleans up all components when the compilation process has finished.
//
void drv_cleanup ()
{
  settings_delete ();
  parser_cleanup ();
  codegen_cleanup ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_start function
//
// Starts the compilation process.
//
bool drv_start ()
{
  if (!parser_start ())
    return false;

  if (!codegen_start ())
      return false;

  return true;
}
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
  char* s;
  int i = 0;

  while (i < argc)
    {
      s = argv[i];
      
      if (s[0] != '-')
	/* Source file */
	ok = drv_process_file_argument (s);
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
//   - Was a source file provided.
//   - Are language options compatible with language provided.
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
      err_report_0 (EC_NO_SOURCE_FILE);
      return false;
    }

  /* if there is no source file, report error, display usage and exit */
  if (settings_.source_file == NULL 
      && settings_.object_files->used_ == 0
      && settings_.library_files->used_ == 0)
    {
      err_report_0 (EC_NO_OBJECT_OR_SOURCE_FILES);
      return false;
    }

  /* Are the language options provided compatible with the language provided */
  if (settings_.language == L_C 
      && (settings_.use_concepts || settings_.use_export))
    {
      err_report_0 (EC_CPP_ONLY_OPTION_ON_C_SOURCE);
      return false;
    }

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
      drv_check_arg (arg,				
		     "--compile",			
		     return settings_.compile_only = true);

      /* Argument --copyright */
      drv_check_arg (arg,				
		     "--copyright",			
		     return settings_.copyright_only = true);

      /* Argument --make_dependencies */
      drv_check_arg (arg,
		     "--make_dependencies",
		     return settings_.dependencies_only = true);

      /* Argument --help */
      drv_check_arg (arg,			
		     "--help",			
		     return settings_.usage_only = true);

      /* Argument --include_path <path> */
      drv_check_arg (arg,					
		     "--include_path",				
		     return drv_process_path (PT_INCLUDE, argv[*pos++], false));

      /* Argument --library_path <path> */
      drv_check_arg (arg,					
		     "--library_path",				
		     return drv_process_path (PT_LIBRARY, argv[*pos++], false));

      /* Argument --no_stdlib */
      drv_check_arg (arg,				
		     "--no_stdlib",			
		     return !(settings_.use_stdlib = false));

      /* Argument --outfile <path> */
      drv_check_arg (arg,				
		     "--outfile",			
		     return drv_process_out_file (argv[*pos++]));

      /* Argument --preprocess */
      drv_check_arg (arg,				
		     "--preprocess",			
		     return settings_.preprocess_only = true);

      /* Argument --source_path <path> */
      drv_check_arg (arg,					
		     "--source_path",				
		     return drv_process_path (PT_SOURCE, argv[*pos++], false));

      /* Argument --usage */
      drv_check_arg (arg,			
		     "--usage",			
		     return settings_.usage_only = true);

      /* Argument --use_concepts */
      drv_check_arg (arg,
		     "--use_concepts",
		     return settings_.use_concepts = true);

      /* Argument --use_deprecated */
      drv_check_arg (arg,
		     "--use_deprecated",
		     return settings_.use_deprecated = true);

      /* Argument --use_export */
      drv_check_arg (arg,
		     "--use_export",
		     return settings_.use_export = true);

      /* Argument --warning <warning flag> */
      drv_check_arg (arg,					
		     "--warning",				
		     return drv_check_warning (argv[*pos++]));

      /* Argument --warrantee */
      drv_check_arg (arg,				
		     "--warrantee",			
		     return settings_.warrantee_only = true);
    }
    break;

  case 'E' :
    {
      /* Argument -E [preprocess] */
      drv_check_arg (arg,				
		     "-E",				
		     return settings_.preprocess_only = true);
    }
    break;

  case 'I' :
    {
      /* Argument -I<path> [include_path <path>] */
      drv_check_arg (arg,					
		     "-I",
		     return drv_process_path (PT_INCLUDE, argv[*pos++], true));
    }
    break;

  case 'L' :
    {
      /* Argument -L<path> [library_path <path>] */
      drv_check_arg (arg,					
		     "-L",					
		     return drv_process_path (PT_LIBRARY, argv[*pos++], true));
    }
    break;

  case 'M' :
    {
      /* Argument -M [make_dependencies] */
      drv_check_arg (arg, "-M", return settings_.dependencies_only = true);
    }
    break;

  case 'S' :
    {
      /* Argument -S<path> [source_path <path>] */
      drv_check_arg (arg,					
		     "-S",					
		     return drv_process_path (PT_SOURCE, argv[*pos++], true));
    }
    break;

  case 'W' :
    {
      /* Argument -W<warning flag> [warning <warning flag>] */
      return drv_check_warning (
				arg+2
				);
    }
    break;

  case 'c' :
    {
      drv_check_arg (arg,"-c",return settings_.compile_only = true);
    }
    break;

  case 'h' :
    {
      /* Argument -h [help] */
      drv_check_arg (arg,"-h",return settings_.usage_only = true);
    }
    break;

  case 'q' :
    {
      /* Argument -q [quiet] */
      drv_check_arg (arg,"-q",return settings_.quiet = true);
    }
    break;

  case 'o' :
    {
      /* Argument -o <file> [outfile <path>] */
      drv_check_arg (arg,				
		     "-o",				
		     return drv_process_out_file (argv[*pos++]));
    }
    break;

  case 's' :
    {
      /* Argument -std=<c89|c99|c11|cpp98|cpp11> */
      drv_check_arg (arg,					
		     "-std=",					
		     return drv_process_language_standard (arg+4));
    }
    break;

  case 'v' :
    {
      /* Argument -v [verbose] */
      drv_check_arg (arg,"-v",return settings_.verbose = true);
    }
    break;
	
  default :
    break;
  }

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_check_warning function
//
// Check a warning flag given as parameter, and if it is valid, apply it to
// the settings.
//
bool drv_check_warning (char* arg)
{
  /* -Wall / --warning all */
  drv_check_arg (arg,"all",set_warnings (WT_ALL); return true);

  /* -Wextra / --warning extra */
  drv_check_arg (arg,"extra",set_warnings (WT_EXTRA); return true);

  /* -Weffc++ / --warning effc++ */
  drv_check_arg (arg,"effc++",set_warnings (WT_CXX_EFFCXX); return true);

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
    settings_.source_type = SFT_SOURCE;

  /* C header file / C implementation file */
  else if (strcmp (ext1, "h") == 0)
    if (strcmp (ext2, "c.h") == 0)
      settings_.source_type = SFT_IMPLEMENTATION;
    else
      settings_.source_type = SFT_HEADER;

  /* Assembler file */
  else if (strcmp (ext1, "s") == 0
	   || strcmp (ext1, "S") == 0
	   || strcmp (ext1, "asm") == 0)
    settings_.source_type = SFT_ASSEMBLER;

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
    }

  /* C++ header file */
  else if (strcmp (ext1, "hpp") == 0
	   || strcmp (ext1, "hxx") == 0
	   || strcmp (ext1, "H") == 0)
    {
      lang = L_CXX;
      settings_.source_type = SFT_HEADER;
    }

  /* C++ implementation file */
  else if (strcmp (ext1, "ipp") == 0)
    {
      lang = L_CXX;
      settings_.source_type = SFT_IMPLEMENTATION;
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
// drv_process_path function
//
// Set include path.
//
bool drv_process_path (slcc_path_type type, char* arg, bool attached)
{
  if (attached)
    if (*arg == '\0')
      return false;
    else
      return add_file_or_path (type, arg);
  else
    return add_file_or_path (type, arg+2);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_process_language_standard function
//
// Check language standard and set settings correctly.
//
bool drv_process_language_standard (char* arg)
{
  if (strncmp (arg, "c89", 3))
    {
      settings_.language = L_C;
      settings_.standard = LS_C89;
    }
  else if (strncmp (arg, "c99", 3))
    {
      settings_.language = L_C;
      settings_.standard = LS_C99;
    }
  else if (strncmp (arg, "c11", 3))
    {
      settings_.language = L_C;
      settings_.standard = LS_C11;
    }
  else if (strncmp (arg, "c1y", 3))
    {
      settings_.language = L_C;
      settings_.standard = LS_C1Y;
    }
  else if (strncmp (arg, "cpp98", 5))
    {
      settings_.language = L_CXX;
      settings_.standard = LS_CXX98;
    }
  else if (strncmp (arg, "cpp11", 5))
    {
      settings_.language = L_CXX;
      settings_.standard = LS_CXX11;
    }
  else if (strncmp (arg, "cpp1y", 5))
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

//==============================================================================

//-<EOF>
