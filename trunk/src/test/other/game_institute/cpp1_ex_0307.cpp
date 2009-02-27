
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
#include <string>

/*
 * Function prototypes.
 */
int binary_search (int*, int, int);

/*
 * This program uses a binary search algorithm to look up numbers in an
 * array.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	
	int array[] = {
		1,  4,  5,  6,  9, 14, 21, 23, 28, 31, 35, 42, 46, 50,
	       53, 57, 62, 63, 65, 74, 79, 89, 95
	};
	int size = 23;

	for (;;)
	{
		cout << "Enter the search key (or x to exit): ";
		char c = cin.peek ();

		if (c >= '0' && c <= '9')
		{
			int key;
			int pos;
			cin >> key;

			if ((pos = binary_search (array, size, key)) == -1)
				cout << "Item " << key << " not found!" << endl;
			else
				cout << "Item " << key
				     << " found at position " << pos << endl;
		}
		else if (c == 'x' || c == 'X')
			break;
		else
		{
			cin.clear ();
			char x;
			while((x = cin.get ()) != '\n' && x != EOF)
			{ }
			cin.clear ();
		}
	}

	cout << "Exiting binary search program..." << endl;
}

/*
 * This function performs a binary search for the searchkey on the given array.
 */
int
binary_search (int* array, int size, int search_key)
{
	int low = 0;
	int high = size - 1;
	int mid;
	
	while (low <= high)
	{
		mid = low + ((high - low) / 2);
		if (array[mid] > search_key)
			/* In the first part */
			high = mid - 1;
		else if (array[mid] < search_key)
			/* In the second part */
			low = mid + 1;
		else
			/* Found */
			return mid;
	}
	
	return -1;

}

/*>- EOF -<*/
