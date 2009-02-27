
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
#include <cmath>
#include <iostream>
#include <string>

/*
 * Constants.
 */
const double pi = 3.14159;
const double e = 2.71828;	

/*
 * Function prototypes.
 */
float atanf2 (float, float);
int get_menu_choice ();
void get_parameters (std::string, float&);
void get_parameters (float&, float&);

/*
 * This program is a simple calculator with some build-in functions.
 */
int
main ()
{
	using std::cout;
	using std::endl;
	using std::string;
	
	int choice = 1;
	while ((choice = get_menu_choice ()) != 12)
	{
		float x;
		float y;

		/*
		 * Get required parameters
		 */
		if (choice == 12)
			continue;
		else if (choice == 4 || choice == 6)
			get_parameters (x, y);
		else
			get_parameters ("x", x);
		
		/*
		 * Perform requested calculation.
		 */
		float result = 0.0f;
		string function;
		
		switch (choice)
		{
		case 1:
			function = "cos(x)";
			result = cosf (x);
			break;

		case 2:
			function = "sin(x)";
			result = sinf (x);
			break;

		case 3:
			function = "tan(x)";
			result = tanf (x);
			break;

		case 4:
			function = "atan2(y,x)";
			result = atanf2 (y, x);
			break;

		case 5:
			function = "sqrt(x)";
			result = sqrt (x);
			break;

		case 6:
			function = "x^y";
			result = powf (x, y);
			break;

		case 7:
			function = "ln(x)";
			result = log (x);
			break;

		case 8:
			function = "e^x";
			result = powf (e, x);
			break;

		case 9:
			function = "|x|";
			result = abs (static_cast<long> (x));
			break;

		case 10:
			function = "floor(x)";
			result = floorf (x);
			break;

		case 11:
			function = "ceil(x)";
			result = ceilf (x);
			break;

		default: /* Can't be reached. */
			break;
		}

		/*
		 * Display result.
		 */
		cout << function << " = " << result << endl;
	}

	cout << "Exiting calculator..." << endl;
}

/*
 * Calculate the correct arc tangent.
 */
float
atanf2 (float y, float x)
{
	/*
	 * using std::atanf;
	 */

	if (x >= 0)
		return atanf (y / x) * (180 / pi);
	else
		return atanf (y / x) * (180 / pi) + 180;
}

/*
 * Display the menu and get the function the user wants to perform.
 */
int
get_menu_choice ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	/* Display menu */
	cout << "\t 1) cos(x)\t 2) sin(x)\t 3) tan(x)\t 4) atan2(y,x)\t 5) sqrt(x)" << endl;
	cout << "\t 6) x^y\t\t 7) ln(x)\t 8) e^x\t\t 9) |x|\t\t10) floor(x)" << endl;
	cout << "\t11) ceil(x)\t12) EXIT" << endl;
	
	/* Get user selection */
	int input = 0;
	while (input < 1 || input > 12)
	{
		cout << "Enter your choice: ";
		cin >> input;

		if (input < 1 || input > 12)
		{
			cout << endl << "Incorrect choice! ";
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
 * Get float parameter from user.
 */
void
get_parameters (std::string name, float& var)
{
	using std::cin;
	using std::cout;

	cout << "Enter " << name << ": ";
	cin >> var;
}

/*
 * Get 2 float parameters from user.
 */
void
get_parameters (float& x, float& y)
{
	get_parameters ("x", x);
	get_parameters ("y", y);
}

/*>- EOF -<*/
