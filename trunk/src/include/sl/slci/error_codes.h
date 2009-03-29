
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

#ifndef _SL_SLCI_ERROR_CODES_H_
#define _SL_SLCI_ERROR_CODES_H_

/* Standard C headers */
#include <stddef.h>

/*
 * Error type enum
 */
enum slci_error_type
	{
		ET_NO_ERROR, /* No error occured */
		ET_FATAL,    /* Fatal errors */
		ET_COMPILE,  /* Compilation/Source analysis error */
		ET_RUNTIME   /* Runtime error */	
	};

typedef enum slci_error_type slci_error_type;

/*
 * Error type descritpion list (Sorted in the order of the slci_error_type enum).
 */
extern char* error_type_list[];

/*
 * Error code enum
 */
enum slci_error_code
	{
		ERR_NO_ERROR,
			
		/* Fatal errors */
		ERR_FATAL_UNKNOWN,    /* Unknown fatal error */
		ERR_OUT_OF_MEMORY,    /* Interpreter out of memory */
		ERR_INVALID_ARGUMENT, /* Invalid arguemts provided */
		ERR_NO_SOURCE_FILE,   /* No source file provided */
			
		/* Compile errors */
		ERR_INVALID_CHARACTER_LITERAL,
		ERR_INVALID_CHARACTER_HEXADECIMAL_LITERAL,
		ERR_INVALID_CHARACTER_OCTAL_LITERAL,
		ERR_INVALID_WCHARACTER_LITERAL,
		ERR_INVALID_STRING_LITERAL
			
		/* Runtime errors */

	};

typedef enum slci_error_code slci_error_code;

/*
 * Error description struct
 */
struct slci_error_description
{
	char* description;
	size_t nbr_of_arguments;
	slci_error_type type;
};

typedef struct slci_error_description slci_error_description;

/*
 * Error description list (Sorted in the order of the slci_error_code enum).
 */
extern slci_error_description error_description_list[];

#endif /* !_SL_SLCI_ERROR_CODES_H_ */

/*>- EOF -<*/
