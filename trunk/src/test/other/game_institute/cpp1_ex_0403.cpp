
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
#include <cstdlib>
#include <ctime>
#include <iostream>

/*
 * Function prototypes.
 */
int random (int, int);
void random_array_fill (int*, int);

/*
 * This program show how to create an array filled with random numbers.
 */
int
main ()
{
	using std::cin;
        using std::cout;
	using std::endl;
	using std::srand;
	using std::time;
	
	srand (time (0));

	int size;

	cout << "Enter the size of an array to create: ";
	cin >> size;

	cout << "Creating an array and filling it with random numbers..."
	     << endl;

	int* array = new int[size];

	random_array_fill (array, size);

	cout << "Array = { ";
	for (int i = 0; i != size; ++i)
		cout << array[i] << ' ';
	cout << '}' << endl;
	
}

/*
 * Random within range.
 */
int
random (int low, int high)
{
	return low + rand () % ((high + 1) - low);	
}

/*
 * Fill array with random numbers.
 */
void
random_array_fill (int* array, int size)
{
	for (int i = 0; i != size; ++i)
		array[i] = random (0, 100);
}

/*>- EOF -<*/
