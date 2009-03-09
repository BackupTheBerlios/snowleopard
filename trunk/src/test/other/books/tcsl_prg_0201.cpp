
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
#include <iostream>
#include <string>

/*
 * max template function.
 */
template< typename T >
inline const T&
max (const T& a, const T& b)
{
	return a < b ? b : a;
}

/*
 * structure used for testing.
 */
struct A {
	A (int a, int b) 
	 : a_(a), b_(b)
	{ }

	int
	getA () const { return a_; }

	int
	getB () const { return b_; }

private:
	int a_;
	int b_;
};

/*
 * Overloaded less than operator.
 */
bool
operator< (const A& a, const A& b)
{
	if (a.getA () < b.getA ())
		return true;
	else if (a.getA () == b.getA ())
		if (a.getB () < b.getB ())
			return true;
	return false;
}

/*
 * Program test the max template on different types.
 */
int
main ()
{
	std::cout << "max (1, 2) = " << max (1, 2) << std::endl;
	std::cout << "max (1.0, 2.0) = " << max (1.0, 2.0) << std::endl;
	std::cout << "max (\"Alicia\", \"Keys\") = "
		  << ::max (std::string("Alicia"), std::string("Keys")) << std::endl;
	std::cout << "max (A (1, 2), A (1, 3)) = "
		  << max (A (1,2), A (1, 3)).getB () << std::endl;
	std::cout << "max (6, 4) = " << max (6, 4) << std::endl;
}

/*>- EOF -<*/
