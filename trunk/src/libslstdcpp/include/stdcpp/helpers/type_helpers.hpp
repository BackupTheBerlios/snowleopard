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
// type_helpers.hpp
//------------------------------------------------------------------------------
// pointer helper templates
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_HELPERS_TYPE_HELPERS_HPP__
#define __SL_STDCPP_HELPERS_TYPE_HELPERS_HPP__

//==============================================================================
namespace sl {

  //============================================================================
  namespace helpers {

    //--------------------------------------------------------------------------
    // integral_constant class template
    template<class T, T v> struct sl_integral_constant {
      static constexpr T value = v;

      typedef T value_type;
      typedef sl_integral_constant<T, v> type;

      constexpr operator value_type() {
	return value;
      }
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_has_nested_type macro
#   define sl_has_nested_type(TYPE)					\
    template<class T> class sl_has_##TYPE##_helper			\
      : private sl_sfinae_types {					\
    private:								\
      template<class U> struct sl_wrap_type { };			\
									\
      template<class U>							\
	static one __sl_check(sl_wrap_type<typename U::TYPE>*);		\
									\
      template<class U> static two __sl_check(...);			\
									\
    public:								\
      static constexpr bool value = sizeof(__sl_check<T>(0)) == 1;	\
    };									\
    									\
    template<typename T> struct sl_has_##TYPE				\
      : sl_integral_constant<						\
          bool,                                                         \
          sl_has_##TYPE##_helper<                                       \
	    typename sl_remove_cv<T>::type                              \
            >::value> { };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_finae_types struct
    struct sl_sfinae_types {
      typedef char one;
      typedef struct { char arr[2]; } two;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_remove_const template
    template<class T> struct sl_remove_const {
      typedef T type;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_remove_const partial specialization
    template<class T> struct sl_remove_const<const T> {
      typedef T type;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_remove_volatile template
    template<class T> struct sl_remove_volatile {
      typedef T type;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_remove_volatile partial specialization
    template<class T> struct sl_remove_volatile<volatile T> {
      typedef T type;
    };
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // sl_remove_cv template
    template<class T> struct sl_remove_cv {
      typedef typename sl_remove_const<
	typename sl_remove_volatile<T>::type
	>::type type;
    };
    //--------------------------------------------------------------------------

  } /* sl::helpers */
  //============================================================================

} /* sl */
//==============================================================================

#endif /* !__SL_STDCPP_HELPERS_TYPE_HELPERS_HPP__ */

//-<EOF>
