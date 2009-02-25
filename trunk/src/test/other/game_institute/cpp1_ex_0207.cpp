
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
int linear_search (int*, int, int);

/*
 * This program uses linear search to search some items in an unsorted
 * array.
 */
int
main ()
{
	using std::cout;
	using std::endl;

	int a[] = {7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8};

	/* Search for 7 */
	int position = linear_search (a, 17, 7);
	if (position >= 0)
		cout << "Element 7 is at position: " << position << endl;
	else
		cout << "Element 7 is not in the array!" << endl;

	/* Search for 8 */
	position = linear_search (a, 17, 8);
	if (position >= 0)
		cout << "Element 8 is at position: " << position << endl;
	else
		cout << "Element 8 is not in the array!" << endl;

	/* Search for 4 */
	position = linear_search (a, 17, 4);
	if (position >= 0)
		cout << "Element 4 is at position: " << position << endl;
	else
		cout << "Element 4 is not in the array!" << endl;

	/* Search for 29 */
	position = linear_search (a, 17, 29);
	if (position >= 0)
		cout << "Element 29 is at position: " << position << endl;
	else
		cout << "Element 29 is not in the array!" << endl;

}

/*
 * Linear search function
 */
int
linear_search (int* a, int size, int item)
{
	for (int i = 0; i != size; ++i)
		if (a[i] == item)
			return i;

	return -1;
}

/*>- EOF -<*/
