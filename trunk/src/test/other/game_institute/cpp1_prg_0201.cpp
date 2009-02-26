
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
 * This program shows some relational operators.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	/*
	 * You can set the boolalpha flag with the setf function.
	 */
	cout.setf (ios_base::boolalpha);

	float num1 = 0.0f;
	float num2 = 0.0f;

	cout << "Enter a number: ";
	cin >> num1;

	cout << "Enter a number: ";
	cin >> num2;

	bool is_equal = num1 == num2;
	bool is_not_equal = num1 != num2;
	
	bool is_num1_greater = num1 > num2;
	bool is_num1_less = num1 < num2;
	
	bool is_num2_greater_or_equal = num2 >= num1;
	bool is_num2_less_or_equal = num2 <= num1;
	
	cout << endl;
	cout << "is equal                 = " << is_equal << endl;
	cout << "is not equal             = " << is_not_equal << endl;
	cout << "num1 is greater          = " << is_num1_greater << endl;
	cout << "num1 is less             = " << is_num1_less << endl;
	cout << "num2 is greater or equal = " << is_num2_greater_or_equal << endl;
	cout << "num2 is less or equal    = " << is_num2_less_or_equal << endl;
	
}

/*>- EOF -<*/
