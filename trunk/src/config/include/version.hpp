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
// version.hpp
//------------------------------------------------------------------------------
// Global version information.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_VERSION_HPP__
#define __SL_CONFIG_VERSION_HPP__

#include sl_include_config(config.hpp)

//==============================================================================
namespace sl {

//==============================================================================
namespace config {

using std::size_t;

#include sl_include_config(version.h)

} /* sl::config */
//==============================================================================

} /* sl */
//==============================================================================

#endif /* !__SL_CONFIG_VERSION_HPP__ */

//-<EOF>

