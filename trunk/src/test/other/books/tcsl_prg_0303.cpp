
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

/* Standard C++ headers */
#include <exception>
#include <iostream>
#include <stdexcept>

/*
 * Namespace my_lib.
 */
namespace my_lib {

	/*
	 * my_exception specification.
	 */
	class my_exception : public std::exception 
	{
	public:

		my_exception (const char* const what)
		  : what_(what)
	        { 
			std::cout << "my_exception constructor"
				  << std::endl;
		}

		virtual const char* what () const throw ()
		{
			std::cout << "my_exception.what ()"
				  << std::endl;
			return what_;
		}

	private:
		const char* const what_;
	};

	class my_range_error : public std::out_of_range 
	{
	public:
		my_range_error (const std::string& what)
		  : out_of_range (what)
		{
			std::cout << "my_range_error constructor"
				  << std::endl;
		}

		virtual const char* what () const throw () 
	        {
			std::cout << "my_range_error.what ()"
				  << std::endl;
			return std::out_of_range::what ();
		}

	};

}

/*
 * Function throws my_exception.
 */
void
f () 
{
	throw my_lib::my_exception ("f throws");
}

/*
 * Function throws my_range_error.
 */
void
g () 
{
	throw my_lib::my_range_error ("g throws");
}

/*
 * This program shows custom exceptions.
 */
int
main () {
	try {
		f ();
	}
	catch (my_lib::my_exception e) {
		std::cout << "My exception: " << e.what () << std::endl;
	}
	catch (std::exception e) {
		std::cout << "Other exception: " << e.what () << std::endl;
	}

	try {
		g ();
	}
	catch (my_lib::my_range_error e) {
		std::cout << "My exception: " << e.what () << std::endl;
	}
	catch (std::exception e) {
		std::cout << "Other exception: " << e.what () << std::endl;
	}

}

/*>- EOF -<*/
