
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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Snow Leopard headers */
#include "sl/slci/lexer.h"
#include "sl/slci/preprocessor.h"
#include "sl/slci/token.h"

/*
 * Private function prototypes.
 */
char* preprocess_token (slci_token);

/*
 * Global variables.
 */
slci_token current_token;
slci_token previous_token;
source_position* current_source_position;

/*
 * Function initializes the lexer by giving it the first filename.
 */
bool initialze (char* filename)
{

	return false;
}

/*
 * Function terminates the lexer and cleans up open files and buffers.
 */
bool terminate ()
{

}

/*
 * Function gets the next token from the stream.
 */
slci_token get_next_token ()
{

}

/*
 * Function gets the previous token. This is not relexed, it is just a variable
 * return to the caller.
 */
slci_token get_prev_token ()
{

}

/*
 * Function puts the current token (the one returned by get_next_token) back so
 * the next call to get_next_token will return the previous token.
 */
bool put_back_token ()
{

}

/*
 * Function preprocesses the preprocessor token given as parameter and returns a
 * string containing the preprocessed token.
 */
char* preprocess_token (slci_token token)
{

}

/*>- EOF -<*/
