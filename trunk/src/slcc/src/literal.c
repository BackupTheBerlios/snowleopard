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
// literal.c
//------------------------------------------------------------------------------
// Literal handling for the compiler front end.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "literal.h"

//------------------------------------------------------------------------------
// literal_delete function
//
// Function deletes a literal object.
//
void literal_delete (slcc_literal* literal) 
{
  switch (literal->type) {

  case LT_STRING :
    free (literal->value.string.value);
    break;

  case LT_STRING16 :
    free (literal->value.string16.value);
    break;

  case LT_STRING32 :
    free (literal->value.string32.value);
    break;

  case LT_WSTRING :
    free (literal->value.wstring.value);
    break;

  case LT_RAW_STRING :
    free (literal->value.raw_string.value);
    break;

  default:
    /* Other literal types need no special handling */
    break;
  }
}
//------------------------------------------------------------------------------

//-<EOF>
