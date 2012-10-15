/*==============================================================================
  Snow Leopard Typed Component Library
  
  Copyright (C) 2011, 2012 Roel Sergeant
  
  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version
  
  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
  details.
  
  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>
  ============================================================================*/

//------------------------------------------------------------------------------
// tree.c.h
//------------------------------------------------------------------------------
// Tree component.
//
// Macros create a tree. The following macros need to be defined:
//   TC_TREE_PREFIX - Tree fix, which can be any identifier, but it needs to
//                      be unique in the program.
//   TC_TREE_NODE_TYPE - Type of the data stored in the tree nodes.
//   TC_TREE_FUNCTION_PREFIX - Prefix added to tree in function names.
//   TC_TREE_FUNCTION_SUFFIX - Suffix appended to a functions to distinguish
//                               them from functions for other trees.
//
// Ex.
//   #define TC_TREE_PREFIX parse
//   #define TC_TREE_NODE_TYPE slci_object*
// Gives
//   TC_TREE_ROOT - Macro containing tree root type
//   TC_TREE_NODE - Macro containing tree node type
//   parse_tree - Tree root
//   parse_tree_node - Tree node with element node of type slci_object*
//------------------------------------------------------------------------------

//==============================================================================
// Check to see if a tree can be created
#ifndef TC_TREE_PREFIX
# error "TC_TREE_PREFIX nedds to be defined"
#else /* !TC_TREE_PREIFX */

#ifndef TC_TREE_NODE_TYPE
# error "TC_TREE_NODE_TYPE needs to be defined"
#else /* !TC_TREE_NODE_TYPE */

#ifndef TC_TREE_FUNCTION_PREFIX
# error "TC_TREE_FUNCTION_PREFIX needs to be defined"
#else /* !TC_TREE_FUNCTION_PREFIX */

#ifndef TC_TREE_FUNCTION_SUFFIX
# error "TC_TREE_FUNCTION_SUFFIX needs to be defined"
#else /* !TC_TREE_FUNCTION_SUFFIX */
//==============================================================================

#include "config_tc.h"

#include <stdlib.h>

//------------------------------------------------------------------------------
// Suffix and hide functions if defined as private.
#ifdef TC_TREE_IS_PRIVATE
# define TC_TREE_SUFFIX _
# define TC_TREE_HIDE _SL_Hidden
#else /* TC_TREE_IS_PRIVATE */
# define TC_TREE_SUFFIX 
# define TC_TREE_HIDE
#endif /* TC_TREE_IS_PRIVATE */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Define root/node macros
#define TC_TREE_ROOT sl_concat_3(TC_TREE_PREFIX,_tree,TC_TREE_SUFFIX)
#define TC_TREE_NODE sl_concat_3(TC_TREE_PREFIX,_tree_node,TC_TREE_SUFFIX)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_tree_new function
//
// Creates and initializes the tree.
//
TC_TREE_ROOT* TC_TREE_HIDE 
sl_concat_3(tc_tree_new,_,TC_TREE_FUNCTION_SUFFIX) ()
{
  TC_TREE_ROOT* t = malloc (sizeof (TC_TREE_ROOT));

  t->top = NULL;
  t->current_node = NULL;

  return t;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_tree_node_new function
//
// Creates and returns tree node.
//
TC_TREE_NODE* TC_TREE_HIDE								
sl_concat_3(tc_tree_node_new,_,TC_TREE_FUNCTION_SUFFIX) 
(
 TC_TREE_ROOT* root,
 TC_TREE_NODE_TYPE object
 )
{
  TC_TREE_NODE* tn = malloc (sizeof (TC_TREE_NODE));

  tn->root = root;
  tn->object = object;

  tn->up = NULL;
  tn->next = NULL;
  tn->previous = NULL;
  tn->first_child = NULL;
  tn->last_child = NULL;

  return tn;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_tree_delete function
//
// Deletes the tree after first descending and deleting each node.
//
void TC_TREE_HIDE						     
sl_concat_3(tc_tree_delete,_,TC_TREE_FUNCTION_SUFFIX) (TC_TREE_ROOT* root)
{
  sl_concat_3(tc_tree_node_delete,_,TC_TREE_FUNCTION_SUFFIX) (root->top);

  free (root);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_tree_node_delete function
//
// Deletes a tree node and recursively all it's descendents.
//
void TC_TREE_HIDE
sl_concat_3(tc_tree_node_delete,_,TC_TREE_FUNCTION_SUFFIX) (TC_TREE_NODE* node)
{
  while (node->first_child != NULL)
    sl_concat_3(tc_tree_node_delete,_,TC_TREE_FUNCTION_SUFFIX)  
      (
       node->last_child
       );

  sl_concat_3(tc_tree_node_delete,_,TC_TREE_FUNCTION_SUFFIX) (node);

  free (node);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// delete_TC_TREE_FUNCTION_PREFIX_tree_node function
//
// Delete a node from the tree. It returns the up node.
//
TC_TREE_NODE* TC_TREE_HIDE						  
sl_concat_3(delete_,TC_TREE_FUNCTION_PREFIX,_tree_node) (TC_TREE_NODE* node)
{
  /* This is the top node, no special handling */
  if (node->up == NULL)
    ;

  /* If there is only one child node for the up */
  else if (node->up->first_child == node && node->up->last_child == node)
    {
      node->up->first_child = NULL;
      node->up->last_child = NULL;
    }

  /* This node is the first child for the up */
  else if (node->up->first_child == node)
    {
      node->up->first_child = node->next;
      node->next->previous = NULL;
    }

  /* This node is the last child for the up */
  else if (node->up->last_child == node)
    {
      node->up->last_child = node->previous;
      node->previous->next = NULL;
    }

  /* This is not the first or last child for the up */
  else
    {
      node->previous->next = node->next;
      node->next->previous = node->previous;
    }

  /* Delete all children */
  while (node->first_child != NULL)
    sl_concat_3(delete_,TC_TREE_FUNCTION_PREFIX,_tree_node) (node->last_child);

  TC_TREE_NODE* up = node->up;

  free (node);

  return up; 
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// insert_TC_TREE_FUNCTION_PREFIX_tree_node_after function
//
// Insert a node after the node in the tree.
//
TC_TREE_NODE* TC_TREE_HIDE
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_after) 
(
 TC_TREE_NODE* tree,
 TC_TREE_NODE* node
 )
{
  if (tree->next == NULL)
    {
      tree->next = node;
      node->previous = tree;
      node->up = tree->up;
      node->next = NULL;
      tree->up->last_child = node;
    }
  else
    {
      tree->next->previous = node;
      node->next = tree->next;
      tree->next = node;
      node->previous = tree;
      node->up = tree->up;
    }

  return node;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// insert_TC_TREE_FUNCTION_PREFIX_tree_node_before function
//
// Inserts a new node before the node give at the same level.
//
TC_TREE_NODE* TC_TREE_HIDE
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_before) 
(
 TC_TREE_NODE* tree,
 TC_TREE_NODE* node
 )
{
  if (tree->previous == NULL)
    {
      tree->previous = node;
      node->next = tree;
      node->previous = NULL;
      node->up = tree->up;
      node->up->first_child = node;
    }
  else 
    {
      node->next = tree;
      node->previous = tree->previous;
      node->previous->next = node;
      tree->previous = node;
      node->up = tree->up;
    }

  return node;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// insert_TC_TREE_FUNCTION_PREFIX_tree_node_as_first_child function
//
// Insert new node as first child of the given node.
//
TC_TREE_NODE* TC_TREE_HIDE							      
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_as_first_child) 
(
 TC_TREE_NODE* tree,
 TC_TREE_NODE* node
 )
{
  if (tree->first_child == NULL)
    {
      tree->first_child = node;
      tree->last_child = node;
    }

  else
    {
      node->next = tree->first_child;
      tree->first_child->previous = node;
      tree->first_child = node;
    }

  return node;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// insert_TC_TREE_FUNCTION_PREFIX_tree_node_as_last_child function
//
// Inserts node as last child of the given node.
//
TC_TREE_NODE* TC_TREE_HIDE							      
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_as_last_child) 
(
 TC_TREE_NODE* tree,
 TC_TREE_NODE* node
 )
{
  if (tree->last_child == NULL)
    {
      tree->first_child = node;
      tree->last_child = node;
    }

  else
    {
      tree->last_child->next = node;
      node->previous = tree->last_child;
      tree->last_child = node;
    }

  return node;
}
//------------------------------------------------------------------------------

//==============================================================================
// End of checks
#endif /* !TC_TREE_FUNCTION_SUFFIX */

#endif /* !TC_TREE_FUNCTION_PREFIX */

#endif /* !TC_TREE_NODE_TYPE */

#endif /* !TC_TREE_PREFIX */
//==============================================================================

//-<EOF>
