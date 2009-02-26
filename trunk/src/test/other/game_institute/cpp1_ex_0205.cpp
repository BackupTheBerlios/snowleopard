
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
 * Function prototypes.
 */
void print_matrix (int (&A)[2][3]);

/*
 * This program sums two matrices.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;

	int a[2][3] = {
		{-5, 2, 8},
		{1,  0, 0}
	};
	int b[2][3] = {
		{1, 0,  2},
		{0, 3, -6}
	};

	int sum[2][3];

	for (int i = 0; i != 2; ++i)
		for (int j = 0; j != 3; ++j)
		{
			// cout << a[i][j] << ", " << b[i][j];
			sum[i][j] = a[i][j] + b[i][j];
			// cout << " = " << sum[i][j] << endl;
		}
	
	cout << "a =" << endl;
	print_matrix (a);
	cout << "b =" << endl;
	print_matrix (b);
	cout << "sum =" << endl;
	print_matrix (sum);
	
}

/*
 * Print the matrix.
 */
void
print_matrix (int (&array)[2][3])
{
	using std::cout;
	using std::endl;

	for (int i = 0; i != 2; ++i)
	{
		for (int j = 0; j != 3; ++j)
			cout << "\t" << array[i][j];
		cout << endl;
	}
	cout << endl;
	
}

/*>- EOF -<*/
