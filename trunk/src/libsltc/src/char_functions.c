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
// char_functions.c
//------------------------------------------------------------------------------
// Character functions for the typed component library.
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "char_functions.h"

//------------------------------------------------------------------------------
// tc_get_char_from_universal_char function
//
// Converts single and double hex-quad universal character names to char. 
//
char tc_get_char_from_universal_char (unsigned long universal_char)
{
  /* <TODO: Implement universal char name lookup> */
  char c = (char)universal_char;

  return c;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_is_alpha_or_underscore function
//
// Return true if the char is a valid first character for an identifier.
//
bool tc_is_alpha_or_underscore (char c) {
  switch (c) {
  case 'a' :
  case 'b' :
  case 'c' :
  case 'd' :
  case 'e' :
  case 'f' :
  case 'g' :
  case 'h' :
  case 'i' :
  case 'j' :
  case 'k' :
  case 'l' :
  case 'm' :
  case 'n' :
  case 'o' :
  case 'p' :
  case 'q' :
  case 'r' :
  case 's' :
  case 't' :
  case 'u' :
  case 'v' :
  case 'w' :
  case 'x' :
  case 'y' :
  case 'z' :
  case 'A' :
  case 'B' :
  case 'C' :
  case 'D' :
  case 'E' :
  case 'F' :
  case 'G' :
  case 'H' :
  case 'I' :
  case 'J' :
  case 'K' :
  case 'L' :
  case 'M' :
  case 'N' :
  case 'O' :
  case 'P' :
  case 'Q' :
  case 'R' :
  case 'S' :
  case 'T' :
  case 'U' :
  case 'V' :
  case 'W' :
  case 'X' :
  case 'Y' :
  case 'Z' : 
  case '_' :
    return true;
    break;
		
  default :			
    return false;
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_is_decimal_digit function
//
// If character is a numeric digit return true.
//
bool tc_is_decimal_digit (char c) 
{
  switch (c) {
  case '0' :
  case '1' :
  case '2' :
  case '3' :
  case '4' :
  case '5' :
  case '6' :
  case '7' :
  case '8' :
  case '9' :
    return true;
    break;
    
  default :
    return false;
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_is_hexadecimal_digit function
//
// If character is a hexadecimal return true.
//
bool tc_is_hexadecimal_digit (char c) 
{
  switch (c) {
  case '0' :
  case '1' :
  case '2' :
  case '3' :
  case '4' :
  case '5' :
  case '6' :
  case '7' :
  case '8' :
  case '9' :
  case 'A' :
  case 'B' :
  case 'C' :
  case 'D' :
  case 'E' :
  case 'F' :
  case 'a' :
  case 'b' :
  case 'c' :
  case 'd' :
  case 'e' :
  case 'f' :
    return true;
    break;
    
  default :
    return false;
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_is_octal_digit function
//
// If character is an octal return true.
//
bool tc_is_octal_digit (char c)
{
  switch (c) {
  case '0' :
  case '1' :
  case '2' :
  case '3' :
  case '4' :
  case '5' :
  case '6' :
  case '7' :
    return true;
    break;

  default :
    return false;
    break;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tc_is_whitespace function
//
// If character is whitespace return true.
//
bool tc_is_whitespace (char c) 
{
  switch (c) {
  case ' ' :
  case '\0' :
  case '\n' :
  case '\r' :
  case '\t' :
    return true;
    break;
    
  default :
    return false;
    break;
  }
}
//------------------------------------------------------------------------------

//-<EOF>
