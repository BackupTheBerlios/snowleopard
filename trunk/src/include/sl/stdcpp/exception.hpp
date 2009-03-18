
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

#ifndef _SL_STDCPP_EXCEPTION_HPP_
#define _SL_STDCPP_EXCEPTION_HPP_

namespace std {

/*
 * Exception classes
 */
	
	/* class exception */
	class exception
	{
	public:
		/* Constructors */
		exception () throw ();
		exception (const exception&) throw ();

		/* Assignment operator */
		exception& operator= (const exception&) throw ();

		/* Destructor */
		virtual ~exception () throw ();

		/* function what */
		virtual const char* what () const throw ();

	private:
		char* what_;
		
	};

	/* class bad_exception */
	class bad_exception;

	/* class nested_exception */
	class nested_exception;

/*
 * Unexpected handler
 */

	/* typedef unexpected_handler function pointer */
	typedef void (*unexpected_handler) ();

	/* function set_unexpected */
	unexpected_handler set_unexpected (unexpected_handler) throw ();

	/* function unexpected */
	void unexpected ();

/*
 * Terminate handler
 */

	/* typedef terminate_handler function pointer */
	typedef void (*terminate_handler) ();

	/* function set_terminate */
	terminate_handler set_terminate (terminate_handler) throw ();

	/* function terminate */
	void terminate ();

/*
 * Uncaught exception
 */

	/* function uncaught_exception */
	bool uncaught_exception () throw ();

/*
 * Exception pointer
 */

	/* typedef exception_ptr */
	typedef exception* exception_ptr;

/*
 * Other exception operations
 */

	/* function current_exception */
	exception_ptr current_exception ();

	/* function rethrow_exception */
	void rethrow_exception (exception_ptr);

	/* function template copy_exception */
	template<typename E>
	exception_ptr copy_exception (E e);

	/* function template throw_with_nested */
	template<typename T>
	void throw_with_nested (T&&);

	/* function template rethrow_if_nested */
	template<typename E>
	void rethrow_if_nested (const E&);
	
} /* std */

/*******************************************************************************
 * If compiler uses export, don't include source for templates. The files are
 * included in the order in which they appear in the header.
 */
#ifdef SL_COMPILER_USE_NO_EXPORT
# include <sl/stdcpp/detail/exception.ipp>
#endif
/*******************************************************************************
 */

#endif /* !_SL_STDCPP_EXCEPTION_HPP_ */

/*>- EOF -<*/
