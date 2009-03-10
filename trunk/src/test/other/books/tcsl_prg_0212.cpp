
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
 * Sample class Car.
 */
class Car
{
public:
	virtual void print ()
	{
		std::cout << "Car class" << std::endl;
	}
};

/*
 * Sample class Cabriolet which inherits from Car.
 */
class Cabriolet : public Car
{
public:
	virtual void print ()
        {
		std::cout << "Cabriolat class" << std::endl;
	}

	void open_roof ()
	{
		std::cout << "Opening roof" << std::endl;
	}
};

/*
 * Sample class Linousine inherits from Car.
 */
class Limousine : public Car
{
public:
	virtual void print ()
	{
		std::cout << "Limousine class" << std::endl;
	}
};

/*
 * Function uses function in class depending on its type.
 */
void
f (Car* cp)
{
	cp->print ();

	Cabriolet* p = dynamic_cast< Cabriolet* > (cp);
	if (p == 0)
		std::cout << "This is not a cabriolet" << std::endl;
	else {
		std::cout << "This is a cabriolet" << std::endl;
		p->open_roof ();
	}
}

/*
 * This program demonstrates a class hierarchy and dynamically calling members.
 */
int
main ()
{
	Car *l = new Limousine ();
	Car *c = new Cabriolet ();

	f (l);
	f (c);

	delete l;
	delete c;
}

/*>- EOF -<*/
