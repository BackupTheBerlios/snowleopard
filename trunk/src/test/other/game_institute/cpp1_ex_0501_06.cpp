
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

/* Snow Leopard headers */
#include "cpp1_ex_0501_02.hpp"
#include "cpp1_ex_0501_03.hpp"
#include "cpp1_ex_0501_04.hpp"
#include "cpp1_ex_0501_06.hpp"

/*
 * map constructor.
 */
map::map ()
{
	player_x_pos_ = 0;
	player_y_pos_ = 0;
}

/*
 * get_player_x_pos function returns the players x position.
 */
int
map::get_player_x_pos ()
{
	return player_x_pos_;
}

/*
 * get_player_y_pos function returns the players y position.
 */
int
map::get_player_y_pos ()
{
	return player_y_pos_;
}

/*
 * Function moves the player around in the game world.
 */
void
map::move_player ()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "1)North 2)East 3)South 4)West: ";
	int selection = 1;
	cin >> selection;

	/* Update coordinates based on selection. */
	switch (selection)
	{
	case 1: /* North */
		player_y_pos_++;
		break;

	case 2: /* East */
		player_x_pos_++;
		break;

	case 3: /* South */
		player_y_pos_--;
		break;

	case 4: /* West */
		player_x_pos_--;
		break;

	}
	cout << endl;
}

/*
 *
 */
monster*
map::check_random_encounter ()
{
	using std::cin;
	using std::cout;
	using std::endl;

	int roll = random (0, 20);

	monster* opponent = 0;

	if (roll <= 5)
		return 0;
	else if (roll >= 6 && roll <= 10)
	{
		opponent = new monster (
			"Orc", 10, 8, 200, 1, "Short Sword", 2, 7
			);
		cout << "You've encountered an Orc!" << endl;
		cout << "Prepare for battle!" <<  endl <<  endl;
	}
	else if (roll >= 11 && roll <= 15)
	{
		opponent = new monster (
			"Goblin", 6, 6, 100, 0, "Dagger", 1, 5
			);
		cout << "You've encountered an Goblin!" << endl;
		cout << "Prepare for battle!" <<  endl <<  endl;
	}
	else if (roll >= 16 && roll <= 19)
	{
		opponent = new monster (
			"Ogre", 20, 12, 500, 2, "Club", 3, 8
			);
		cout << "You've encountered an Ogre!" << endl;
		cout << "Prepare for battle!" <<  endl <<  endl;
	}
	else if (roll == 20)
	{
		opponent = new monster (
			"Orc Lord", 25, 15, 2000, 5, "Two Handed Sword", 5, 20
			);
		cout << "You've encountered an Orc Lord!!!" << endl;
		cout << "Prepare for battle!" <<  endl <<  endl;
	}

	return opponent;
}

/*
 *
 */
void
map::print_player_pos ()
{
	using std::cout;
	using std::endl;

	cout << "Player position = ("
	     << player_x_pos_ << ", " << player_y_pos_
	     << ")" << endl << endl;
}

/*>- EOF -<*/
