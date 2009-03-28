
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

#ifndef _SL_SLCI_HASH_FUNCTION_H_
#define _SL_SLCI_HASH_FUNCTION_H_

/* Standard C headers */
#include <stddef.h>

/*
 * Maxinum number of values in hash tables.
 */
extern const size_t MaxCppHashTableEntries;
extern const size_t MaxPreHashTableEntries;

/*
 * Typdef for hash functions.
 */
typedef size_t (*hash_function_ptr) (char);

/*
 * Hash function for C++ identifiers, used for hashing the keys for the
 * Snow Leopard interpreter's symbol table.
 */
size_t generate_cpp_hash_key (const char*);
size_t generate_pre_hash_key (const char*);

/*
 * General hash function.
 */
size_t generate_hash_key (hash_function_ptr, const size_t, const char*);

#endif /* !_SL_SLCI_HASH_FUNCTION_H_ */

/*>- EOF -<*/
