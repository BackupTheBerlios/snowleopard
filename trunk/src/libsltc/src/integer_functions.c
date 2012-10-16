/*==============================================================================
  Snow Leopard Typed Component Library
  
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
// integer_functions.c
//------------------------------------------------------------------------------
// Integer functions for the typed component library.
//------------------------------------------------------------------------------

#include "integer_functions.h"

//------------------------------------------------------------------------------
// tc_convert_hex_to_dec function 
//
// Convert hexadecimal string to numeric. 
//
unsigned long tc_convert_hex_to_dec (const char* s)
{
  unsigned long n = 0;

  for (int i = 0; s[i] != '\0'; i++)
    n = (n * 16) + tc_get_hex_value (s[i]);

  return n;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_convert_oct_to_dec function 
//
// Convert octal string to numeric.
//
unsigned long tc_convert_oct_to_dec (const char* s)
{
  unsigned long n = 0;
  
  for (int i = 0; s[i] != '\0'; i++)
    n = (n * 8) + tc_get_oct_value (s[i]);

  return n;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_get_hex_value function
//
// If character is a hexadecimal return it, otherwise return -1.
//
int tc_get_hex_value (char c) 
{
  switch (c) {
  case '0' :
    return 0;
    break;

  case '1' :
    return 1;
    break;

  case '2' :
    return 2;
    break;

  case '3' :
    return 3;
    break;

  case '4' :
    return 4;
    break;

  case '5' :
    return 5;
    break;

  case '6' :
    return 6;
    break;

  case '7' :
    return 7;
    break;

  case '8' :
    return 8;
    break; 

  case '9' :
    return 9;
    break;

  case 'A' :
  case 'a' :
    return 10;
    break;

  case 'B' :
  case 'b' :
    return 11;
    break;

  case 'C' :
  case 'c' :
    return 12;
    break;

  case 'D' :
  case 'd' :
    return 13;
    break;

  case 'E' :
  case 'e' :
    return 14;
    break;

  case 'F' :
  case 'f' :
    return 15;
    break;

  default :
    return -1;
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_get_oct_value function
//
// If character is a octal return it, otherwise return -1.
//
int tc_get_oct_value(char c) {
  switch (c) {
  case '0' :
    return 0;
    break;

  case '1' :
    return 1;
    break;

  case '2' :
    return 2;
    break;

  case '3' :
    return 3;
    break;

  case '4' :
    return 4;
    break;

  case '5' :
    return 5;
    break;

  case '6' :
    return 6;
    break;

  case '7' :
    return 7;
    break;

  default :
    return -1;
    break;
  }
}
//------------------------------------------------------------------------------
   
//------------------------------------------------------------------------------
//-<EOF>
