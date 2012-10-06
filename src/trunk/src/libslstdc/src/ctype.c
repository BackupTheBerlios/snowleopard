/*==============================================================================
  Snow Leopard Standard C Library
  
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
// ctype.c
//------------------------------------------------------------------------------
// Standard character type implementation
//------------------------------------------------------------------------------

#include <ctype.h>
#include <stdbool.h>

//------------------------------------------------------------------------------
// isalnum
int isalnum(int c) {
  /* TODO */
  return (isdigit(c) | isalpha(c));
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isalpha
int isalpha(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isblank
int isblank(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// iscntrl
int iscntrl(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isdigit
int isdigit(int c) {
  switch (c) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
      return true;
      break;
    default:
      return false;
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isgraph
int isgraph(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// islower
int islower(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isprint
int isprint(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ispunct
int ispunct(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isspace
int isspace(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isupper
int isupper(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// isxdigit
int isxdigit(int c) {
  /* TODO */
  return false;
}
//------------------------------------------------------------------------------

//-<EOF>
