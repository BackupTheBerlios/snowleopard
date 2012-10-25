/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2012 Roel Sergeant
  
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
// features.c
//------------------------------------------------------------------------------
// Feature handling for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "features.h"
#include "macros_slcc.h"
#include "settings.h"

//------------------------------------------------------------------------------
// check_feature_flag function
//
// Check a feature flag given as parameter, and if it is valid, apply it to
// the settings.
//
bool check_feature_flag (char* arg)
{
  /* -fc / --feature c */
  if_equal_execute (arg, "c", set_features (FEATURE_C); return true);

  /* -fc++ / --feature c++ */
  if_equal_execute (arg, "c++", set_features (FEATURE_CXX); return true);

  /* -fbinary_literals / --feature binary_literals */
  if_equal_execute (arg, 
		    "binary_literals", 
		    set_features (FEATURE_BINARY_LITERALS); return true);

  /* -fanonymous_unions / --feature anonymous_unions */
  if_equal_execute (arg, 
		    "anonymous_unions", 
		    set_features (FEATURE_ANONYMOUS_UNIONS); return true);

  /* -fexport / --feature export */
  if_equal_execute (arg, "export", set_features (FEATURE_EXPORT); return true);

  /* -fconcepts / --feature concepts */
  if_equal_execute (arg, 
                    "concepts",
                    set_features (FEATURE_CONCEPTS); return true);

  /* -fc89 / --feature c89 */
  if_equal_execute (arg, "c89", set_features (FEATURE_C89); return true);

  /* -fc99 / --feature c99 */
  if_equal_execute (arg, "c89", set_features (FEATURE_C99); return true);

  /* -fc11 / --feature c11 */
  if_equal_execute (arg, "c89", set_features (FEATURE_C11); return true);

  /* -fc1y / --feature c1y */
  if_equal_execute (arg, "c89", set_features (FEATURE_C1Y); return true);

  /* -fc++98 / --feature c++98 */
  if_equal_execute (arg, "c++98", set_features (FEATURE_CXX98); return true);

  /* -fc++11 / --feature c++11 */
  if_equal_execute (arg, "c++11", set_features (FEATURE_CXX11); return true);

  /* -fc++1y / --feature c++1y */
  if_equal_execute (arg, "c++1y", set_features (FEATURE_CXX1Y); return true);

  return false;
}
//------------------------------------------------------------------------------

//-<EOF>
