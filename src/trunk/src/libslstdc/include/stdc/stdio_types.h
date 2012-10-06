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
// stdio_types.h
//------------------------------------------------------------------------------
// Standard input/output implementation: types
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STDIO_TYPES_H__
#define __SL_STDC_IMPL_STDIO_TYPES_H__

#include <config/config.h>

#include <stddef.h>

//------------------------------------------------------------------------------
// FILE struct
struct FILE {
  int _file_descriptor;
  int _flag;
  
  char* _ptr;
  char* _base;
  size_t _count;
  size_t _buffersize;
  
  char* _name;
};

typedef struct FILE FILE;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// fpos_t struct
struct fpos_t {
  __SL_ConfigNamespace sl_file_position_t _pos;
};

typedef struct fpos_t fpos_t;
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_STDIO_TYPES_H__ */

//-<EOF>
