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
// error.h
//------------------------------------------------------------------------------
// Error structure for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_ERROR_H__
#define __SL_SLCC_ERROR_H__

#include "error_codes.h"

//------------------------------------------------------------------------------
// slcc_error structure
//
// Structure for storing a single error, not used for fatal errors, as those 
// result in immediate abortion.
//
struct slcc_error
{
  slcc_error_code code;
  char* arg1;
  char* arg2;
};

typedef struct slcc_error slcc_error;
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_ERROR_H__ */

//-<EOF>
