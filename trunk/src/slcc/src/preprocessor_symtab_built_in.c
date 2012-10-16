/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// preprocessor_symtab_built_in.c
//------------------------------------------------------------------------------
// Preprocessor symbol table built ins for the compiler front end.
//------------------------------------------------------------------------------

#include "config_slcc.h"

#include "macros.h"

#include <stdbool.h>
#include <stdlib.h>

#include "preprocessor_symtab.h"
#include "settings.h"
#include "source_position.h"
#include "symbol_table.h"
#include "version_slcc.h"

#include "date_functions.h"
#include "string_functions.h"

//------------------------------------------------------------------------------
// Private functions
bool pp_symtab_new_bi_entry (char*, char*);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_symtab_load_built_in_macros function
//
// Loads the built in macros into the symbol table.
//
bool pp_symtab_load_built_in_macros () 
{
  bool ok = true;
  char* buffer;

  /* Snow Leopard macros */
  buffer = malloc (sizeof (char[MaxVersionLabelSize]));
  buffer = get_version_string (buffer);
  ok = pp_symtab_new_bi_entry ("__SLCC__", buffer);

  /* Standard compiler macros */
  ok = pp_symtab_new_bi_entry 
    (
     "__DATE__", 
     tc_get_datetime (11, "%Y-%m-%d")
     );
  ok = pp_symtab_new_bi_entry 
    (
     "__FILE__", 
     tc_copy_string (settings_.source_file)
     );
  ok = pp_symtab_new_bi_entry ("__LINE__", "0");
  ok = pp_symtab_new_bi_entry 
    (
     "__TIME__", 
     tc_get_datetime (9, "%H:%M:%S")
     );

  if (!settings_.use_deprecated)
    ok = pp_symtab_new_bi_entry 
      (
       "__SL_NO_DEPRECATED_FEATURES__", 
       ""
       );
    
  if (settings_.language == L_C) 
    {
      /* Standard C macros */
      ok = pp_symtab_new_bi_entry ("__STDC__", sl_str(__SL_STDC__));
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_HOSTED__",
	 sl_str(__SL_STDC_HOSTED__)
	 );
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_ISO_10646__",
	 sl_str(__SL_STDC_ISO_10646__)
	 );
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_MB_MIGHT_NEQ_WC__",
	 sl_str(__SL_STDC_MB_MIGHT_NEQ_WC__)
	 );
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_UTF_16__", 
	 sl_str(__SL_STDC_UTF_16__)
	 );
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_UTF_32__", 
	 sl_str(__SL_STDC_UTF_32__)
	 );
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_IEC_559__",
	 sl_str(__SL_STDC_IEC_559__)
	 );
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_IEC_559_COMPLEX__",
	 sl_str(__SL_STDC_IEC_559_COMPLEX__)
	 );
      ok = pp_symtab_new_bi_entry 
	(
	 "__STDC_NO_VLA__", 
	 sl_str(__SL_STDC_NO_VLA__)
	 );

      if (settings_.standard == LS_C99) 
	{
	  /* Standard C99 macros */
	  ok = pp_symtab_new_bi_entry 
	    (
	     "__STDC_VERSION__",
	     sl_str(__SL_C99_STDC_VERSION__)
	     );
	}
      else if (settings_.standard == LS_C11) 
	{
	  /* Standard C11 macros */
	  ok = pp_symtab_new_bi_entry 
	    (
	     "__STDC_VERSION__",
	     sl_str(__SL_C11_STDC_VERSION__)
	     );
	  ok = pp_symtab_new_bi_entry 
	    (
	     "__STDC_ANALYZABLE__",
	     sl_str(__SL_C11_STDC_ANALYZABLE__)
	     );
	  ok = pp_symtab_new_bi_entry 
	    (
	     "__STDC_LIB_EXT1__",
	     sl_str(__SL_C11_STDC_LIB_EXT1__)
	     );
	  ok = pp_symtab_new_bi_entry 
	    (
	     "__STDC_NO_ATOMICS__",
	     sl_str(__SL_C11_STDC_NO_ATOMICS__)
	     );
	  ok = pp_symtab_new_bi_entry 
	    (
	     "__STDC_NO_THREADS__",
	     sl_str(__SL_C11_STDC_NO_THREADS__)
	     );
	}
    }
  if (settings_.language == L_CXX) 
    {
      /* Standard C++ macros */
      if (settings_.standard == LS_CXX98)
	ok = pp_symtab_new_bi_entry 
	  (
	   "__cplusplus",
	   sl_str(__SL_CPP03_cplusplus__)
	   );
      else if (settings_.standard == LS_CXX11)
	ok = pp_symtab_new_bi_entry 
	  (
	   "__cplusplus",
	   sl_str(__SL_CPP11_cplusplus__)
	   );

      if (settings_.use_export)
	ok = pp_symtab_new_bi_entry 
	  (
	   "__SL_COMPILER_USE_EXPORT__", 
	   ""
	   );
      if (settings_.use_concepts)
	ok = pp_symtab_new_bi_entry 
	  (
	   "__SL_COMPILER_USE_CONCEPTS__", 
	   ""
	   );
    }
  
  return ok;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_symtab_new_bi_entry function
//
// Create a built-in type symbol table entry.
//
bool pp_symtab_new_bi_entry (char* token, char* value) 
{
  if (!symtab_set_entry (
			 &preprocessor_symtab,
			 token,
			 token_new_preprocessor_built_in (
							  token,
							  NoSourcePosition
							  ),
			 NoSourcePosition,
			 value
			 ))
    return false;

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
