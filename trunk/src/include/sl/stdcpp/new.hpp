
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

#ifndef _SL_STDCPP_NEW_HPP_
#define _SL_STDCPP_NEW_HPP_

/* Snow Leopard configuration header */
#include <sl/config/config.hpp>

/* Snow Leopard C++ headers */
#include <sl/stdcpp/cstddef.hpp>
#include <sl/stdcpp/exception.hpp>

namespace std {

/*
 * bad_alloc class
 */

	/* bad_alloc class */
	class bad_alloc
	  : public exception
	{
	public:
		bad_alloc () throw ();
		bad_alloc (const bad_alloc&) throw ();
		
		bad_alloc& operator= (const bad_alloc&) throw ();
		
		virtual const char* what () const throw ();

	};
	
/*
 * nothrow_t struct
 */

	/* nothrow_t struct */
	struct nothrow_t;

	/* nothrow constant */
	extern const nothrow_t nothrow;

/*
 * new_handler
 */

	/* new_handler typedef */
	typedef void (*new_handler) ();
	
	/* set_new_handler function */
	new_handler set_new_handler (new_handler) throw ();

}

/*
 * new and delete operator
 */

/* Standard new operator, throws bad_alloc */
void* operator new (std::size_t) throw (std::bad_alloc);

/* Standard new operator, no throw */
void* operator new (std::size_t, const std::nothrow_t&) throw ();

/* Standard delete operator */
void operator delete (void*) throw ();

/* Standard delete operator, no throw */
void operator delete (void*, const std::nothrow_t&) throw ();

/* Array new operator, throws bad_alloc */
void* operator new[] (std::size_t) throw (std::bad_alloc);

/* Array new operator, no throw */
void* operator new[] (std::size_t) throw ();

/* Array delete operator */
void operator delete[] (void*) throw ();

/* Array delete operator, no throw */
void operator delete[] (void*, std::nothrow_t&) throw ();

/* Placement new operator */
void* operator new (std::size_t, void*) throw ();

/* Placement array new operator */
void* operator new[] (std::size_t, void*) throw ();

/* Placement delete operator */
void operator delete (void*, void*) throw ();

/* Placement array delete operator */
void operator delete[] (void*, void*) throw ();

#endif /* !_SL_STDCPP_NEW_HPP_ */

/*>- EOF -<*/
