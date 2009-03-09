
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
 * Struct to show name clashes.
 */
struct Call_info
{
	static const int ARG_ONE = 1;
	static const int ARG_TWO = 2;
};

/*
 * Define ARG_TWO
 */
#define ARG_TWO a2

/*
 * Function f
 */
int
f( int a
#ifdef ARG_TWO
    , int b
#endif
       )
{
#ifdef ARG_TWO
	std::cout << "Two argument function" << std::endl;
	return a + b;
#else
	std::cout << "One argument function" << std::endl;
#endif
	return a;
}

/*
 * Define string, better use a const char*
 */
#define NAME "Lena Katina"
const char* name = NAME;

/*
 * Dangerous macros, don't know C++ syntax
 */
#define MAC(x,y) int argument1 = x; int argument2 = y
MAC (1234, 4321);

/*
 * Useless macros
 */
#define USE_CASE(y,z) \
	case z: std::cout << "CASE " << z << "; calc: " << y * z << std::endl;

/*
 * This program demonstrates some abuses of the macro preprocessor. Don't try
 * this at home.
 */
int
main ()
{
	std::cout << "Variable: " << name << "; MACRO: " << NAME << std::endl;
	std::cout << "Expanded: " << argument1 << " & " << argument2 << std::endl;
  
	int x = 1;
	int y = 2;
	
	switch (x) {
		USE_CASE(y,1)
		    USE_CASE(y,2)
		    USE_CASE(y,3) break;
		USE_CASE(y,4)
		    }
	
#ifdef ARG_TWO
	f (1, 2);
	//  f (1); ERROR => Too few arguments in call
#else
	f (1);
	//  f (1, 2); ERROR => Too many arguments in call
#endif
  
	Call_info ci;
	std::cout << "ci.ARG_ONE = " << ci.ARG_ONE << std::endl;
	/*
	 * std::cout << "c1.ARG_TWO = " << ci.ARG_TWO << std::endl;
	 * ERROR => if ARG_TWO defined after struct, 
	 *          ARG_TWO is replaced by a2, but not in the struct.
	 *          struct 'Call_info' has no member named 'a2'
	 */
  
	return 0;
}

/*>- EOF -<*/
