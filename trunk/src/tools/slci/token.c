
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

/* Standard C headers */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* Snow Leopard headers */
#include "sl/slci/cpp_symtab.h"
#include "sl/slci/literal.h"
#include "sl/slci/source_position.h"
#include "sl/slci/string.h"
#include "sl/slci/symbol_table.h"
#include "sl/slci/token.h"

/*
 * Keyword list.
 */
char* keyword_list[] = {
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
	"while"
};

/*
 * Keyword list length.
 */
const size_t keyword_list_length = 72;

/*
 * Punctuation list.
 */
char* punctuation_list[] = {
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

/*
 * Punctuation list length.
 */
const size_t punctuation_list_length = 69;

/*
 * destroy_token function. This function destroys a token.
 */
void
destroy_token (slci_token* token)
{
	destroy_source_position (&token->pos);

	switch (token->type)
	{
	case TT_BUILT_IN:
		free (token->built_in);
		break;

	case TT_COMMENT:
		free (token->comment);
		break;

	case TT_IDENTIFIER:
		free (token->identifier);
		break;

	case TT_LITERAL:
		destroy_literal (&token->literal);
		break;

	case TT_PREPROCESSOR:
		free (token->preprocessor);
		break;

	default:
		/* Other token types need no special handling */
		break;
	}
}

/*
 * built_in_token function. This function returns a token for a built-in.
 */
slci_token
built_in_token (char* s, slci_source_position pos)
{
	slci_token token;

	token.type = TT_BUILT_IN;
	token.pos = pos;

	token.built_in = s;

	return token;
}

/*
 * character_token function. This function returns a character token.
 */
slci_token
character_token (char c, slci_source_position pos)
{
	slci_token token;

	token.type = TT_LITERAL;
	token.pos = pos;

	token.literal.type = LT_SIGNED_CHAR;
	token.literal.schar_value = c;

	return token;
}

/*
 * comment_token function. This function returns a comment token.
 */
slci_token
comment_token (const slci_string* s, slci_source_position pos)
{
	slci_token token;

	token.type = TT_COMMENT;
	token.pos = pos;
	token.comment = get_c_string (s);

	return token;
}

/*
 * empty_token function. This function returns an empty token.
 */
slci_token
empty_token (slci_source_position pos)
{
	slci_token token;

	token.type = TT_EMPTY;
	token.pos = pos;

	return token;
}

/*
 * eof_token function. This function return an eof token.
 */
slci_token
eof_token ()
{
	slci_token token;

	token.type = TT_EOF;

	return token;
}

/*
 * identifier_token function. This function returns an identifier token.
 */
slci_token
identifier_token (const slci_string* s, slci_source_position pos)
{
	slci_token token;

	token.type = TT_IDENTIFIER;

	token.pos = pos;

	token.identifier = get_c_string (s);

	return token;
}

/*
 * keyword_token function. This function returns a keyword token.
 */
slci_token
keyword_token (slci_keyword keyword, slci_source_position pos)
{
	slci_token token;

	token.type = TT_KEYWORD;

	token.pos = pos;

	token.keyword = keyword;

	return token;
}

/*
 * preprocessor_token function. This function returns a preprocessor token.
 */
slci_token
preprocessor_token (const slci_string* s, slci_source_position pos)
{
	slci_token token;

	token.type = TT_PREPROCESSOR;
	token.pos = pos;

	token.preprocessor = get_c_string (s);

	/* Cut last character from string (it's \n) */
	token.preprocessor[strlen (token.preprocessor) - 1] = '\0';

	return token;
}

/*
 * preprocessor_built_in_token function. This function returns a preprocessor built in token.
 */
slci_token
preprocessor_built_in_token (char* s, slci_source_position pos)
{
	slci_token token;

	token.type = TT_PREPROCESSOR_BUILT_IN;
	token.pos = pos;

	token.preprocessor = s;

	return token;
}

/*
 * punctuation_token function. This function returns a punctuation token.
 */
slci_token
punctuation_token (slci_punctuation punctuation, slci_source_position pos)
{
	slci_token token;

	token.type = TT_PUNCTUATION;

	token.pos = pos;

	token.punctuation = punctuation;

	return token;
}

/*
 * string_token function. This function returns a string token.
 */
slci_token
string_token (const slci_string* s, slci_source_position pos)
{
	slci_token token;

	token.type = TT_LITERAL;
	token.pos = pos;

	token.literal.type = LT_STRING;

	token.literal.string.size = s->size;
	token.literal.string.value = get_c_string (s);

	return token;
}

/*
 * wcharacter_token function. This function returns a wcharacter token.
 */
slci_token
wcharacter_token (wchar_t c, slci_source_position pos)
{
	slci_token token;

	token.type = TT_LITERAL;
	token.pos = pos;

	token.literal.type = LT_WCHAR_T;
	token.literal.wchar_t_value = c;

	return token;
}

/*
 * wstring_token function. This function returns a wstring token.
 */
slci_token
wstring_token (const slci_wstring* s, slci_source_position pos)
{
	slci_token token;

	token.type = TT_LITERAL;
	token.pos = pos;

	token.literal.type = LT_WSTRING;

	token.literal.wstring.size = s->size;
	token.literal.wstring.value = get_wc_string (s);

	return token;
}

/*
 * print_token function. This function prints a token.
 */
void
print_token (size_t i, slci_token token)
{
	switch (token.type)
	{
	case TT_EMPTY:
		printf ("%i: EMPTY token", i);
		break;

	case TT_COMMENT:
		printf ("%i: COMMENT <%s>\n", i, token.comment);
		break;

	case TT_PREPROCESSOR:
		printf ("%i: PREPROCESSOR <%s>\n", i, token.preprocessor);
		break;

	case TT_KEYWORD:
		printf (
			"%i: KEYWORD <%s>\n",
			i,
			keyword_list[token.keyword]
			);
		break;

	case TT_PUNCTUATION:
		printf (
			"%i: PUNCTUATION <%s>\n",
			i,
			punctuation_list[token.punctuation]
			);
		break;

	case TT_LITERAL:
		printf (
			"%i: LITERAL <type: %i;lexeme: %s>\n",
			i,
			-1,

			"TODO"
			);
		break;

	case TT_IDENTIFIER:
		printf (
			"%i: IDENTIFIER <%s>\n",
			i,
			token.identifier
			);
		break;

	default:
		printf ("%i: UNKNOWN TOKEN\n", i);
		break;
	}
}

/*>- EOF -<*/
