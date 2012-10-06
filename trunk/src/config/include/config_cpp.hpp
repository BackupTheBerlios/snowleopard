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
// config_cpp.hpp
//------------------------------------------------------------------------------
// Configuration applicable to all C++ code.
//    - slcc
//    - sltst
//    - slbld
//    - libsltst
//    - libslstdcpp
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_CPP_HPP__
#define __SL_CONFIG_CONFIG_CPP_HPP__

//------------------------------------------------------------------------------
// C++ doesn't have certain C11 keywords
#define restrict
#define _Noreturn __attribute__((noreturn))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// State type
#define __SL_StateT mbstate_t
//------------------------------------------------------------------------------

//==============================================================================
namespace sl {

//==============================================================================
namespace config {

//------------------------------------------------------------------------------
// Snow Leopard C configuration header
#include sl_include_config(config_c.h)
//------------------------------------------------------------------------------

} /* sl::config */
//==============================================================================

} /* sl */
//==============================================================================

#endif /* !__SL_CONFIG_CONFIG_CPP_HPP__ */

//-<EOF>

