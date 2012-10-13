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

#include "error_codes.h"
#include "error_handling.h"
#include "settings.h"

//------------------------------------------------------------------------------
// Private functions
//
bool drv_check_arguments (); 
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
// drv_cleanup function
//
// Cleans up all components when the compilation process has finished.
//
bool drv_cleanup ()
{

  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_start function
//
// Starts the compilation process.
//
bool drv_start ()
{

  return false;
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

//------------------------------------------------------------------------------
// drv_get_first_error function
//
// Get the first error produced.
//
slcc_error_code drv_get_first_error ()
{

  return EC_NO_ERROR;
};
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// drv_check_arguments function
//
// Check the following:
//   - Was a source file provided.
//   - Is the language standard given compatibel with the language provided.
//
bool drv_check_arguments ()
{
  
  return false;
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
      drv_check_arg(arg,					\
		    "--compile",				\
		    return settings_.compile_only = true);

      /* Argument --copyright */
      drv_check_arg(arg,					\
		    "--copyright",				\
		    return settings_.copyright_only = true);

      /* Argument --help */
      drv_check_arg(arg,				\
		    "--help",				\
		    return settings_.usage_only = true);

      /* Argument --include_path <path> */
      drv_check_arg(arg,						\
		    "--include_path",					\
		    return drv_process_path (PT_INCLUDE, argv[*pos++], false));

      /* Argument --library_path <path> */
      drv_check_arg(arg,						\
		    "--library_path",					\
		    return drv_process_path (PT_LIBRARY, argv[*pos++], false));

      /* Argument --no_stdlib */
      drv_check_arg(arg,					\
		    "--no_stdlib",				\
		    return !(settings_.use_stdlib = false));

      /* Argument --outfile <path> */
      drv_check_arg(arg,					\
		    "--outfile",				\
		    return drv_process_out_file (argv[*pos++]));

      /* Argument --preprocess */
      drv_check_arg(arg,					\
		    "--preprocess",				\
		    return settings_.preprocess_only = true);

      /* Argument --source_path <path> */
      drv_check_arg(arg,						\
		    "--source_path",					\
		    return drv_process_path (PT_SOURCE, argv[*pos++], false));

      /* Argument --usage */
      drv_check_arg(arg,				\
		    "--usage",				\
		    return settings_.usage_only = true);

      /* Argument --warrantee */
      drv_check_arg(arg,					\
		    "--warrantee",				\
		    return settings_.warrantee_only = true);
    }
    break;

  case 'E' :
    {
      /* Argument -E [preprocess] */
      drv_check_arg(arg,					\
		    "-E",					\
		    return settings_.preprocess_only = true);
    }
    break;

  case 'I' :
    {
      /* Argument -I<path> [include_path <path>] */
      drv_check_arg(arg,						\
		    "-I",                                               \
		    return drv_process_path (PT_INCLUDE, argv[*pos++], true));
    }
    break;

  case 'L' :
    {
      /* Argument -L<path> [library_path <path>] */
      drv_check_arg(arg,						\
		    "-L",						\
		    return drv_process_path (PT_LIBRARY, argv[*pos++], true));
    }
    break;

  case 'S' :
    {
      /* Argument -S<path> [source_path <path>] */
      drv_check_arg(arg,						\
		    "-S",						\
		    return drv_process_path (PT_SOURCE, argv[*pos++], true));
    }
    break;

  case 'c' :
    {
      drv_check_arg(arg,"-c",return settings_.compile_only = true);
    }
    break;

  case 'h' :
    {
      /* Argument -h [help] */
      drv_check_arg(arg,"-h",return settings_.usage_only = true);
    }
    break;

  case 'q' :
    {
      /* Argument -q [quiet] */
      drv_check_arg(arg,"-q",return settings_.quiet = true);
    }
    break;

  case 'o' :
    {
      /* Argument -o <file> [outfile <path>] */
      drv_check_arg(arg,					\
		    "-o",					\
		    return drv_process_out_file (argv[*pos++]));
    }
    break;

  case 's' :
    {
      /* Argument -std=<c89|c99|c11|cpp98|cpp11> */
      drv_check_arg(arg,						\
		    "-std=",						\
		    return drv_process_language_standard (arg+4));
    }
    break;

  case 'v' :
    {
      /* Argument -v [verbose] */
      drv_check_arg(arg,"-v",return settings_.verbose = true);
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
//         c/h                     - C source file
//         cpp/cxx/hpp/hxx/C/H/ipp - C++ source file
//
bool drv_process_file_argument (char* file)
{

  return false;
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
    if (&arg == '\0')
      return false;
    else
      return add_path (type, arg);
  else
    return add_path (type, arg+2);
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
  if (&arg == '\0')
    return false;
  else
    return set_out_file (arg);
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
