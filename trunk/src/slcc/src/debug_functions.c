/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
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
// debug_functions.c
//------------------------------------------------------------------------------
// Debug functions for the compiler front end.
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// Debug functions
#ifdef __SLCC_DEBUG

#include <stdio.h>

#include "cpp_symtab.h"
#include "preprocessor_symtab.h"
#include "settings.h"
#include "symbol_table.h"

//------------------------------------------------------------------------------
// Private debug functions
void debug_print_title (const char* s);
void debug_print_bool (const char* s, bool b);
void debug_print_language (const char* s, slcc_language l);
void debug_print_language_standard (const char* s, slcc_language_standard l);
void debug_print_size (const char* s, size_t n);
void debug_print_source_file_type (const char* s, slcc_source_file_type t);
void debug_print_string (const char* s, const char* v);
void debug_print_string_array (const char* s, char** a, size_t n);
void debug_print_symbol_table (slcc_symtab symtab);
//------------------------------------------------------------------------------

#ifdef __SLCC_DEBUG_SETTINGS
//------------------------------------------------------------------------------
// debug_print_settings function
//
// Print settings object.
//
void debug_print_settings () 
{
  debug_print_title ("SLCC Settings");

  debug_print_bool ("quiet", settings_.quiet);
  debug_print_bool ("verbose", settings_.verbose);

  debug_print_bool ("copyright", settings_.copyright_only);
  debug_print_bool ("license", settings_.license_only);
  debug_print_bool ("usage", settings_.usage_only);
  debug_print_bool ("warrantee", settings_.warrantee_only);

  debug_print_bool ("compile only", settings_.compile_only);
  debug_print_bool ("dependencies only", settings_.dependencies_only);
  debug_print_bool ("preprocess only", settings_.preprocess_only);

  debug_print_string ("out file", settings_.out_file);
  debug_print_string ("source file", settings_.source_file);
  debug_print_source_file_type ("source file type", settings_.source_type);
  debug_print_size ("number of object files", settings_.object_files->used_);
  if (settings_.object_files->used_ > 0)
    debug_print_string_array (
			      "object files", 
			      settings_.object_files->data_, 
			      settings_.object_files->used_
			      );
  debug_print_size ("number of library files", settings_.object_files->used_);
  if (settings_.library_files->used_ > 0)
    debug_print_string_array (
			      "library files", 
			      settings_.library_files->data_, 
			      settings_.library_files->used_
			      );

  debug_print_language ("language", settings_.language);
  debug_print_language_standard ("standard", settings_.standard);
  debug_print_bool ("use deprecated", settings_.use_deprecated);

  debug_print_bool ("use standard library", settings_.use_stdlib);
  debug_print_size ("number of include paths", settings_.include_paths->used_);
  if (settings_.include_paths->used_ > 0)
    debug_print_string_array (
			      "include paths", 
			      settings_.include_paths->data_, 
			      settings_.include_paths->used_
			      );
  debug_print_size ("number of library paths", settings_.library_paths->used_);
  if (settings_.library_paths->used_ > 0)
    debug_print_string_array (
			      "library paths", 
			      settings_.library_paths->data_, 
			      settings_.library_paths->used_
			      );
  debug_print_size ("number of source paths", settings_.source_paths->used_);
  if (settings_.source_paths->used_ > 0)
    debug_print_string_array (
			      "source paths", 
			      settings_.source_paths->data_, 
			      settings_.source_paths->used_
			      );

  debug_print_bool ("use concepts", settings_.use_concepts);
  debug_print_bool ("use export", settings_.use_export);

  fprintf (stderr, "\n");
}
//------------------------------------------------------------------------------
#endif /* __SLCC_DEBUG_SETTINGS */

#ifdef __SLCC_DEBUG_SYMBOL_TABLES
//------------------------------------------------------------------------------
// debug_print_symbol_table function
//
// Prints the symbol table entries.
//
void debug_print_symbol_table (slcc_symtab symtab) 
{
  for (size_t i = 0; i < symtab.size; ++i) 
    {
      if (symtab.data[i].value != NULL)
	fprintf (
		 stderr,
		 "  %s -> value: %s\n",
		 symtab.data[i].key,
		 symtab.data[i].value
		 );
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// debug_print_preprocessor_symbol_table function
//
// Prints the preprocessor symbol table.
//
void debug_print_preprocessor_symbol_table() {
  fprintf (stderr, "Preprocessor symbol table\n");
  debug_print_symbol_table (preprocessor_symtab);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// debug_print_cpp_symbol_table function
//
// Prints the C++ symbol table.
//
void debug_print_cpp_symbol_table () 
{
  fprintf (stderr, "C++ Symbol table\n");
  debug_print_symbol_table (cpp_symtab);
}
//------------------------------------------------------------------------------
#endif /* __SLCC_DEBUG_SYMBOL_TABLES */

//------------------------------------------------------------------------------
// debug_print functions
//
void debug_print_title (const char* s) 
{
  fprintf (stderr, "<DEBUG> %s\n", s);
}

void debug_print_bool (const char* s, bool b) 
{
  fprintf (stderr, "   %s = %s\n", s, b == true ? "true" : "false");
}

void debug_print_language (const char* s, slcc_language l) 
{
  fprintf (
	   stderr, 
	   "   %s = %s\n", 
	   s, 
	   l == L_NONE ? "none selected" : l == L_C ? "C" : "C++"
	   );
}

void debug_print_language_standard (const char* s, slcc_language_standard l) 
{
  fprintf (
	   stderr,
	   "   %s = %s\n",
	   s,
	   l == LS_NONE ? "none selected" 
	   : l == LS_C99 ? "C99"
	   : l == LS_C11 ? "C11"
	   : "C++11"
	   );
}

void debug_print_size (const char* s, size_t n) 
{
  fprintf (stderr, "   %s = %llu\n", s, (unsigned long long)n);
}

void debug_print_source_file_type (const char* s, slcc_source_file_type t)
{
  fprintf (
	   stderr, 
	   "   %s = %s\n",
	   s,
	   t == SFT_NONE ? "none selected"
	   : t == SFT_ASSEMBLER ? "assembler"
	   : t == SFT_HEADER ? "header"
	   : t == SFT_IMPLEMENTATION ? "implementation"
	   : "source"
	   );
}

void debug_print_string (const char* s, const char* v) 
{
  fprintf (stderr, "   %s = %s\n", s, v);
}

void debug_print_string_array (const char* s, char** a, size_t n) 
{
  fprintf (stderr, "   %s\n", s);
  for (size_t i = 0; i < n; i++)
    fprintf (stderr, "     %llu = %s\n", (unsigned long long)i, a[i]);
}
//------------------------------------------------------------------------------

#endif /* __SLCC_DEBUG */
////////////////////////////////////////////////////////////////////////////////

//-<EOF>
