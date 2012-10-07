/*==============================================================================
  Snow Leopard Standard C++ Library
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// algorithm.hpp
//------------------------------------------------------------------------------
// Standard STL algorithms implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDCPP_ALGORITHM_HPP_
#define _SL_STDCPP_ALGORITHM_HPP_

/* Snow Leopard configuration header */
#include <sl/config/config.hpp>

/* Standard C++ headers */
#include <sl/stdcpp/concept.hpp>

namespace std {

/*
 * non-modifying sequence operations
 *
 * File: detail/non_modifying_sequence.ipp
 */

	/* all_of function template */
	template<
		InputIterator Iter,
		Predicate<auto, Iter::value_type> Pred
		>
	requires CopyConstructible<Pred>
	bool all_of (Iter first, Iter last, Pred predicate);

        /* any_of function template */
        template<
		InputIterator Iter,
		Predicate<auto, Iter::value_type> Pred
		>
	requires CopyConstructible<Pred>
	bool any_of (Iter first, Iter last, Pred predicate);

        /* none_of function template */
	template<
		InputIterator Iter,
		Predicate<auto, Iter::value_type> Pred
		>
	requires CopyConstructible<Pred>
	bool none_of (Iter first, Iter last, Pred predicate);

	/* for_each function template */
	template<
		InputIterator Iter,
		Callable<auto, Iter::reference> Function
		>
	requires CopyConstructible<Function>
	Function for_each (Iter first, Iter last, Function function);

	/* find function template */
	template<
		InputIterator Iter,
		typename Type
		>
	requires HasEqualTo<Iter::value_type, Type>
	Iter find (Iter first, Iter last, const Type& value);

	/* find_if function template */
	template<
		InputIterator Iter,
		Predicate<auto, Iter::value_type> Pred
		>
	requires CopyContructible<Pred>
	Iter find_if (Iter first, Iter last, Pred predicate);

        /* find_if_not function template */
        template<
		InputIterator Iter,
		Predicate<auto, Iter::value_type> Pred
		>
	requires CopyConstructible<Pred>
	Iter find_if_not (Iter first, Iter last, Pred predicate);

	/* find_end function template */
	template<
		ForwardIterator Iter1,
		ForwardIterator Iter2
		>
	requires HasEqualTo<Iter1::value_type, Iter2::value_type>
	Iter1 find_end (Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2);
	
	/* find_end function template with predicate */
	template<
		ForwardIterator Iter1,
		ForwardIterator Iter2,
		Predicate<auto, Iter1::value_type, Iter2::value_type> Pred
		>
	requires CopyConstructible<Pred>
	Iter1 find_end (
		Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2,
		Pred predicate
		);

	/* find_first_of function template */
	template<
		ForwardIterator Iter1,
		ForwardIterator Iter2
		>
	requires HasEqualTo<Iter1::value_type, Iter2::value_type>
	Iter1 find_first_of (
		Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2
		);

	/* find_first_of function template with predicate */
	template<
		ForwardIterator Iter1,
		ForwardIterator Iter2,
		Predicate<auto, Iter1::value_type, Iter2::value_type> Pred
		>
	requires CopyConstructible<Pred>
	Iter1 find_first_of (
		Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2,
		Pred predicate
		);

/*
 * swap
 *
 * File: details/swap.ipp
 */

        /* swap function template */
	template<typename T>
	requires MoveAssignable<T> && MoveConstructible<T>
	void swap (T& a, T& b);

	/* swap function template for arrays */
	template<
		ValueType T,
		size_t N
		>
	requires Swappable<T>
	void swap (T (&a)[N], T (&b)[N]);

	/* swap_ranges function template */
	template<
		ForwardIterator Iter1,
		ForwardIterator Iter2
		>
	requires HasSwap<Iter1::reference, Iter2::reference>
	Iter2 swap_ranges (Iter1 first1, Iter1 last1, Iter2 first2);

	/* iter_swap function template */
	template<
		Iterator Iter1,
		Iterator Iter2
		>
	requires HasSwap<Iter1::reference, Iter2::reference>
	void iter_swap (Iter1 a, Iter2 b);

/*
 * min max
 *
 * File: detail/min_max.ipp
 */

	/* min function template */
	template<typename T>
	const T& min (const T& a, const T& b);

        /* min function template with predicate */
	template<
		typename T,
		typename Compare
		>
	const T& min (const T& a, const T& b, Compare c);

        /* max function template */
	template<typename T>
	const T& max (const T& a, const T& b);

        /* max function template with predicate */
	template<
		typename T,
		typename Compare
		>
	const T& max (const T& a, const T& b, Compare c);

} /* std */

/*******************************************************************************
 * If compiler uses export, don't include source for templates. The files are
 * included in the order in which they appear in the header.
 */
#ifdef SL_COMPILER_USE_NO_EXPORT
# include <sl/stdcpp/detail/non_modifying_sequence.ipp>
# include <sl/stdcpp/detail/swap.ipp>
# include <sl/stdcpp/detail/min_max.ipp>
#endif
/*******************************************************************************
 */

#endif /* !_SL_STDCPP_ALGORITHM_HPP_ */

//-<EOF>

