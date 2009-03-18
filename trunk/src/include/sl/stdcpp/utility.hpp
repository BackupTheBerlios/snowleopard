
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

#ifndef _SL_STDCPP_UTILITY_HPP_
#define _SL_STDCPP_UTILITY_HPP_

/* Snow Leopard configuration header */
#include <sl/config/config.hpp>

/* Snow Leopard C++ headers */
#include <sl/stdcpp/concepts.hpp>
#include <sl/stdcpp/cstddef.hpp>
#include <sl/stdcpp/memory_concepts.hpp>

namespace std {

/*
 * Operators
 */

	/*
	 * relational_operators
	 */
	namespace rel_ops {

		/* != operator */
		template<EqualityComparable T>
		bool operator!= (const T&, const T&);

		/* > operator */
		template<LessThanComparable T>
		bool operator> (const T&, const T&);

		/* <= operator */
		template<LessThanComparable T> 
		bool operator<= (const T&, const T&);

		/* >= operator */
		template<LessThanComparable T> 
		bool operator>= (const T&, const T&);
		
	}

/*
 * Forward and Move
 */
	
	/* Forward */
	template<IdentityOf T>
	T&& forward (IdentityOf<T>::type &&);
	
        /* Move */
	template<RvalueOf T>
	RvalueOf<T>::type move (T&&);

/*
 * Pairs
 */

	/* pair class template */
	template<
		VariableType T1,
		VariableType T2
		>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;
		
		T1 first;
		T2 second;

		/* Constructors */
		requires DefaultConstructible<T1> && DefaultConstructible<T2>
		pair ();

		requires CopyConstructible<T1> && CopyConstructible<T2>
		pair (const T1&, const T2&);

		template<typename U, typename V>
		requires Constructible<T1, const U&> && Constructible<T2, const V&>
		pair (const pair<U, V>&);

		templace<typename U, typename V>
		requires Constructible<T1, RvalueOf<U>::type>
		    && Constructible<T2, RvalueOf<V>::type>
		pair (pair<U, V>&&);

	        template<typename U, typename... Args>
		requires Constructible<T1, U&&> && Constructible<T2, Args&&...>
		pair (U&&, Args&&... args);

		/* Allocator extended constructors */
		template<Allocator Alloc>
		requires ConstructibleWithAllocator<T1, Alloc>
		    && ConstructibleWithAllocator<T2, Alloc>
		pair (allocator_arg_t, const Alloc&);

		template<typename U, typename V, Allocator Alloc>
		requires ConstructibleWithAllocator<T1, Alloc, const U&>
		    && ConstructibleWithAllocator<T2, Alloc, const V&>
		pair (allocator_arg_t, const Alloc&, const pair<U, V>&);

		template<typename U, typename V, Allocator Alloc>
		requires ConstructibleWithAllocator<T1, Alloc, RvalueOf<U>::type>
		    && ConstructibleWithAllocator<T2, Alloc, RvalueOf<V>::type>
		pair (allocator_arg_t, const Alloc&, pair<U, V>&&);

		template<typename U, typename... Args, Allocator Alloc>
		requires ConstructibleWithAllocator<T1, Alloc, U&&>
		    && ConstructibleWithAllocator<T2, Alloc, Args&&...>
		pair (allocator_arg_t, const Alloc&, U&&, Args&&...);

		/* Assignment operators */
		template<typename U, typename v>
		requires HasAssign<T1, const U&> && HasAssign<T2, const V&>
		pair& operator= (const pair<U, V>&);

		requires MoveAssignable<T1> && MoveAssignable<T2>
		pair& operator= (pair&&);

		template<typename U, typename V>
		requires HasAssign<T1, RvalueOf<U>::type>
		    && HasAssign<T2, RvalueOf<V>::type>
		pair& operator= (pair<U, V>&&);

		/* function swap */
		requires Swappable<T1> && Swappable<T2>
		void swap (pair&&);
	};

	/* concept_map UsesAllocator */
	template<typename T1, typename T2, typename Alloc>
	concept_map UsesAllocator<pair<T1, T2>, Alloc>
	{
		typedef Alloc allocator_type;
	}
	
	/* operator == for pairs */
	template<
		EqualityComparable T1,
		EqualityComparable T2
		>
	bool operator== (const pair<T1, T2>&, const pair<T1, T2>&);

	/* operator < for pairs */
	template<
		LessThanComparable T1,
		LessThanComparable T2
		>
	bool operator< (const pair<T1, T2>&, const pair<T1, T2>&);
	
	/* operator != for pairs */
	template<
		EqualityComparable T1,
		EqualityComparable T2
		>
	bool operator!= (const pair<T1, T2>&, const pair<T1, T2>&);

	/* operator > for pairs */
	template<
		LessThanComparable T1,
		LessThanComparable T2
		>
	bool operator> (const pair<T1, T2>&, const pair<T1, T2>&);

	/* operator >= for pairs */
	template<
		LessThanComparable T1,
		LessThanComparable T2
		>
	bool operator>= (const pair<T1, T2>&, const pair<T1, T2>&);

	/* operator <= for pairs */
	template<
		LessThanComparable T1,
		LessThanComparable T2
		>
	bool operator<= (const pair<T1, T2>&, const pair<T1, T2>&);


	/* swap for pairs */
	template<
		Swappable T1,
		Swappable T2
		>
	void swap (pair<T1, T2>&, pair<T1, T2>&);

	/* swap for pairs (move first) */
	template<
		Swappable T1,
		Swappable T2
		>
	void swap (pair<T1, T2>&&, pair<T1, T2>&);

	/* swap for pairs (move second) */
	template<
		Swappable T1,
		Swappable T2
		>
	void swap (pair<T1, T2>&, pair<T1, T2>&&);

	/* make_pair convenience function template */
	template<
		MoveConstructible T1,
		MoveConstructible T2
		>
	pair<V1, V2> make_pair (T1&&, T2&&);

/*
 * Tuple-alike access to pair
 */

	/* tuple_size class template */
	template<IdentityOf T>
	class tuple_size;

	/* tuple_element class template */
	template<
		size_t I,
		IdentityOf T
		>
	class tuple_element;

	/* tuple_size class template specialization (std::pair) */
	template<
		VariableType T1,
		VariableType T2
		>
	class tuple_size<std::pair<T1, T2>>;

	/* tuple_element class template specialization (element 0) */
	template<
		VariableType T1,
		VariableType T2
		>
	class tuple_element<0, pair<T1, T2>>;

	/* tuple_element class template specialization (element 1) */
	template<
		VariableType T1,
		VariableType T2
		>
	class tuple_element<1, pair<T1, T2>>;

	/* get function template */
	template<
		size_t I,
		typename T1,
		typename T2
		>
	requires True<(I < 2)>
	P& get (pair<T1, T2>&);

	/* get function template (const) */
	template<
		size_t I,
		typename T1,
		typename T2
		>
	requires True<(I < 2)>
	const P& get (const pair<T1, T2>&);

/*
 * Range concept maps for pair
 */

	/* Range concept map */
	template<InputIterator Iter>
	concept_map Range<pair<Iter, Iter>>
	{
		typedef Iter iterator;

		Iter begin (pair<Iter, Iter>& p)
		{
			return p.first;
		}

		Iter end (pair<Iter, Iter>& p)
		{
			return p.second;
		}
	}

	/* Range concept map (const) */
	template<InputIterator Iter>
	concept_map Range<const pair<Iter, Iter>>
	{
		typedef Iter iterator;

		Iter begin (const pair<Iter, Iter>& p)
		{
			return p.first;
		}

		Iter end (const pair<Iter, Iter>& p)
		{
			return p.second;
		}
	}
	
} //std

/*******************************************************************************
 * If compiler uses export, don't include source for templates. The files are
 * included in the order in which they appear in the header.
 */
#ifdef SL_COMPILER_USE_NO_EXPORT
# include <sl/stdcpp/detail/rel_ops.ipp>
# include <sl/stdcpp/detail/forward_move.ipp>
# include <sl/stdcpp/detail/pair.ipp>
# include <sl/stdcpp/detail/tuple_access_pair.ipp>
#endif /* !SL_COMPILER_USE_NO_EXPORT */
/*******************************************************************************
 */

#endif /* !_SL_STDCPP_UTILITY_HPP_ */

/*>- EOF -<*/
