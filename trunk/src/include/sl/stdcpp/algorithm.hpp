
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

/*
 * swap
 *
 * File: details/swap.ipp
 */

        /* swap function template */
	template<typename T>
	void swap (T& a, T& b);

} /* std */

/*******************************************************************************
 * If compiler uses export, don't include source for templates. The files are
 * included in the order in which they appear in the header.
 */
#ifdef SL_COMPILER_USE_NO_EXPORT
# include <sl/stdcpp/detail/non_modifying_sequence.ipp>
# include <sl/stdcpp/detail/min_max.ipp>
# include <sl/stdcpp/detail/swap.ipp>
#endif
/*******************************************************************************
 */

#endif /* !_SL_STDCPP_ALGORITHM_HPP_ */

/*>- EOF -<*/
