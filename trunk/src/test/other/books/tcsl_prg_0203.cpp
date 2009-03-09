
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
#include <vector>

/*
 * Class template that uses the vector class to store values.
 */
template< typename T, typename Container = std::vector< T > >
class my_class
{
public:
	typedef Container container_type;

	void add (T x)
	{
		container_.push_back (x);
	}

	Container& get ()
	{
		return container_;
	}

private:
	Container container_;
};

/*
 * This program uses our new template class.
 */
int
main ()
{
	my_class< int > xi;
	xi.add (11);
	xi.add (22);
	xi.add (33);
	my_class< int >::container_type xic = xi.get ();

	std::cout << "my_class< int >" << std::endl;
	for (my_class< int >::container_type::size_type i = 0;
	     i != xic.size ();
	     ++i)
		std::cout << "\t" << i << " = " << xic[i] << std::endl;

	my_class< double > xd;
	xd.add (11);
	xd.add (22);
	xd.add (33);
	my_class< double >::container_type xdc = xd.get ();

	std::cout << "my_class< int >" << std::endl;
	for (my_class< double >::container_type::size_type i = 0;
	     i != xdc.size ();
	     ++i)
		std::cout << "\t" << i << " = " << xdc[i] << std::endl;
}

/*>- EOF -<*/
