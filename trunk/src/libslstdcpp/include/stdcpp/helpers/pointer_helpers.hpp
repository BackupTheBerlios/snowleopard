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
// pointer_helpers.hpp
//------------------------------------------------------------------------------
// pointer helper templates
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_HELPERS_POINTER_HELPERS_HPP__
#define __SL_STDCPP_HELPERS_POINTER_HELPERS_HPP__

#include <sl/stdcpp/helpers/type_helpers.hpp>

#include <cstddef>

//==============================================================================
namespace sl {

  //============================================================================
  namespace helpers {

    //--------------------------------------------------------------------------
    // Generate sl_has_element_type
    sl_has_nested_type(element_type)
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_ptr_element_type class template
    template<class T, bool = sl_has_element_type<T>::value> 
    struct sl_ptr_element_type;
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_ptr_element_type specializations
    template<class T> struct sl_ptr_element_type<T, true> {
      typedef typename T::element_type type;
    };

    template<
      template<class, class ...> class Pointer, 
      class T,
      class ... Args
      >
    struct sl_ptr_element_type<Pointer<T, Args ...>, false> {
      typedef T type;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_ptr_non_void template
    template<class T, class = typename sl_remove_cv<T>::type> 
    struct sl_ptr_non_void {
      typedef T type;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_ptr_non_void specialization
    template<class T> 
    struct sl_ptr_non_void<T, void> {
      struct type { };
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_ptr_rebind_helper class template
    template<class Pointer, class U>
    class sl_ptr_rebind_helper {
    private:
      template<class Pointer2, class U2>
      static constexpr bool __sl_check(
				       typename Pointer2::template rebind<U2>*
				       ) { 
	return true; 
      }
      
      template<class, class>
      static constexpr bool __sl_check(...) { 
	return false; 
      }
      
    public:
      static const bool value = __sl_check<Pointer, U>(nullptr);
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_ptr_rebind class template
    template<class T, class U, bool = sl_ptr_rebind_helper<T, U>::value>
    struct sl_ptr_rebind;
    //--------------------------------------------------------------------------
   
    //--------------------------------------------------------------------------
    // sl_ptr_rebind specializations
    template<class T, class U>
    struct sl_ptr_rebind<T, U, true> {
      typedef typename T::template rebind<U> type;
    };

    template<
      template<class, class ...> class Pointer, 
      class U,
      class T, 
      class ... Args
      > 
    struct sl_ptr_rebind<Pointer<T, Args ...>, U, false> {
      typedef Pointer<U, Args ...> type;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_pointer_to class template
    template<class Pointer>
    class sl_pointer_to {
    private:
      typedef typename sl_ptr_element_type<Pointer>::type original_type;
      typedef typename sl_ptr_non_void<original_type>::type element_type;
    
    public:
      static element_type* pointer_to(element_type& e) { 
	return Pointer::pointer_to(e); 
      }
    };
    //--------------------------------------------------------------------------

  } /* sl::helpers */
  //============================================================================

} /* sl */
//==============================================================================

#endif /* !__SL_STDCPP_HELPERS_POINTER_HELPERS_HPP__ */

//-<EOF>
