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
// run_1_P1_1_list_files_in_dir.c
//------------------------------------------------------------------------------
// Program 1.1 from Advanced Programming in the UNIX Environment. It lists all
// files in the current directory. 
//------------------------------------------------------------------------------

//##############################################################################
// SLTST - Config
//
// [build]  = [strict]
// [source] = run_1_P1_1_list_files_in_dir.c;apue_error_functions.c
// [run]    = [arg <directory:string>]
// [result] = [run <directory:valid>]
//              [no_assert][stdout:same_as("ls -1 <directory>")];
//            [run <directory:invalid>]
//              [no_assert][stdout("Can't open <directory>")];
//            [run]
//              [no_assert]
//              [stdout("A single argument (the directory name) is required")]
//##############################################################################

#include <dirent.h>

#include "apue_header.h"

//------------------------------------------------------------------------------
// main function
//
int main (int argc, char** argv)
{
  DIR *dp;
  struct dirent *dirp;

  if (argc != 2)
    err_quit ("A single argument (the directory name) is required");

  if ((dp = opendir (argv[1])) == NULL)
    err_sys ("Can't open %s", argv[1]);

  while ((dirp = readdir (dp)) != NULL)
    printf ("%s\n", dirp->d_name);

  closedir (dp);

  exit (0);
}
//------------------------------------------------------------------------------

//-<EOF>
