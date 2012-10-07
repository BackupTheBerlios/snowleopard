
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

#ifndef _SL_STDCPP_CONTAINER_CONCEPTS_MEMBER_HPP_
#define _SL_STDCPP_CONTAINER_CONCEPTS_MEMBER_HPP_

/*******************************************************************************
 * Is container_concepts.hpp included?
 */
#ifndef _SL_STDCPP_CONTAINER_CONCEPTS_HPP_
# error <container_concepts_member.hpp> included without <concepts.hpp>
#endif /* !_SL_STDCPP_CONTAINER_CONCEPTS_HPP_ */
/*******************************************************************************
 */

namespace std {

/*
 * Member container concepts
 */

	/* concept MemberContainer */
	auto concept MemberContainer<typename C>
	{
		ObjectType value_type = typename C::value_type;
		typename reference = typename C::reference;
		typename const_reference = typename C::const_reference;
		UnsignedIntegralLike size_type = typename C::size_type;

		ForwardIterator iterator;
		ForwardIterator const_iterator;

		requires Convertible<reference, const_reference>
		    && Convertible<reference, const value_type&>
		    && Convertible<const_reference, const value_type&>
		    && Convertible<iterator, const_iterator>
		    && SameType<ForwardIterator<iterator>::value_type,
		                value_type>
		    && SameType<ForwardIterator<const_iterator>::value_type,
		                value_type>
		    && Convertible<ForwardIterator<iterator>::reference,
		                   reference>
		    && Covnertible<ForwardIterator<const_iterator>::reference,
		                   reference>
		    && SameType<ForwardIterator<iterator>::difference_type,
		                ForwardIterator<const_iterator>::difference_type>
		    && IntegralType<size_type>
		    && Convertible<ForwardIterator<iterator>::difference_type,
		                   size_type>;

		bool C::empty () const
		{
			return begin () == end ();
		}

		size_type C::size () const
		{
			return distance (begin (), end ());
		}

		iterator C::begin ();
		const_iterator C::begin () const;
		iterator C::end ();
		const_iterator C::end () const;
		
		const_iterator C::cbegin () const
		{
			return begin ();
		}

		const_iterator C::cend () const
		{
			return end ();
		}

		reference C::front ()
		{
			return *begin ();
		}

		const_reference C::front () const
		{
			return *begin ();
		}

		axiom MemberAccessFront (C c)
		{
			if (c.begin () != c.end ())
				c.front () == *c.begin ();
		}

		axiom MemberContainerSize (C c)
		{
			(c.begin () == c.end ()) == c.empty ();
			(c.begin () != c.end ()) == (c.size () > 0);
		}
	}
	
	/* concept MemberFrontInsertionContainer */
	auto concept MemberFrontInsertionContainer<typename C>
		: MemberContainer<C>
	{
		void C::push_front (value_type&&);

		axiom MemberFrontInsertion (C c, value_type x)
		{
			x == (c.push_front (c), c.front ());
		}
	}
	
	/* concept MemberBackInsertionContainer */
	auto concept MemberBackInsertionContainer<typename C>
		: MemberContainer<C>
	{
		void C::push_back (value_type&&);
	}
	
	/* concept MemberStackLikeContainer */
	auto concept MemberStackLikeContainer<typename C>
		: MemberBackInsertionContainer<C>
	{
		reference C::back ();
		const_reference C::back () const;

		void C::pop_back ();

		requires BidirectionalIterator<iterator>
		    axiom MemberAccessBack (C c)
		{
			if (c.begin () != c.end ())
				c.back () == *(--c.end ());
		}

		axiom MemberBackInsertion (C c, value_type x)
		{
			x == (c.push_back (x), c.back ());
		}

		axiom MemberBackRemoval (C c, value_type x)
		{
			c == (c.push_back (x), c.pop_back (), c);
		}
	}
	
	/* concept MemberQueueLikeContainer */
	auto concept MemberQueueLikeContainer<typename C>
		: MemberBackInsertionContainer<C>
	{
		void C::pop_front ();
	}
	
	/* concept MemberInsertionContainer */
	auto concept MemberInsertionContainer<typename C>
		: MemberContainer<C>
	{
		iterator C::insert (const_iterator, value_type&&);

		axiom MemberInsertion (
			C c,
			const_iterator position,
			value_type v
			)
		{
			v == *c.insert (position, v);
		}
	}
	
	/* concept MemberRangeInsertionContainer */
	auto concept MemberRangeInsertionContainer<typename C, typename Iter>
		: MemberInsertionContainer<C>
	{
		requires InputIterator<Iter>;

		void C::insert (
			const_iterator position,
			Iter first,
			Iter last
			);
	}
	
	/* concept MemberFrontEmplacementContainer */
	auto concept MemberFrontEmplacementContainer<
		typename C,
		typename... Args
		>
		: MemberContainer<C>
	{
		void C::emplace_front (Args&&... args);

		requires Constructible<value_type, Args...>
		    axiom MemberFrontEmplacement (C c, Args... args)
		{
			value_type (args...)
			    == (c.emplace_front (args...), c.front ());
		}

		requires MemberFrontInsertionContainer<C>
		    && Constructible<value_type, Args...>
		    axiom MemberFrontEmplacementPushEquivalence(
			    C c,
			    Args... args
			    )
		{
			(c.emplace_front (args...), c.front ())
			    == (c.push_front (value_type (args...)), c.front ());
		}
	}
	
	/* concept MemberBackEmplacementContainer */
	auto concept MemberBackEmplacementContainer<typename C, typename... Args>
		: MemberBackInsertionContainer<C>
	{
		void C::emplace_back (Args&&... args);

		requires MemberStackLikeContainer<C>
		    && Constructible<value_type, Args...>
		    axiom MemberBackEmplacement (C c, Args... args)
		{
			value_type (args...)
			    == (c.emplace_back (args...), c.back ());
		}

		requires MemberStackLikeContainer<C>
		    && Constructible<value_type, Args...>
		    axiom MemberBackEmplacementPushEquivalence (C c, Args... args)
		{
			(c.emplace_back (args...), c.back ())
			    == (c.push_back (value_type (args...)), c.back ());
		}
	}
	
	/* concept MemberEmplacementContainer */
	auto concept MemberEmplacementContainer<typename C, typename... Args>
		: MemberInsertionContainer<C>
	{
		void C::emplace (const_iterator position, Args&&... args);

		requires Constructible<value_type, Args...>
		    axiom MemberEmplacement (
			    C c,
			    const_iterator position,
			    Args... args
			    )
		{
			value_type (args...) == *c.emplace (position, args...);
		}

		requires MemeberInsertionContainer<C>
		    && Constructible<value_type, Args&&...>
		    axiom MemberEmplacementPushEquivalence (
			    C c,
			    const_iterator position,
			    Args... args
			    )
		{
			*c.emplace (position, args...)
			    == *c.insert (position, value_type (args...));
		}
	}
	
} /* std */

#endif /* !_SL_STDCPP_CONTAINER_CONCEPTS_MEMBER_HPP_ */ 

/*>- EOF -<*/

