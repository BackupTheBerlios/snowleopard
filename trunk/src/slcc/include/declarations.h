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
// declarations.h
//------------------------------------------------------------------------------
// Declarations for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_DECLARATIONS_H__
#define __SL_SLCC_DECLARATIONS_H__

#include "definitions.h"
#include "specifiers.h"
#include "types.h"

//------------------------------------------------------------------------------
// slcc_declaration_type enumeration
//
// Types of declarations.
//
enum slcc_declaration_type
  {
    DECLT_VARIABLE,
    DECLT_ARRAY
  };

typedef enum slcc_declaration_type slcc_declaration_type;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// slcc_variable_declaration structure
//
// Structure for storing a variable declaration.
//
struct slcc_variable_declaration
{ 
  slcc_type_specifier* type_specifier;
  size_t n_ref_specifiers;
  slcc_ref_specifier** ref_specifiers;
};

typedef struct slcc_variable_declaration slcc_variable_declaration;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_array_declaration structure
//
// Structure for storing an array declaration.
//
struct slcc_array_declaration
{ 
  slcc_type_specifier* type_specifier;
  size_t n_ref_specifiers;
  slcc_ref_specifier** ref_specifiers;
  size_t n_dimensions;
  size_t* dimension_sizes;
};

typedef struct slcc_array_declaration slcc_array_declaration;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_declaration structure
//
// Stored a single declaration.
//
struct slcc_declaration
{
  slcc_declaration_type type;
  slcc_definition* scope;

  union
  {
    slcc_variable_declaration variable;
    slcc_array_declaration array;
  } declaration;
};

typedef struct slcc_declaration slcc_declaration;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initializer functions
slcc_declaration* decl_new_variable (
				     slcc_type_specifier* type_spec,
				     size_t n_ref_specs,
				     slcc_ref_specifier** ref_spec,
				     slcc_definition* scope
				    );
slcc_declaration* decl_new_array (
				  slcc_type_specifier* type_spec,
				  size_t n_ref_specs,
				  slcc_ref_specifier** ref_spec,
				  size_t n_dim,
				  size_t* dim_sizes,
				  slcc_definition* scope
				  );
void decl_delete (slcc_declaration* declaration);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_DECLARATIONS_H__ */

//-<EOF>
