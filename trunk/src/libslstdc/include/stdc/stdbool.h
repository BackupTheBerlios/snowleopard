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
// stdbool.h
//------------------------------------------------------------------------------
// Standard boolean implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STDBOOL_H__
#define __SL_STDC_IMPL_STDBOOL_H__

#include "stdc/config_stdc.h"

//==============================================================================
// In C++ bool, true, false are keywords.
//
#ifndef __cplusplus

//------------------------------------------------------------------------------
// bool macro
//
typedef sl_boolean bool;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// true/false macros
//
#define true 1
#define false 0
//------------------------------------------------------------------------------

#endif /* !__cplusplus */
//==============================================================================

//------------------------------------------------------------------------------
// __bool_true_false_are_defined macro
//
#define __bool_true_false_are_defined 1
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_STDBOOL_H__ */

//-<EOF>
