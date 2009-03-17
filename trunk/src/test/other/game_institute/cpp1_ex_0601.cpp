
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
#include <cstring>
#include <iostream>
#include <string>

/*
 * function prototypes
 */
char* reverse_string (const char*);

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

	cout << "\nReversed string: " << reverse_string (s.c_str ()) << endl;
}


/*
 * reverse_string function
 */
char*
reverse_string (const char* str)
{
	using std::strlen;
	
	size_t s = strlen (str);
	char* reversed = new char[s + 1];

	for (size_t i = s, j = 0; i != 0; --i, ++j)
	{
		reversed[j] = str[i - 1];
	}
	reversed[s] = '\0';
	
	return reversed;
}

/*>- EOF -<*/
