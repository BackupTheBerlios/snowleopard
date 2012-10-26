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
// token.h
//------------------------------------------------------------------------------
// Token for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_TOKEN_H__
#define __SL_SLCC_TOKEN_H__

#include "config_slcc.h"

#include <stdbool.h>
#include <stddef.h>

#include sl_os_fixinclude(uchar.h)

#include "literal.h"
#include "source_position.h"
#include "strings.h"
#include "types.h"

//------------------------------------------------------------------------------
// slcc_token_type enum
//
// Token types used by the compiler front end.
//
enum slcc_token_type 
  {
    TT_BUILT_IN,              /* Built in type token */
    TT_COMMENT,               /* Comment token */
    TT_EMPTY,                 /* Empty token */
    TT_EOF,                   /* EOF token */
    TT_IDENTIFIER,            /* Identifier token */
    TT_KEYWORD,               /* Keyword token */
    TT_LITERAL,               /* Literal token */
    TT_PREPROCESSOR,          /* Preprocessor token */
    TT_PREPROCESSOR_BUILT_IN, /* Preprocessor built in token */
    TT_PUNCTUATION            /* Punctuation token */
  };

typedef enum slcc_token_type slcc_token_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_keyword enum
//
// Keyword used by the compiler front end.
//
enum slcc_keyword 
  {
    KW_ALIGNAS,          /* alignas */
    KW_ALIGNOF,          /* alignof */
    KW_ASM,              /* asm */
    KW_AUTO,             /* auto */
    KW_AXIOM,            /* axiom */
    KW_BOOL,             /* bool */
    KW_BREAK,            /* break */
    KW_CASE,             /* case */
    KW_CATCH,            /* catch */
    KW_CHAR,             /* char */
    KW_CHAR16_T,         /* char16_t */
    KW_CHAR32_T,         /* char32_t */
    KW_CLASS,            /* class */
    KW_CONCEPT,          /* concept */
    KW_CONCEPT_MAP,      /* concept_map */
    KW_CONST,            /* const */
    KW_CONST_CAST,       /* const_cast */
    KW_CONSTEXPR,        /* constexpr */
    KW_CONTINUE,         /* continue */
    KW_DECLTYPE,         /* decltype */
    KW_DEFAULT,          /* default */
    KW_DELETE,           /* delete */
    KW_DO,               /* do */
    KW_DOUBLE,           /* double */
    KW_DYNAMIC_CAST,     /* dynamic_cast */
    KW_ELSE,             /* else */
    KW_ENUM,             /* enum */
    KW_EXPLICIT,         /* explicit */
    KW_EXPORT,           /* export */
    KW_EXTERN,           /* extern */
    KW_FALSE,            /* false */
    KW_FLOAT,            /* float */
    KW_FOR,              /* for */
    KW_FRIEND,           /* friend */
    KW_GOTO,             /* goto */
    KW_IF,               /* if */
    KW_INLINE,           /* inline */
    KW_INT,              /* int */
    KW_LATE_CHECK,       /* late_check */
    KW_LONG,             /* long */
    KW_MUTABLE,          /* mutable */
    KW_NAMESPACE,        /* namespace */
    KW_NEW,              /* new */
    KW_NULLPTR,          /* nullptr */
    KW_OPERATOR,         /* operator */
    KW_PRIVATE,          /* private */
    KW_PROTECTED,        /* protected */
    KW_PUBLIC,           /* public */
    KW_REGISTER,         /* register */
    KW_REINTERPRET_CAST, /* reinterpret_cast */
    KW_REQUIRES,         /* requires */
    KW_RESTRICT,         /* restrict C11 */
    KW_RETURN,           /* return */
    KW_SHORT,            /* short */
    KW_SIGNED,           /* signed */
    KW_SIZEOF,           /* sizeof */
    KW_STATIC,           /* static */
    KW_STATIC_ASSERT,    /* static_assert */
    KW_STATIC_CAST,      /* static_cast */
    KW_STRUCT,           /* struct */
    KW_SWITCH,           /* switch */
    KW_TEMPLATE,         /* template */
    KW_THIS,             /* this */
    KW_THREAD_LOCAL,     /* thread_local */
    KW_THROW,            /* throw */
    KW_TRUE,             /* true */
    KW_TRY,              /* try */
    KW_TYPEDEF,          /* typedef */
    KW_TYPEID,           /* typeid */
    KW_TYPENAME,         /* typename */
    KW_UNION,            /* union */
    KW_UNSIGNED,         /* unsigned */
    KW_USING,            /* using */
    KW_VIRTUAL,          /* virtual */
    KW_VOID,             /* void */
    KW_VOLATILE,         /* volatile */
    KW_WCHAR_T,          /* wchar_t */
    KW_WHILE,            /* while */
    KW__ALIGNAS,         /* _Alignas C11 */
    KW__ALIGNOF,         /* _Alignof C11 */
    KW__ATOMIC,          /* _Atomic C11 */
    KW__BOOL,            /* _Bool C11 */
    KW__COMPLEX,         /* _Complex C11 */
    KW__GENERIC,         /* _Generic C11 */
    KW__IMAGINARY,       /* _Imaginary C11 */
    KW__NORETURN,        /* _Noreturn C11 */
    KW__STATIC_ASSERT,   /* _Static_assert C11 */
    KW__THREAD_LOCAL     /* _Thread_local C11 */
  };

typedef enum slcc_keyword slcc_keyword;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// keyword_list_ array / keyword_list_length_ constant
//
// Keyword list sorted alphabetically because it is searched with a binary 
// search.
//
extern char* keyword_list_[];
extern const size_t keyword_list_length_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_punctuation enum
enum slcc_punctuation 
  {
    PU_NOT,                   /* ! */
    PU_NOT_EQ,                /* != */
    PU_CROSS,                 /* # */
    PU_CROSS_CROSS,           /* ## */
    PU_MODULUS,               /* % */
    PU_ALT_CROSS,             /* %: */
    PU_ALT_CROSS_CROSS,       /* %:%: */
    PU_MODULUS_EQ,            /* %= */
    PU_ALT_CURLY_BRACE_CLOSE, /* %> */
    PU_BITAND,                /* & */
    PU_AND,                   /* && */
    PU_AND_EQ,                /* &= */
    PU_BRACKET_OPEN,          /* ( */
    PU_BRACKET_CLOSE,         /* ) */
    PU_STAR,                  /* * */
    PU_MULTIPLY_EQ,           /* *= */
    PU_PLUS,                  /* + */
    PU_PLUS_PLUS,             /* ++ */
    PU_PLUS_EQ,               /* += */
    PU_COMMA,                 /* , */
    PU_MINUS,                 /* - */
    PU_MINUS_MINUS,           /* -- */
    PU_MINUS_EQ,              /* -= */
    PU_INDIRECT,              /* -> */
    PU_INDIRECT_PTR,          /* ->* */
    PU_PERIOD,                /* . */
    PU_MEMBER_PTR,            /* .* */
    PU_TRIPLE_PERIOD,         /* ... */
    PU_DIVIDE,                /* / */
    PU_DIVIDE_EQ,             /* /= */
    PU_DOUBLE_POINT,          /* : */
    PU_SCOPE_RESOLUTION,      /* :: */
    PU_ALT_SQUARE_CLOSE,      /* :> */
    PU_SEMICOLON,             /* ; */
    PU_LESS_THAN,             /* < */
    PU_ALT_CURLY_BRACE_OPEN,  /* <% */
    PU_ALT_SQUARE_OPEN,       /* <: */
    PU_SHIFT_LEFT,            /* << */
    PU_SHIFT_LEFT_EQ,         /* <<= */
    PU_LESS_THAN_EQ,          /* <= */
    PU_EQ,                    /* = */
    PU_EQ_EQ,                 /* == */
    PU_GREATER,               /* > */
    PU_GREATER_EQ,            /* >= */
    PU_SHIFT_RIGHT,           /* >> */
    PU_SHIFT_RIGHT_EQ,        /* >>= */
    PU_CONDITION,             /* ? */
    PU_SQUARE_OPEN,           /* [ */
    PU_DOUBLE_SQUARE_OPEN,    /* [[ */
    PU_SQUARE_CLOSE,          /* ] */
    PU_DOUBLE_SQUARE_CLOSE,   /* ]] */
    PU_XOR,                   /* ^ */
    PU_XOR_EQ,                /* ^= */
    PU_ALT_AND,               /* and */
    PU_ALT_AND_EQ,            /* and_eq */
    PU_ALT_BITAND,            /* bitand */
    PU_ALT_BITOR,             /* bitor */
    PU_ALT_COMPL,             /* compl */
    PU_DELETE,                /* delete */
    PU_NEW,                   /* new */
    PU_ALT_NOT,               /* not */
    PU_ALT_NOT_EQ,            /* not_eq */
    PU_ALT_OR,                /* or */
    PU_ALT_OR_EQ,             /* or_eq */
    PU_ALT_XOR,               /* xor */
    PU_ALT_XOR_EQ,            /* xor_eq */
    PU_CURLY_BRACE_OPEN,      /* { */
    PU_BITOR,                 /* | */
    PU_OR_EQ,                 /* |= */
    PU_OR,                    /* || */
    PU_CURLY_BRACE_CLOSE,     /* } */
    PU_COMPL                  /* ~ */
  };

typedef enum slcc_punctuation slcc_punctuation;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// punctuation_list_ array / punctuation_list_length_ constant
//
// Punctuation list sorted alphabetically because it is searched with a binary 
// search.
//
extern char* punctuation_list_[];
extern const size_t punctuation_list_length_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_token struct
//
// Stores a single token of any type.
//
struct slcc_token 
{
  slcc_token_type type;
  slcc_source_position pos;

  union 
  {
    char* built_in;
    char* comment;
    char* identifier;
    slcc_keyword keyword;
    slcc_literal literal;
    char* preprocessor;
    slcc_punctuation punctuation;
    void* empty;
  } value;
};

typedef struct slcc_token slcc_token;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
//
extern const slcc_token empty_token_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Token function prototypes
slcc_token token_new_built_in (char* s, slcc_source_position pos);
slcc_token token_new_char (char c, slcc_source_position pos);
slcc_token token_new_char16 (char16_t c, slcc_source_position pos);
slcc_token token_new_char32 (char32_t c, slcc_source_position pos);
slcc_token token_new_comment (const slcc_string* s, slcc_source_position pos);
slcc_token token_new_empty (slcc_source_position pos);
slcc_token token_new_eof ();
slcc_token token_new_float (
			    slcc_string* s, 
			    slcc_source_position pos, 
			    bool type_float,
			    bool type_long_double
			    );
slcc_token token_new_identifier (
				 const slcc_string* s, 
				 slcc_source_position pos
				 );
slcc_token token_new_int (
			  slcc_string* s, 
			  slcc_source_position pos, 
			  bool is_binary, 
			  bool is_octal,
			  bool is_hexadecimal, 
			  bool is_unsigned,
			  bool type_long,
			  bool type_long_long
			  );
slcc_token token_new_keyword (slcc_keyword keyword, slcc_source_position pos);
slcc_token token_new_preprocessor (
				   const slcc_string* s, 
				   slcc_source_position pos
				   );
slcc_token token_new_preprocessor_built_in (char* s, slcc_source_position pos);
slcc_token token_new_punctuation (
				  slcc_punctuation punctuation, 
				  slcc_source_position pos
				  );
slcc_token token_new_raw_string (char* s, slcc_source_position pos);
slcc_token token_new_string (slcc_string* s, slcc_source_position pos);
slcc_token token_new_string16 (slcc_string16* s, slcc_source_position pos);
slcc_token token_new_string32 (slcc_string32* s, slcc_source_position pos);
slcc_token token_new_wchar (wchar_t c, slcc_source_position pos);
slcc_token token_new_wstring (slcc_wstring* s, slcc_source_position pos);
void token_delete (slcc_token* token);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
void token_print (size_t u, slcc_token token);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_TOKEN_H__ */

//-<EOF>
