/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
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
// built_in_types.h
//------------------------------------------------------------------------------
// Built-in types for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_BUILT_IN_TYPES_H__
#define __SL_SLCC_BUILT_IN_TYPES_H__

//------------------------------------------------------------------------------
// slcc_built_in_type enumeration
//
// List of built in types. These are the types with native compiler support.
//
enum slcc_cpp_built_in_type 
  {
    BT_VOID,               /* Void */
    BT_BOOL,               /* Boolean value */
    BT_UNSIGNED_CHAR,      /* Unsigned character */
    BT_SIGNED_CHAR,        /* Signed character */
    BT_CHAR16_T,           /* Char16_t character */
    BT_CHAR32_T,           /* Char32_t character */
    BT_WCHAR_T,            /* Wchar_t character */
    BT_UNSIGNED_SHORT,     /* Unsigned short */
    BT_SIGNED_SHORT,       /* Signed short */
    BT_UNSIGNED_INT,       /* Unsigned integer */
    BT_SIGNED_INT,         /* Signed integer */
    BT_UNSIGNED_LONG,      /* Unsigned long */
    BT_SIGNED_LONG,        /* Signed long */
    BT_UNSIGNED_LONG_LONG, /* Unsigned long long */
    BT_SIGNED_LONG_LONG,   /* Signed long long */
    BT_FLOAT,              /* Floating point number */
    BT_DOUBLE,             /* Double floating point number */
    BT_LONG_DOUBLE         /* Long double floating point number */
  };

typedef enum slcc_cpp_built_in_type slcc_cpp_built_in_type;
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_BUILT_IN_TYPES_H__ */

//-<EOF>
