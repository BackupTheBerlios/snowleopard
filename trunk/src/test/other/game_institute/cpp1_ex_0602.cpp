
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
#include <cstddef>
#include <iostream>
#include <string>

/*
 * function prototypes
 */
std::string to_upper (std::string);
char to_upper (char);
std::string to_lower (std::string);
char to_lower (char);

/*
 * This program demonstrates how to use C++ C-string functions to reverse a
 * string.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::getline;
	using std::string;
	
	string s;

	cout << "Enter a string: ";
	getline (cin, s);

	cout << "\nUppercase string: " << to_upper (s) << endl;
	cout << "Lowercase string: " << to_lower (s) << endl;
}

/*
 * to_upper function (string)
 */
std::string
to_upper (const std::string str)
{
	using std::size_t;
	using std::string;

	string upper = "";

	for (size_t i = 0; i != str.size (); ++i)
		upper += to_upper (str[i]);

	return upper;
}

/*
 * to_upper function (char)
 */
char
to_upper (char c)
{
	if (c >= 97 && c <= 122)
		return c - 32;

	return c;
}

/*
 * to_lower function (string)
 */
std::string
to_lower (const std::string str)
{
	using std::size_t;
	using std::string;

	string lower = "";

	for (size_t i = 0; i != str.size (); ++i)
		lower += to_lower (str[i]);

	return lower;
}

/*
 * to_lower function (char)
 */
char
to_lower (char c)
{
	if (c >= 65 && c <= 90)
		return c + 32;

	return c;
}

/*>- EOF -<*/
