
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
 * This program allows you to move in all 4 directions.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;

	int x = 0;
	int y = 0;
	char i = ' ';

	while (!(i == 'q' || i == 'Q'))
	{
		cout << "Current position is = (" << x << ", " << y << ')'
		     << endl;
		cout << "Move (N)orth, (E)ast, (S)outh, (W)est, (Q)uit? ";
		cin >> i;
		
		switch (i)
		{
		case 'n':
			// Fall through
		case 'N':
			y++;
			break;
			
		case 'e':
			// Fall through
		case 'E':
			x++;
			break;
			
		case 's':
			// Fall through
		case 'S':
			y--;
			break;
			
		case 'w':
			// Fall through
		case 'W':
			x--;
			break;
			
		case 'q':
			// Fall through
		case 'Q':
			// Do nothing, q (or Q) ends the loop
			break;
			
		default:
			cout << "Please enter a valid input." << endl;
			break;
			
		}
		
	}
	
}

/*>- EOF -<*/
