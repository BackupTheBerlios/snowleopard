
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
void print_array (int*, int);
int* resize_array (int*, int, int);

/*
 * This program demonstrates pointer arithmetic.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;

	/* main array and array size */
	int* array = 0;
	int size = 0;

	bool done = false;

	while (!done)
	{
		print_array (array, size);

		/* Get user input */
		cout <<
		    "1) Get element "
		    "2) Resize array "
		    "3) Quit ";

		int selection = 1;
		cin >> selection;

		/* Some variables */
		int index = -1;
		int value = 0;
		int new_size = 0;

		switch (selection)
		{
		case 1:
			/*
			 * Ask for the index of the element the user wants to
			 * set.
			 */
			cout << "Index = ";
			cin >> index;

			if (index < 0 || index >= size)
				cout << "Bad index!" << endl;
			else
			{
				cout << '[' << index << "] = ";
				cin >> value;

				array[index] = value;
			}
			break;

		case 2:
			cout << "Size = ";
			cin >> new_size;

			array = resize_array (array, size, new_size);
			size = new_size;
			break;

		default: /* Quit */
			done = true;
			break;
			
		}
	}
	
	delete[] array;
	array = 0;
}

/*
 * This function prints an array.
 */
void
print_array (int* array, int size)
{
	using std::cout;
	using std::endl;
	
	if (size == 0)
		cout << "empty array" << endl;
	else
	{
		cout << "{ ";
		for (int i = 0; i != size; ++i)
			cout << array[i] << ' ';
		cout << '}' << endl;
	}
}

/*
 * This function resizes the given array from the old_size to the new_size.
 */
int*
resize_array (int* array, int old_size, int new_size)
{
	int* new_array = new int[new_size];

	if (new_size >= old_size)
		/* Copy old elements */
		for (int i = 0; i != old_size; ++i)
			new_array[i] = array[i];
	else
		/* Copy only the first new_size elements */
		for (int i = 0; i != new_size; ++i)
			new_array[i] = array[i];

	delete[] array;

	return new_array;
}

/*>- EOF -<*/
