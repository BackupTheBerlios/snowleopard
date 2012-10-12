/*==============================================================================
  Snow Leopard Standard Typed Component Library
  
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
// linked_list.c.h
//------------------------------------------------------------------------------
// Implementation of the linked list functions defined in linked_list.h.
//
// Macros create a linked list. The following macros need to be defined:
//   TC_LL_TYPE - Type of the linked list, which can be any valid identifier,
//                but it needs to be unique in the program.
//   TC_LL_NODE_TYPE - Is the type to be stored in each node.
//   TC_LL_IS_PRIVATE - Defines functions to be hidden, and by convention
//                      add an underscore to list head and node.
//
// A compare function also needs to be implemented with the following
// prototype. 
//   bool tc_ll_nodes_equal(TC_LL_NODE_TYPE, TC_LL_NODE_TYPE)
//
// Alternatively the find function can be dropped by defining
//   TC_LL_NO_FIND
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

#include <stddef.h>
#include <stdlib.h>

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
// tc_ll_new function
TC_LL_HEAD* TC_LL_HIDE 
sl_concat_3(tc_ll_new,_,TC_LL_FUNCTION_SUFFIX) () 
{
  TC_LL_HEAD* ll = malloc(sizeof(TC_LL_HEAD));

  ll->first_ = NULL;
  ll->last_ = NULL;
  ll->entries_ = 0;
  
  return ll;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_ll_delete function
void TC_LL_HIDE 
sl_concat_3(tc_ll_delete,_,TC_LL_FUNCTION_SUFFIX) (TC_LL_HEAD* list) 
{
  if(list->entries_ != 0)
    while(list->entries_ != 0)
      sl_concat_3(tc_ll_remove,_,TC_LL_FUNCTION_SUFFIX) (list, list->first_);

  free(list);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_ll_add function
int TC_LL_HIDE 
sl_concat_3(tc_ll_add,_,TC_LL_FUNCTION_SUFFIX) (
						TC_LL_HEAD* list, 
						TC_LL_NODE_TYPE node, 
						size_t max_entries
						) 
{
  if(list->last_->next_ != NULL)
    return EXIT_FAILURE;

  if(list->entries_ == max_entries)
    return EXIT_FAILURE;
  
  TC_LL_NODE* e = malloc(sizeof(TC_LL_NODE));

  e->head_ = list;
  e->prev_ = list->last_;
  e->next_ = NULL;
  e->node_ = node;

  if(list->entries_ == 0)
    list->first_ = e;
  list->last_ = e;
  list->entries_++;
  
  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_ll_remove function
int TC_LL_HIDE 
sl_concat_3(tc_ll_remove,_,TC_LL_FUNCTION_SUFFIX) (
						   TC_LL_HEAD* list, 
						   TC_LL_NODE* node
						   ) 
{
  if(node == NULL)
    return EXIT_FAILURE;
  
  if(node == list->first_)
    list->first_ = node->prev_;
  if(node == list->last_)
    list->last_ = node->prev_;
  node->prev_->next_ = node->next_;
  node->next_->prev_ = node->prev_;
  list->entries_--;
  
  free(node);
  
  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_ll_replace function
TC_LL_NODE_TYPE TC_LL_HIDE 
sl_concat_3(tc_ll_replace,_,TC_LL_FUNCTION_SUFFIX) (
						    TC_LL_HEAD* list, 
						    TC_LL_NODE* node, 
						    TC_LL_NODE_TYPE new_node
						    ) 
{
  TC_LL_NODE_TYPE e = node->node_;

  node->node_ = new_node;

  return e;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_ll_find function
//
// If the macro TC_LL_NO_FIND is defined, this function is excluded.
#ifndef TC_LL_NO_FIND

TC_LL_NODE* TC_LL_HIDE 
sl_concat_3(tc_ll_find,_,TC_LL_FUNCTION_SUFFIX) (
						 TC_LL_HEAD* list, 
						 TC_LL_NODE_TYPE node
						 ) 
{
  TC_LL_NODE* e = list->first_;

  while(!sl_concat_3(tc_ll_nodes_equal,_,TC_LL_FUNCTION_SUFFIX) 
	(
	 e->node_, node
	 )
	) 
    {
      e = e->next_;
    }
  
  return e;
}

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
