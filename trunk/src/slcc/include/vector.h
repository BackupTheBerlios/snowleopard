/*==============================================================================
  Snow Leopard C Source Component Library
  
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
// vector.h
//------------------------------------------------------------------------------
// Vector for the compiler front end.
//
// <TODO: Make vector strongly typed>
//------------------------------------------------------------------------------

#ifndef __SL_LSLC_VECTOR_H__
#define __SL_LSLC_VECTOR_H__

#include <stddef.h>

//------------------------------------------------------------------------------
// Global constant
extern size_t LSLCVectorInitialSize;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lslc_vector structure
//
struct lslc_vector
{
  size_t reserved;
  size_t used;
  void** data;
};

typedef struct lslc_vector lslc_vector;
//------------------------------------------------------------------------------

#endif /* !__SL_LSLC_VECTOR_H__ */

//-<EOF>
