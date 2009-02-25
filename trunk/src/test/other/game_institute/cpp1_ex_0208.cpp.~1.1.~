
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
 * Function prototypes
 */
void print_array (int*, int);
void selection_sort (int*, int);
void swap (int*, int*);

/*
 * This program sorts an array using a selection sort.
 */
int
main ()
{
	using std::cout;
	using std::endl;

	int a[] = {7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8};
	int size = 17;

	cout << "Unsorted: ";
	print_array (a, size);

	selection_sort (a, size);

	cout << "Sorted: ";
	print_array (a, size);
}

/*
 * Selection sort function.
 */
void
selection_sort (int* a, int size)
{
	for (int i = 0; i != size - 1; ++i)
	{
		int pos_smallest = i;
		for (int j = i+1; j != size; ++j)
			if (a[j] < a[pos_smallest])
				pos_smallest = j;
		if (pos_smallest != i)
			swap (&a[i], &a[pos_smallest]);
	}
}

/*
 * Function to swap two items using pointers.
 */
void
swap (int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
 * Print an array of size items.
 */
void
print_array (int* a, int size)
{
	using std::cout;
	using std::endl;

	cout << "Array = ";
	for (int i = 0; i != size - 1; ++i)
		cout << a[i] << ", ";
	cout << a[size - 1] << endl;

}

/*>- EOF -<*/
