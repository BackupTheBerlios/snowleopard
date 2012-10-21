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
// arguments.h
//------------------------------------------------------------------------------
// Objects for storing arguments used by the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_ARGUMENTS_H__
#define __SL_SLCC_ARGUMENTS_H__

#include "token.h"
#include "types.h"

//------------------------------------------------------------------------------
// slcc_argument_type enumeration
enum slcc_argument_type 
  {
    ARGT_LITERAL, /* Argument is a literal */
    ARGT_VARIABLE /* Argument is a variable */
  };

typedef enum slcc_argument_type slcc_argument_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_argument structure
//
// Structure to store a single argument.
//
struct slcc_argument 
{
  slcc_argument_type type;

  union 
  {
    symtab_key_t variable;
    slcc_token literal;
  } argument;
};

typedef struct slcc_argument slcc_argument;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_arguments structure
//
// Stores all arguments.
//
struct slcc_arguments
{
  size_t size;
  slcc_argument* args;
};

typedef struct slcc_arguments slcc_arguments;
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_ARGUMENTS_H__ */

//-<EOF>
