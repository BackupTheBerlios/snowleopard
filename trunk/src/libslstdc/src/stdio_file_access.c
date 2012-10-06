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
// stdio_file_access.c
//------------------------------------------------------------------------------
// Standard input/output implementation: file access functions
//
// Functions: fclose
//            fflush
//            fopen
//            freopen
//            setbuf
//            setvbuf
//------------------------------------------------------------------------------

#include <sl/config/config.h>

#include <sl/config/os_fixinclude.h>

#include <sl/stdc/private/ll_open_files.h>
#include <sl/stdc/private/program_globals.h>
#include <sl/stdc/private/stdio_private.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include sl_os_fixinclude(fcntl.h)
#include sl_os_fixinclude(unistd.h)

//------------------------------------------------------------------------------
// fclose function
int fclose(FILE* stream) {
  if(fflush(stream) == EXIT_FAILURE)
    return EXIT_FAILURE;

  int retval = close(stream->_file_descriptor);

  _sl_destroy_stream(stream);
  
  return retval;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// fflush function
int fflush(FILE* stream) {  
  if (stream == NULL) {
    errno_t e = errno;
    errno = 0;
    
    e = _sl_apply_to_streams(&fflush);
    
    if (errno != 0)
      return EXIT_FAILURE;
    errno = e;
    return EXIT_SUCCESS;
  }

  /* Stream not open for writing */
  if((stream->_flag && _IOWRITE) != _IOWRITE) {
    errno = EINVAL;
    return EXIT_SUCCESS;
  }

  /* Undo ungetc */
  stream->_flag &= ~_IOUNGETC;

  char* base;
  int r_n;
  int n;
  
  /* Check for buffered dirty blocks */
  if(((stream->_flag & (_IODIRTYBLOCK|_IOUNBUF)) == _IODIRTYBLOCK)
     && (stream->_base != NULL)) {
    base = stream->_base;

    /* if the buffer is read ahead and dirty we will flush it entirely else
       the buffer is appended to the file to the extend it has valid bytes */
    if ((stream->_flag & _IOREADAHEAD) == _IOREADAHEAD)
      r_n = n = stream->_ptr - base + stream->_count;
    else
      r_n = n = stream->_ptr - base;
    
    stream->_ptr = base;
    
    if((stream->_flag & _IOFIXEDBUF) == _IOFIXEDBUF)
      if((stream->_flag & _IOREADAHEAD) == _IOREADAHEAD)
        lseek(stream->_file_descriptor,-r_n, SEEK_CUR);
    
    stream->_flag &= ~_IOREADAHEAD;
    
    stream->_count = (stream->_flag & (_IOLINEBUF|_IOUNBUF))
        ? 0
        : stream->_buffersize;

    /* possibly commit the flushed data */
    do {
      n = write(stream->_file_descriptor, base, r_n);
      if (n <= 0) {
        stream->_flag |= _IOERROR;
        return EOF;
      }
      r_n -= n;
      base += n;
    } while(r_n > 0);
    
    /* Dirty blocks have been written */
    stream->_flag &= ~_IODIRTYBLOCK;
  }
  
  /* Reset count and pointer */
  if((stream->_flag && (_IOREAD || _IOWRITE)) == (_IOREAD || _IOWRITE))
  {
    stream->_count = 0;
    stream->_ptr = stream->_base;
  }
  
  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// fopen function
FILE* fopen(const char* restrict filename, const char* restrict smode) {
  int fd;
  int mode;

  if(*smode != 'r' && *smode != 'w' && *smode != 'a')
    return NULL;

  if(*smode == 'w') {
    mode = _IOWRITE;
    fd = creat(filename, _DEFAULT_PERMISSIONS);
  }
  else if(*smode == 'a') {
    mode = _IOWRITE;
    if((fd = open(filename, O_WRONLY, 0)) == -1)
      fd = creat(filename, _DEFAULT_PERMISSIONS);
    lseek(fd, 0L, SEEK_END);
  }
  else {
    mode = _IOREAD;
    fd = open(filename, O_RDONLY, 0);
  }
  
  if(fd == -1)
    return NULL;

  FILE* stream = _sl_create_stream(fd, mode, filename);

  if(stream == NULL)
    return NULL;
  
  _sl_ll_add_of(__SL_OpenFiles, stream, FOPEN_MAX);
  
  return stream;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// freopen function
FILE* freopen(
    const char* restrict filename,
    const char* restrict mode,
    FILE* restrict stream
              ) {
  fclose(stream);

  return fopen(filename, mode);
}
//------------------------------------------------------------------------------

//-<EOF>

