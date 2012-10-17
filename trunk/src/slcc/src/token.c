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
// token.c
//------------------------------------------------------------------------------
// Token information for the compiler front end.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdlib.h>

#include "token.h"

//------------------------------------------------------------------------------
// keyword_list_ array
//
// Keyword list sorted alphabetically.
//
char* keyword_list_[] = {
  "alignof",
  "asm",
  "auto",
  "axiom",
  "bool",
  "break",
  "case",
  "catch",
  "char",
  "char16_t",
  "char32_t",
  "class",
  "concept",
  "concept_map",
  "const",
  "const_cast",
  "constexpr",
  "continue",
  "decltype",
  "default",
  "delete",
  "do",
  "double",
  "dynamic_cast",
  "else",
  "enum",
  "explicit",
  "export",
  "extern",
  "false",
  "float",
  "for",
  "friend",
  "goto",
  "if",
  "inline",
  "int",
  "late_check",
  "long",
  "mutable",
  "namespace",
  "new",
  "nullptr",
  "operator",
  "private",
  "protected",
  "public",
  "register",
  "reinterpret_cast",
  "requires",
  "restrict", 
  "return",
  "short",
  "signed",
  "sizeof",
  "static",
  "static_assert",
  "static_cast",
  "struct",
  "switch",
  "template",
  "this",
  "thread_local",
  "throw",
  "true",
  "try",
  "typedef",
  "typeid",
  "typename",
  "union",
  "unsigned",
  "using",
  "virtual",
  "void",
  "volatile",
  "wchar_t",
  "while", 
  "_Alignas", 
  "_Alignof",
  "_Atomic", 
  "_Bool",
  "_Complex",
  "_Generic",
  "_Imaginary",
  "_Noreturn",
  "_Static_assert",
  "_Thread_local"
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// keyword_list_length_ constant 
//
// Keyword list length.
//
const size_t keyword_list_length_ = 97;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 
//
// Punctuation list sorted alphabetically.
//
char* punctuation_list_[] = {
  "!",
  "!=",
  "#",
  "##",
  "%",
  "%:",
  "%:%:",
  "%=",
  "%>",
  "&",
  "&&",
  "&=",
  "(",
  ")",
  "*",
  "*=",
  "+",
  "++",
  "+=",
  ",",
  "-",
  "--",
  "-=",
  "->",
  "->*",
  ".",
  ".*",
  "...",
  "/",
  "/=",
  ":",
  "::",
  ":>",
  ";",
  "<",
  "<%",
  "<:",
  "<<",
  "<<=",
  "<=",
  "=",
  "==",
  ">",
  ">=",
  ">>",
  ">>=",
  "?",
  "[",
  "]",
  "^",
  "^=",
  "and",
  "and_eq",
  "bitand",
  "bitor",
  "compl",
  "delete",
  "new",
  "not",
  "not_eq",
  "or",
  "or_eq",
  "xor",
  "xor_eq",
  "{",
  "|",
  "|=",
  "||",
  "}",
  "~"
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// punctuation_list_length_ constant 
//
// Punctuation list length.
//
const size_t punctuation_list_length_ = 69;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// empty_token_ const
//
// This token is used to initialize tokens in the lexer. It will also be 
// returned, but with NoSourcePosition filled in if the lexer doesn't know
// how to handle the code it was given.
//
const slcc_token empty_token_ = {
  TT_EMPTY,                
  SLCC_NO_SOURCE_POSITION, 
  {NULL}                   
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_delete function
//
// This function destroys a token.
//
void token_delete (slcc_token* token) 
{
  switch (token->type) {
  case TT_BUILT_IN:
    free (token->value.built_in);
    break;

  case TT_COMMENT:
    free (token->value.comment);
    break;

  case TT_IDENTIFIER:
    free (token->value.identifier);
    break;

  case TT_LITERAL:
    literal_delete (&token->value.literal);
    break;

  case TT_PREPROCESSOR:
    free (token->value.preprocessor);
    break;

  default:
    /* Other token types need no special handling */
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// token_print function
//
// This function prints a token.
//
void token_print (size_t u, slcc_token token) 
{
  switch (token.type) {
  case TT_EMPTY :
    printf ("%llu: EMPTY token", (unsigned long long)u);
    break;
    
  case TT_COMMENT :
    printf ("%llu: COMMENT <%s>\n", (unsigned long long)u, token.value.comment);
    break;
    
  case TT_PREPROCESSOR :
    printf (
	    "%llu: PREPROCESSOR <%s>\n", 
	    (unsigned long long)u, 
	    token.value.preprocessor
	    );
    break;
    
  case TT_KEYWORD :
    printf (
	    "%llu: KEYWORD <%s>\n",
	    (unsigned long long)u,
	    keyword_list_[token.value.keyword]
	    );
    break;
    
  case TT_PUNCTUATION :
    printf (
	    "%llu: PUNCTUATION <%s>\n",
	    (unsigned long long)u,
	    punctuation_list_[token.value.punctuation]
	    );
    break;
    
  case TT_LITERAL : 
    switch(token.value.literal.type) {
    case LT_BOOL :
      printf(
	     "%llu: LITERAL <type: LT_BOOL; lexeme: %s; value: %s>\n", 
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     token.value.literal.value.bool_value == true ? "true" : "false"
	     );
      break;
      
    case LT_UNSIGNED_CHAR :
      printf(
	     "%llu: LITERAL <type: LT_UNSIGNED_CHAR; lexeme: %s; value: %i>\n", 
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     (unsigned int)token.value.literal.value.uchar_value
	     );
      break;
      
    case LT_SIGNED_CHAR :
      printf(
	     "%llu: LITERAL <type: LT_SIGNED_CHAR; lexeme: %s; value: %i>\n", 
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     (int)token.value.literal.value.schar_value
	     );
      break;

    case LT_SIGNED_INT :
      printf(
	     "%llu: LITERAL <type: LT_SIGNED_INT; lexeme: %s; value: %i>\n",
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     token.value.literal.value.sint_value
	     );
      break;

    case LT_SIGNED_LONG :
      printf(
	     "%llu: LITERAL <type: LT_SIGNED_LONG; lexeme: %s; value: %li>\n",
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     token.value.literal.value.slong_value
	     );
      break;

    case LT_UNSIGNED_LONG :
      printf(
	     "%llu: LITERAL <type: LT_UNSIGNED_LONG; lexeme: %s; value: %lu>\n",
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     token.value.literal.value.ulong_value
	     );
      break;

    case LT_UNSIGNED_LONG_LONG :
      printf(
	     "%llu: LITERAL <type: LT_UNSIGNED_LONG_LONG; lexeme: %s; value: %llu>\n",
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     token.value.literal.value.ulong_long_value
	     );
      break;

    default:
      printf(
	     "%llu: LITERAL <type: -1; lexeme: %s; value: %s>\n", 
	     (unsigned long long)u,
	     token.value.literal.lexeme,
	     "<TODO: Print more types>"
	     );
      break;
    }
    break;

  case TT_IDENTIFIER :
    printf (
	    "%llu: IDENTIFIER <%s>\n",
	    (unsigned long long)u,
	    token.value.identifier
	    );
    break;
      
  default :
    printf ("%llu: UNKNOWN TOKEN\n", (unsigned long long)u);
    break;
  }
}
//------------------------------------------------------------------------------

//-<EOF>
