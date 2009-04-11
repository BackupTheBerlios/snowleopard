
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

#ifndef _SL_SLCI_LITERAL_H_
#define _SL_SLCI_LITERAL_H_

/* Standard C headers */
#include <stdbool.h>
#include <stddef.h>
#include <wchar.h>

/*
 * Literal type enum.
 */
enum slci_literal_type
	{
		LT_BOOL,               /* Boolean value */
		LT_UNSIGNED_CHAR,      /* Unsigned character */
		LT_SIGNED_CHAR,        /* Signed character */
		LT_CHAR16_T,           /* Char16_t character */
		LT_CHAR32_T,           /* Char32_t character */
		LT_WCHAR_T,            /* Wchar_t character */
		LT_UNSIGNED_SHORT,     /* Unsigned short */
		LT_SIGNED_SHORT,       /* Signed short */
		LT_UNSIGNED_INT,       /* Unsigned integer */
		LT_SIGNED_INT,         /* Signed integer */
		LT_UNSIGNED_LONG,      /* Unsigned long */
		LT_SIGNED_LONG,        /* Signed long */
		LT_UNSIGNED_LONG_LONG, /* Unsigned long long */
		LT_SIGNED_LONG_LONG,   /* Signed long long */
		LT_FLOAT,              /* Floating point number */
		LT_DOUBLE,             /* Double floating point number */
		LT_LONG_DOUBLE,        /* Long double floating point number */
		LT_STRING,             /* Character string value */
		LT_STRING16_T,         /* Char16_t string value */
		LT_STRING32_T,         /* Char32_t string value */
		LT_WSTRING,            /* Wchar_t string value */
		LT_USER_DEFINED        /* User defined literal */
	};

typedef enum slci_literal_type slci_literal_type;

/*
 * slci_char_string struct.
 */
struct slci_char_string
{
	size_t size;
	char* value;
};

typedef struct slci_char_string slci_char_string;

/*
 * slci_char16_string struct.
 */
struct slci_char16_string
{
	size_t size;
	unsigned short* value;
};

typedef struct slci_char16_string slci_char16_string;

/*
 * slci_char32_string struct.
 */
struct slci_char32_string
{
	size_t size;
	unsigned int* value;
};

typedef struct slci_char32_string slci_char32_string;

/*
 * slci_wchar_string struct.
 */
struct slci_wchar_string
{
	size_t size;
	wchar_t* value;
};

typedef struct slci_wchar_string slci_wchar_string;

/*
 * Literal struct.
 */
struct slci_literal
{
	slci_literal_type type;

	union {
		bool bool_value;
		unsigned char uchar_value;
		signed char schar_value;
		unsigned short uchar16_t_value;
		signed short schar16_t_value;
		unsigned int uchar32_t_value;
		signed int schar32_t_value;
		wchar_t wchar_t_value;
		unsigned short ushort_value;
		signed short sshort_value;
		unsigned int uint_value;
	        signed int sint_value;
		unsigned long ulong_value;
		signed long slong_value;
		unsigned long long ulong_long_value;
		signed long long slong_long_value;
		float float_value;
		double double_value;
		long double long_double_value;
		slci_char_string string;
		slci_char16_string char16_string;
		slci_char32_string char32_string;
		slci_wchar_string wstring;
	};

	char* lexeme;
};

typedef struct slci_literal slci_literal;

/*
 * Initialize function prototypes.
 */
void destroy_literal (slci_literal*);

#endif /* !_SL_SLCI_LITERAL_H_ */

/*>- EOF -<*/
