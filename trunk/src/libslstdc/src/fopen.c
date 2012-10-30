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
// fopen.c
//------------------------------------------------------------------------------
// Standard input output implementation. This file contains the fopen function.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "stdc/private/program_globals.h"
#include "stdc/private/stdio_private.h"

//------------------------------------------------------------------------------
// fopen function
//
// Open a file.
//
FILE* (fopen) (const char* name, const char* mode)
{
  FILE *file = malloc (sizeof (FILE));

  sl_ll_of_node_* node = 
  
  return NULL;
}
//------------------------------------------------------------------------------

//-<EOF>
