/*==============================================================================
  Snow Leopard C Source Component Library
  
  Copyright (C) 2008-2012 Roel Sergeant
  
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
//   LSLC_TREE_PREFIX - Tree fix, which can be any identifier, but it needs to
//                      be unique in the program.
//   LSLC_TREE_NODE_TYPE - Type of the data stored in the tree nodes.
//   LSLC_TREE_FUNCTION_PREFIX - Prefix added to tree in function names.
//   LSLC_TREE_FUNCTION_SUFFIX - Suffix appended to a functions to distinguish
//                               them from functions for other trees.
//
// Ex.
//   #define SL_TREE_PREFIX parse
//   #define SL_TREE_NODE_TYPE slci_object*
// Gives
//   SL_TREE_ROOT - Macro containing tree root type
//   SL_TREE_NODE - Macro containing tree node type
//   parse_tree - Tree root
//   parse_tree_node - Tree node with element node of type slci_object*
//
// <TODO: Put component in seperate source library>
//------------------------------------------------------------------------------

//==============================================================================
// Check to see if a tree can be created
#ifndef LSLC_TREE_PREFIX
# error "LSLC_TREE_PREFIX nedds to be defined"
#else /* !LSLC_TREE_PREIFX */

#ifndef LSLC_TREE_NODE_TYPE
# error "LSLC_TREE_NODE_TYPE needs to be defined"
#else /* !LSLC_TREE_NODE_TYPE */

#ifndef LSLC_TREE_FUNCTION_PREFIX
# error "LSLC_TREE_FUNCTION_PREFIX needs to be defined"
#else /* !LSLC_TREE_FUNCTION_PREFIX */

#ifndef LSLC_TREE_FUNCTION_SUFFIX
# error "LSLC_TREE_FUNCTION_SUFFIX needs to be defined"
#else /* !LSLC_TREE_FUNCTION_SUFFIX */
//==============================================================================

#include "config_lslc.h"

#include <stdlib.h>

//------------------------------------------------------------------------------
// Suffix and hide functions if defined as private.
#ifdef LSLC_TREE_IS_PRIVATE
# define LSLC_TREE_SUFFIX _
# define LSLC_TREE_HIDE _SL_Hidden
#else /* LSLC_TREE_IS_PRIVATE */
# define LSLC_TREE_SUFFIX 
# define LSLC_TREE_HIDE
#endif /* LSLC_TREE_IS_PRIVATE */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Define root/node macros
#define LSLC_TREE_ROOT sl_concat_3(LSLC_TREE_PREFIX,_tree,LSLC_TREE_SUFFIX)
#define LSLC_TREE_NODE sl_concat_3(LSLC_TREE_PREFIX,_tree_node,LSLC_TREE_SUFFIX)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// initialize_LSLC_TREE_FUNCTION_PREFIX_tree function
//
// Creates and initializes the tree node.
//
LSLC_TREE_ROOT* LSLC_TREE_HIDE 
sl_concat_3(initialize_,LSLC_TREE_FUNCTION_PREFIX,_tree) ()
{
  LSLC_TREE_ROOT* t = malloc (sizeof (LSLC_TREE_ROOT));

  t->top = NULL;
  t->current_node = NULL;

  return t;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// initialize_LSLC_TREE_FUNCTION_PREFIX_tree_node function
//
// Creates and returns tree node.
//
LSLC_TREE_NODE* LSLC_TREE_HIDE						
sl_concat_3(initialize_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) 
(
 LSLC_TREE_ROOT* root,
 LSLC_TREE_NODE_TYPE object
 )
{
  LSLC_TREE_NODE* tn = malloc (sizeof (LSLC_TREE_NODE));

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
// destroy_LSLC_TREE_FUNCTION_PREFIX_tree function
//
// Destroys the tree after first descending and deleting each node.
//
void LSLC_TREE_HIDE						     
sl_concat_3(destroy_,LSLC_TREE_FUNCTION_PREFIX,_tree) (LSLC_TREE_ROOT* root)
{
  sl_concat_3(destroy_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) (root->top);

  free (root);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// destroy_LSLC_TREE_FUNCTION_PREFIX_tree_node function
//
// Destroys a tree node and recursively all it's descendents.
//
void LSLC_TREE_HIDE
sl_concat_3(destroy_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) 
(
 LSLC_TREE_NODE* node
 )
{
  while (node->first_child != NULL)
    sl_concat_3(destroy_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) 
      (
       node->last_child
       );

  sl_concat_3(delete_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) (node);

  free (node);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// delete_LSLC_TREE_FUNCTION_PREFIX_tree_node function
//
// Delete a node from the tree. It returns the up node.
//
LSLC_TREE_NODE* LSLC_TREE_HIDE						  
sl_concat_3(delete_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) (LSLC_TREE_NODE* node)
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
    sl_concat_3(delete_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) (node->last_child);

  LSLC_TREE_NODE* up = node->up;

  free (node);

  return up; 
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// insert_LSLC_TREE_FUNCTION_PREFIX_tree_node_after function
//
// Insert a node after the node in the tree.
//
LSLC_TREE_NODE* LSLC_TREE_HIDE
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_after) 
(
 LSLC_TREE_NODE* tree,
 LSLC_TREE_NODE* node
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
// insert_LSLC_TREE_FUNCTION_PREFIX_tree_node_before function
//
// Inserts a new node before the node give at the same level.
//
LSLC_TREE_NODE* LSLC_TREE_HIDE
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_before) 
(
 LSLC_TREE_NODE* tree,
 LSLC_TREE_NODE* node
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
// insert_LSLC_TREE_FUNCTION_PREFIX_tree_node_as_first_child function
//
// Insert new node as first child of the given node.
//
LSLC_TREE_NODE* LSLC_TREE_HIDE							      
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_as_first_child) 
(
 LSLC_TREE_NODE* tree,
 LSLC_TREE_NODE* node
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
// insert_LSLC_TREE_FUNCTION_PREFIX_tree_node_as_last_child function
//
// Inserts node as last child of the given node.
//
LSLC_TREE_NODE* LSLC_TREE_HIDE							      
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_as_last_child) 
(
 LSLC_TREE_NODE* tree,
 LSLC_TREE_NODE* node
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
#endif /* !LSLC_TREE_FUNCTION_SUFFIX */

#endif /* !LSLC_TREE_FUNCTION_PREFIX */

#endif /* !LSLC_TREE_NODE_TYPE */

#endif /* !LSLC_TREE_PREFIX */
//==============================================================================

//-<EOF>
