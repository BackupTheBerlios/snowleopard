
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
#include <algorithm>

/*
 * Class used for testing min/max functions on user-defined types.
 */
class class_A
{
private:
	int value_;

public:
	class_A (int v)
	    : value_ (v)
	{ }

	bool operator< (const class_A& rhs) const
	{
		return value_ < rhs.get_value ();
	}

	int get_value () const
	{
		return value_;
	}
};

/*
 * Template function for use as predicate in testing min/max.
 */
template<typename T>
bool greater_than (const T& a, const T& b)
{
	return ! (a < b);
}

/*
 * Program for testing min/max functions.
 */
int
main ()
{
	int i = 12;
	int j = 24;
  
	// SUCCESS> test two integers
	i = std::min (i, j);
	j = std::max (i, j);

	float f = 2.4;
	float g = 1.2;
 
	// SUCCESS> test two floats
	g = std::min (f, g);
	f = std::max (f, g);

	class_A a (12);
	class_A b (24);

	// SUCCESS> test two A's with overloaded < operator
	a = std::min (a, b);
	b = std::max (a, b);

	// SUCCESS> test two ints using a compare function
	j = std::min (i, j, greater_than<int>);
	i = std::max (i, j, greater_than<int>);

	// SUCCESS> test two A's using a compare function
	b = std::min (a, b, greater_than<class_A>);
	a = std::max (a, b, greater_than<class_A>);

}

/*>- EOF -<*/
