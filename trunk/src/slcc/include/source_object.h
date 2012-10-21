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
// source_object.h
//------------------------------------------------------------------------------
// Source object for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_SOURCE_OBJECT_H__
#define __SL_SLCC_SOURCE_OBJECT_H__

#include <constructs.h>
#include <declarations.h>
#include <definitions.h>
#include <source_object_f.h>
#include <statements.h>
#include <templates.h>
#include <types.h>

//------------------------------------------------------------------------------
// slcc_source_type enum
//
// Source type.
//
enum slcc_source_object_type
  {
    SRCT_CONSTRUCT,   /* Construct type */
    SRCT_DECLARATION, /* Declaration type */
    SRCT_DEFINITION,  /* Definition type */
    SRCT_STATEMENT    /* Statement type */
  };
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_source_oject struct
//
// Stores one source object and all it's dependents.
//
struct slcc_source_object
{
  slcc_source_type type;
  symtab_key_t key;

  union
  {
    slcc_declaration* declaration;
    slcc_definition* definition;
    //    slcc_construct* construct;
    slcc_statement* statement;
  } object;
};
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_SOURCE_OBJECT_H__ */

//-<EOF>
