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
// cpp_symtab_built_in.c
//------------------------------------------------------------------------------
// Load built-ins into the symbol table.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "built_in_identifiers.h"
#include "built_in_types.h"
#include "cpp_symtab.h"
#include "source_position.h"
#include "strings.h"
#include "symbol_table.h"
#include "token.h"

//------------------------------------------------------------------------------
// Private functions.
//
bool cpp_symtab_new_bt_entry (slcc_cpp_built_in_type type, char* token);
bool cpp_symtab_new_bi_entry (
			      slcc_cpp_built_in_identifier identifier, 
			      char* token
			      );
slcc_definition* cpp_symtab_new_ns_entry (
					  char* token,
					  slcc_definition* namespace
					  );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// load_cpp_built_in_types function
//
// Loads the built-in types into the symbol table.
//
bool load_cpp_built_in_types () 
{
  bool ok = true;

  ok = cpp_symtab_new_bt_entry (BT_VOID, "void");
  ok = cpp_symtab_new_bt_entry (BT_BOOL, "bool");
  ok = cpp_symtab_new_bt_entry (BT_UNSIGNED_CHAR, "unsigned char");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_CHAR, "signed char");
  ok = cpp_symtab_new_bt_entry (BT_UNSIGNED_CHAR, "char");
  ok = cpp_symtab_new_bt_entry (BT_CHAR16_T, "char16_t");
  ok = cpp_symtab_new_bt_entry (BT_CHAR32_T, "char32_t");
  ok = cpp_symtab_new_bt_entry (BT_WCHAR_T, "wchar_t");
  ok = cpp_symtab_new_bt_entry (BT_UNSIGNED_SHORT, "unsigned short");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_SHORT, "signed short");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_SHORT, "short");	
  ok = cpp_symtab_new_bt_entry (BT_UNSIGNED_INT, "unsigned int");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_INT, "signed int");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_INT, "int");
  ok = cpp_symtab_new_bt_entry (BT_UNSIGNED_LONG, "unsigned long");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_LONG, "signed long");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_LONG, "long");
  ok = cpp_symtab_new_bt_entry (BT_UNSIGNED_LONG_LONG, "unsigned long long");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_LONG_LONG, "signed long long");
  ok = cpp_symtab_new_bt_entry (BT_SIGNED_LONG_LONG, "long long");
  ok = cpp_symtab_new_bt_entry (BT_FLOAT, "float");
  ok = cpp_symtab_new_bt_entry (BT_DOUBLE, "double");
  ok = cpp_symtab_new_bt_entry (BT_LONG_DOUBLE, "long double");
  
  return ok;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// load_cpp_built_in_identifiers function
//
// Loads the built-in types into the symbol table.
//
bool load_cpp_built_in_identifiers () 
{
  bool ok = true;
	
  ok = cpp_symtab_new_bi_entry (BI_CURRENT_FUNCTION, "__func__");

  return ok;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// load_cpp_built_in_namespaces function
//
// Create the built-in namespaces.
//
bool load_cpp_built_in_namespaces ()
{
  bool ok = true;
  slcc_definition* ns = NULL;

  ns = cpp_symtab_new_ns_entry ("::", ns);
  ok = ns == NULL ? false : true;

  ns = cpp_symtab_new_ns_entry ("::sl", ns);
  ok = ns == NULL ? false : true;

  ns = cpp_symtab_new_ns_entry ("::sl::built_in", ns);
  ok = ns == NULL ? false : true;

  ns = cpp_symtab_new_ns_entry ("::sl::built_in::functions",ns);
  ok = ns == NULL ? false : true;

  return ok;
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions.

//------------------------------------------------------------------------------
// cpp_symtab_new_bt_entry function
//
// Create a built-in type symbol table entry.
//
bool cpp_symtab_new_bt_entry (slcc_cpp_built_in_type type, char* token) 
{
  symtab_key_t key;
  key = symtab_set_entry (
			  &cpp_symtab,
			  token,
			  token_new_built_in (token, NoSourcePosition),
			  NoSourcePosition,
			  NULL
			  );

  if (key == MaxSymtabKeyT)
    return false;
  
  if (!symtab_set_definition (
			      &cpp_symtab,
			      key,
			      def_new_built_in_type (type)
			      )
      )
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// cpp_symtab_new_bi_entry function
//
// Creates a symtab entry for built-in identifiers.
//
bool cpp_symtab_new_bi_entry (
			      slcc_cpp_built_in_identifier identifier, 
			      char* token
			      )
{
  symtab_key_t key;
  key = symtab_set_entry (
			  &cpp_symtab,
			  token,
			  token_new_identifier (
						str_new (token), 
						NoSourcePosition
						),
			  NoSourcePosition,
			  NULL
			  );

  if (key == MaxSymtabKeyT)
    return false;
  
  if (!symtab_set_definition (
			      &cpp_symtab,
			      key,
			      /* <TODO: replace by identifier built-in> */
			      def_new_built_in_type (identifier)
			      )
      )
    return false;

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// cpp_symtab_new_ns_entry function
//
// Creates a symtab entry for namespace identifiers.
//
slcc_definition* cpp_symtab_new_ns_entry (
					  char* token, 
					  slcc_definition* outer_namespace
					  )
{
  symtab_key_t key;
  key = symtab_set_entry (
			  &cpp_symtab,
			  token,
			  token_new_identifier (
						str_new (token), 
						NoSourcePosition
						),
			  NoSourcePosition,
			  NULL
			  );

  if (key == MaxSymtabKeyT)
    return NULL;
  
  slcc_definition* ns = def_new_namespace (
					   outer_namespace,
					   key, 
					   false
					   );

  if (ns == NULL)
    return NULL;

  if (!symtab_set_definition (&cpp_symtab, key, ns))
    return NULL;

  return ns;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
