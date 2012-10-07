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
// type_traits.hpp
//------------------------------------------------------------------------------
// Standard pointer traits implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_TYPE_TRAITS_HPP__
#define __SL_STDCPP_IMPL_TYPE_TRAITS_HPP__

#include <sl/config/config.hpp>

#include <sl/stdcpp/helpers/type_helpers.hpp>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // integral_constant class template
  template<class T, T v> struct integral_constant
    : public sl::helpers::sl_integral_constant<T, v> { };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Boolean constant types
  typedef integral_constant<bool, true> true_type;
  typedef integral_constant<bool, false> false_type;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // remove_const template
  template<class T> struct remove_const {
    typedef typename sl::helpers::sl_remove_const<T>::type type;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // remove_volatile template
  template<class T> struct remove_volatile {
    typedef typename sl::helpers::sl_remove_volatile<T>::type type;
  };
  //----------------------------------------------------------------------------


  //g----------------------------------------------------------------------------
  // remove_cv template
  template<class T> struct remove_cv {
    typedef typename sl::helpers::sl_remove_cv<T>::type type;
  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_TYPE_TRAITS_HPP__ */

//-<EOF>
