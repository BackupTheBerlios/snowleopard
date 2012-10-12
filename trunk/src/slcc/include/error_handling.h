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
// error_handling.h
//------------------------------------------------------------------------------
// Error handling for the compiler front end.
//------------------------------------------------------------------------------

#ifndef __SL_SLCC_ERROR_HANDLING_H__
#define __SL_SLCC_ERROR_HANDLING_H__

#include "error.h"
#include "error_codes.h"
#include "error_array.h"

//------------------------------------------------------------------------------
// error_list array
//
// Error list for storing all errors occured during the compilation process.
//
extern slcc_error_array* error_list_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error handling functions.
slcc_error* err_report_0 (slcc_error_code code);
slcc_error* err_report_1 (slcc_error_code code, char* arg1);
slcc_error* err_report_2 (slcc_error_code code, char* arg1, char* arg2);
void err_report_and_exit_0 (slcc_error_code code);
void err_report_and_exit_1 (slcc_error_code code, char* arg1);
void err_report_and_exit_2 (slcc_error_code code, char* arg1, char* arg2);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_ERROR_HANDING_H__ */

//-<EOF>
