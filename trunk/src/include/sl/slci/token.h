
/*-
 * Copyright (c) 2009 Roel Sergeant.
 * All rights reserved.
 *
 * This code is derived from software contributed to the Snow Leopard
 * project.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SL_SLCI_TOKEN_H_
#define _SL_SLCI_TOKEN_H_

/* Standard C headers */
#include <stddef.h>

/* Snow Leopard headers */
#include "sl/slci/literal.h"
#include "sl/slci/source_position.h"
#include "sl/slci/string.h"

/*
 * Token type enum.
 */
enum slci_token_type
	{
		TT_EOF,          /* EOF token */         
	        TT_EMPTY,        /* Empty token */
		TT_COMMENT,      /* Comment token */
		TT_PREPROCESSOR, /* Preprocessor token */
		TT_KEYWORD,      /* Keyword token */
		TT_PUNCTUATION,  /* Punctuation token */
		TT_LITERAL,      /* Literal token */
		TT_IDENTIFIER    /* Identifier token */
	};

typedef enum slci_token_type slci_token_type;

/*
 * Keyword enum.
 */
enum slci_keyword
	{
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
		KW_WHILE             /* while */
	};

typedef enum slci_keyword slci_keyword;

/*
 * Keyword list (sorted alphabetically because it is searched with a binary search).
 */
extern char* keyword_list[];
extern const size_t keyword_list_length;

/*
 * Punctuation enum.
 */
enum slci_punctuation
	{
		PU_XOR,                   /* ^ */
		PU_XOR_EQ,                /* ^= */
		PU_MINUS,                 /* - */
		PU_MINUS_MINUS,           /* -- */
		PU_INDIRECT,              /* -> */
	        PU_MINUS_EQ,              /* -= */
		PU_INDIRECT_PTR,          /* ->* */
		PU_COMMA,                 /* , */
		PU_SEMICOLON,             /* ; */
		PU_DOUBLE_POINT,          /* : */
		PU_SCOPE_RESOLUTION,      /* :: */
		PU_ALT_SQUARE_CLOSE,      /* :> */
		PU_NOT,                   /* ! */
		PU_NOT_EQ,                /* != */
		PU_CONDITION,             /* ? */
		PU_PERIOD,                /* . */
		PU_TRIPLE_PERIOD,         /* ... */
		PU_MEMBER_PTR,            /* .* */
		PU_BRACKET_OPEN,          /* ( */
		PU_BRACKET_CLOSE,         /* ) */
		PU_SQUARE_OPEN,           /* [ */
		PU_SQUARE_CLOSE,          /* ] */
		PU_CURLY_BRACE_OPEN,      /* { */
		PU_CURLY_BRACE_CLOSE,     /* } */
		PU_STAR,                  /* * */
		PU_MULTIPLY_EQ,           /* *= */
		PU_DIVIDE,                /* / */
		PU_DIVIDE_EQ,             /* /= */
		PU_BITAND,                /* & */
		PU_AND,                   /* && */
		PU_AND_EQ,                /* &= */
		PU_CROSS,                 /* # */
		PU_CROSS_CROSS,           /* ## */
		PU_MODULUS,               /* % */
		PU_ALT_CROSS,             /* %: */
		PU_ALT_CROSS_CROSS,       /* %:%: */
		PU_MODULUS_EQ,            /* %= */
		PU_ALT_CURLY_BRACE_CLOSE, /* %> */
		PU_PLUS,                  /* + */
		PU_PLUS_PLUS,             /* ++ */
		PU_PLUS_EQ,               /* += */
		PU_LESS_THAN,             /* < */
		PU_ALT_SQUARE_OPEN,       /* <: */
		PU_ALT_CURLY_BRACE_OPEN,  /* <% */
		PU_SHIFT_LEFT,            /* << */
		PU_SHIFT_LEFT_EQ,         /* <<= */
		PU_LESS_THAN_EQ,          /* <= */
		PU_EQ,                    /* = */
		PU_EQ_EQ,                 /* == */
		PU_GREATER,               /* > */
		PU_GREATER_EQ,            /* >= */
		PU_SHIFT_RIGHT,           /* >> */
		PU_SHIFT_RIGHT_EQ,        /* >>= */
		PU_BITOR,                 /* | */
		PU_OR_EQ,                 /* |= */
		PU_OR,                    /* || */
		PU_COMPL,                 /* ~ */
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
		PU_ALT_XOR_EQ             /* xor_eq */
	};

typedef enum slci_punctuation slci_punctuation;

/*
 * Punctuation list (sorted alphabetically because it is searched with a binary search).
 */
extern char* punctuation_list[];
extern const size_t punctuation_list_length;

/*
 * Token structure.
 */
struct slci_token
{
	slci_token_type type;
	slci_source_position pos;
	
	union {
		char* comment;
		unsigned int identifier_position;
		slci_keyword keyword;
		slci_literal literal;
		slci_punctuation punctuation;
	};
};

typedef struct slci_token slci_token;

/*
 * Function prototypes
 */
slci_token character_token (char, slci_source_position);
slci_token comment_token (const slci_string*, slci_source_position);
slci_token empty_token (slci_source_position);
slci_token eof_token ();
slci_token string_token (const slci_string*, slci_source_position);
void print_token (size_t, slci_token);

#endif /* !_SL_SLCI_TOKEN_H_ */

/*>- EOF -<*/
