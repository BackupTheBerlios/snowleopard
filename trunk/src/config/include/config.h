/*==============================================================================
  Snow Leopard Compiler Project
  
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
// config.h
//------------------------------------------------------------------------------
// Configuration applicable to all code in the project.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_H__
#define __SL_CONFIG_CONFIG_H__

#include <macros.h>

//==============================================================================
// Include correct config file depending on the language compiled.
#ifdef __cplusplus
//------------------------------------------------------------------------------
// C++
# define __SL_ConfigNamespace sl::config::
# include sl_include_config(config_cpp.hpp)
//------------------------------------------------------------------------------
#else /* __cplusplus */
//------------------------------------------------------------------------------
// C
# define __SL_ConfigNamespace
# include sl_include_config(config_c.h)
//------------------------------------------------------------------------------
#endif /* __cplusplus */
//==============================================================================

#endif /* !__SL_CONFIG_CONFIG_H__ */

//-<EOF>
