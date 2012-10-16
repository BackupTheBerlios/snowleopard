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

#include <stdbool.h>

#include "error.h"
#include "error_array.h"
#include "error_codes.h"
#include "source_position.h"

//------------------------------------------------------------------------------
// error_list array
//
// Error list for storing all errors occured during the compilation process.
//
extern slcc_error_array* error_list_;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// err_report_# macros
//
// Report error with # arguments and store it if it is not a warning.
//
#define err_report_0(code)			\
  err_report (code, NULL, NULL, NULL, true)
#define err_report_1(code,arg1)			\
  err_report (code, arg1, NULL, NULL, true)
#define err_report_2(code,arg1,arg2)		\
  err_report (code, arg1, arg2, NULL, true)
#define err_report_3(code,arg1,arg2,arg3)	\
  err_report (code, arg1, arg2, arg3, true)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// err_report_and_exit_# macros
//
// Report error with # arguments and exit.
//
#define err_report_and_exit_0(code)			\
  err_report_and_exit (code, NULL, NULL, NULL)
#define err_report_and_exit_1(code,arg1)		\
  err_report_and_exit (code, arg1, NULL, NULL)
#define err_report_and_exit_2(code,arg1,arg2)		\
  err_report_and_exit (code, arg1, arg2, NULL)
#define err_report_and_exit_3(code,arg1,arg2,arg3)	\
  err_report_and_exit (code, arg1, arg2, arg3)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// src_err_report_# macros
// 
// Report source code errors with # arguments.
//
#define src_err_report_0(code,pos)		        \
  src_err_report (code, pos, NULL, NULL, NULL)
#define src_err_report_1(code,pos,arg1)                 \
  src_err_report (code, pos, arg1, NULL, NULL)
#define src_err_report_2(code,pos,arg1,arg2)		\
  src_err_report (code, pos, arg1, arg2, NULL)
#define src_err_report_3(code,pos,arg1,arg2,arg3)       \
  src_err_report (code, pos, arg1, arg2, arg3)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error handling functions.
//
bool err_initialize ();
void err_cleanup ();
slcc_error* err_report (
			slcc_error_code code, 
			char* arg1, 
			char* arg2, 
			char* arg3, 
			bool store
			);
void err_report_and_exit (
			  slcc_error_code code, 
			  char* arg1,
			  char* arg2,
			  char* arg3
			  );
slcc_error* src_err_report (
			    slcc_error_code code,
			    slcc_source_position pos,
			    char* arg1,
			    char* arg2,
			    char* arg3
			    );
slcc_error_code err_get_code_of_first_fatal_error ();
slcc_error* err_get_first_error_of_type (slcc_error_type type);
//------------------------------------------------------------------------------

#endif /* !__SL_SLCC_ERROR_HANDING_H__ */

//-<EOF>
