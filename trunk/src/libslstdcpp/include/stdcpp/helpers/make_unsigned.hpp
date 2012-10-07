/*==============================================================================
  Snow Leopard Standard C++ Library
  
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
// make_unsigned.hpp
//------------------------------------------------------------------------------
// make_unsigned class template
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_HELPERS_MAKE_UNSIGNED_HPP__
#define __SL_STDCPP_HELPERS_MAKE_UNSIGNED_HPP__

//==============================================================================
namespace sl {

  //============================================================================
  namespace helpers {

    //--------------------------------------------------------------------------
    // make_unsigned class template
    template<class T> struct sl_make_unsigned {
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // make_unsigned specializations
    template<> struct sl_make_unsigned<int> {
      typedef unsigned int type;
    };

    template<> struct sl_make_unsigned<const int> {
      typedef const unsigned int type;
    };

    template<> struct sl_make_unsigned<long> {
      typedef unsigned long type;
    };

    template<> struct sl_make_unsigned<const long> {
      typedef const unsigned long type;
    };

    template<> struct sl_make_unsigned<long long> {
      typedef unsigned long long type;
    };

    template<> struct sl_make_unsigned<const long long> {
      typedef const unsigned long long type;
    };
    //--------------------------------------------------------------------------

  } /* sl::helpers */
  //============================================================================

} /* sl */
//==============================================================================

#endif /* !__SL_STDCPP_HELPERS_MAKE_UNSIGNED_HPP__ */

//-<EOF>
