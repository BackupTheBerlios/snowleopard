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
// utility.hpp
//------------------------------------------------------------------------------
// Standard utility implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_UTILITY_HPP__
#define __SL_STDCPP_IMPL_UTILITY_HPP__

#include <sl/config/config.hpp>

#include <sl/stdcpp/helpers/meta_functions.hpp>

#include <initializer_list>

namespace std {

  //----------------------------------------------------------------------------
  // relational_operators
  namespace rel_ops {

    template<typename T>
    bool operator!=(const T&, const T&);

    template<typename T>
    bool operator>(const T&, const T&);

    template<typename T> 
    bool operator<=(const T&, const T&);

    template<typename T> 
    bool operator>=(const T&, const T&);

  }
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // swap functions
  template<class T> void swap(T& a, T& b) 
    nothrow(
	    sl_and<
	    is_nothrow_move_constructible<T>,
	    is_nothrow_move_assignable<T>
	    >::value
    );
  template<class T> 
  void swap(T (&a)[N], T (&b)[N]) noexcept(noexcept(swap(*a, *b)));
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // forward/move functions
  template<class T> T&& forward(typename remove_reference<T>::type& t) noexcept;
  template<class T> T&& forward(
				typename remove_reference<T>::type&& t
				) noexcept;
  template<class T> typename remove_reference<T>::type&& move(T&&) noexcept;
  template<class T> typename conditional<
    !is_nothrow_move_constructible<T>::value
    && is_copy_constructible<T>::value, 
    const T&, 
    T&&
    >::type move_if_noexcept(T& x) noexcept;
  //----------------------------------------------------------------------------
		       
  //----------------------------------------------------------------------------
  // declval function
  template<class T> typename add_rvalue_reference<T>::type declval() noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // pair class template
  template<class T1, class T2> struct pair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair(const pair&) = default;
    pair(pair&&) = default;
    constexpr pair();
    pair(const T1& x, const T2& y);
    template<class U, class V> pair(U&& x, V&& y);
    template<class U, class V> pair(const pair<U, V>& p);
    template<class U, class V> pair(pair<U, V>&& p);
    template<class ... Args1, class ... Args2> pair(
						    piecewise_construct_t,
						    tuple<Args1 ...> first_args,
						    tuple<Args2 ...> second_args
						    );

    pair& operator=(const pair& p);
    template<class U, class V> pair& operator=(const pair<U, V>& p);
    pair& operator=(pair&& p) noexcept(
				       sl_and<
				       is_nothrow_move_constructible<T>,
				       is_nothrow_move_assignable<T>
				       >::value
      );
    template<class U, class V> pair& operator=(pair<U, V>&& p);

    void swap(pair& p) noexcept(
				sl_and<
				noexcept(swap(first, p.first)),
				noexcept(swap(second, p.second))
				>::value
				);
  };
  //---------------------------------------------------------------------------- 

  //----------------------------------------------------------------------------
  // pair specialized algorithms
  template<class T1, class T2>
  bool operator==(const pair<T1, T2>&, const pair<T1, T2>&);
  template<class T1, class T2>
  bool operator<(const pair<T1, T2>&, const pair<T1, T2>&);
  template<class T1, class T2>
  bool operator!=(const pair<T1, T2>&, const pair<T1, T2>&);
  template<class T1, class T2>
  bool operator>(const pair<T1, T2>&, const pair<T1, T2>&);
  template<class T1, class T2>
  bool operator>=(const pair<T1, T2>&, const pair<T1, T2>&);
  template<class T1, class T2>
  bool operator<=(const pair<T1, T2>&, const pair<T1, T2>&);
  template<class T1, class T2>
  void swap(pair<T1, T2>& x, pair<T1, T2>& y) noexcept(noexcept(x.swap(y)));
  template<class T1, class T2>
  pair<V1, V2>(std::forward<T1>(x), std::forward<T2>(y)) make_pair(T1&&, T2&&);
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // tuple-like access to a pair
  template<class T> class tuple_size;
  template<size_t I, class T> class tuple_element;

  template<class T1, class T2> struct tuple_size<std::pair<T1, T2>>;
  template<class T1, class T2> struct tuple_element<0, std::pair<T1, T2>>;
  template<class T1, class T2> struct tuple_element<1, std::pair<T1, T2>>;
  //----------------------------------------------------------------------------

} /* std */

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifdef SL_COMPILER_USE_NO_EXPORT
#  include <sl/stdcpp/detail/rel_ops.ipp>
#  include <sl/stdcpp/detail/forward_move.ipp>
#  include <sl/stdcpp/detail/pair.ipp>
#endif //SL_COMPILER_USE_NO_EXPORT
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_STDCPP_IMPL_UTILITY_HPP__ */

//-<EOF>

