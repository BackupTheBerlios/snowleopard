
/*-
 * Copyright (c) 2009 Roel Sergeant.
 * All rights reserved.
 *
 * This code is derived from software contributed to the Snow Leopard
 * project.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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

/*>- EOF -<*/
