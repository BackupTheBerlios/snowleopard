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
// definitions.h
//------------------------------------------------------------------------------
// Definition structures for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_DEFINITIONS_H__
#define __SL_SLCC_DEFINITIONS_H__

#include <stdbool.h>

#include "built_in_types.h"
#include "specifiers.h"
#include "types.h"

//------------------------------------------------------------------------------
// Forward definitions.
//
struct slcc_class_type;
struct slcc_enumeration_type;
struct slcc_function_type;
struct slcc_namespace;
struct slcc_definition;

typedef struct slcc_class_type slcc_class_type;
typedef struct slcc_enumeration_type slcc_enumeration_type;
typedef struct slcc_function_type slcc_function_type;
typedef struct slcc_namespace slcc_namespace;
typedef struct slcc_definition slcc_definition;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_type enumeration
//
// Different types recognized by the compiler.
//
enum slcc_definition_type 
  {
    DT_BUILT_IN,    /* Built-in type */
    DT_CLASS,       /* Class type */
    DT_ENUMERATION, /* Enumerated type */
    DT_FUNCTION,    /* Function type */
    DT_NAMESPACE    /* Namespace type */
  };

typedef enum slcc_definition_type slcc_definition_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_class_type structure
//
// Stores a single class type
//
struct slcc_class_type 
{
  symtab_key_t symtab_key;
  bool is_class;
  size_t n_ancestors;
  slcc_class_type* ancestors;
  size_t n_members;
  slcc_type_specifier* members;
  size_t n_methods;
  slcc_function_type* methods;
  size_t n_types;
  slcc_type_specifier* types;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_enumeration_type structure
//
// Stores a single enumeration type.
//
struct slcc_enumeration_type 
{
  symtab_key_t symtab_key;
  slcc_type_specifier type;
  size_t n_values;
  signed long* values;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_function_type structure
//
// Structure for storing a function definition.
//
struct slcc_function_type
{
  symtab_key_t symtab_key;
  slcc_type_specifier return_type;
  size_t n_args;
  slcc_type_specifier* args;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_namespace structure
//
// Store a namespace.
// 
struct slcc_namespace
{
  symtab_key_t symtab_key;
  bool is_anonymous;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_definition structure
//
// Stores a single defintion.
//
struct slcc_definition 
{
  slcc_definition_type type;
  slcc_definition* scope;

  union 
  {
    slcc_cpp_built_in_type built_in;
    slcc_class_type class;
    slcc_enumeration_type enumeration;
    slcc_function_type function;
    slcc_namespace namespace;
  } definition;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initializer functions
slcc_definition* def_new_built_in_type (slcc_cpp_built_in_type type);
slcc_definition* def_new_namespace (
				    slcc_definition* outer_namespace,
				    symtab_key_t key, 
				    bool is_anonymous);
void def_delete (slcc_definition* definition);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_DEFINITIONS_H__ */

//-<EOF>
