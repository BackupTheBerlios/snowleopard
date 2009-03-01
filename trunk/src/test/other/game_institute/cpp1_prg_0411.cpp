
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
#include <vector>
/*
 * Function prototypes.
 */
void print_array (std::vector<int>&);

/*
 * This program demonstrates the use of std::vector.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::vector;
	
	/* main array and array size */
	vector<int> array;

	bool done = false;

	while (!done)
	{
		print_array (array);

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

			if (index < 0 || index >= array.size ())
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

			array.resize (new_size);
			break;

		default: /* Quit */
			done = true;
			break;
			
		}
	}
}

/*
 * This function prints an array.
 */
void
print_array (std::vector<int>& array)
{
	using std::cout;
	using std::endl;
	
	if (array.size () == 0)
		cout << "empty array" << endl;
	else
	{
		cout << "{ ";
		for (int i = 0; i != array.size (); ++i)
			cout << array[i] << ' ';
		cout << '}' << endl;
	}
}

/*>- EOF -<*/
