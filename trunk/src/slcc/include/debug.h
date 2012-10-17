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
// debug.h
//------------------------------------------------------------------------------
// Debug for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_DEBUG_H__
#define __SL_SLCC_DEBUG_H__

////////////////////////////////////////////////////////////////////////////////
// Debug
//
#ifdef __SLCC_DEBUG

//------------------------------------------------------------------------------
// Debug macros
//
# define __SLCC_DEBUG_PRINT_0(DEBUG_TYPE,func)	        \
  DEBUG_TYPE##_0(func)

# define __SLCC_DEBUG_PRINT_1(DEBUG_TYPE,func,arg0)	\
  DEBUG_TYPE##_1(func,arg0)
//------------------------------------------------------------------------------

# include "debug_functions.h"

//==============================================================================
// Debug settings
//
#ifdef __SLCC_DEBUG_SETTINGS
# define __SLCC_DEBUG_SETTINGS_0(func)		\
  func ();
#else /* __SLCC_DEBUG_SETTINGS */
# define __SLCC_DEBUG_SETTINGS_0(func)
#endif /* __SLCC_DEBUG_SETTINGS */
//==============================================================================

//==============================================================================
// Debug symbol tables
//
#ifdef __SLCC_DEBUG_SYMBOL_TABLES
# define __SLCC_DEBUG_SYMBOL_TABLES_0(func)	\
  func ();
#else /* __SLCC_DEBUG_SYMBOL_TABLES */
# define __SLCC_DEBUG_SYMBOL_TABLES_0(func)
#endif /* __SLCC_DEBUG_SYMBOL_TABLES */
//==============================================================================

#else /* __SLCC_DEBUG */

//------------------------------------------------------------------------------
// If no debug, undefine all debug macros
//
# undef __SLCC_DEBUG_SETTINGS
# undef __SLCC_DEBUG_SYMBOL_TABLES

# define __SLCC_DEBUG_PRINT_0(DEBUG_TYPE,func)
# define __SLCC_DEBUG_PRINT_1(DEBUG_TYPE,func,arg0)
//------------------------------------------------------------------------------

#endif /* __SLCC_DEBUG */
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_SLCC_DEBUG_H__ */

//-<EOF>
