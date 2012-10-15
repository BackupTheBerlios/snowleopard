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
// info.c
//------------------------------------------------------------------------------
// Information functions for the compiler front end.
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "info.h"
#include "settings.h"
#include "version_slcc.h"

//------------------------------------------------------------------------------
// inf_display_copyright function
//
// Displays the copyright information.
//
void inf_display_copyright ()
{
  printf (
	  "Copyright (c) %d Roel Sergeant. All rights reserved.\n\n",
	  __SL_COPYRIGHT_YEAR
	  );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// inf_display_license function
//
// Displays the license.
//
void inf_display_license ()
{
  printf 
    (
     "This program is free software: you can redistribute it and/or modify it under\n"
     "the terms of the GNU General Public License as published by the Free\n"
     "Software Foundation, either version 3 of the License, or (at your option) any\n"
     "later version\n"
     "\n"
     "This program is distributed in the hope that it will be useful, but WITHOUT\n"
     "ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS\n"
     "FOR A PARTICULAR PURPOSE. See the GNU General Public License for more\n"
     "details.\n"
     "\n"
     "You should have received a copy of the GNU General Public License along with\n"
     "this program. If not, see <http://www.gnu.org/licenses/>\n"
     );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// inf_display_program_info function
//
// Display program information.
//
void inf_display_program_info ()
{
  /* If quiet operation, do not display anything. */
  if (settings_.quiet)
    return;

  char* buffer = malloc (sizeof (char[MaxVersionLabelSize]));

  get_version_string (buffer);

  printf (
	  "%s - Snow Leopard C++ Interpreter - %s\n",
	  getprogname (), buffer
	  );

  inf_display_copyright ();

  free (buffer);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// inf_display_reporting_bugs function
//
// Display how to report bugs.
//
void inf_display_reporting_bugs ()
{
  printf 
    (
     "Please report the problem encountered to the developers. "
     "For more information, please check the file REPORTING_BUGS "
     "which was included in your distribution.\n"
     );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// inf_display_usage function
//
// Display usage information.
//
void inf_display_usage ()
{
  printf
    (
     "usage: %s [-ivlw] [-Ipath] [-Spath] [-std=<std>] [--language=<language>] "
     "source-file\n",
     getprogname ()
     );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// inf_display_warrantee function
//
// Display warrantee information.
//
void inf_display_warrantee ()
{
  printf
    (
     "THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY\n"
     "EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED\n"
     "WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE\n"
     "DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR\n"
     "ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
     "DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR\n"
     "SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER\n"
     "CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,\n"
     "OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
     "OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n"
     );
}
//------------------------------------------------------------------------------

//-<EOF>
