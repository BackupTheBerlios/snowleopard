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
// pointer_traits.hpp
//------------------------------------------------------------------------------
// Standard pointer traits implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_POINTER_TRAITS_HPP__
#define __SL_STDCPP_IMPL_POINTER_TRAITS_HPP__

//------------------------------------------------------------------------------
// This header should not be included by itself.
#ifndef __SL_STDCPP_IMPL_MEMORY_HPP__

# error "The header pointer_traits.hpp should not be included directly"

#else /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */

#include <sl/config/config.hpp>

#include <sl/config/macros.hpp>

#include <sl/stdcpp/helpers/pointer_helpers.hpp>

#include <cstddef>
#include <type_traits>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // Forward declarations
  template<class T> T* addressof(T& r) noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // pointer_traits class template
  template<class Pointer> class pointer_traits 
    : public sl::helpers::sl_pointer_to<Pointer> {
  public:
    typedef Pointer pointer;

  private:
    sl_use_type_or_alt(Pointer,element_type,void)
    sl_use_type_or_alt(Pointer,difference_type,ptrdiff_t)

  public:
    typedef sl_element_type element_type;
    typedef sl_difference_type difference_type;

    template<class U> struct rebind {
      typedef typename sl::helpers::sl_ptr_rebind<Pointer, U>::type other;
    };

  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // pointer_traits partial specialization
  template<class T> class pointer_traits<T*> {
  public:
    typedef T* pointer;
    typedef T element_type;
    typedef ptrdiff_t difference_type;

    template<class U> struct rebind {
      typedef U* other;
    };

    static pointer pointer_to(
			      typename sl::helpers::sl_ptr_non_void<
				element_type
				>::type& r
			      ) noexcept {
      return std::addressof(r);
    }
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // pointer_safety enum
  enum class pointer_safety {
    relaxed,
      preferred,
      strict
      };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */
//------------------------------------------------------------------------------

#endif /* !__SL_STDCPP_IMPL_POINTER_TRAITS_HPP__ */

//-<EOF>
