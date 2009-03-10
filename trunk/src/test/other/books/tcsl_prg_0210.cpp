
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
 * Stack without explicit constructor.
 */
class Stack_noexplicit 
{
public:
	Stack_noexplicit ()
	{
		std::cout << "Default constructor" << std::endl;
	}

	Stack_noexplicit (int size)
	{
		std::cout << "Automatic conversion or Constructor" << std::endl;
	}
};

/*
 * Stack with explicit constructor.
 */
class Stack_explicit 
{
public:
	Stack_explicit ()
	{
		std::cout << "Default constructor" << std::endl;
	}

	explicit Stack_explicit (int size)
	{
		std::cout << "Constructor only" << std::endl;
	}
};

/*
 * This program demonstrates a class with and without explicit constructors.
 */
int
main ()
{
	Stack_noexplicit s;

	s = 40;

	Stack_explicit e;

	/* e = 40; ERROR - No operator "=" matches these operands */

	Stack_explicit e1 (40);
}

/*>- EOF -<*/
