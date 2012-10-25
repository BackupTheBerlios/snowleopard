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
// warnings.c
//------------------------------------------------------------------------------
// Warning handling for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "macros_slcc.h"
#include "settings.h"
#include "warnings.h"

//------------------------------------------------------------------------------
// check_warning_flag function
//
// Check a warning flag given as parameter, and if it is valid, apply it to
// the settings.
//
bool check_warning_flag (char* arg)
{
  /* -Wmost / --warning most */
  if_equal_execute (arg, "most", set_warnings (WT_MOST); return true);

  /* -Wall / --warning all */
  if_equal_execute (arg, "all", set_warnings (WT_ALL); return true);

  /* -Wextra / --warning extra */
  if_equal_execute (arg, "extra", set_warnings (WT_EXTRA); return true);

  /* -Weffc++ / --warning effc++ */
  if_equal_execute (arg, "effc++", set_warnings (WT_CXX_EFFCXX); return true);

  /* -Wunused_arguments / --warning unused_arguments */
  if_equal_execute (arg, 
                    "unused_arguments",
                    set_warnings (WT_UNUSED_ARGS); return true);

  /* -Wunused_functions / --warning unused_functions */
  if_equal_execute (arg, 
                    "unused_functions",
                    set_warnings (WT_UNUSED_FUNCTIONS); return true);

  /* -Wno_virtual_destructors / --warning no_virtual_destructors */
  if_equal_execute (arg, 
                    "no_virtual_destructors",
                    set_warnings (WT_NO_VIRTUAL_DESTRUCTOR); return true);

  return false;
}
//------------------------------------------------------------------------------

//-<EOF>

