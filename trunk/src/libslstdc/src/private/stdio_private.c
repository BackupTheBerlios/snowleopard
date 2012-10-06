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
// stdio_private.c
//------------------------------------------------------------------------------
// Standard input/output implementation (Private functions)
//------------------------------------------------------------------------------

#include <config/config.h>

#include <stdc/private/ll_open_files.h>
#include <stdc/private/program_globals.h>
#include <stdc/private/stdio_private.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// _sl_create_stream function
FILE* _SL_Hidden _sl_create_stream(int fd, int mode, const char* name) {
  FILE* stream = malloc(sizeof(FILE));

  if(stream == NULL)
    return NULL;
  
  stream->_file_descriptor = fd;
  stream->_flag = mode;

  char* ptr = malloc(sizeof(BUFSIZE));
  if(ptr == NULL) {
    free(stream);
    return NULL;
  }
  stream->_ptr = ptr;
  stream->_base = ptr;
  stream->_count = 0;
  stream->_buffersize = BUFSIZE;
  
  stream->_name = malloc(strlen(name));
  if(stream == NULL) {
    free(ptr);
    free(stream);
    return NULL;
  }
  strcpy(stream->_name, name);

  return stream;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _sl_destroy_stream function
void _SL_Hidden _sl_destroy_stream(FILE* stream) {
  if(stream->_base != NULL)
    free(stream->_base);

  if(stream->_name != NULL)
    free(stream->_name);

  _sl_ll_remove_of(__SL_OpenFiles, _sl_ll_find_of(__SL_OpenFiles, stream));
  
  free(stream);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _sl_apply_to_streams function
errno_t _SL_Hidden _sl_apply_to_streams(_sl_strfunc_t f) {
  int retval = EXIT_SUCCESS;
  
  sl_ll_of_node_* e = __SL_OpenFiles->first_;
  while(e != __SL_OpenFiles->last_) {
    if(e->node_ != NULL)
      if(f(e->node_) == EXIT_FAILURE)
        retval = (retval == 0 && errno > 0) ? errno : retval;
    e = e->next_;
  }
  
  return retval;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _sl_startup_initialize_standard_streams function
//
// This function initializes the standard input and output streams.
void _sl_startup_initialize_standard_streams() {
  /* Create the open files list */
  __SL_OpenFiles = _sl_ll_new_of();
  if(__SL_OpenFiles == NULL)
    abort();

  /* Add standard streams */
  FILE* stream = _sl_create_standard_stream(0, _IOREAD, "stdin");
  if(stream == NULL)
    abort();

  stdin = stream;
  _sl_ll_add_of(__SL_OpenFiles, stream, FOPEN_MAX);
  
  stream = _sl_create_standard_stream(1, _IOWRITE, "stdout");
  if(stream == NULL)
    abort();

  stdout = stream;
  _sl_ll_add_of(__SL_OpenFiles, stream, FOPEN_MAX);

  stream = _sl_create_standard_stream(2, _IOWRITE | _IOUNBUF, "stderr");
  if(stream == NULL)
    abort();

  stderr = stream;
  _sl_ll_add_of(__SL_OpenFiles, stream, FOPEN_MAX);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _sl_create_standard_stream function
//
// Creates a standard stream, based on the parameters supplied.
FILE* _sl_create_standard_stream(int fd, int mode, const char* name) {
  FILE* stream = malloc(sizeof(FILE));

  stream->_file_descriptor = fd;
  stream->_flag = mode;
  
  stream->_ptr = NULL;
  stream->_base = NULL;
  stream->_count = 0;

  stream->_name = malloc(strlen(name));
  strcpy(stream->_name, name);

  return stream;
}
//------------------------------------------------------------------------------

//-<EOF>

