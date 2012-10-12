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
// tree.h
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
//   parse_tree_node - Tree node with element object of type slci_object*
//
// <TODO: Put component into a seperate library>
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
// Forward declaration
struct LSLC_TREE_NODE;
typedef struct LSLC_TREE_NODE LSLC_TREE_NODE;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tree root structure
struct LSLC_TREE_ROOT
{
  LSLC_TREE_NODE* top;
  LSLC_TREE_NODE* current_node;
};

typedef struct LSLC_TREE_ROOT LSLC_TREE_ROOT;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tree node structure
struct LSLC_TREE_NODE 
{
  LSLC_TREE_ROOT* root;
  LSLC_TREE_NODE* up;
  LSLC_TREE_NODE* next;
  LSLC_TREE_NODE* previous;
  LSLC_TREE_NODE* first_child;
  LSLC_TREE_NODE* last_child;
  LSLC_TREE_NODE_TYPE object;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initializer functions
LSLC_TREE_ROOT* LSLC_TREE_HIDE 
sl_concat_3(initialize_,LSLC_TREE_FUNCTION_PREFIX,_tree) ();
LSLC_TREE_NODE* LSLC_TREE_HIDE								
sl_concat_3(initialize_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) 
(
 LSLC_TREE_ROOT*,
 LSLC_TREE_NODE_TYPE
 );
void LSLC_TREE_HIDE						     
sl_concat_3(destroy_,LSLC_TREE_FUNCTION_PREFIX,_tree) (LSLC_TREE_ROOT*);
void LSLC_TREE_HIDE
sl_concat_3(destroy_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) (LSLC_TREE_NODE*);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tree manipulation functions
LSLC_TREE_NODE* LSLC_TREE_HIDE						  
sl_concat_3(delete_,LSLC_TREE_FUNCTION_PREFIX,_tree_node) (
							   LSLC_TREE_NODE* node
							   );
LSLC_TREE_NODE* LSLC_TREE_HIDE
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_after) 
(
 LSLC_TREE_NODE*,
 LSLC_TREE_NODE*
 );
LSLC_TREE_NODE* LSLC_TREE_HIDE
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_before) 
(
 LSLC_TREE_NODE*,
 LSLC_TREE_NODE*
 );
LSLC_TREE_NODE* LSLC_TREE_HIDE							      
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_as_first_child) 
(
 LSLC_TREE_NODE*,
 LSLC_TREE_NODE*
 );
LSLC_TREE_NODE* LSLC_TREE_HIDE							      
sl_concat_3(insert_,LSLC_TREE_FUNCTION_PREFIX,_tree_node_as_last_child) 
(
 LSLC_TREE_NODE*,
 LSLC_TREE_NODE*
 );
//------------------------------------------------------------------------------

//==============================================================================
// End of checks
#endif /* !LSLC_TREE_FUNCTION_SUFFIX */

#endif /* !LSLC_TREE_FUNCTION_PREFIX */

#endif /* !LSLC_TREE_NODE_TYPE */

#endif /* !LSLC_TREE_PREFIX */
//==============================================================================

//-<EOF>
