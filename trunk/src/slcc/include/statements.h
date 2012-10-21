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
// statements.h
//------------------------------------------------------------------------------
// Template structures for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_STATEMENTS_H__
#define __SL_SLCC_STATEMENTS_H__

#include "arguments.h"

//------------------------------------------------------------------------------
// Forward declarations.
struct slcc_unary_operator;
struct slcc_binary_operator;
struct slcc_ternary_operator;
struct slcc_function_call;
struct slcc_assignment;

typedef struct slcc_unary_operator slcc_unary_operator;
typedef struct slcc_binary_operator slcc_binary_operator;
typedef struct slcc_ternary_operator slcc_ternary_operator;
typedef struct slcc_function_call slcc_function_call;
typedef struct slcc_assignment slcc_assignment;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_statement_type enumeration
enum slcc_statement_type 
  {
    STMT_UNARY_OP,      /* Unary operator */
    STMT_BINARY_OP,     /* Binary operator */
    STMT_TERNARY_OP,    /* Ternary operator */
    STMT_FUNCTION_CALL, /* Function call */
    STMT_ASSIGNMENT     /* Assignment */
  };

typedef enum slcc_statement_type slcc_statement_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_unary_operator struct
//
// Store a single unary operator.
//
struct slcc_unary_operator
{

};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_binary_operator struct
//
// Store a single binary operator.
//
struct slcc_binary_operator
{

};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_ternary_operator structure
//
// Stores a single ternary operator.
//
struct slcc_ternary_operator
{

};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_function_call structure
//
// Store a function call.
//
struct slcc_function_call
{
  symtab_key_t symtab_key;
  slcc_arguments* args;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_assignment structure
//
// Stores a single assignment.
//
struct slcc_assignment
{

};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_statement structure
//
// Stores a single statement.
//
struct slcc_statement
{
  slcc_statement_type type;

  union
  {
    slcc_unary_operator unary_op;
    slcc_binary_operator binary_op;
    slcc_ternary_operator ternary_op;
    slcc_function_call function_call;
    slcc_assignment assignment;
  } statement;
};

typedef struct slcc_statement slcc_statement;
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_STATEMENTS_H__ */

//-<EOF>
