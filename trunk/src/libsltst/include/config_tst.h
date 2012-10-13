/*==============================================================================
  Snow Leopard Test Library
  
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
// config_tst.h
//------------------------------------------------------------------------------
// Configuration information for the test library
//------------------------------------------------------------------------------

#ifndef __SL_TST_CONFIG_TST_H__
#define __SL_TST_CONFIG_TST_H__

#ifdef __SL_TST_NO_SL_STDLIB
#define __SL_NO_SL_STDLIB
#endif /* __SL_TST_NO_SL_STDLIB */

#ifdef __SL_INSTALLED
# include "sl/config/macros.h"
#else /* __SL_INSTALLED */
# include "macros.h"
#endif /* __SL_INSTALLED */

#include sl_include_config(config.h)
#include sl_include_config(os_fixinclude.h)

#endif /* !__SL_TST_CONFIG_TST_H__ */

//-<EOF>
