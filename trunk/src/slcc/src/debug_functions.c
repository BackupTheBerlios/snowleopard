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
void debug_print_title (const char*);
void debug_print_bool (const char*, bool);
void debug_print_language (const char*, slcc_language);
void debug_print_language_version (const char*, slcc_language_version);
void debug_print_size (const char*, size_t);
void debug_print_string (const char*, const char*);
void debug_print_string_array (const char*, char**, size_t n);
void debug_print_symbol_table (slcc_symtab);
//------------------------------------------------------------------------------

#if __SLCC_DEBUG_SETTINGS
//------------------------------------------------------------------------------
// debug_print_settings function
//
// Print settings object.
//
wvoid debug_print_settings () 
{
  debug_print_title ("SLCC Settings");

  debug_print_bool ("interactive", settings->interactive);
  debug_print_bool ("license", settings->license);
  debug_print_bool ("make rules only", settings->make_rules_only);
  debug_print_bool ("preprocess only", settings->preprocess_only);
  debug_print_bool ("verbose", settings->verbose);
  debug_print_bool ("version", settings->version);
  debug_print_bool ("warrantee", settings->warrantee);

  debug_print_bool ("debug", settings->debug);
  debug_print_language ("language", settings->language);
  debug_print_language_version (
				"language version", 
				settings->language_version
				);
  debug_print_bool ("use deprecated", settings->use_deprecated);

  debug_print_bool ("use concepts", settings->use_concepts);
  debug_print_bool ("use export", settings->use_export);

  debug_print_string ("call", settings->call);
  debug_print_size ("number of arguments", settings->n_arguments);
  if (settings->n_arguments > 0)
    debug_print_string_array (
			      "arguments", 
			      settings->arguments, 
			      settings->n_arguments
			      );

  debug_print_string ("source file", settings->source_file);
  debug_print_size ("number of source paths", settings->n_source_paths);
  if (settings->n_source_paths > 0)
    debug_print_string_array (
			      "source paths", 
			      settings->source_paths, 
			      settings->n_source_paths
			      );

  debug_print_size ("number of include paths", settings->n_include_paths);
  if (settings->n_include_paths > 0)
    debug_print_string_array (
			      "include paths", 
			      settings->include_paths, 
			      settings->n_include_paths
			      );

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
	   l == LAN_NONE ? "none selected" : l == LAN_C ? "C" : "C++"
	   );
}

void debug_print_language_version (const char* s, slcc_language_version l) 
{
  fprintf (
	   stderr,
	   "   %s = %s\n",
	   s,
	   l == LAN_V_NONE ? "none selected" 
	   : l == LAN_V_C99 ? "C99"
	   : l == LAN_V_C11 ? "C11"
	   : l == LAN_V_CPP03 ? "C++03"
	   : l == LAN_V_CPP11 ? "C++11"
	   : "C++11 with extensions"
	   );
}

void debug_print_size (const char* s, size_t n) 
{
  fprintf (stderr, "   %s = %llu\n", s, (unsigned long long)n);
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
