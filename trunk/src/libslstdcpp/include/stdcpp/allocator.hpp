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
// allocator.hpp
//------------------------------------------------------------------------------
// Standard memory allocator implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_ALLOCATOR_HPP__
#define __SL_STDCPP_IMPL_ALLOCATOR_HPP__

//------------------------------------------------------------------------------
// This header should not be included by itself.
#ifndef __SL_STDCPP_IMPL_MEMORY_HPP__

# error "The header allocator.hpp should not be included directly"

#else /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */

#include <sl/config/config.hpp>

#include <sl/config/macros.hpp>

#include <sl/stdcpp/helpers/make_unsigned.hpp>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // allocator_traits struct
  template<typename Allocator> class allocator_traits {
  public:
    typedef Allocator allocator_type;

    typedef typename Allocator::value_type value_type;

  private:
    sl_use_type_or_alt(Allocator,pointer,value_type*)

  public:
    typedef sl_pointer pointer;

  private:
    sl_use_type_or_alt(Allocator,const_pointer,				\
		       typename pointer_traits<pointer>::		\
		       template rebind<const value_type>)
    sl_use_type_or_alt(Allocator,void_pointer,			        \
		       typename pointer_traits<pointer>::		\
		       template rebind<void>)
    sl_use_type_or_alt(Allocator,const_void_pointer,			\
		       typename pointer_traits<pointer>::		\
		       template rebind<const void>)
    sl_use_type_or_alt(Allocator,difference_type,			\
		       typename pointer_traits<pointer>::difference_type)

  public:
    typedef sl_const_pointer const_pointer;
    typedef sl_void_pointer void_pointer;
    typedef sl_const_void_pointer const_void_pointer;

    typedef sl_difference_type difference_type;

  private:
    sl_use_type_or_alt(Allocator,size_type,				\
		       typename						\
		       sl::helpers::sl_make_unsigned<difference_type>::type)

  public:
    typedef sl_size_type size_type;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // allocator class
  template<typename T> class allocator {
  public:
    typedef T value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */
//------------------------------------------------------------------------------

#endif /* !__SL_STDCPP_IMPL_ALLOCATOR_HPP__ */

//-<EOF>
