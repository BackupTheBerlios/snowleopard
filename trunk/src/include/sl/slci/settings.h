
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

#ifndef _SL_SLCI_SETTINGS_H_
#define _SL_SLCI_SETTINGS_H_

/* Standard C headers */
#include <stdbool.h>
#include <stddef.h>

/*
 * Settings structure
 */
struct slci_settings
{
	bool interactive;
	bool license;
	bool make_rules_only;
	bool preprocess_only;
	bool verbose;
	bool version;
	bool warrantee;
	char* source_file;
	char** source_paths;
	size_t size_source_paths;
	char** include_paths;
	size_t size_include_paths;
};

typedef struct slci_settings slci_settings;

/*
 * Global variables.
 */
extern slci_settings* settings;

/*
 * Initialize settings.
 */
slci_settings* initialize_settings ();
void destroy_settings ();

/*
 * Additional functions.
 */
void add_include_path (const char*);
void add_source_path (const char*);

#endif /* !_SL_SLCI_SETTINGS_H_ */

/*>- EOF -<*/
