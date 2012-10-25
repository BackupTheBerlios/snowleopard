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
// features.h
//------------------------------------------------------------------------------
// Warning handling for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_FEATURES_H__
#define __SL_SLCC_FEATURES_H__

#include <stdbool.h>

//------------------------------------------------------------------------------
// slcc_feature_type
//
// Feature flags used by the compiler.
//
enum slcc_feature_type
  {
    FEATURE_NONE = 0,              /* 0b000000000, No features selected */
    FEATURE_C = 1,                 /* 0b000000001, C89 language */
    FEATURE_CXX = 2,               /* 0b000000010, C++98 language */
    FEATURE_BINARY_LITERALS = 4,   /* 0b000000100, Support binary literals */
    FEATURE_ANONYMOUS_UNIONS = 8,  /* 0b000001000, Support anonymous nested 
				      unions */
    FEATURE_EXPORT = 16,           /* 0b000010000, C++ template export */
    FEATURE_CONCEPTS = 32,         /* 0b000100000, C++ template concepts */   
    FEATURE_C89 = 65,              /* 0b001000001, Standard C89 language */
    FEATURE_C99 = 129,             /* 0b010000001, Standard C99 language */
    FEATURE_C11 = 193,             /* 0b011000001, Standard C11 language */
    FEATURE_C1Y = 269,             /* 0b100001101, Experimental C language */
    FEATURE_CXX98 = 322,           /* 0b101000010, Standard C++98 language */
    FEATURE_CXX11 = 398,           /* 0b110001110, Standard C++11 language */
    FEATURE_CXX1Y = 510            /* 0b111111110, Experimental C++ language */
  };

typedef enum slcc_feature_type slcc_feature_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// check_features macro
//
// Check feature flags.
//
#define check_features(warning_flag)		\
  (settings_.features & warning_flag)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// reset_features macro
//
// Reset feature flags.
//
#define reset_features(warning_flag)			\
  settings_.features = warning_flag 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// set_features macro
//
// Set feature flags.
//
#define set_features(warning_flag)			\
  settings_.features = settings_.features | warning_flag
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Warning functions
//
bool check_feature_flag (char* warning_flag);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_FEATURES_H__ */

//-<EOF>

