/*==============================================================================
  Snow Leopard Typed Component Library
  
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
// integer_functions.h
//------------------------------------------------------------------------------
// Integer functions for the typed component library.
//------------------------------------------------------------------------------

#ifndef __SL_TC_INTEGER_FUNCTIONS_H__
#define __SL_TC_INTEGER_FUNCTIONS_H__

//------------------------------------------------------------------------------
// Integer functions
//
unsigned long tc_convert_bin_to_dec (const char* s);
unsigned long tc_convert_hex_to_dec (const char* s);
unsigned long tc_convert_oct_to_dec (const char* s);
int tc_get_bin_value (char);
int tc_get_hex_value (char);
int tc_get_oct_value (char);
//------------------------------------------------------------------------------

#endif /* !__SL_TC_INTEGER_FUNCTIONS_H__ */

//-<EOF>
