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
// optimize_flags.c
//------------------------------------------------------------------------------
// Optimize flag handling for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "macros_slcc.h"
#include "optimize_flags.h"

//------------------------------------------------------------------------------
// drv_check_optimize_flag function
//
// Check the optimize flag given as parameter, and if it is valid, apply it to
// the settings.
//
bool drv_check_optimize_flag (char* arg)
{
  /* -O0 / --optimize 0 */
  if_equal_execute (arg, "0", set_optimize_flags (OF_O0); return true);

  /* -O1 / --optimize 1 */
  if_equal_execute (arg, "1", set_optimize_flags (OF_O1); return true);

  /* -O2 / --optimize 2 */
  if_equal_execute (arg, "2", set_optimize_flags (OF_O2); return true);

  /* -O3 / --optimize 3 */
  if_equal_execute (arg, "3", set_optimize_flags (OF_O3); return true);

  /* -Ounroll_loops / --optimize unroll_loops */
  if_equal_execute (arg, 
		 "unroll_loops", 
		 set_optimize_flags (OF_UNROLL_LOOPS); return true);

  /* -Oreduce_loops / --optimize reduce_loops */
  if_equal_execute (arg, 
		 "reduce_loops", 
		 set_optimize_flags (OF_REDUCE_LOOPS); return true);

  return false;
}
//------------------------------------------------------------------------------

//-<EOF>

