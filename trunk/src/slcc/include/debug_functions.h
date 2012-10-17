/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2010, 2011, 2012 Roel Sergeant
  
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
// debug_functions.h
//------------------------------------------------------------------------------
// Debug functions for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_DEBUG_FUNCTIONS_H__
#define __SL_SLCC_DEBUG_FUNCTIONS_H__

////////////////////////////////////////////////////////////////////////////////
// Debug functions

//------------------------------------------------------------------------------
// Settings
#ifdef __SLCC_DEBUG_SETTINGS
void debug_print_settings ();
#endif /* __SLCC_DEBUG_SETTINGS */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Symbol tables
#ifdef __SLCC_DEBUG_SYMBOL_TABLES
void debug_print_preprocessor_symbol_table ();
void debug_print_cpp_symbol_table ();
#endif /* __SLCC_DEBUG_SYMBOL_TABES */
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_SLCC_DEBUG_FUNCTIONS_H__ */

//-<EOF>
