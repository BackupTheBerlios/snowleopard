
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
//#include <iostream> #include <string> ERROR Extra text after expected end of preprocessing directive
#include <iostream>
#include <string>

/*
 * This program doesn't do much, but in comment you can see the original program
 * that contained a lot of errors.
 */
//int mian () ERROR Missing return statement at end of non-void function "mian"
int
main ()
{
	using std::cout;
	using std::endl;
	using std::string;

	//string str = "Hello World!" ERROR Identifier "string" is undefined
	string str = "Hello World!";

	// ERROR Expected a ";"
	//cout << std << endl; ERROR A namespace name is not allowed
	cout << endl;

	// cout << float x = 5.0f * str << endl; ERROR Type name is not allowed
	float x = 5.0f;
	//  cout << x * str << endl; ERROR No operator "*" matches these operands
	cout << x << " * " << str << endl;

	// int 65Num = 65; ERROR extra text after expected end of number; expected an identifier
	int n65 = 65;
	
	// cout << "n65Num = " < 65Num << endl; ERROR extra text after expected end of number; 
	//cannot determine which instance of fucntion template "std::endl" is intended
	cout << "n65 = " << n65 << endl;

	// WARNING Missing return statement at end of non-void function "mian"
}

/*>- EOF -<*/
