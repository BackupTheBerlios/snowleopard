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
// initializer_list.hpp
//------------------------------------------------------------------------------
// Standard initializer list implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_INITIALIZER_LIST_HPP__
#define __SL_STDCPP_IMPL_INITIALIZER_LIST_HPP__

#include <sl/config/config.hpp>

#include <cstddef>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // initializer_list class template
  template<class E> class initializer_list {
  public:
    typedef E value_type;
    typedef const E& reference;
    typedef const E& const_reference;
    typedef size_t size_type;
    typedef const E* iterator;
    typedef const E* const_iterator;

    initializer_list() noexcept;

    size_t size() const noexcept;
    const E* begin() const noexcept;
    const E* end() const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // begin/end function
  template<class E> const E* begin(initializer_list<E> il) noexcept;
  template<class E> const E* end(initializer_list<E> il) noexcept;
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifndef __SL_COMPILER_USE_EXPORT__
# include <sl/stdcpp/implementation/initializer_list.ipp>
#endif /* !__SL_COMPILER_USE_EXPORT__ */
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_STDCPP_IMPL_INITIALIZER_LIST_HPP__ */

//-<EOF>
