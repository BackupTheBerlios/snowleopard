
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
 * person class
 */
class person
{
public:
	person (std::string, int age);

	std::string get_name ();
	int get_age ();
	void talk (person&);

private:
	std::string name_;
	int age_;

};

/*
 * This program demonstrates that the this pointer is almost always optional.
 */
int
main ()
{
	person alice ("Alice", 29);
	person roel ("Roel", 33);
	person vanessa ("Vanessa", 20);
	
	alice.talk (vanessa);
	roel.talk (vanessa);
}

/*
 * person constructor
 */
person::person (std::string name, int age)
  : name_ (name), age_ (age)
{ }

/*
 * get_name function
 */
std::string
person::get_name ()
{
	return name_;
}

/*
 * get_age function
 */
int
person::get_age ()
{
	return age_;
}

/*
 * talk function
 */
void
person::talk (person& p)
{
	using std::cout;
	using std::endl;

	cout << name_ << " is talking to " << p.name_ << endl;
}

/*>- EOF -<*/
