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
// vector.hpp
//------------------------------------------------------------------------------
// Standard vector implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_VECTOR_HPP__
#define __SL_STDCPP_IMPL_VECTOR_HPP__

#include <sl/config/config.hpp>

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <memory>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // vector class template
  template<class T, class Allocator = allocator<T>> class vector {
  public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef size_t size_type;
    typedef diff_t difference_type;
    typedef Allocator allocator_type;
    typedef typename allocator_traits<Allocator>::pointer pointer;
    typedef typename allocator_traits<Allocator>::const_pointer const_pointer;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    explicit vector(const Allocator& = Allocator());
    explicit vector(size_type n);
    vector(size_type n, const T& value, const Allocator& = Allocator());
    template<class InputIterator>
    vector(
	   InputIterator first, 
	   InputIterator last, 
	   const Allocator& = Allocator()
	   );
    vector(const vector& x);
    vector(vector&&);
    vector(const vector&, const Allocator&);
    vector(vector&&, const Allocator&);
    vector(initializer_list<T>, const Allocator& = Allocator());

    ~vector();
  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_VECTOR_HPP__ */

//-<EOF>
