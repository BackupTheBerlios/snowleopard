/*==============================================================================
  Lynx Typesetting System
  
  Copyright (C) 2012 Roel Sergeant
  All rights reserved.
   
  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:
       
   o Redistributions of source code must retain the above copyright notice, 
     this list of conditions and the following disclaimer.
   o Redistributions in binary form must reproduce the above copyright notice, 
     this list of conditions and the following disclaimer in the documentation 
     and/or other materials provided with the distribution.
                            
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
  POSSIBILITY OF SUCH DAMAGE.
  ============================================================================*/

//------------------------------------------------------------------------------
// driver.c
//------------------------------------------------------------------------------
// Driver functions for the Lynx typesetting system.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <string.h>

#include "driver.h"
#include "settings.h"

//------------------------------------------------------------------------------
// drv_initialize function
//
// Initializes the driver.
//
bool drv_initialize ()
{
  if (!settings_initialize ())
    return false;

  if (!drv_initialize_tool_specific_settings ())
    {
      settings_cleanup ();
      return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_cleanup function
//
// Cleans up after the elimination process has finished.
//
void drv_cleanup ()
{
  settings_cleanup ();

  drv_cleanup_tool_specific_settings ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_start function
// 
// Start the process.
//
bool drv_start ()
{
  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// parse_command_line function
//
// Parses the command line arguments and stores the settings.
//
bool drv_parse_command_line (int argc, char** argv) 
{
  for(int i = 1; i < argc; i++)
    {
      /* Argument --copyright */
      if (strcmp (argv[i], "--copyright") == 0)
	settings_.copyright_only = true;

      /* 
       * Argument --help
       *          -h
       *	  --usage
       */
      else if (strcmp (argv[i], "--help") == 0 
	  || strcmp (argv[i], "-h") == 0 
	  || strcmp (argv[i], "--usage") == 0)
	settings_.usage_only = true;

      /*
       * Argument -q 
       *          --quiet
       */
      else if (strcmp (argv[i], "-q") == 0
	       || strcmp (argv[i], "--quiet") == 0)
	settings_.quiet = true;

      /*
       * Argument -v
       *          --verbose
       */
      else if (strcmp (argv[i], "-v") == 0
	       || strcmp (argv[i], "--verbose") == 0)
	settings_.verbose = true;

      /* Argument --version */
      else if (strcmp (argv[i], "--version") == 0)
	settings_.version_only = true;

      /* Argument --warrantee */
      else if (strcmp (argv[i], "--warrantee") == 0)
	settings_.warrantee_only = true;

      /* Tool specific arguments */
      else if (drv_parse_tool_specific_argument (&i, argv))
	/* Argument parsed */ ;

      /* Argument not valid */
      else
	return false;
    }

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>

