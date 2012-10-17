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
// hash_function.c
//------------------------------------------------------------------------------
// Hash function for the compiler front end.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

#include "hash_function.h"
#include "types.h"

//------------------------------------------------------------------------------
// Private functions
//
symtab_key_t hash_generate_key (slcc_hash_type type, const char* key_value);
symtab_key_t hash_get_cxx_char_hash_value (char c);
symtab_key_t hash_get_pp_char_hash_value (char c);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// MaxCppHashTableEntries constant
//
// Contains the maxinum number of entries allowed in the C++ hash table.
//
const symtab_key_t MaxCppHashTableEntries = 128000;
const size_t MaxCppHashCharacterValue = 84;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// MaxPreHashTableEntries constant
//
// Contains the maxinum number of entries allowed in the Preprocessor hash
// table.
//
const symtab_key_t MaxPreHashTableEntries = 64000;
const size_t MaxPreHashCharacterValue = 83;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// hash_generate_cxx_key function
//
// Generates a hash key for a C++ identifier.
//
symtab_key_t hash_generate_cxx_key (const char* key_value) 
{
  return hash_generate_key (
			    HT_CXX,
			    key_value
			    );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// hash_generate_pp_key function
//
// Generates a hash key for a preprocessor macro.
//
symtab_key_t hash_generate_pp_key (const char* key_value) 
{
  return hash_generate_key (
			    HT_PREPROCESSOR,
			    key_value
                            );
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions

//------------------------------------------------------------------------------
// hash_generate_key function
//
// This function generates a hash key based on the string and the configuration
// parameters given.
//
// Hashing is done as follows:
//    1) For each character a number is generated using the supplied function 
//       pointer.
//    2) This value for each character is multiplied by the position in the 
//       string.
//    3) The obtained values are summed. If this sum overflows we ignore it.
//    4) The remainder of the sum divided by the hash_table_size parameter is 
//       the hash_key.
//
symtab_key_t hash_generate_key (slcc_hash_type type, const char* key_value) 
{
  hash_function_ptr hash_function;
  symtab_key_t hash_table_size;
  size_t max_char_value;

  if (type == HT_CXX) 
    {
      hash_function = &hash_get_cxx_char_hash_value;
      hash_table_size = MaxCppHashTableEntries;
      max_char_value = MaxCppHashCharacterValue;
    }
  else 
    {
      hash_function = &hash_get_pp_char_hash_value;
      hash_table_size = MaxPreHashTableEntries;
      max_char_value = MaxPreHashCharacterValue;
    }

  symtab_key_t key = 0;
  symtab_key_t pos = 0;
  
  while (*key_value != '\0') 
    {
      pos++;
      key += hash_function (*key_value) * pos * max_char_value;
      key_value++;
    }
  
  return key % hash_table_size;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// hash_get_cxx_char_hash_value function
//
// This function calculates the character value for a valid C++ character to
// hash.
//
// Allowed characters are:
//   space = 0
//   @     = 1
//   (     = 2
//   #     = 3
//   <     = 4
//   >     = 5
//   0-9   = 8  + c - '0'
//   a-z   = 20 + c - 'a'
//   A-Z   = 50 + c - 'A'
//   _     = 83
//   :     = 84
//
symtab_key_t hash_get_cxx_char_hash_value (char c) 
{
  if (c == ' ')
    return 0;
  else if (c == '@')
    return 1;
  else if (c == '(')
    return 2;
  else if (c == '#')
    return 3;
  else if (c == '<')
    return 4;
  else if (c == '>')
    return 5;
  else if (c >= '0' && c <= '9')
    return 8 + c - '0';
  else if (c >= 'A' && c <= 'Z')
    return 20 + c - 'A';
  else if (c >= 'a' && c <= 'z')
    return 50 + c - 'a';
  else if (c == '_')
    return 83;
  else if (c == ':')
    return 84;
  else
    return MaxCppHashTableEntries;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// hash_get_pp_char_hash_value function
//
// This function calculates the character value for a valid C++ character to
// hash.
//
// Allowed characters are:
//   space = 0
//   0-9   = 1  + c - '0'
//   a-z   = 15 + c - 'a'
//   A-Z   = 45 + c - 'A'
//   _     = 83
//
symtab_key_t hash_get_pp_char_hash_value (char c) 
{
  if (c == ' ')
    return 0;
  else if (c >= '0' && c <= '9')
    return 1 + c - '0';
  else if (c >= 'A' && c <= 'Z')
    return 15 + c - 'A';
  else if (c >= 'a' && c <= 'z')
    return 45 + c - 'a';
  else if (c == '_')
    return 83;
  else
    return MaxPreHashTableEntries;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
