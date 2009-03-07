
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

/* Snow Leopard headers */
#include "sl/slci/literal.h"

/*
 * Token type enum.
 */
enum slci_token_type
	{
		TT_EOF,          /* EOF token */         
	        TT_EMPTY,        /* Empty token */
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

/*
 * Punctuation enum.
 */
enum slci_punctuation
	{
		PU_SQUARE_OPEN,  /* { */
		PU_SQUARE_CLOSE, /* ) */

	};

typedef enum slci_punctuation slci_punctuation;

/*
 * Punctuation list (sorted alphabetically because it is searched with a binary search).
 */
extern char* punctuation_list[];

/*
 * Token structure.
 */
struct slci_token
{
	slci_token_type type;

	union {
		slci_keyword keyword;
		slci_punctuation punctuation;
		slci_literal literal;
		unsigned int identifier_position;
	};
};

typedef struct slci_token slci_token;

#endif /* !_SL_SLCI_INFO_H_ */

/*>- EOF -<*/
