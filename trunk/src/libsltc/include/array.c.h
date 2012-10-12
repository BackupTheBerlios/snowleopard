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
// array.c.h
//------------------------------------------------------------------------------
// Implementation of the linked list functions defined in linked_list.h.
//
// Macros create a linked list. The following macros need to be defined:
//   TC_ARRAY_TYPE - Type of the array, which can be any valid identifier,
//                   but it needs to be unique in the program.
//   TC_ARRAY_ELEMENT_TYPE - Is the type to be stored in each element.
//   TC_ARRAY_FUNCTION_SUFFIX - To make function names stand out a suffix can
//                              be added.
//   TC_ARRAY_IS_PRIVATE - Defines functions to be hidden, and by convention
//                         add an underscore to list head and node.
//   TC_ARRAY_INITIAL_SIZE - Defines the initial size of the array.
//
// A compare function also needs to be implemented with the following
// prototype. 
//   bool tc_array_elements_equal(TC_ARRAY_ELEMENT_TYPE, TC_ARRAY_ELEMENT_TYPE)
//
// Alternatively the find function can be dropped by defining
//   TC_ARRAY_NO_FIND
//------------------------------------------------------------------------------

//==============================================================================
// Checks to see if an array can be created.
//
#ifndef TC_ARRAY_TYPE_NAME
# error "TC_ARRAY_TYPE_NAME needs to be defined"
#else /* !TC_ARRAY_TYPE_NAME */

#ifndef TC_ARRAY_ELEMENT_TYPE
# error "TC_ARRAY_ELEMENT_TYPE needs to be defined"
#else /* !TC_ARRAY_ELEMENT_TYPE */

#ifndef TC_ARRAY_FUNCTION_SUFFIX
# error "TC_ARRAY_FUNCTION_SUFFIX needs to be defined"
#else /* !TC_ARRAY_FUNCTION_SUFFIX */
//==============================================================================

#include "config_tc.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// If private define suffix and use standard hiding attributes, otherwise don't
// hide.
//
#ifdef TC_ARRAY_IS_PRIVATE
# define TC_ARRAY_SUFFIX _
# define TC_ARRAY_HIDE _SL_Hidden
#else /* TC_ARRAY_IS_PRIVATE */
# define TC_ARRAY_SUFFIX 
# define TC_ARRAY_HIDE
#endif /* TC_ARRAY_IS_PRIVATE */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Check initial array size.
//
#ifndef TC_ARRAY_INITIAL_SIZE
# define TC_ARRAY_INITIAL_SIZE 256
#elif TC_ARRAY_INITIAL_SIZE < 2
# undef TC_ARRAY_INITIAL_SIZE
# define TC_ARRAY_INITIAL_SIZE 256
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Define array macros.
//
#define TC_ARRAY_TYPE sl_concat_2(TC_ARRAY_TYPE_NAME,TC_ARRAY_SUFFIX)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_array_new function
//
// Creates a new array.
//
TC_ARRAY_TYPE* TC_ARRAY_HIDE
sl_concat_3(tc_array_new,_,TC_ARRAY_FUNCTION_SUFFIX) ()
{
  TC_ARRAY_TYPE* array = malloc (sizeof (TC_ARRAY_TYPE));

  if (TC_ARRAY_INITIAL_SIZE == 0)
    array->reserved_ = 256;
  else
    array->reserved_ = TC_ARRAY_INITIAL_SIZE;

  array->used_ = 0;
  
  array->data_ = malloc (sizeof (TC_ARRAY_ELEMENT_TYPE) * array->reserved_);

  return array;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_array_delete function
//
// Deletes the array.
//
void TC_ARRAY_HIDE
sl_concat_3(tc_array_delete,_,TC_ARRAY_FUNCTION_SUFFIX) (TC_ARRAY_TYPE* array)
{
  free (array->data_);

  free (array);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_array_get function
//
// Returns the element at position pos.
//
TC_ARRAY_ELEMENT_TYPE* TC_ARRAY_HIDE
sl_concat_3(tc_array_get,_,TC_ARRAY_FUNCTION_SUFFIX)
(
 TC_ARRAY_TYPE* array,
 size_t pos
 )
{
  if (pos < array->used_)
    return &(array->data_[pos]);
  else 
    return NULL;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_array_add function
//
// Adds an element to the array and extends it if necessary.
//
size_t TC_ARRAY_HIDE 
sl_concat_3(tc_array_add,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* array, 
 TC_ARRAY_ELEMENT_TYPE elem
 )
{
  if (array->used_ == array->reserved_)
    {
      TC_ARRAY_ELEMENT_TYPE* d 
	= malloc (sizeof(TC_ARRAY_ELEMENT_TYPE) 
		  * (array->reserved_ + TC_ARRAY_INITIAL_SIZE));
      memcpy (d, array->data_, array->reserved_);
      array->reserved_ += TC_ARRAY_INITIAL_SIZE;
    }

  array->used_++;
  array->data_[array->used_] = elem;

  return array->used_;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_array_remove function
//
// Removes the element at position pos.
//
bool TC_ARRAY_HIDE 
sl_concat_3(tc_array_remove,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* array, 
 size_t pos
 )
{
  TC_ARRAY_ELEMENT_TYPE e;

  if (pos > array->used_)
    return false;

  array->data_[pos] = e;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_array_set function
//
// Sets the element at position pos.
//
TC_ARRAY_ELEMENT_TYPE* TC_ARRAY_HIDE 
sl_concat_3(tc_array_set,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* array, 
 size_t pos, 
 TC_ARRAY_ELEMENT_TYPE elem
 )
{
  if (pos > array->used_)
    return NULL;

  array->data_[pos] = elem;

  return &(array->data_[pos]);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_array_find function
//
// If the macro TC_ARRAY_NO_FIND is defined, this function is excluded.
//
#ifndef TC_ARRAY_NO_FIND

TC_ARRAY_ELEMENT_TYPE* TC_ARRAY_HIDE 
sl_concat_3(tc_array_find,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* array, 
 TC_ARRAY_ELEMENT_TYPE elem
 ) 
{

  for(size_t i = 1; i < array->used_; i++)
    if (sl_concat_3(tc_array_elements_equal,_,TC_ARRAY_FUNCTION_SUFFIX) 
	(
	 array->data_[i], elem
	 )
	) 
      return &(array->data_[i]);
  
  return NULL;
}

#endif /* !TC_ARRAY_NO_FIND */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Undefine other macros
#undef TC_ARRAY_SUFFIX
#undef TC_ARRAY_HIDE
//------------------------------------------------------------------------------

//==============================================================================
// End of checks
#endif /* !TC_ARRAY_FUNCTION_SUFFIX */

#endif /* !TC_ARRAY_ELEMENT_TYPE */

#endif /* !TC_ARRAY_TYPE_NAME */
//==============================================================================

//-<EOF>
