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
// string_functions.h
//------------------------------------------------------------------------------
// String functions for the typed component library.
//------------------------------------------------------------------------------

#ifndef __SL_TC_STRING_FUNCTIONS_H__
#define __SL_TC_STRING_FUNCTIONS_H__

//------------------------------------------------------------------------------
// String functions
//
char* tc_append_string (const char* str1, const char* str2);
char* tc_copy_string (const char* str);
char* tc_get_str_after_nth_last (const char* str, const char delim, int count);
char* tc_replace_in_string (
			    const char* str1, 
			    const char* to_replace, 
			    const char* replacement
			    );
//------------------------------------------------------------------------------

#endif /* !__SL_TC_STRING_FUNCTIONS_H__ */

//-<EOF>
