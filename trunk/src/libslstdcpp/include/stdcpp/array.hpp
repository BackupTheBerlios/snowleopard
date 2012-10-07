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
// array.hpp
//------------------------------------------------------------------------------
// array template class
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_ARRAY_HPP__
#define __SL_STDCPP_IMPL_ARRAY_HPP__

#include <sl/config/config.hpp>

#include <cstddef>
#include <initializer_list>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // array template class
  template<typename T, size_t N> struct array {
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef pointer iterator;
    typedef const_pointer const_iterator;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef reverse_iterator<iterator> reverse_iterator;
    typedef reverse_iterator<const_iterator> const_reverse_iterator;

    T elems[N];

    void fill(const T& u);
    void swap(array&) noexcept(noexcept(swap(declval<T&>(), declval<T&>())));

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;

    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;

    constexpr size_type size() noexcept;
    constexpr size_type max_size() noexcept;
    constexpr bool empty() noexcept;

    reference operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference at(size_type);
    const_reference at(size_type n) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    T* data() noexcept;
    const T* data() const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Comparison operators
  template<typename T, size_t N>
  bool operator==(const array<T, N>& x, const array<T, N>& y);
  template<typename T, size_t N>
  bool operator!=(const array<T, N>& x, const array<T, N>& y);
  template<typename T, size_t N>
  bool operator<(const array<T, N>& x, const array<T, N>& y);
  template<typename T, size_t N>
  bool operator>(const array<T, N>& x, const array<T, N>& y);
  template<typename T, size_t N>
  bool operator<=(const array<T, N>& x, const array<T, N>& y);
  template<typename T, size_t N>
  bool operator>=(const array<T, N>& x, const array<T, N>& y);
  //----------------------------------------------------------------------------
   
  //----------------------------------------------------------------------------
  // swap template function
  template<typename T, size_t N>
  void swap(array<T, N>& x, array<T, N>& y) noexcept(noexcept(x.swap(y)));
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // tuple_size/tuple_element template classes
  template<typename T> class tuple_size;
  template<size_t I, typename T> class tuple_element;
  template<typename T, size_t N> struct tuple_size<array<T, N>>;
  template<size_t I, typename T, size_t N> struct tuple_element<I, array<T, N>>;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // get functions
  template<size_t I, typename T, size_t N> T& get(array<T, N>&) noexcept;
  template<size_t I, typename T, size_t N> T&& get(array<T, N>&&) noexcept;
  template<size_t I, typename T, size_t N> 
  const T& get(const array<T, N>&) noexcept;
  //----------------------------------------------------------------------------

} //std
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifndef __SL_COMPILER_USE_EXPORT__
# include <sl/stdcpp/detail/array.ipp>
#endif /* !__SL_COMPILER_USE_EXPORT__ */
////////////////////////////////////////////////////////////////////////////////

#endif //__SL_STDCPP_IMPL_ARRAY_HPP__

//-<EOF>
