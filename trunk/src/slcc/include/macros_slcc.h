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
// macros_slcc.h
//------------------------------------------------------------------------------
// Misc macros for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_MACROS_SLCC_H__
#define __SL_SLCC_MACROS_SLCC_H__

#include <string.h>

//------------------------------------------------------------------------------
// if_equal_execute macro
//
// Macro to replace the following pattern:
//   if (string1 == string2)
//    command;
//
#define if_equal_execute(string1,string2,command)               \
  if (strlen (string1) == strlen (string2))                     \
    if (strncmp (string1, string2, strlen (string2)) == 0)      \
      {                                                         \
	command;                                                \
      }
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_MACROS_SLCC_H__ */

//-<EOF>
