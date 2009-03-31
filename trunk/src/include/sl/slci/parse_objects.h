
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

#ifndef _SL_SLCI_PARSE_OBJECTS_H_
#define _SL_SLCI_PARSE_OBJECTS_H_

/* Standard C headers */
#include <stddef.h>

/* Snow Leopard headers */
#include "sl/slci/parse_argument_object.h"
#include "sl/slci/types.h"

/*
 * slci_object_type enumeration.
 */
enum slci_object_type
	{
		OT_CLASS,             /* Definition of a class/struct */
		OT_CLASS_TEMPLATE,    /* Definition of a class/struct template */
		OT_FUNCTION,          /* Definition of a function */
		OT_FUNCTION_CALL,     /* Expression or function call */
	        OT_FUNCTION_TEMPLATE, /* Definition of a function template */
		OT_VARIABLE,          /* Definition of a variable */
		OT_UNION,             /* Definition of a union */
		OT_UNION_TEMPLATE,    /* Definition of a union template */
		OT_ENUM,              /* Definition of an enumeration */
	        OT_NAMESPACE,         /* Namespace */
		OT_IF,                /* If statement */
		OT_LOOP,              /* Do While/For/While statement */
		OT_BREAK,             /* Break statement */
		OT_CONTINUE,          /* Continue statement */
		OT_GOTO,              /* Goto statement */
		OT_LABEL,             /* Label */
		OT_TRY,               /* Try - Catch statement */
		OT_THROW              /* Throw statement */
	};

typedef enum slci_object_type slci_object_type;

/*
 * Forward definitions.
 */
struct slci_function;
struct slci_function_call;
struct slci_function_template;

typedef struct slci_function slci_function;
typedef struct slci_function_call slci_function_call;
typedef struct slci_function_template slci_function_template;

/*
 * slci_object structure.
 */
struct slci_object
{
	symtab_key_t symbol_table_entry;
	slci_object_type type;

	union {
		slci_function* function;
		slci_function_call* function_call;
		slci_function_template* function_template;
	};
};

typedef struct slci_object slci_object;

/*
 * slci_function structure.
 */
struct slci_function
{

};

/*
 * slci_function_call structure.
 */
struct slci_function_call
{
	size_t nr_params;
	slci_argument* params;
};

/*
 * slci_function_template structure.
 */
struct slci_function_template
{

};

#endif /* !_SL_SLCI_PARSE_OBJECTS_H_ */

/*>- EOF -<*/
