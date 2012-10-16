/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2008-2012 Roel Sergeant
  
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
// built_in_identifiers.h
//------------------------------------------------------------------------------
// Built-in identifiers for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_BUILT_IN_IDENTIFIERS_H__
#define __SL_SLCC_BUILT_IN_IDENTIFIERS_H__

//------------------------------------------------------------------------------
// slcc_built_in_identifier enumeration
//
// Enumeration for built-in identifiers and namespaces.
//
enum slcc_cpp_built_in_identifier 
  {
    BI_CURRENT_FUNCTION,              /* Identifier for the current function 
					 name */
  };

typedef enum slcc_cpp_built_in_identifier slcc_cpp_built_in_identifier;
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_BUILT_IN_IDENTIFIERS_H__ */

//-<EOF>
