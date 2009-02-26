
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
 * This macro prints a prompt and get the value entered.
 */
#define GET_VALUE(var)                        \
   cout << "Enter 0 for false, 1 for true? "; \
   cin >> var

/*
 * This macro prints a text followed by a value.
 */
#define PRINT_VAR(text, var) \
   cout << text << " = " << var << endl

/*
 * This program performs some boolean operations on 4 values entered by
 * the user.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;

	bool a, b, c, d;

	GET_VALUE(a);
	GET_VALUE(b);
	GET_VALUE(c);
	GET_VALUE(d);

	bool r1 = a || b || c || d;
	bool r2 = a && b && c && d;
	bool r3 = !((a && b) || (b && !c)) || !(c && d);
	bool r4 = !(!((a && !d) && (b || c)));

	PRINT_VAR("a                                    ", a);
	PRINT_VAR("b                                    ", b);
	PRINT_VAR("c                                    ", c);
	PRINT_VAR("d                                    ", d);

	PRINT_VAR("a || b || c || d                     ", r1);
	PRINT_VAR("a && b && c && d                     ", r2);
	PRINT_VAR("!((a && b) || (b && !c)) || !(c && d)", r3);
	PRINT_VAR("!(!((a && !d) && (b || c)))          ", r4);

}

/*>- EOF -<*/
