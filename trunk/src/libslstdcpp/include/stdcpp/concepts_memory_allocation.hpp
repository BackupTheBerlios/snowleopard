
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

#ifndef _SL_STDCPP_CONCEPTS_MEMORY_ALLOCATION_HPP_
#define _SL_STDCPP_CONCEPTS_MEMORY_ALLOCATION_HPP_

/*******************************************************************************
 * Is concepts.hpp included?
 */
#ifndef _SL_STDCPP_CONCEPTS_HPP_
# error <concepts_memory_allocation.hpp> included without <concepts.hpp>
#endif /* !_SL_STDCPP_CONCEPTS_HPP_ */
/*******************************************************************************
 */

namespace std {

/*
 * Memory Allocation
 */

	/* concept FreeStoreAllocatable */
	auto concept FreeStoreAllocatable<typename T>
	{
		/* operator new */
		void*
		T::operator new (size_t size);

		/* operator delete */
		void
		T::operator delete (void*);

		/* operator new[] */
		void*
		T::operator new[] (size_t size)
		{
			return T::operator new (size);
		}

		/* operator delete[] */
		void
		T::operator delete[] (void* ptr)
		{
			T::operator delete (ptr);
		}

		/* operator new (no throw) */
		void*
		T::operator new (size_t size, const nothrow_t&)
		{
			try {
				return T::operator new (size);
			}
			catch (...) {
				return 0;
			}
		}

		/* operator new[] (no throw) */
		void*
		T::operator new[] (size_t size, const nothrow_t&)
		{
			try {
				return T::operator new[] (size);
			}
			catch (...) {
				return 0;
			}
		}

		/* operator delete (no throw) */
		void
		T::operator delete (void* ptr, const nothrow_t&)
		{
			T::operator delete (ptr);
		}

		/* operator delete[] (no throw) */
		void
		T::operator delete[] (void* ptr, const nothrow_t&)
		{
			T::operator delete[] (ptr);
		}
		
	}
	
} /* std */

#endif /* !_SL_STDCPP_CONCEPTS_MEMORY_ALLOCATION_HPP_ */

/*>- EOF -<*/

