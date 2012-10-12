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
// array.h
//------------------------------------------------------------------------------
// An array component is defined here.
//
// Macros create a array. The following macros need to be defined:
//   TC_ARRAY_TYPE - Type of the array, which can be any valid identifier,
//                   but it needs to be unique in the program.
//   TC_ARRAY_ELEMENT_TYPE - Is the type to be stored in each element.
//   TC_ARRAY_FUNCTION_SUFFIX - To make function names stand out a suffix can
//                              be added.
//   TC_ARRAY_IS_PRIVATE - Defines functions to be hidden, and by convention
//                         add an underscore to the array type.
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
// Forward declaration
//
struct TC_ARRAY_TYPE;
typedef struct TC_ARRAY_TYPE TC_ARRAY_TYPE;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Compare function prototype
//
#ifndef TC_ARRAY_NO_FIND
bool 
sl_concat_3(tc_array_elements_equal,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_ELEMENT_TYPE n1, 
 TC_ARRAY_ELEMENT_TYPE n2
 );
#endif /* !TC_ARRAY_NO_FIND */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// TC_ARRAY_TYPE struct
//
struct TC_ARRAY_TYPE {
  TC_ARRAY_ELEMENT_TYPE* data_;
  size_t used_;
  size_t reserved_;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions
//
TC_ARRAY_TYPE* TC_ARRAY_HIDE 
sl_concat_3(tc_array_new,_,TC_ARRAY_FUNCTION_SUFFIX) ();

void TC_ARRAY_HIDE 
sl_concat_3(tc_array_delete,_,TC_ARRAY_FUNCTION_SUFFIX) (TC_ARRAY_TYPE* array);

TC_ARRAY_ELEMENT_TYPE* TC_ARRAY_HIDE
sl_concat_3(tc_array_get,_,TC_ARRAY_FUNCTION_SUFFIX)
(
 TC_ARRAY_TYPE* array,
 size_t pos
 );

size_t TC_ARRAY_HIDE 
sl_concat_3(tc_array_add,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* array, 
 TC_ARRAY_ELEMENT_TYPE elem
 );

bool TC_ARRAY_HIDE 
sl_concat_3(tc_array_remove,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* array, 
 size_t pos
 );

TC_ARRAY_ELEMENT_TYPE* TC_ARRAY_HIDE 
sl_concat_3(tc_array_set,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* array, 
 size_t pos, 
 TC_ARRAY_ELEMENT_TYPE elem
 );

#ifndef TC_ARRAY_NO_FIND
TC_ARRAY_ELEMENT_TYPE* TC_ARRAY_HIDE 
sl_concat_3(tc_array_find,_,TC_ARRAY_FUNCTION_SUFFIX) 
(
 TC_ARRAY_TYPE* list, 
 TC_ARRAY_ELEMENT_TYPE elem
 );
#endif /* !TC_ARRAY_NO_FIND */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Undefine other macros
//
#undef TC_ARRAY_SUFFIX
#undef TC_ARRAY_HIDE
//------------------------------------------------------------------------------

//==============================================================================
// End of checks
//
#endif /* !TC_ARRAY_FUNCTION_SUFFIX */

#endif /* !TC_ARRAY_ELEMENT_TYPE */

#endif /* !TC_ARRAY_TYPE_NAME */
//==============================================================================

//-<EOF>
