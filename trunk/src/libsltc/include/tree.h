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
// tree.h
//------------------------------------------------------------------------------
// Tree component.
//
// Macros create a tree. The following macros need to be defined:
//   TC_TREE_PREFIX - Tree fix, which can be any identifier, but it needs to
//                    be unique in the program.
//   TC_TREE_NODE_TYPE - Type of the data stored in the tree nodes.
//   TC_TREE_FUNCTION_PREFIX - Prefix added to tree in function names.
//   TC_TREE_FUNCTION_SUFFIX - Suffix appended to a functions to distinguish
//                             them from functions for other trees.
//
// Ex.
//   #define TC_TREE_PREFIX parse
//   #define TC_TREE_NODE_TYPE slci_object*
// Gives
//   TC_TREE_ROOT - Macro containing tree root type
//   TC_TREE_NODE - Macro containing tree node type
//   parse_tree - Tree root
//   parse_tree_node - Tree node with element object of type slci_object*
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
// Forward declaration
struct TC_TREE_NODE;
typedef struct TC_TREE_NODE TC_TREE_NODE;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tree root structure
struct TC_TREE_ROOT
{
  TC_TREE_NODE* top;
  TC_TREE_NODE* current_node;
};

typedef struct TC_TREE_ROOT TC_TREE_ROOT;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tree node structure
struct TC_TREE_NODE 
{
  TC_TREE_ROOT* root;
  TC_TREE_NODE* up;
  TC_TREE_NODE* next;
  TC_TREE_NODE* previous;
  TC_TREE_NODE* first_child;
  TC_TREE_NODE* last_child;
  TC_TREE_NODE_TYPE object;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initializer functions
TC_TREE_ROOT* TC_TREE_HIDE 
sl_concat_3(initialize_,TC_TREE_FUNCTION_PREFIX,_tree) ();
TC_TREE_NODE* TC_TREE_HIDE								
sl_concat_3(initialize_,TC_TREE_FUNCTION_PREFIX,_tree_node) 
(
 TC_TREE_ROOT*,
 TC_TREE_NODE_TYPE
 );
void TC_TREE_HIDE						     
sl_concat_3(destroy_,TC_TREE_FUNCTION_PREFIX,_tree) (TC_TREE_ROOT*);
void TC_TREE_HIDE
sl_concat_3(destroy_,TC_TREE_FUNCTION_PREFIX,_tree_node) (TC_TREE_NODE*);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tree manipulation functions
TC_TREE_NODE* TC_TREE_HIDE						  
sl_concat_3(delete_,TC_TREE_FUNCTION_PREFIX,_tree_node) (
							 TC_TREE_NODE* node
							 );
TC_TREE_NODE* TC_TREE_HIDE
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_after) 
(
 TC_TREE_NODE*,
 TC_TREE_NODE*
 );
TC_TREE_NODE* TC_TREE_HIDE
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_before) 
(
 TC_TREE_NODE*,
 TC_TREE_NODE*
 );
TC_TREE_NODE* TC_TREE_HIDE							      
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_as_first_child) 
(
 TC_TREE_NODE*,
 TC_TREE_NODE*
 );
TC_TREE_NODE* TC_TREE_HIDE							      
sl_concat_3(insert_,TC_TREE_FUNCTION_PREFIX,_tree_node_as_last_child) 
(
 TC_TREE_NODE*,
 TC_TREE_NODE*
 );
//------------------------------------------------------------------------------

//==============================================================================
// End of checks
#endif /* !TC_TREE_FUNCTION_SUFFIX */

#endif /* !TC_TREE_FUNCTION_PREFIX */

#endif /* !TC_TREE_NODE_TYPE */

#endif /* !TC_TREE_PREFIX */
//==============================================================================

//-<EOF>
