
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
#include <stdlib.h>

/* Snow Leopard headers */
#include "sl/slci/parse_objects.h"
#include "sl/slci/parse_tree.h"

/*
 * Global variables.
 */
slci_parse_tree parse_tree;

/*
 * initialize_parse_tree function. Initializes the interpreters parse tree.
 */
bool
initialize_parse_tree ()
{
	parse_tree.top = initialize_parse_tree_node (0, 0, 0, 0);
	parse_tree.current_node = parse_tree.top;

	return true;
}

/*
 * initialize_parse_tree_node function. Initializes a parse tree node.
 */
slci_parse_tree_node*
initialize_parse_tree_node (
	slci_parse_tree_node* parent,
	slci_parse_tree_node* next,
	slci_parse_tree_node* previous,
	slci_object* object
	)
{
	slci_parse_tree_node* node = malloc (sizeof (slci_parse_tree_node));

	if (node == 0)
		return 0;

	node->parent = parent;
	node->next = next;
	node->previous = previous;
	node->child = 0;
	node->object = object;

	return node;
}

/*
 * destroy_parse_tree function. Destroys the interpreters parse tree.
 */
void
destroy_parse_tree ()
{

}

/*>- EOF -<*/
