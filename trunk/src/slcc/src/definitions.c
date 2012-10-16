/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// definitions.c
//------------------------------------------------------------------------------
// Definition handling for the compiler front end.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "built_in_types.h"
#include "definitions.h"
#include "types.h"

//------------------------------------------------------------------------------
// def_new_built_in_type function
//
// Create a built_int_type object and returns it as definition object
//
slcc_definition* def_new_built_in_type (slcc_cpp_built_in_type type) 
{
  slcc_definition* definition = malloc (sizeof (slcc_definition));

  definition->type = DT_BUILT_IN;
  definition->definition.built_in = type;

  return definition;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// def_new_namespace function
//
// Creates a namespace and returns it as defintiions object.
//
slcc_definition* def_new_namespace (
				    slcc_definition* outer_namespace, 
				    symtab_key_t key,
				    bool is_anonymous
				    )
{
  slcc_definition* definition = malloc (sizeof (slcc_definition));

  definition->type = DT_NAMESPACE;
  definition->scope = outer_namespace;
  definition->definition.namespace.symtab_key = key;
  definition->definition.namespace.is_anonymous = is_anonymous;

  return definition;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// def_delete function
//
// Destroy a definition object.
//
void def_delete (slcc_definition* definition) 
{
  free (definition->scope);

  switch (definition->type) {

  case DT_BUILT_IN :
    /* Nothing to do */
    break;
 
  case DT_CLASS :
    free (definition->definition.class.ancestors);
    free (definition->definition.class.members);
    free (definition->definition.class.methods);
    free (definition->definition.class.types);
    break;

  case DT_ENUMERATION :
    free (definition->definition.enumeration.values);
    break;

  case DT_FUNCTION :
    free (definition->definition.function.args);
    break;

  case DT_NAMESPACE :
    /* Nothing to do */
    break;

  default :
    /* <TODO - Report error ERR_INVALID_DEFINITION> */
    break;
  }

  free (definition);
}
//------------------------------------------------------------------------------

//-<EOF>
