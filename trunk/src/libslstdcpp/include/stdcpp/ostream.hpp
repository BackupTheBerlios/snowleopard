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
// ostream.hpp
//------------------------------------------------------------------------------
// Standard ostream implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_OSTREAM_HPP__
#define __SL_STDCPP_OSTREAM_HPP__

#include <sl/config/config.hpp>

#include <sl/stdcpp/iosfwd.hpp>
#include <sl/stdcpp/ios.hpp>

namespace std {

//==============================================================================
// basic_ostream

  //----------------------------------------------------------------------------
  // basic_ostream class template
  template < 
    typename CharT,
    typename Traits
  >
  class basic_ostream
    : virtual public basic_ios<CharT, Traits>
  {
  public:
    // Constructor
    explicit basic_ostream (basic_streambuf<CharT, Traits>* sb);

    // Copy Constructor
    basic_ostream (basic_ostream& rhs);

    // Destructor
    virtual ~basic_ostream ();

    // Assignment
    basic_ostream& operator= (basic_ostream& rhs);

    // Swap
    void swap (basic_ostream& rhs);

  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // basic_ostream typedefs
  typedef basic_ostream<char> ostream;
  typedef basic_ostream<wchar_t> wostream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // endl object
  template <
    typename CharT,
    typename Traits
  >
  basic_ostream<CharT, Traits>& endl (basic_ostream<CharT, Traits>& os);
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // ends object
  template <
    typename CharT,
    typename Traits
  >
  basic_ostream<CharT, Traits>& ends (basic_ostream<CharT, Traits>& os);
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // flush object
  template <
    typename CharT, 
    typename Traits
  >
  basic_ostream<CharT, Traits>& flush (basic_ostream<CharT, Traits>& os);
  //----------------------------------------------------------------------------

//==============================================================================

} //std

#endif //__SL_STDCPP_OSTREAM_HPP__

//------------------------------------------------------------------------------
// Revision history
//
// 11/11/2008 Roel Sergeant   Initial
//------------------------------------------------------------------------------
