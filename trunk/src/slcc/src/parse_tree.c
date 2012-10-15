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
// parse_tree.h
//------------------------------------------------------------------------------
// Parse tree for the compiler front end.
//------------------------------------------------------------------------------

#include "parse_tree.h"
#include "source_object.h"

//------------------------------------------------------------------------------
// Define parse tree
#define TC_TREE_PREFIX slcc_parse
#define TC_TREE_NODE_TYPE slcc_source_object*
#define TC_TREE_FUNCTION_PREFIX pt
#define TC_TREE_FUNCTION_SUFFIX

#include "tree.c.h"

#undef TC_TREE_PREFIX
#undef TC_TREE_NODE_TYPE
#undef TC_TREE_FUNCTION_PREFIX
#undef TC_TREE_FUNCTION_SUFFIX
#undef TC_TREE_ROOT
#undef TC_TREE_NODE
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global parse tree
slcc_parse_tree* parse_tree_;
//------------------------------------------------------------------------------

//-<EOF>
