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
// parser.c
//------------------------------------------------------------------------------
// Parser for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "lexer.h"
#include "parse_tree.h"
#include "parser.h"
#include "token.h"

//------------------------------------------------------------------------------
// parser_initialize function
//
// Initializes the code generator.
//
bool parser_initialize ()
{
  parse_tree_ = tc_tree_new_pt ();

  if (parse_tree_ == NULL)
    return false;

  if (!lexer_initialize ())
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// parser_cleanup function
//
// Cleans up all pointers and arrays used by the code generator.
//
void parser_cleanup ()
{
  lexer_cleanup ();
  tc_tree_delete_pt (parse_tree_);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// parser_start function
//
// Starts the code generation process based on the parsed source.
//
bool parser_start ()
{
  size_t i = 0;
  slcc_token token = lex_get_next_token (false);

  while (token.type != TT_EOF)
    {
      if (token.type != TT_EOF && token.type != TT_EMPTY
          && token.type != TT_COMMENT && token.type != TT_PREPROCESSOR
          && token.type != TT_KEYWORD && token.type != TT_PUNCTUATION
          && token.type != TT_LITERAL && token.type != TT_IDENTIFIER)
        return false;

      if (token.type != TT_COMMENT)
        {
          token_print (i, token);
          ++i;
        }

      token = lex_get_next_token (false);
    }

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
