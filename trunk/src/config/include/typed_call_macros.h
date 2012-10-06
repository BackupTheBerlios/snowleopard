/*==============================================================================
  Snow Leopard Compiler Project
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// typed_call_macros.h
//------------------------------------------------------------------------------
// Typed call macros.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_TYPED_CALL_MACROS_H__
#define __SL_CONFIG_TYPED_CALL_MACROS_H__

//------------------------------------------------------------------------------
// sl_fp_typed_call_1_arg macro
//
// Calls a macro or function with the correct type deduced from the argument
// provided.
// If argument is float      : <name>f(arg0)
//                double     : <name>d(arg0)
//                long double: <name>l(arg0)
//
#define sl_fp_typed_call_1_arg(name, arg) \
  ((sizeof(arg0) == sizeof(float))        \
  ? name ## f (arg0)                      \
  : ((sizeof(arg0) == sizeof(double))     \
  ? name ## d (arg0)                      \
  : name ## l (arg0)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sl_fp_typed_call_2_arg macro
//
// Calls a macro or function with the correct type deduced from the argument
// provided.
// If argument is float      : <name>f(arg0,arg1)
//                double     : <name>d(arg0,arg1)
//                long double: <name>l(arg0,arg1)
//
#define sl_fp_typed_call_2_arg(name, arg0, arg1) \
  ((sizeof(arg0) == sizeof(float))               \
  ? name ## f (arg0,arg1)                        \
  : ((sizeof(arg0) == sizeof(double))            \
  ? name ## d (arg0,arg1)                        \
  : name ## l (arg0,arg1)
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_TYPED_CALL_MACROS_H__ */

//-<EOF>
