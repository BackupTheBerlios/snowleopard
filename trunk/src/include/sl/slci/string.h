
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

#ifndef _SL_SLCI_STRING_H_
#define _SL_SLCI_STRING_H_

/* Standard C headers */
#include <stdbool.h>
#include <stddef.h>

/*
 * slci_string structure. Contains a dynamic string implementation.
 */
struct slci_string
{
	size_t size;
	size_t reserved;
	char* value;
};

typedef struct slci_string slci_string;

/*
 * slci_wstring structure. Contains a dynamic wstring implementation.
 */
struct slci_wstring
{
	size_t size;
	size_t reserved;
	wchar_t* value;
};

typedef struct slci_wstring slci_wstring;

/*
 * Function prototypes.
 */
slci_string initialize_string ();
slci_string initialize_string_with_data (const char*);
slci_wstring initialize_wstring ();
void destroy_string (slci_string*);
void destroy_wstring (slci_wstring*);

/*
 * String functions.
 */
bool append_string (slci_string*, char);
bool append_wstring (slci_wstring*, wchar_t);
size_t first_none_whitespace (const slci_string*, size_t);
char get_char_from_string (const slci_string*, size_t);
char* get_c_string (const slci_string*);
wchar_t* get_wc_string (const slci_wstring*);
bool reset_string (slci_string*);
bool reset_wstring (slci_wstring*);

#endif /* !_SL_SLCI_STRING_H_ */

/*>- EOF -<*/
