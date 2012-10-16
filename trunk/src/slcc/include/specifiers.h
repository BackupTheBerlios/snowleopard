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
// specifiers.h
//------------------------------------------------------------------------------
// Specifier structures for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SPECIFIERS_H__
#define __SL_SLCC_SPECIFIERS_H__

#include <stdbool.h>

#include "types.h"

//------------------------------------------------------------------------------
// slcc_cv_qualifiers enum
//
// Constant/Volatile qualification.
//
enum slcc_cv_qualifier 
  {
    CVQ_NONE, 
    CVQ_CONST,
    CVQ_VOLATILE,
    CVQ_CONST_VOLATILE
  };

typedef enum slcc_cv_qualifier slcc_cv_qualifier;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_ref_type enumeration
//
// Pointer/Reference/Rvalue Reference type.
//
enum slcc_ref_type
  {
    REF_POINTER,
    REF_REFERENCE,
    REF_RVALUE_REFERENCE
  };

typedef enum slcc_ref_type slcc_ref_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_storage_class structure
//
// Structure for storing the storage class of an object.
//
struct slcc_storage_class 
{
  bool is_extern;
  bool is_mutable;
  bool is_register;
  bool is_static;
  bool is_thread_local;
};

typedef struct slcc_storage_class slcc_storage_class;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_ref_specifier structure
//
// Structure to store the reference type of a pointer/reference
//
struct slcc_ref_specifier
{
  slcc_ref_type ref_type;
  slcc_cv_qualifier cv_qualifier;
};

typedef struct slcc_ref_specifier slcc_ref_specifier;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_type_specifier structure
//
// Structure for storing a type specification.
//
struct slcc_type_specifier
{
  slcc_storage_class storage_class;
  slcc_cv_qualifier cv_qualifier;
  symtab_key_t type_key;
};

typedef struct slcc_type_specifier slcc_type_specifier;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global initial specifiers
extern slcc_cv_qualifier initial_cv_qualifier;
extern slcc_storage_class initial_storage_class;
extern symtab_key_t initial_type_key;
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SPECIFIERS_H__ */

//-<EOF>
