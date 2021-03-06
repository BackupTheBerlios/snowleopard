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
// program_globals.h
//------------------------------------------------------------------------------
// Private global program variables
//------------------------------------------------------------------------------

#ifndef __SL_STDC_PRIVATE_GLOBALS_H__
#define __SL_STDC_PRIVATE_GLOBALS_H__

#include "stdc/config_stdc.h"

#include "stdc/stdio_types.h"

#include "stdc/private/ll_open_files.h"

//------------------------------------------------------------------------------
// Global variables
//
extern sl_ll_of_head_* _SL_Hidden __SL_OpenFiles;
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_PRIVATE_GLOBALS_H__ */

//-<EOF>
