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
// stdio_private.h
//------------------------------------------------------------------------------
// Standard input/output implementation (Private functions)
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STDIO_PRIVATE_H__
#define __SL_STDC_IMPL_STDIO_PRIVATE_H__

#include <config/config.h>

#include <errno.h>
#include <stdio.h>

//------------------------------------------------------------------------------
// Buffer functions
char* _SL_Hidden _sl_create_buffer(FILE* stream);
int _SL_Hidden _sl_destroy_buffer(FILE* stream);
int _SL_Hidden _sl_fill_buffer(FILE* stream);
int _SL_Hidden _sl_flush_buffer(int n, FILE* stream);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Stream functions
FILE* _SL_Hidden _sl_create_stream(int fd, int mode, const char* name);
void _SL_Hidden _sl_destroy_stream(FILE* stream);
typedef int (*_sl_strfunc_t)(FILE* stream);
errno_t _SL_Hidden _sl_apply_to_streams(_sl_strfunc_t f);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialization functions
void _sl_startup_initialize_standard_streams();
FILE* _sl_create_standard_stream(int fd, int mode, const char* name);
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_STDIO_PRIVATE_H__ */

//-<EOF>

