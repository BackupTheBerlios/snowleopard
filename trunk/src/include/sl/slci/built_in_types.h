
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

#ifndef _SL_SLCI_BUILT_IN_TYPES_H_
#define _SL_SLCI_BUILT_IN_TYPES_H_

/*
 * slci_built_in_type enumeration.
 */
enum slci_cpp_built_in_type
	{
		BT_VOID,               /* Void */
		BT_BOOL,               /* Boolean value */
		BT_UNSIGNED_CHAR,      /* Unsigned character */
		BT_SIGNED_CHAR,        /* Signed character */
		BT_CHAR16_T,           /* Char16_t character */
		BT_CHAR32_T,           /* Char32_t character */
		BT_WCHAR_T,            /* Wchar_t character */
		BT_UNSIGNED_SHORT,     /* Unsigned short */
		BT_SIGNED_SHORT,       /* Signed short */
		BT_UNSIGNED_INT,       /* Unsigned integer */
		BT_SIGNED_INT,         /* Signed integer */
		BT_UNSIGNED_LONG,      /* Unsigned long */
		BT_SIGNED_LONG,        /* Signed long */
		BT_UNSIGNED_LONG_LONG, /* Unsigned long long */
		BT_SIGNED_LONG_LONG,   /* Signed long long */
		BT_FLOAT,              /* Floating point number */
		BT_DOUBLE,             /* Double floating point number */
		BT_LONG_DOUBLE,        /* Long double floating point number */
	};

typedef enum slci_cpp_built_in_type slci_cpp_built_in_type;

#endif /* !_SL_SLCI_BUILT_IN_TYPES_H_ */

/*>- EOF -<*/
