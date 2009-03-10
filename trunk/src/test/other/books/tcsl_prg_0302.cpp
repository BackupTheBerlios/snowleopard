
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

/*
 * Sample classes.
 */
class E1 { };
class E2 { };

/*
 * Function that throws exceptions depending on input. It has no specification
 * for bad_exceptions.
 */
void
f (bool throwE1) throw (E1)
{
	if (throwE1)
		throw E1 ();
	else 
		throw E2 ();
}

/*
 * This function throws an exception, but the exception specification specifies
 * bad_exception.
 */
void
g (bool throwE1) throw (E1, std::bad_exception)
{
	if (throwE1)
		throw E1 ();
	else 
		throw E2 ();
}

int
main ()
{
	try {
		f (true);
	}
	catch (E1) {
		std::cout << "E1 thrown" << std::endl;
	}
	catch (std::bad_exception) {
		std::cout << "bad_exception thrown" << std::endl;
	}

	/*
	 * Calls TERMINATE ()
	 *  try {
	 *    f (false);
	 *  }
	 *  catch (E1) {
	 *    std::cout << "E1 thrown" << std::endl;
	 *  }
	 *  catch (std::bad_exception) {
	 *    std::cout << "bad_exception thrown" << std::endl;
	 *  }  
	 */
	
	try {
		g (true);
	}
	catch (E1) {
		std::cout << "E1 thrown" << std::endl;
	}
	catch (std::bad_exception) {
		std::cout << "bad_exception thrown" << std::endl;
	}  
	
	try {
		g (false);
	}
	catch (E1) {
		std::cout << "E1 thrown" << std::endl;
	}
	catch (std::bad_exception) {
		std::cout << "bad_exception thrown" << std::endl;
	}
}

/*>- EOF -<*/
