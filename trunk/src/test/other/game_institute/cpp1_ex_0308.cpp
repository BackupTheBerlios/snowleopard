
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
void bubble_sort (int[], const int);
void print_array (const int[], const int);
void swap (int&, int&);

/*
 * This program is a simple calculator with some build-in functions.
 */
int
main ()
{
	using std::cin;
        using std::cout;
	using std::endl;

	int* array;
	int size;

	cout << "How many elements do you want to enter: ";
	cin >> size;

	array = new int[size];

	for (int i = 0; i != size; ++i)
	{
		cout << "Element [" << i << "]: ";
		cin >> array[i];
	}
	
	print_array (array, size);
	bubble_sort (array, size);
	print_array (array, size);
	
}

/*
 * Bubble sort function.
 */
void
bubble_sort (int data[], int size)
{
	for (int i = 0; i != size; ++i)
		for (int j = i; j != size; ++j)
			if (data[i] > data[j])
				swap (data[i], data[j]);
}

/*
 * Print all elements in the array.
 */
void
print_array (const int array[], const int size)
{
	using std::cout;
	using std::endl;

	cout << "Array: " << endl;
	for (int i = 0; i != size; ++i)
		cout << '\t' << array[i];
	cout << endl;
}

/*
 * Swap function.
 */
void
swap (int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

/*>- EOF -<*/
