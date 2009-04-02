
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

#ifndef _SL_SLCI_TYPE_INFO_H_
#define _SL_SLCI_TYPE_INFO_H_

/* Snow Leopard headers */
#include "sl/slci/string.h"
#include "sl/slci/types.h"

/* Forward declarations */
struct slci_array_type;
struct slci_built_in_type;
struct slci_class_type;
struct slci_enumeration_type;
struct slci_pointer_type;
struct slci_type_info;

typedef struct slci_array_type slci_array_type;
typedef struct slci_built_in_type slci_built_in_type;
typedef struct slci_class_type slci_class_type;
typedef struct slci_enumeration_type slci_enumeration_type;
typedef struct slci_pointer_type slci_pointer_type;
typedef struct slci_type_info slci_type_info;

/*
 * slci_type enumeration.
 */
enum slci_type
	{
		T_EMPTY,       /* Empty */
		T_ARRAY,       /* Array type */
		T_BUILT_IN,    /* Built in type */
		T_CLASS,       /* Class type */
		T_ENUMERATION, /* Enumerated type */
		T_POINTER      /* Pointer type */
	};

typedef enum slci_type slci_type;

/*
 * slci_array_type structure.
 */
struct slci_array_type
{
	size_t size;
	symtab_key_t type;
};

/*
 * slci_built_in_type structure.
 */
struct slci_built_in_type
{
	symtab_key_t type; 
};

/*
 * slci_class_type structure.
 */
struct slci_class_type
{
	slci_string name;
	bool is_class;
	size_t nr_ancestors;
	symtab_key_t* ancestors;
};

/*
 * slci_enumeration_type structure.
 */
struct slci_enumeration_type
{
	slci_string name;
	symtab_key_t type;
	size_t nr_values;
	signed long* values;
};

/*
 * slci_pointer_type structure.
 */
struct slci_pointer_type
{
	symtab_key_t type;
};

/*
 * slci_type_info structure.
 */
struct slci_type_info
{
	slci_type type;

	union {
		slci_array_type array;
		slci_built_in_type built_in;
		slci_class_type class;
		slci_enumeration_type enumeration;
		slci_pointer_type pointer;
	};
};

/*
 * Initializer functions.
 */
void destroy_type_info (slci_type_info* type_info);

#endif /* !_SL_SLCI_TYPE_INFO_H_ */

/*>- EOF -<*/
