
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

/*
 * Sample class my_class.
 */
template< typename T >
class my_class
{
public:

	/* Regular constructor needed because copy constructor is provided */
	my_class ()
	{
		std::cout << "Called regular constructor" << std::endl;
		value = 0;
	}

	/* Copy constructor */
	my_class (const my_class< T >& x)
	{
		std::cout << "Called default copy constructor" << std::endl;
		value = x.get_value ();
	}

	/* Templated copy constructor */
	template< typename U >
	my_class (const my_class< U >& x)
	{
		std::cout << "Called template constructor" << std::endl;
		value = x.get_value ();
	}

	void
	assign (const my_class< T >& x) /* x must have the same type as *this */
	{
		std::cout << "None templated assign" << std::endl;
		value = x.value;
	}

	template< typename U >
	void
	assign (const my_class< U >& x)
	{
		std::cout << "Templated assign" << std::endl;
		value = x.get_value ();
	}

	T
	get_value () const
	{
		return value;
	}

private:
	T value;

};

/*
 * This program demonstrates a class template.
 */
int
main ()
{
	my_class< double > d;
	my_class< int > i;

	d.assign (d);
	d.assign (i);

	my_class< double > xd (d);
	my_class< int > xi (xd);
}

/*>- EOF -<*/
