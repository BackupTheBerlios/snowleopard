
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

#ifndef _SL_STDCPP_CONCEPT_HPP_
#define _SL_STDCPP_CONCEPT_HPP_

/* Snow Leopard configuration header */
#include <sl/config/config.hpp>

namespace std {

/*
 * Type transformations
 */
	
	/* concept IdentityOf */
	auto concept IdentityOf<typename T> 
	{
		typename Type = T;
		requires SameType<Type, T>;
	}

	/* concept RvalueOf */
	auto concept RvalueOf<typename T> 
	{
		typename Type = T;
		requires Convertible<T&, Type> && Convertible<T&&, Type>;
	}

	/* concept_map RvalueOf */
	template<typename T>
	concept_map RvalueOf<T&> 
	{
		typedef T&& type;
	}

/*
 * True
 */

	/* concept True */
	concept True<bool>
	{ }
	
        /* concept_map True */
	concept_map True<true>
	{ }

/*
 * Operator Concepts
 */

	/* concept HasEqualTo */
	auto concept HasEqualTo<typename T, typename U>
	{
		bool operator== (const T& a, const T& b);
	}

/*
 * Comparisons
 */

	/* concept LessThanComparable */
	auto concept LessThanComparable<typename T> 
	{
		bool operator> (const T& lhs, const T& rhs) 
		{
			return rhs < lhs;
		}
		
		bool operator<= (const T& lhs, const T& rhs)
		{
			return !(rhs < lhs);
		}
		
		bool operator>= (const T& lhs, const T& rhs)
		{
			return !(lhs < rhs);
		}

		axiom Consistency (T a, T b)
		{
			(a > b) == (b < a);
			(a <= b) == !(b < a);
			(a >= b) == !(a < b);
		}

		axiom Irreflexivity (T a)
		{
			(a < a) == false;
		}

		axiom Transitivity (T a, T b)
		{
			if (a < b)
				(b < a) == false;
		}
		
		axiom TransitivityOfEquivalence (T a, T b, T c)
		{
			if (!(a < b) && !(b < a) && !(b < c) && !(c < b))
				(!(a < c) && !(c < a)) == true;
		}
	}

	/* concept EqualityComparable */
	auto concept EqualityComparable<typename T>
	  : HasEqualTo<T, T> 
	{
		bool operator!= (const T& a, const T& b)
		{
			return !(a == b);
		}

		axiom Consistency (T a, T b)
		{
			(a == b) == !(a != b);
		}
    
		axiom Reflexivity (T a)
		{
			a == a;
		}

		axiom Symmetry (T a, T b)
		{
			if (a == b)
				b == a;
		}

		axiom Transitivity (T a, T b, T c)
		{
			if ( a == b && b == c)
				a == c;
		}
	}

	/* concept StrictWeakOrder */
	auto concept StrictWeakOrder<typename F, typename T> 
	  : Predicate < F, T, T >
	{
		axiom Irreflexivity (F f, T a)
		{
			f (a, a) == false;
		}

		axiom Antisymmetry (F f, T a, T b)
		{
			if (f (a, b) && f (b, a))
				f (a, b) == false;
		}

		axiom Transitivity (F f, T a, T b, T c)
		{
			if (f (a, b) && f (b, c))
				f (a, c) == true;
		}

		axiom TransitivityOfEquivalence (F f, T a, T b, T c)
		{
			if (!f (a, b) && !f (b, a) && !f (b, c) && !f (c, b))
				(!f (a, c) && !f (c, a)) == true;
		}
	}

        /* concept EquivalenceRelation */
	auto concept EquivalenceRelation<typename F, typename T> 
	  : Predicate <F, T, T>
	{
		axiom Reflexivity (F f, T a)
		{
			f (a, a) == true;
		}

		axiom Symmetry (F f, T a, T b)
		{
			if (f (a, b))
				f (b, a) == true;
		}

		axiom Transitivity (F f, T a, T b, T c)
		{
			if (f (a, b) && f (b, c))
				f (a, c) == true;
		}
	}

} /* std */

#endif /* !_SL_STDCPP_CONCEPT_HPP_ */

/*>- EOF -<*/
