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
// linked_list.h
//------------------------------------------------------------------------------
// Linked list creation
//
// Macros create a linked list. The following macros need to be defined:
//   TC_LL_TYPE - Type of the linked list, which can be any valid identifier,
//                but it needs to be unique in the program.
//   TC_LL_NODE_TYPE - Is the type to be stored in each node.
//   TC_LL_FUNCTION_SUFFIX - Suffix appended to function to distinguish them
//                           from functions of different linked lists.
//   TC_LL_IS_PRIVATE - Defines functions to be hidden, and by convention
//                      add an underscore to list head and node.
//
// A compare function also needs to be implemented with the following
// prototype. 
//   bool tc_ll_nodes_equal(TC_LL_NODE_TYPE, TC_LL_NODE_TYPE)
//
// Alternatively the find function can be dropped by defining
//   TC_LL_NO_FIND
//
// Ex.
//   #define TC_LL_TYPE open_files
//   #define TC_LL_NODE_TYPE FILE*
// Gives
//   TC_LL_HEAD - Macro containing list head type
//   TC_LL_NODE - Macro containing list node type
//   open_files_head - List head
//   open_files_node - List node with element node_ of type FILE*
//------------------------------------------------------------------------------

//==============================================================================
// Checks to see if a linked list can be created
#ifndef TC_LL_TYPE
# error "TC_LL_TYPE needs to be defined"
#else /* !TC_LL_TYPE */

#ifndef TC_LL_NODE_TYPE
# error "TC_LL_NODE_TYPE needs to be defined"
#else /* !TC_LL_NODE_TYPE */

#ifndef TC_LL_FUNCTION_SUFFIX
# error "TC_LL_FUNCTION_SUFFIX needs to be defined"
#else /* !TC_LL_FUNCTION_SUFFIX */
//==============================================================================

#include "config_tc.h"

#include <stdbool.h>
#include <stddef.h>

//------------------------------------------------------------------------------
// If private define suffix and use standard hiding attributes, otherwise don't
// hide.
#ifdef TC_LL_IS_PRIVATE
# define TC_LL_SUFFIX _
# define TC_LL_HIDE _SL_Hidden
#else /* TC_LL_IS_PRIVATE */
# define TC_LL_SUFFIX 
# define TC_LL_HIDE
#endif /* TC_LL_IS_PRIVATE */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Define head/node macros
#define TC_LL_HEAD sl_concat_3(TC_LL_TYPE,_head,TC_LL_SUFFIX)
#define TC_LL_NODE sl_concat_3(TC_LL_TYPE,_node,TC_LL_SUFFIX)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward declaration
struct TC_LL_NODE;
typedef struct TC_LL_NODE TC_LL_NODE;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Compare function prototype
#ifndef TC_LL_NO_FIND
bool sl_concat_3(tc_ll_nodes_equal,_,TC_LL_FUNCTION_SUFFIX) (
							     TC_LL_NODE_TYPE n1, 
							     TC_LL_NODE_TYPE n2
							     );
#endif /* !TC_LL_NO_FIND */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// TC_LL_HEAD struct
struct TC_LL_HEAD {
  TC_LL_NODE* first_;
  TC_LL_NODE* last_;
  size_t entries_;
};

typedef struct TC_LL_HEAD TC_LL_HEAD;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// TC_LL_NODE struct
struct TC_LL_NODE {
  TC_LL_HEAD* head_;
  TC_LL_NODE* prev_;
  TC_LL_NODE* next_;
  TC_LL_NODE_TYPE node_;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions
TC_LL_HEAD* TC_LL_HIDE 
sl_concat_3(tc_ll_new,_,TC_LL_FUNCTION_SUFFIX) ();
void TC_LL_HIDE 
sl_concat_3(tc_ll_delete,_,TC_LL_FUNCTION_SUFFIX) (TC_LL_HEAD* list);
int TC_LL_HIDE 
sl_concat_3(tc_ll_add,_,TC_LL_FUNCTION_SUFFIX) (
						TC_LL_HEAD* list, 
						TC_LL_NODE_TYPE node, 
						size_t max_entries
						);
int TC_LL_HIDE 
sl_concat_3(tc_ll_remove,_,TC_LL_FUNCTION_SUFFIX) (
						   TC_LL_HEAD* list, 
						   TC_LL_NODE* node
						   );
TC_LL_NODE_TYPE TC_LL_HIDE 
sl_concat_3(tc_ll_replace,_,TC_LL_FUNCTION_SUFFIX) (
						    TC_LL_HEAD* list, 
						    TC_LL_NODE* node, 
						    TC_LL_NODE_TYPE new_node
						    );
#ifndef TC_LL_NO_FIND
TC_LL_NODE* TC_LL_HIDE 
sl_concat_3(tc_ll_find,_,TC_LL_FUNCTION_SUFFIX) (
						 TC_LL_HEAD* list, 
						 TC_LL_NODE_TYPE node
						 );
#endif /* !TC_LL_NO_FIND */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Undefine other macros
#undef TC_LL_SUFFIX
#undef TC_LL_HIDE
//------------------------------------------------------------------------------

//==============================================================================
// End of checks
#endif /* !TC_LL_FUNCTION_SUFFIX */

#endif /* !TC_LL_NODE_TYPE */

#endif /* !TC_LL_TYPE */
//==============================================================================

//-<EOF>
