/*==============================================================================
  Snow Leopard Standard C Library
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
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
//   SL_LL_TYPE - Type of the linked list, which can be any valid identifier,
//                but it needs to be unique in the program.
//   SL_LL_NODE_TYPE - Is the type to be stored in each node.
//   SL_LL_FUNCTION_SUFFIX - Suffix appended to function to distinguish them
//                           from functions of different linked lists.
//   SL_LL_IS_PRIVATE - Defines functions to be hidden, and by convention
//                      add an underscore to list head and node.
//
// A compare function also needs to be implemented with the following
// prototype. 
//   bool sl_ll_nodes_equal(SL_LL_NODE_TYPE, SL_LL_NODE_TYPE)
//
// Alternatively the find function can be dropped by defining
//   SL_LL_NO_FIND
//
// Ex.
//   #define SL_LL_TYPE open_files
//   #define SL_LL_NODE_TYPE FILE*
// Gives
//   SL_LL_HEAD - Macro containing list head type
//   SL_LL_NODE - Macro containing list node type
//   open_files_head - List head
//   open_files_node - List node with element node_ of type FILE*
//------------------------------------------------------------------------------

//==============================================================================
// Checks to see if a linked list can be created
#ifndef SL_LL_TYPE
# error "SL_LL_TYPE needs to be defined"
#else /* !SL_LL_TYPE */

#ifndef SL_LL_NODE_TYPE
# error "SL_LL_NODE_TYPE needs to be defined"
#else /* !SL_LL_NODE_TYPE */

#ifndef SL_LL_FUNCTION_SUFFIX
# error "SL_LL_FUNCTION_SUFFIX needs to be defined"
#else /* !SL_LL_FUNCTION_SUFFIX */
//==============================================================================

#include <sl/config/config.h>

#include <sl/config/macros.h>

#include <stdbool.h>
#include <stddef.h>

//------------------------------------------------------------------------------
// If private define suffix and use standard hiding attributes, otherwise don't
// hide.
#ifdef SL_LL_IS_PRIVATE
# define SL_LL_SUFFIX _
# define SL_LL_HIDE _SL_Hidden
#else /* SL_LL_IS_PRIVATE */
# define SL_LL_SUFFIX 
# define SL_LL_HIDE
#endif /* SL_LL_IS_PRIVATE */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Define head/node macros
#define SL_LL_HEAD sl_concat_3(SL_LL_TYPE,_head,SL_LL_SUFFIX)
#define SL_LL_NODE sl_concat_3(SL_LL_TYPE,_node,SL_LL_SUFFIX)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward declaration
struct SL_LL_NODE;
typedef struct SL_LL_NODE SL_LL_NODE;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Compare function prototype
#ifndef SL_LL_NO_FIND
bool sl_concat_3(sl_ll_nodes_equal,_,SL_LL_FUNCTION_SUFFIX) (
							     SL_LL_NODE_TYPE n1, 
							     SL_LL_NODE_TYPE n2
							     );
#endif /* !SL_LL_NO_FIND */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SL_LL_HEAD struct
struct SL_LL_HEAD {
  SL_LL_NODE* first_;
  SL_LL_NODE* last_;
  size_t entries_;
};

typedef struct SL_LL_HEAD SL_LL_HEAD;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SL_LL_NODE struct
struct SL_LL_NODE {
  SL_LL_HEAD* head_;
  SL_LL_NODE* prev_;
  SL_LL_NODE* next_;
  SL_LL_NODE_TYPE node_;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions
SL_LL_HEAD* SL_LL_HIDE 
sl_concat_3(_sl_ll_new,_,SL_LL_FUNCTION_SUFFIX) ();
void SL_LL_HIDE 
sl_concat_3(_sl_ll_delete,_,SL_LL_FUNCTION_SUFFIX) (SL_LL_HEAD* list);
int SL_LL_HIDE 
sl_concat_3(_sl_ll_add,_,SL_LL_FUNCTION_SUFFIX) (
						 SL_LL_HEAD* list, 
						 SL_LL_NODE_TYPE node, 
						 size_t max_entries
						 );
int SL_LL_HIDE 
sl_concat_3(_sl_ll_remove,_,SL_LL_FUNCTION_SUFFIX) (
						    SL_LL_HEAD* list, 
						    SL_LL_NODE* node);
SL_LL_NODE_TYPE SL_LL_HIDE 
sl_concat_3(_sl_ll_replace,_,SL_LL_FUNCTION_SUFFIX) (
						     SL_LL_HEAD* list, 
						     SL_LL_NODE* node, 
						     SL_LL_NODE_TYPE new_node
						     );
#ifndef SL_LL_NO_FIND
SL_LL_NODE* SL_LL_HIDE 
sl_concat_3(_sl_ll_find,_,SL_LL_FUNCTION_SUFFIX) (
						  SL_LL_HEAD* list, 
						  SL_LL_NODE_TYPE node
						  );
#endif /* !SL_LL_NO_FIND */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Undefine other macros
#undef SL_LL_SUFFIX
#undef SL_LL_HIDE
//------------------------------------------------------------------------------

//==============================================================================
// End of checks
#endif /* !SL_LL_FUNCTION_SUFFIX */

#endif /* !SL_LL_NODE_TYPE */

#endif /* !SL_LL_TYPE */
//==============================================================================

//-<EOF>
