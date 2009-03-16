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

#ifndef _SL_STDCPP_CONTAINER_CONCEPTS_CONTAINER_HPP_
#define _SL_STDCPP_CONTAINER_CONCEPTS_CONTAINER_HPP_

/*******************************************************************************
 * Is container_concepts.hpp included?
 */
#ifndef _SL_STDCPP_CONTAINER_CONCEPTS_HPP_
# error <container_concepts_container.hpp> included without <concepts.hpp>
#endif /* !_SL_STDCPP_CONTAINER_CONCEPTS_HPP_ */
/*******************************************************************************
 */

namespace std {

/*
 * Container concepts
 */

	/* concept Container */
	concept Container<typename C>
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
		    && SameType<ForwardIterator<iterator>::value_type, value_type>
		    && SameType<ForwardIterator<const_iterator>::value_type,
		                value_type>
		    && Convertible<ForwardIterator<iterator>::reference, reference>
		    && Convertible<ForwardIterator<const_iterator>::reference,
		                   const_reference>
		    && SameType<ForwardIterator<iterator>::difference_type,
		                ForwardIterator<const_iterator>::difference_type>
	 	    && IntergralType<size_type>
		    && Convertible<ForwardIterator<iterator>::difference_type,
		                   size_type>;

		bool empty (const C& c)
		{
			return begin (c) == end (c);
		}

		size_type size (const C& c)
		{
			return distance (begin (c), end (c));
		}

		iterator begin (C&);
		const_iterator begin (const C&);
		iterator end (C&);
		const_iterator end (const C&);

		const_iterator cbegin (const C& c)
		{
			return begin (c);
		}

		const_itertor cend (const C& c)
		{
			return end (c);
		}

		reference front (C& c)
		{
			return *begin (c);
		}

		const_reference front (const C& c)
		{
			return *begin (c);
		}

		axiom ContainerSize (C c)
		{
			(begin (c) == end (c)) == empty (c);
			(begin (c) != end (c)) == (size (c) > 0);
		}
	}

	/* concept FrontInsertionContainer */
	concept FrontInsertionContainer<typename C>
	  : Container<C>
	{
		void push_front (C&, value_type&&);

		axiom FrontInsertion (C c, value_type x)
		{
			x == (push_front (c, x), front (c));
		}
	}

	/* concept BackInsertionContainer */
	concept BackInsertionContainer<typename C>
	  : Container<C>
	{
		void push_back (C&, value_type&&);
	}
	
	/* concept StackLikeContainer */
	concept StackLikeContainer<typename C>
	  : Container<C>
	{
		reference back (C&);
		const_reference back (const C&);

		void pop_back (C&);

		requires BidirectionalIterator<iterator>
		    axiom AccessBack (C c)
		{
			if (begin (c) != end (c))
				back (c) == *(--end (c));
		}

		axiom BackInsertion (C c, value_type x)
		{
			x == (push_back (c, x), back (c));
		}

		axiom BackRemoval (C c, value_type x)
		{
			c == (push_back (c, x), pop_back (c), c);
		}
	}
	
	/* concept QueueLikeContainer */
	concept QueueLikeContainer<typename C>
	  : BackInsertionContainer<C>
	{
		void pop_front (C&);
	}
	
	/* concept InsertionContainer */
	concept InsertionContainer<typename C>
	  : Container<C>
	{
		iterator insert (C&, const_iterator, value_type&&);

		axiom Insertion (C c, const_iterator position, value_type v)
		{
			v == *insert (c, position, v);
		}
	}
	
	/* concept RangeInsertionContainer */
	concept RangeInsertionContainer<typename C, typename Iter>
	  : InsertionContainer<C>
	{
		requires InputIterator<Iter>;

		void insert (C&, const_iterator position, Iter first, Iter last);
	}
	
	/* concept FrontEmplacementContainer */
	concept FrontEmplacementContainer<typename C, typename... Args>
	  : Container<C>
	{
		void emplace_front (C& c, Args&&... args);

		requires Constructible<value_type, Args...>
		    axiom FrontEmplacement (C c, Args... args)
		{
			value_type (args...)
			    == (emplace_front (c, args...), front (c));
		}

		requires FrontInsertionContainer<C>
		    && Constructible<value_type, Args...>
		    axiom FrontEmplacementPushEquivalence (C c, Args... args)
		{
			(emplace_front (c, args...), front (c))
			    == (push_front (c, value_type (args...)), front (c));
		}
	}
	
	/* concept BackEmplacementContainer */
	concept BackEmplacementContainer<typename C, typename... Args>
	  : Container<C>
	{
		void emplace_back (C& c, Args&&... args);

		requires StackLikeContainer<C>
		    && Constructible<value_type, Args...>
		    axiom BackEmplacement (C c, Args... args)
		{
			value_type (args...)
			    == (emplace_back (c, args...), back (c));
		}

		requires StackLikeContainer<C>
		    && Constructible<value_type, Args...>
		    axiom BackEmplacementPushEquivalence(C c, Args... args)
		{
			(emplace_back (c, args...), back (c))
			    == (push_back (c, value_type (args...)), back (c));
		}
	}
	
	/* concept EmplacementContainer */
	concept EmplacementContainer<typename C, typename... Args>
	  : Container<C>
	{
		iterator emplace (C& c, const_iterator position, Args&&... args);

		requires Constructible<value_type, Args...>
		    axiom Emplacement (C c, const_iterator position, Args... args)
		{
			value_type (args...) == emplace (c, position, args...);
		}

		requires InsertionContainer<C>
		    && Constructible<value_type, Args...>
		    axiom EmplacementPushEquivalence (
			    C c,
			    const_iterator position,
			    Args... args
			    )
		{
			*emplace (c, position, args...)
			    == *insert (c, position, value_type (args...));
		}
	}


} /* std */

#endif /* !_SL_STDCPP_CONTAINER_CONCEPTS_CONTAINER_HPP_ */

/*>- EOF -<*/
