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
// driver.c
//------------------------------------------------------------------------------
// Driver functions for the front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdio.h>

#include "driver.h"
#include "error.h"
#include "error_codes.h"
#include "error_handling.h"
#include "settings.h"
#include "types.h"

#include "file_functions.h"

//------------------------------------------------------------------------------
// Private function prototypes
//
void drv_parse_spec_line (char* line);
bool drv_parse_specs_file (const char* file);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_parse_specs function
//
// Parses the specs file. The search for this file is as follows. Files parsed
// later are higher priority.
//   ../shared/slcc/slcc.specs
//   ./slcc.specs
//   ~/.slcc.specs
//
bool drv_parse_specs ()
{
  bool ok = true;

  char* specs_file = "../shared/slcc/slcc.deps";
  if (tc_file_exists (specs_file))
    ok = drv_parse_specs_file (specs_file);

  specs_file = "./slcc.specs";
  if (tc_file_exists (specs_file))
    ok = drv_parse_specs_file (specs_file);

  specs_file = "~/.slcc.specs";
  if (tc_file_exists (specs_file))
    ok = drv_parse_specs_file (specs_file);

  return true;
}
//------------------------------------------------------------------------------

//==============================================================================
// Private functions
//

//------------------------------------------------------------------------------
// drv_parse_spec_line function
//
// Parse a single spec line.
//
void drv_parse_spec_line (char* line)
{
  /* Is it a comment */
  if (*line == '#')
    return;

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_parse_specs_file function
//
// This function parses the specs file given as argument.
//
bool drv_parse_specs_file (const char* specs_file)
{
  char* line = malloc (sizeof (char[MaxLineSize]));
  FILE* file = fopen (specs_file, "r");

  if (file == NULL)
    {
      while (!feof (file))
	{
	  if (fgets (line, MaxLineSize, file) != NULL)
	    drv_parse_spec_line (line);
	}
      fclose (file);
    }
  else
    return false;

  return true;
}
//------------------------------------------------------------------------------

//==============================================================================

//-<EOF>
