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
// warnings.h
//------------------------------------------------------------------------------
// Warning handling for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_WARNINGS_H__
#define __SL_SLCC_WARNINGS_H__

#include <stdbool.h>

//------------------------------------------------------------------------------
// slcc_warning_type
//
// Warning flags used by the compiler.
//
enum slcc_warning_type
  {
    WT_NONE = 0,                  /* 0b000000, No warnings, only errors are 
				     reported */
    WT_UNUSED_ARGS = 1,           /* 0b000001, Warn on unused arguments */
    WT_UNUSED_FUNCTIONS = 2,      /* 0b000010, Warn about unused functions */
    WT_NO_VIRTUAL_DESTRUCTOR = 4, /* 0b000100, No virtual destructor */
    WT_MOST = 9,                  /* 0b001001, Most warnings. Default setting */
    WT_ALL = 23,                  /* 0b010111, Use all regular warnings */ 
    WT_EXTRA = 24,                /* 0b011000, Use all extra warnings */
    WT_CXX_EFFCXX = 32            /* 0b100000, Effective C++ warnings (C++) */
  };

typedef enum slcc_warning_type slcc_warning_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// check_warnings macro
//
// Check warning flags.
//
#define check_warnings(warning_flag)		\
  (settings_.warnings & warning_flag)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// reset_warnings macro
//
// Reset warning flags.
//
#define reset_warnings(warning_flag)			\
  settings_.warnings = warning_flag 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// set_warnings macro
//
// Set warning flags.
//
#define set_warnings(warning_flag)			\
  settings_.warnings = settings_.warnings | warning_flag
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Warning functions
//
bool check_warning_flag (char* warning_flag);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_WARNINGS_H__ */

//-<EOF>


