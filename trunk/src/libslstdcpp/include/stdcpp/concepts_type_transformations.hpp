
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

#ifndef _SL_STDCPP_CONCEPTS_TYPE_TRANSFORMATIONS_HPP_
#define _SL_STDCPP_CONCEPTS_TYPE_TRANSFORMATIONS_HPP_

/*******************************************************************************
 * Is concepts.hpp included?
 */
#ifndef _SL_STDCPP_CONCEPTS_HPP_
# error <concepts_type_transformations.hpp> included without <concepts.hpp>
#endif /* !_SL_STDCPP_CONCEPTS_HPP_ */
/*******************************************************************************
 */

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

} /* std */

#endif /* !_SL_STDCPP_CONCEPTS_TYPE_TRANSFORMATIONS_HPP_ */

/*>- EOF -<*/

