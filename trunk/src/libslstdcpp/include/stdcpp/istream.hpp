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
// istream.hpp
//------------------------------------------------------------------------------
// Standard istream implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_ISTREAM_HPP__
#define __SL_STDCPP_ISTREAM_HPP__

#include <sl/config/config.hpp>

#include <sl/stdcpp/iosfwd.hpp>

namespace std {

//============================================================================
// basic_istream

  //----------------------------------------------------------------------------
  // basic_istream class template
  template <
    typename CharT, 
    typename Traits
  >
  class basic_istream
  {

  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // basic_istream typedefs
  typedef basic_istream<char> istream;
  typedef basic_istream<wchar_t> wistream;
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// basic_iostream

  //----------------------------------------------------------------------------
  // basic_iostream class template
  template <
    typename CharT, 
    typename Traits
  >
  class basic_iostream
  {

  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // basic_iostream typedefs
  typedef basic_iostream<char> iostream;
  typedef basic_iostream<wchar_t> wiostream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // ws object
  template <
    typename CharT, 
    typename Traits
  >
  basic_istream<CharT, Traits>& ws (basic_istream<CharT, Traits>& is);
  //----------------------------------------------------------------------------

//==============================================================================

} //std

#endif //__SL_STDCPP_ISTREAM_HPP__

//------------------------------------------------------------------------------
// Revision history
//
// 11/11/2008 Roel Sergeant   Initial
//------------------------------------------------------------------------------
