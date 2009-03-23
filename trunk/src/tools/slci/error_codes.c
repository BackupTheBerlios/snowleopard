
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

/* Snow Leopard headers */
#include "sl/slci/error_codes.h"

/*
 * Error type description list.
 */
char* error_type_list[] = {
	"No error occured",
        "FATAL",
	"Source Error",
	"RUNTIME ERROR"
};

/*
 * Error descriptions list.
 */
slci_error_description error_description_list[] = {

	{"No error occured", 0, ET_NO_ERROR},
		
	/*  Fatal errors */
	{"An unknown fatal error occured", 0, ET_FATAL},
	{"An out of memory error occured", 0, ET_FATAL},
	{"Invalid arguments provided ", 0, ET_FATAL},
	{"No source-file given as parameter", 0, ET_FATAL},
		
	/* Compile errors */
	{"Invalid character literal \'%1\'", 1, ET_COMPILE},
	{"Invalid string literal \"%1\"", 1, ET_COMPILE}

	/* Runtime errors */
};

/*>- EOF -<*/
