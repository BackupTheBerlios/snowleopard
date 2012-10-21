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
// constructs.h
//------------------------------------------------------------------------------
// Constructs for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_CONSTRUCTS_H__
#define __SL_SLCC_CONSTRUCTS_H__

#include "statements.h"

//------------------------------------------------------------------------------
// Forward declarations.
//
struct slcc_if_construct;
struct slcc_switch_construct;
struct slcc_for_construct;
struct slcc_for_range_construct;
struct slcc_while_construct;
struct slcc_do_construct;
struct slcc_construct;

typedef struct slcc_if_construct slcc_if_construct;
typedef struct slcc_switch_construct slcc_switch_construct;
typedef struct slcc_for_construct slcc_for_construct;
typedef struct slcc_for_range_construct slcc_for_range_construct;
typedef struct slcc_while_construct slcc_while_construct;
typedef struct slcc_do_construct slcc_do_construct;
typedef struct slcc_construct slcc_construct;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_declaration_type enumeration
//
// Types of constructs.
//
enum slcc_construct_type {
  CONSTR_STATEMENT, /* Any statement that's not a construct, including calls */
  CONSTR_IF,        /* if () ; else ; construct */
  CONSTR_SWITCH,    /* switch () { case: ; default: ; } construct */
  CONSTR_FOR,       /* for (;;) ; construct */
  CONSTR_FOR_RANGE, /* for (:) ; construct */
  CONSTR_WHILE,     /* while () ; construct */
  CONSTR_DO         /* do { } while () construct */
};

typedef enum slcc_construct_type slcc_construct_type;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_if_construct structure
//
// Stores a single if construct.
//
struct slcc_if_construct
{ 
  slcc_construct* condition;
  slcc_construct* if_statement;
  slcc_construct* else_statement;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// slcc_construct structure
//
// Store a single construct.
//
struct slcc_construct
{
  slcc_construct_type type;

  union
  {
    slcc_statement* stmt;
    slcc_if_construct* if_stmt;
    slcc_switch_construct* switch_stmt;
    slcc_for_construct* for_stmt;
    slcc_for_range_construct* for_range_stmt;
    slcc_while_construct* while_stmt;
    slcc_do_construct* do_stmt;
  } construct;
};
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_CONSTRUCTS_H__ */

//-<EOF>
