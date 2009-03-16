
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

#ifndef _SL_STDCPP_CONTAINER_CONCEPTS_CONCEPT_MAPS_HPP_
#define _SL_STDCPP_CONTAINER_CONCEPTS_CONCEPT_MAPS_HPP_

/*******************************************************************************
 * Is container_concepts.hpp included?
 */
#ifndef _SL_STDCPP_CONTAINER_CONCEPTS_HPP_
# error <container_concepts_concept_maps.hpp> included without <concepts.hpp>
#endif /* !_SL_STDCPP_CONTAINER_CONCEPTS_HPP_ */
/*******************************************************************************
 */

namespace std {

/*
 * Container concept maps
 */

	/* concept_map Container */
	template<MemberContainer C>
	concept_map Container<C>
	{
		typedef C::value_type value_type;
		typedef C::reference reference;
		typedef C::const_reference const_reference;
		typedef C::size_type size_type;

		typedef C::iterator iterator;
		typedef C::const_iterator const_iterator;

		bool empty (const C& c)
		{
			return c.empty ();
		}

		size_type size (const C& c)
		{
			return c.size ();
		}

		iterator begin (C& c)
		{
			return c.begin ();
		}

		const_iterator begin (const C& c)
		{
			return c.begin ();
		}

		iterator end (C& c)
		{
			return c.end ();
		}

		const_iterator end (const C& c)
		{
			return c.end ();
		}

		const_iterator begin (const C& c)
		{
			return c.cbegin ();
		}

		const_iterator cend (const C& c)
		{
			return c.cend ();
		}

		reference front (C& c)
		{
			return c.front ();
		}

		const_reference front (const C& c)
		{
			return c.front ();
		}
	}
	
	/* concept_map FrontInsertionContainer */
	template<MemberFrontInsertionContainer C>
	concept_map FrontInsertionContainer<C>
	{
		typedef Container<C>::value_type value_type;

		void push_front (C& c, value_type&& v)
		{
			c.push_front (static_cast<value_type&&> (v));
		}
	}
	
	/* concept_map BackInsertionContainer */
	template<MemberBackInsertionContainer C>
	concept_map BackInsertionContainer<C>
	{
		typedef Container<C>::value_type value_type;

		void push_back (C& c, value_type&& v)
		{
			c.push_back (static_cast<value_type&&> (v));
		}
	}
	
	/* concept_map StackLikeContainer */
	template<MemberStackLikeContainer C>
	concept_map StackLikeContainer<C>
	{
		typedef Container<C>::reference reference;
		typedef Container<C>::const_reference const_reference;

		reference back (C& c)
		{
			return c.back ();
		}

		const_reference back (const C& c)
		{
			return c.back ();
		}

		void pop_back (C& c)
		{
			c.pop_back ();
		}
	}
	
	/* concept_map QueueLikeContainer */
	template<MemberQueueLikeContainer C>
	concept_map QueueLikeContainer<C>
	{
		void pop_front (C& c)
		{
			c.pop_front ();
		}
	}
	
	/* concept_map InsertionContainer */
	template<MemberInsertionContainer C>
	concept_map InsertionContainer<C>
	{
		typedef Container<C>::value_type value_type;

		Container<C>::iterator insert (
			C& c,
			Container<C>::const_iterator i,
			value_type&& v
			)
		{
			return c.insert (i, static_cast<value_type&&> (v));
		}
	}
	
	/* concept_map RangeInsertionContainer */
	template<MemberRangeInsertionContainer C, InputIterator Iter>
	concept_map RangeInsertionContainer<C, Iter>
	{
		void insert (
			C& c,
			Container<C>::const_iterator i,
			value_type&& v
			)
		{
			c.insert (i, first, last);
		}
	}
	
	/* concept_map FrontEmplacementContainer */
	template<MemberFrontEmplacementContainer C, typename... Args>
	concept_map FrontEmplacementContainer<C, Args...>
	{
		void emplace_front (C& c, Args&&... args)
		{
			c.emplace_front (forward<Args> (args)...);
		}
	}
	
	/* concept_map BackEmplacementContainer */
	template<MemberBackEmplacementContainer C, typename... Args>
	concept_map Container<C, Args...>
	{
		void emplace_back (C& c, Args&&... args)
		{
			c.emplace_back (forward<Args> (args)...);
		}
	}
	
	/* concept_map EmplacementContainer */
	template<MemberEmplacementContainer C, typename... Args>
	concept_map EmplacementContainer<C, Args...>
	{
		Container<C>::iterator emplace (
			C& c,
			Container<C>::const_iterator position,
			Args&&... args
			)
		{
			return c.emplace (position, forward<Args> (args)...);
		}
	}
	
	/* concept_map Container (array) */
	template<typename E, size_t N>
	concept_map Container<E[N]>
	{
		typedef E value_type;
		typedef E& reference;
		typedef const E& const_reference;
		typedef size_t size_type;
		
		typedef E* iterator;
		typedef const E* const_iterator;

		bool empty (const E (&c)[N])
		{
			return N == 0;
		}

		size_type size (const E (&c)[N])
		{
			return N;
		}

		iterator begin (E (&c)[N])
		{
			return c;
		}

		const_iterator begin (E (&c)[N])
		{
			return c;
		}

		iterator end (E (&c)[N])
		{
			return c + N;
		}

		const_iterator end (E (&c)[N])
		{
			return c + N;
		}
	}
	
	/* concept_map Container (constant array) */
	template<typename E, size_t N>
	concept_map Container<const E[N]>
	{
		typedef E value_type;
		typedef const E& reference;
		typedef const E& const_reference;
		typedef size_t size_type;
		
		typedef const E* iterator;
		typedef const E* const_iterator;

		bool empty (const E (&c)[N])
		{
			return N == 0;
		}

		size_type size (const E (&c)[N])
		{
			return N;
		}

		const_iterator begin (E (&c)[N])
		{
			return c;
		}

		const_iterator end (E (&c)[N])
		{
			return c + N;
		}
	}

	/* concept_map Range (container) */
	template<Container C>
	concept_map Range<C>
	{
		typedef C::iterator iterator;

		iterator begin (C& c)
		{
			return Container<C>::begin (c);
		}

		iterator end (C& c)
		{
			return Container<C>::end (c);
		}
	}
	
	/* concept_map Range (constant container) */
	template<Container C>
	concept_map Range<const C>
	{
		typedef C::const_iterator iterator;

		iterator begin (const C& c)
		{
			return Container<C>::begin (c);
		}

		iterator end (const C& c)
		{
			return Container<C>::end (c);
		}
	}

} /* std */

#endif /* !_SL_STDCPP_CONTAINER_CONCEPTS_CONCEPT_MAPS_HPP_ */

/*>- EOF -<*/
