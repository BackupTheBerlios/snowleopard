/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// preprocessor.c
//------------------------------------------------------------------------------
// Preprocessor for the compiler front end. 
// <TODO: fix unused parameters
//        + remove -Wno-unused-parameter from object_rules.mk>
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "error_codes.h"
#include "lexer.h"
#include "preprocessor_symtab.h"
#include "preprocessor.h"
#include "reader.h"
#include "strings.h"

#include "char_functions.h"

//------------------------------------------------------------------------------
// Private global variables
//
bool skipping_code;
size_t current_nesting;
slcc_error_code last_error;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private global constants
//
const char* DefaultMacroValue = "0";
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private preprocessor command strings
//
const char* DirectiveDEFINE = "define";
const char* DirectiveDEFINED = "defined";
const char* DirectiveELIF = "elif";
const char* DirectiveELIFDEFINED = "elifdefined";
const char* DirectiveELIFNOTDEFINED = "elif!defined";
const char* DirectiveELSE = "else";
const char* DirectiveENDIF = "endif";
const char* DirectiveERROR = "error";
const char* DirectiveIF = "if";
const char* DirectiveIFDEF = "ifdef";
const char* DirectiveIFDEFINED = "ifdefined";
const char* DirectiveIFNDEF = "ifndef";
const char* DirectiveIFNOTDEFINED = "if!defined";
const char* DirectiveINCLUDE = "include";
const char* DirectiveLINE = "line";
const char* DirectivePRAGMA = "pragma";
const char* DirectiveUNDEF = "undef";
const char* DirectiveWARNING = "warning";
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private functions
//
static bool pp_check_condition (const slcc_string* s);
static bool pp_check_preprocessor_cmd (const char* s, const char* cmd);
static bool pp_check_preprocessor_cmd_in_string (
						 const slcc_string* s, 
						 const char* cmd
						 );
static bool pp_get_define (
			   const slcc_string* s, 
			   const char* cmd, 
			   char* macro, 
			   char* body
			   );
static char* pp_get_defined (const slcc_string* s);
static bool pp_process_define (const slcc_string* s);
static bool pp_process_endif (const slcc_string* s);
static bool pp_process_error (const slcc_string* s);
static bool pp_process_include (const slcc_string* s);
static bool pp_process_if (const slcc_string* s);
static bool pp_process_line (const slcc_string* s);
static bool pp_process_pragma (const slcc_string* s);
static bool pp_process_undef (const slcc_string* s);
static bool pp_process_warning (const slcc_string* s);
static void pp_skip_to_endif ();
static void pp_skip_to_else_elif_endif ();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_initialize function
//
// Initializes the preprocessor.
//
bool pp_initialize () 
{
  if (!pp_symtab_new ()) 
    {
      /* TODO - Display error */
      return false;
    }

  skipping_code = false;
  current_nesting = 0;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_delete function
//
// Destroys the preprocessor.
//
void pp_delete () 
{
  pp_symtab_delete ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_is_skipping_code function
//
// Returns true if the preprocessor is skipping code, otherwise it returns 
// false.
//
bool pp_is_skipping_code ()
{
  return skipping_code;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_is_function function
//
// Returns true if the symbol is a preprocessor function.
//
bool pp_is_function (const slcc_string* identifier)
{
  /* <TODO: Implement lookup for function> */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_is_symbol function
//
// Returns true if the symbol given is a preprocessor symbol.
//
bool pp_is_symbol (const slcc_string* identifier)
{
  return pp_symtab_get_macro_position (identifier) != 0 ? false : true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_directive function
//
// Processes a preprocessor directive.
//
bool pp_process_directive (const slcc_string* s) 
{
  bool ok = false;

  /* If in skip mode, do not process tokens */
  if (!skipping_code) 
    {
      size_t pos = str_get_first_none_whitespace (s, 1);
      char c = str_get_char_from_string (s, pos);
      
      switch (c) {
      case 'd' : /* #define */
        ok = pp_process_define (s);
        break;

      case 'e' : /* #endif or #error */
        if (str_get_char_from_string (s, pos + 1) == 'n')
          ok = pp_process_endif (s);
        else
          ok = pp_process_error (s);
        break;

      case 'i' : /* #if (and variants) or #include */
        if (str_get_char_from_string (s, pos + 1) == 'f')
          ok = pp_process_if (s);
        else
          ok = pp_process_include (s);
        break;

      case 'l' : /* #line */
        ok = pp_process_line (s);
        break;

      case 'p' : /* #pragma */
        ok = pp_process_pragma (s);
        break;

      case 'u' : /* #undef */
        ok = pp_process_undef (s);
        break;

      case 'w' : /* #warning */
        ok = pp_process_warning (s);
        break;

      default :
        last_error = EC_PP_INVALID_DIRECTIVE;
        break;

      }

      if  (!ok) 
	{
	  /* TODO - Report last error */;
	}

    }
  return ok;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_function function
//
// Preprocesses a function by replacing it with the fully expanded version.
//
void pp_process_function (const slcc_string* s)
{
  /* TODO: Preprocess function received */
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_string function
//
// Preprocesses string by replacing macros with the corresponding values.
//
void pp_process_string (const slcc_string* s) 
{
  /* TODO: Preprocess string received */
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// pp_check_condition function
//
// Checks the condition in an #IF or #ELIF statement.
//
bool pp_check_condition (const slcc_string* s) 
{
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_check_preprocessor_cmd function
//
// Checks if the input string is the preprocessor command given.
//
bool pp_check_preprocessor_cmd (const char* s, const char* cmd) 
{
  size_t i;
  size_t j;
  size_t offset;
  size_t size = strlen (s);

  /* Start over # and whitespace */
  for (i = 0; i != size; ++i)
    if (s[i] != '#'
        && !tc_is_whitespace (s[i]))
      break;

  offset = i;
  size = strlen (cmd);
  for (i = j = 0; i != size; ++i, ++j) {
    char c = s[i + offset];

    /* If c is whitespace, skip */
    if (c != '\n' && tc_is_whitespace (c))
      i++;
    /* Does c match character in valid command */
    else if (c != cmd[j])
      return false;
  }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// check_preprocessor_comamnd_in_string function
//
// Check if the input string is the preprocessor command given.
//
bool pp_check_preprocessor_cmd_in_string(
					 const slcc_string* s,
					 const char* cmd
					 ) 
{
  char* string = str_get_c_string (s);
  bool r = pp_check_preprocessor_cmd (string, cmd);

  free(string);
  return r;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_get_define function
//
// Get definition used in #DEFINE.
//
bool pp_get_define (
		    const slcc_string* s, 
		    const char* cmd, 
		    char* macro, 
		    char* body
		    ) 
{
  macro = str_get_c_string_after (s, cmd);
  body = str_get_c_string_after (s, macro);

  if (strcmp (macro, "") == 0)
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_get_defined function
//
// Get definition used in #IFNDEF or #IFDEF.
//
char* pp_get_defined (const slcc_string* s) 
{
  char* macro = str_get_last_word_in_string (s);

  if (strcmp (macro, "") == 0)
    return "";

  return macro;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_define function
//
// Processes a #define preprocessor line.
//
bool pp_process_define (const slcc_string* s) 
{
  char* macro;
  char* body;

  if (!pp_check_preprocessor_cmd_in_string (s, DirectiveDEFINE))
    return false;

  if (!pp_get_define (s, DirectiveDEFINE, macro, body))
    return false;

  if (strcmp (str_get_c_string(s), "") == 0)
    return false;

  if (!symtab_set_entry 
      (
       &preprocessor_symtab,
       macro,
       token_new_preprocessor (s, rdr_get_current_source_position ()),
       rdr_get_current_source_position (),
       body
       )
      ) 
    {
      /* TODO - Report error */
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_endif function
//
// Processes an #endif preprocessor line.
//
bool pp_process_endif (const slcc_string* s) 
{
  /* Is this an #endif line */
  if (!pp_check_preprocessor_cmd_in_string (s, DirectiveENDIF))
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_error function
//
// Processes an #error preprocessor line.
//
bool pp_process_error (const slcc_string* s) 
{
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_include function
//
// Processes an #include preprocessor line.
//
bool pp_process_include (const slcc_string* s) 
{
  char* file;

  /* Is this an #include line */
  if (!pp_check_preprocessor_cmd_in_string (s, DirectiveINCLUDE))
    return false;

  /* Get file name */
  if ((file = str_get_c_string_between (s, '\"', '\"')) == 0)
    if ((file = str_get_c_string_between (s, '<', '>')) == 0)
      return false;

  /* Get full path to file */
  file = rdr_get_full_path_for_file (file);
  if (file == 0)
    return false;

  /* Set file to be read for next token */
  if (!rdr_set_nested_file (file))
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_if function
//
// Processes an #if preprocessor line.
//
bool pp_process_if(const slcc_string* s) 
{
  /* Handle #ifndef, #if !defined, #elif !defined macros */
  if (pp_check_preprocessor_cmd_in_string (s, DirectiveIFNDEF)
      || pp_check_preprocessor_cmd_in_string (s, DirectiveIFNOTDEFINED)
      || (skipping_code
          && pp_check_preprocessor_cmd_in_string (
						  s, 
						  DirectiveELIFNOTDEFINED
						  ))) 
    {
      if (symtab_is_in (&preprocessor_symtab, pp_get_defined (s)))
	pp_skip_to_else_elif_endif ();
    }
  /* Handle #ifdef, #if defined, #elif defined macros */
  else if (pp_check_preprocessor_cmd_in_string (s, DirectiveIFDEF)
           || pp_check_preprocessor_cmd_in_string (s, DirectiveIFDEFINED)
           || (skipping_code
               && pp_check_preprocessor_cmd_in_string (
						       s, 
						       DirectiveELIFDEFINED
						       ))) 
    {
      if (!symtab_is_in (&preprocessor_symtab, pp_get_defined (s)))
	pp_skip_to_else_elif_endif ();
    }
  /* Handle #if <condition>, #elif <condition> macros */
  else if (pp_check_preprocessor_cmd_in_string (s, DirectiveIF)
           || (skipping_code
               && pp_check_preprocessor_cmd_in_string (s, DirectiveELIF))) 
    {
      if (pp_check_condition (s))
	pp_skip_to_else_elif_endif ();
    }
  /* Handle #else macros */
  else if (pp_check_preprocessor_cmd_in_string (s, DirectiveELSE)) 
    {
      pp_skip_to_endif ();
    }
  /* Invalid #if variant */
  else
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_line function
//
// Processes a #line preprocessor line.
//
bool pp_process_line (const slcc_string* s) 
{
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_pragma function
//
// Processes an #pragma preprocessor line.
//
bool pp_process_pragma (const slcc_string* s) 
{
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_undef function
//
// Processes an #undef preprocessor line.
//
bool pp_process_undef (const slcc_string* s) 
{
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_process_warning function
//
// Processes an #warning preprocessor line.
//
bool pp_process_warning (const slcc_string* s) 
{
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_skip_to_endif function
//
// Skip to next #ENDIF token at same nesting level.
//
void pp_skip_to_endif () 
{
  slcc_string* s;
  slcc_token token;

  skipping_code = true;

  for (;;) 
    {
      token = lex_get_next_token (true);

      if (token.type == TT_PREPROCESSOR) 
	{
	  if (pp_check_preprocessor_cmd (
					 token.value.preprocessor,
					 DirectiveIF
					 )
	      )
	    current_nesting++;
	  else if (pp_check_preprocessor_cmd (
					      token.value.preprocessor,
					      DirectiveENDIF
					      )
		   ) 
	    {
	      if (current_nesting == 0)
		break;
	      else
		current_nesting--;
	    }
	}
    }

  /* Process the encountered preprocessor token */
  skipping_code = false;
  s = str_new_with_data (token.value.preprocessor);
  pp_process_directive (s);
  token_delete (&token);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// pp_skip_to_else_elif_endif function
//
// Skip to next #ELSE, #ELIF and #ENDIF token at same nesting level.
//
void pp_skip_to_else_elif_endif () 
{
  slcc_string* s;
  slcc_token token;

  skipping_code = true;

  for (;;) 
    {
      token = lex_get_next_token (true);

      if (token.type == TT_PREPROCESSOR) 
	{
	  if (pp_check_preprocessor_cmd (
					 token.value.preprocessor,
					 DirectiveIF
					 )
	      )
	    current_nesting++;
	  else if (pp_check_preprocessor_cmd (
					      token.value.preprocessor,
					      DirectiveELIF
					      )
		   && current_nesting == 0)
	    break;
	  else if (pp_check_preprocessor_cmd (
					      token.value.preprocessor,
					      DirectiveELSE
					      )
		   && current_nesting == 0)
	    break;
	  else if (pp_check_preprocessor_cmd (
					      token.value.preprocessor,
					      DirectiveENDIF
					      )
		   ) 
	    {
	      if (current_nesting == 0)
		break;
	      else
		current_nesting--;
	    }
	}
    }

  /* Process the encountered preprocessor token */
  skipping_code = false;
  s = str_new_with_data (token.value.preprocessor);
  pp_process_directive (s);
  token_delete (&token);
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
