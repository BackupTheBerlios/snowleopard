
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
 * Class for testing swap on a user-defined type.
 */
class class_A
{
private:
	int value_;

public:
	class_A (int v)
	    : value_ (v)
	{ }

};

/*
 * Class for testing user defined overloaded swap function.
 */
class class_B
{
private:
	int value_;
	float another_value_;

public:
	class_B (int v)
	    : value_ (v), another_value_ (v * 0.98)
	{ }

	void swap (class_B& x)
	{
		std::swap (value_, x.value_);
		std::swap (another_value_, x.another_value_);
	}

};


namespace std {

	/*
	 * Overloaded swap function for class_B.
	 */
	void swap (class_B& a, class_B& b)
	{
		a.swap (b);
	}

}

/*
 * This program tests the swap function.
 */
int
main ()
{
	int i = 12;
	int j = 24;
  
	// SUCCESS> test two integers
	std::swap (i, j);

	float f = 2.4;
	float g = 1.2;
 
	// SUCCESS> test two floats
	std::swap (f, g);

	class_A a (12);
	class_A b (24);

	// SUCCESS> test two A's with overloaded < operator
	std::swap (a, b);

	class_B c (24);
	class_B d (12);
	
	// SUCCESS> overloaded swap function
	std::swap (c, d);

}

/*>- EOF -<*/
