/*==============================================================================
  Snow Leopard C++ Tools
  
  Copyright (C) 2008-2012 Roel Sergeant
  
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
// ios.hpp
//------------------------------------------------------------------------------
// Standard ios implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IOS_HPP__
#define __SL_STDCPP_IOS_HPP__

#include <sl/config/config.hpp>

#include <sl/stdcpp/iosfwd.hpp>

//------------------------------------------------------------------------------
// Components of this header
#include <sl/stdcpp/stream_types.hpp>
#include <sl/stdcpp/fpos.hpp>
#include <sl/stdcpp/ios_base.hpp>
#include <sl/stdcpp/basic_ios.hpp>
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifdef SL_COMPILER_USE_NO_EXPORT
#  include <sl/stdcpp/detail/fpos.ipp>
#  include <sl/stdcpp/detail/ios_base.ipp>
#  include <sl/stdcpp/detail/basic_ios.ipp>
#  include <sl/stdcpp/detail/ios_manipulators.ipp>
#  include <sl/stdcpp/detail/ios_fields.ipp>
#endif //SL_COMPILER_USE_NO_EXPORT
////////////////////////////////////////////////////////////////////////////////

#endif //__SL_STDCPP_IOS_HPP__

//------------------------------------------------------------------------------
// Revision history
//
// 29/12/2008 Roel Sergeant   Initial
//------------------------------------------------------------------------------
