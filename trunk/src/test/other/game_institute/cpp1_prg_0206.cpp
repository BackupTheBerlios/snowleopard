
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
 * Fill in person variables.
 */
#define FILL_VARS(hp, mp, w, c) \
{                               \
  n_hit_points = hp;            \
  n_magic_points = mp;          \
  weapon_name = w;              \
  class_name = c;               \
}
   
/*
 * The program fills up variables depending on user input.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	/* Output some text asking the user to make a selection. */
	cout << "Welcome to Text-RPG 1.0" << endl;
	cout << "Please select a character class number..." << endl;
	cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief: ";

	/* Prompt the user to make a selection. */
	int char_n = 1;
	cin >> char_n;

	/* Initialize some variables. */
	int n_hit_points = 0;
	int n_magic_points = 0;
	string weapon_name;
	string class_name;

	if (char_n == 1) /* Fighter selected */
	{
		FILL_VARS(10, 4, "Sword", "Fighter");
	}
	else if (char_n == 2) /* Wizard selected */
	{
		FILL_VARS(4, 10, "Magic staff", "Wizard");
	}
	else if (char_n == 3) /* Cleric selected */
	{
		FILL_VARS(7, 7, "Magic staff", "Cleric");
	}
	else /* Other selected */
	{
		FILL_VARS(8, 6, "Short sword", "Thief");
	}
	
	cout << endl;
	cout << "Character properties: " << endl;
	cout << "Class name  = " << class_name << endl;
	cout << "Hitpoints   = " << n_hit_points << endl;
	cout << "Magicpoints = " << n_magic_points << endl;
	cout << "Weapon      = " << weapon_name << endl;

}

/*>- EOF -<*/
