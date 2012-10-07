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
// iterator.hpp
//------------------------------------------------------------------------------
// Standard iterator implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_ITERATOR_HPP__
#define __SL_STDCPP_IMPL_ITERATOR_HPP__

#include <sl/config/config.hpp>

#include <cstddef>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // Iterator tags
  struct input_iterator_tag { };
  struct output_itertor_tag { };
  struct forward_iterator_tag : public input_iterator_tag { };
  struct bidirectional_iterator_tag : public forward_iterator_tag { };
  struct random_access_iterator_tag : public bidirectional_iterator_tag { };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // iterator_traits class template
  template<class Iterator> struct iterator_traits {
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // iterator_traits partial template specialization
  //
  // for pointers
  template<class T> struct iterator_traits<T*> {
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
  };
  // for const pointers
  template<class T> struct iterator_traits<const T*> {
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef random_access_iterator_tag iterator_category;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // iterator class template
  template<
    class Category, 
    class T,
    class Distance = ptrdiff_t,
    class Pointer = T*,
    class Reference = T&
    >
  struct iterator {
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
    typedef Category iterator_category;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Iterator operations
  template<class InputIterator, class Distance>
  void advance(InputIterator& i, Distance n);

  template<class InputIterator>
  typename iterator_traits<InputIterator>::difference_type
  distance(InputIterator first, InputIterator last);

  template<class ForwardIterator>
  ForwardIterator 
  next(
       ForwardIterator x,
       typename iterator_traits<ForwardIterator>::difference_type n = 1
       );

  template<class BidirectionalIterator>
  BidirectionalIterator
  prev(
       BidirectionalIterator x,
       typename iterator_traits<BidirectionalIterator>::difference_type n = 1
       );
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // reverse_iterator class template
  template<class Iterator> class reverse_iterator 
    : public iterator<
    typename iterator_traits<Iterator>::iterator_category,
    typename iterator_traits<Iterator>::value_type,
    typename iterator_traits<Iterator>::difference_type,
    typename iterator_traits<Iterator>::pointer,
    typename iterator_traits<Iterator>::reference
    > {
  public:
    typedef Iterator iterator_type;
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    typedef typename iterator_traits<Iterator>::reference reference;
    typedef typename iterator_traits<Iterator>::pointer pointer;

    reverse_iterator();
    explicit reverse_iterator(Iterator x);
    template<class U> reverse_iterator(const reverse_iterator<U>& u);

    template<class U> 
    reverse_iterator& operator= (
				 const reverse_iterator<U>& u
				 );

    Iterator base() const;

    reference operator*() const;
    pointer operator->() const;

    reverse_iterator& operator++();
    reverse_iterator operator++(int);
    reverse_iterator& operator--();
    reverse_iterator operator--(int);

    reverse_iterator operator+(difference_type n) const;
    reverse_iterator& operator+=(difference_type n);
    reverse_iterator operator-(difference_type n) const;
    reverse_iterator& operator-=(difference_type n);

    reference operator[](difference_type n) const;

  protected:
    Iterator current;

  private:
    Iterator _deref_tmp;
  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifndef __SL_COMPILER_USE_EXPORT__
# include <sl/stdcpp/implementation/iterator.ipp>
#endif /* !__SL_COMPILER_USE_EXPORT__ */
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_STDCPP_IMPL_ITERATOR_HPP__ */

//-<EOF>
