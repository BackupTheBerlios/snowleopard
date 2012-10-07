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
// ios_base.hpp
//------------------------------------------------------------------------------
// ios_base class, manipulators, adjustfield, basefield, floatfield
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IOS_BASE_HPP__
#define __SL_STDCPP_IOS_BASE_HPP__

#include <sl/config/config.hpp>

#include <sl/stdcpp/iosfwd.hpp>

namespace std {

  //----------------------------------------------------------------------------
  // ios_base class
  class ios_base
  {

  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // manipulators
  ios_base& boolalpha (ios_base& stream);
  ios_base& noboolalpha (ios_base& stream);

  ios_base& showbase (ios_base& stream);
  ios_base& noshowbase (ios_base& stream);

  ios_base& showpoint (ios_base& stream);
  ios_base& noshowpoint (ios_base& stream);

  ios_base& showpos (ios_base& stream);
  ios_base& noshowpos (ios_base& stream);

  ios_base& skipws (ios_base& stream);
  ios_base& noskipws (ios_base& stream);

  ios_base& uppercase (ios_base& stream);
  ios_base& nouppercase (ios_base& stream);

  ios_base& unitbuf (ios_base& stream);
  ios_base& nounitbuf (ios_base& stream);
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // adjustfield
  ios_base& internal (ios_base& stream);
  ios_base& left (ios_base& stream);
  ios_base& right (ios_base& stream);
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // basefield
  ios_base& dec (ios_base& stream);
  ios_base& hex (ios_base& stream);
  ios_base& oct (ios_base& stream);
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // floatfield
  ios_base& fixed (ios_base& stream);
  ios_base& scientific (ios_base& stream);
  ios_base& hexfloat (ios_base& stream);
  ios_base& defaultfloat (ios_base& stream);
  //----------------------------------------------------------------------------

} //std

#endif //__SL_STDCPP_IOS_BASE_HPP__

//------------------------------------------------------------------------------
// Revision history
//
// 29/12/2008 Roel Sergeant   Initial
//------------------------------------------------------------------------------
