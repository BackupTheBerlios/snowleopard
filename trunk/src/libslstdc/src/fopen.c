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

#include "stdc/private/ll_open_files.h"
#include "stdc/private/program_globals.h"
#include "stdc/private/stdio_private.h"

#include sl_os_fixinclude(fcntl.h)
#include sl_os_fixinclude(unistd.h)

//------------------------------------------------------------------------------
// fopen function
//
// Open a file.
//
FILE* (fopen) (const char* name, const char* smode)
{
  int fd;
  int mode;

  if (*smode != 'r' && *smode != 'w' && *smode != 'a')
    return NULL;

  if (*smode == 'w') 
    {
      mode = _IOWRITE;
      fd = creat (name, _DEFAULT_PERMISSIONS);
    }
  else if(*smode == 'a') 
    {
      mode = _IOWRITE;
      if ((fd = open (name, O_WRONLY, 0)) == -1)
	fd = creat (name, _DEFAULT_PERMISSIONS);
      lseek (fd, 0L, SEEK_END);
    }
  else 
    {
      mode = _IOREAD;
      fd = open (name, O_RDONLY, 0);
    }
  
  if (fd == -1)
    return NULL;
  
  FILE *file = malloc (sizeof (FILE));

  if(file == NULL)
    return NULL;
  
  tc_ll_add_of (__SL_OpenFiles, file, FOPEN_MAX);
  
  return file;
}
//------------------------------------------------------------------------------

//-<EOF>
