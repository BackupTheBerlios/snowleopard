
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
#include <string>

/*
 * Function prototypes.
 */
void do_bet (int&);
int get_choice (const int);
int random (const int, const int);

/*
 * This program is a simple slot machine implementation.
 */
int
main ()
{
	using std::cout;
	using std::endl;
	using std::srand;
	using std::time;

	srand (time (0));

	int chips = 1000;

	int choice;

	while ((choice = get_choice (chips)) == 1)
	{
		do_bet (chips);
		if (chips == 0)
		{
			cout << "You lost all your chips!" << endl;
			break;
		}
	}

	cout << "Exiting slot machine..." << endl;
}

/*
 * This function performs the bet.
 */
void
do_bet (int& chips)
{
	using std::cin;
	using std::cout;
	using std::endl;
	
	int bet = 0;

	while (bet < 1 || bet > chips)
	{
		cout << "Enter your bet: ";
		cin >> bet;

		if (bet < 1 || bet > chips)
		{
			cout << "You did not enter a valid bet." << endl;
		        cin.clear();
			char c;
			while((c = cin.get ()) != '\n' && c != EOF)
			{ }
			cin.clear();			
		}
	}

	int r1 = random (2, 7);
	int r2 = random (2, 7);
	int r3 = random (2, 7);
	cout << r1 << ' ' << r2 << ' ' << r3 << endl;

	if (r1 == 7 && r2 == 7 && r3 == 7)
	{
		cout << "You win!" << endl;
		chips -= bet;
		chips += bet * 10;
	}
	else if (r1 == r2 && r1 == r3)
	{
		cout << "You win!" << endl;
		chips -= bet;
		chips += bet * 5;
	}
	else if ((r1 == r2) || (r1 == r3) || (r2 == r3))
	{
		cout << "You win!" << endl;
		chips -= bet;
		chips += bet * 3;
	}
	else
	{
		cout << "You lose!" << endl;
		chips -= bet;
	}
}

/*
 * This function gets user input and checks that the input is correct.
 */
int
get_choice (const int chips)
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	
	cout << "Player's chips: $" << chips << endl;

	int input = 0;

	while (input < 1 || input > 2)
	{
		cout << "1) Play slot. \t2) EXIT. ";
		cin >> input;

		if (input < 1 || input > 2)
		{
			cout << endl << "Invalid input, please try again: ";
		        cin.clear();
			char c;
			while((c = cin.get ()) != '\n' && c != EOF)
			{ }
			cin.clear();
		}
	}

	return input;
}

/*
 * This function generates a random number between the two intervals given.
 */
int
random (const int low, const int high)
{
	return low + rand () % ((high + 1) - low);
}

/*>- EOF -<*/
