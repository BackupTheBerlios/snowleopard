
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
 * Print boolean accompanied by a text.
 */
#define PRINT_BOOL(text, var)            \
   cout << text << " = " << var << endl;

/*
 * This program evaluates some boolean expressions based on values provided by
 * the user.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	cout.setf (ios_base::boolalpha);

	bool b0 = false;
	bool b1 = false;
	bool b2 = false;

	cout << "Enter a 0 for false or a 1 for true: ";
	cin >> b0;
	
	cout << "Enter a 0 for false or a 1 for true: ";
	cin >> b1;
	
	cout << "Enter a 0 for false or a 1 for true: ";
	cin >> b2;
	
	bool notb0 = !b0;
	bool notb1 = !b1;
	bool notb2 = !b2;
	
	bool is_b0_and_b1 = b0 && b1;
	bool is_b0_b1_and_b2 = b0 && b1 && b2;
	
	bool is_b0_or_b1 = b0 || b1;
	bool is_b1_or_b2 = b1 || b2;

	bool is_b0_excl_or_b1 = (b0 || b1) && !(b0 && b1);
	
	bool is_complex = (b0 && (b1 || b2)) && !((b0 && b1) || (b0 && b2));
	
	PRINT_BOOL("Is b0           ", b0);
	PRINT_BOOL("Is b1           ", b1);
	PRINT_BOOL("Is b2           ", b2);
	PRINT_BOOL("Is not b0       ", notb0);
	PRINT_BOOL("Is not b1       ", notb1);
	PRINT_BOOL("Is not b2       ", notb2);
	PRINT_BOOL("Is b0 and b1    ", is_b0_and_b1);
	PRINT_BOOL("Is b0, b1 and b2", is_b0_b1_and_b2);
	PRINT_BOOL("Is b0 or b1     ", is_b0_or_b1);
	PRINT_BOOL("Is b1 or b2     ", is_b1_or_b2);
	PRINT_BOOL("Is b0 excl or b1", is_b0_excl_or_b1);
	PRINT_BOOL("Is complex expr ", is_complex);

}

/*>- EOF -<*/
