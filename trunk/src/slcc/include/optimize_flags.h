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
// optimize_flags.h
//------------------------------------------------------------------------------
// Optimize flag handling for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_OPTIMIZE_FLAGS_H__
#define __SL_SLCC_OPTIMIZE_FLAGS_H__

#include <stdbool.h>

//------------------------------------------------------------------------------
// slcc_optimize_flags enum
//
// All optimizer flags used by the compiler. These are summed together, so their
// bit-pattern should not overlap.
//
// Seperate flags
//  OF_<name> = 000xxxx
//
// Collection flags
//   O0 = 001xxxx
//   O1 = 010xxxx
//   O2 = 011xxxx
//   O3 = 100xxxx
//
enum slcc_optimizer_flag
  {
    OF_NONE = 0,         /* 0b00000, No optimization */
    OF_UNROLL_LOOPS = 1, /* 0b00001, Unroll loops aggressively */
    OF_REDUCE_LOOPS = 2, /* 0b00010, Move code out of the loops */
    OF_O0 = 5,           /* 0b00101, Standard O0 optimizer setting */
    OF_O1 = 11,          /* 0b01011, Standard O1 optimizer setting */
    OF_O2 = 15,          /* 0b01111, Standard O2 optimizer setting */
    OF_O3 = 19           /* 0b10011, Standard O3 optimizer setting */
  };

typedef enum slcc_optimizer_flag slcc_optimizer_flag;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// check_optimize_flags macro
//
// Check optimize flags.
//
#define check_optimize_flags(optimize_flag)	\
  (settings_.optimize_flags & optimize_flag)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// reset_optimize_flags macro
//
// Reset optimize flags.
//
#define reset_optimize_flags(optimize_flag)		\
  settings_.optimize_flags = settings_.optimize_flags 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// set_optimize_flags macro
//
// Set optimize flags.
//
#define set_optimize_flags(optimize_flag)				\
  settings_.optimize_flags = settings_.optimize_flags | optimize_flag
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Optimize flag functions
//
bool check_optimize_flag (char* warning_flag);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_OPTIMIZE_FLAGS_H__ */

//-<EOF>
