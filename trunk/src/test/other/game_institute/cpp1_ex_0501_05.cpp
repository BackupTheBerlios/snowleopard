
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

/* Snow Leopard headers */
#include "cpp1_ex_0501_01.hpp"
#include "cpp1_ex_0501_02.hpp"
#include "cpp1_ex_0501_03.hpp"
#include "cpp1_ex_0501_04.hpp"
#include "cpp1_ex_0501_05.hpp"

/*
 * Player constructor, just initializes all members.
 */
player::player ()
		: name_ ("Default"), class_name_ ("Default"), accuracy_ (0), hit_points_ (0),
		  max_hit_points_ (0), exp_points_ (0), next_level_exp_ (0), gold_ (0),
		  level_ (0), armor_ (0)
{
	weapon_.name_ = "Default weapon name";
	weapon_.damage_range_.low_ = 0;
	weapon_.damage_range_.high_ = 0;
}

/*
 * The function returns true is the player is dead.
 */
bool
player::is_dead ()
{
	return hit_points_ <= 0;
}

/*
 * This function returns the player's armor.
 */
int
player::get_armor ()
{
	return armor_;
}

/*
 * This function applies the damage the player sustained during an attack.
 */
void
player::take_damage (int damage)
{
	hit_points_ -= damage;
}

/*
 * This function performs the character generation.
 */
void
player::create_class ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::getline;

	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "==========================" << endl;

	/* Get character's name. */
	cout << "Enter your character's name: ";
	getline (cin, name_);

	/* Character selection. */
	cout << "Please select a character class number..." << endl;
	cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief: ";

	int character_nr = 1;
	cin >> character_nr;

	switch (character_nr)
	{
	case 1: /* Fighter */
		class_name_ = "Fighter";
		accuracy_ = 10;
		hit_points_ = 20;
		max_hit_points_ = 20;
		exp_points_ = 0;
		next_level_exp_ = 1000;
		gold_ = 0;
		level_ = 1;
		armor_ = 4;
		weapon_.name_ = "Long Sword";
		weapon_.damage_range_.low_ = 1;
		weapon_.damage_range_.high_ = 8;
		break;

	case 2: /* Wizard */
		class_name_ = "Wizard";
		accuracy_ = 5;
		hit_points_ = 10;
		max_hit_points_ = 10;
		exp_points_ = 0;
		next_level_exp_ = 1000;
		gold_ = 0;
		level_ = 1;
		armor_ = 1;
		weapon_.name_ = "Staff";
		weapon_.damage_range_.low_ = 1;
		weapon_.damage_range_.high_ = 4;
		break;

	case 3: /* Cleric */
		class_name_ = "Cleric";
		accuracy_ = 8;
		hit_points_ = 15;
		max_hit_points_ = 15;
		exp_points_ = 0;
		next_level_exp_ = 1000;
		gold_ = 0;
		level_ = 1;
		armor_ = 3;
		weapon_.name_ = "Flail";
		weapon_.damage_range_.low_ = 1;
		weapon_.damage_range_.high_ = 6;
		break;

	case 4: /* Thief */
		class_name_ = "Thief";
		accuracy_ = 7;
		hit_points_ = 12;
		max_hit_points_ = 12;
		exp_points_ = 0;
		next_level_exp_ = 1000;
		gold_ = 0;
		level_ = 1;
		armor_ = 2;
		weapon_.name_ = "Short Sword";
		weapon_.damage_range_.low_ = 1;
		weapon_.damage_range_.high_ = 6;
		break;

	}
}

/*
 * The function performs the attack, either initiated by the player or by the
 * monster.
 */
bool
player::attack (monster& opponent)
{
	using std::cin;
	using std::cout;
	using std::endl;

	int selection = 1;
	cout << "1)Attack 2)Run: ";
	cin >> selection;
	cout << endl;

	switch (selection)
	{
	case 1: /* Attack */
		cout << "You attack an " << opponent.get_name ()
		     << " with a " << weapon_.name_ << endl;

		if (random (0, 20) < accuracy_)
		{
			int damage = random (weapon_.damage_range_);

			int total_damage = damage - opponent.get_armor ();

			if (total_damage <= 0)
				cout << "Your attack failed to penetrate the armor"
				     << endl;
			else
			{
				cout << "You attack for " << total_damage
				     << " damage!" << endl;

				/* Substract from monsters hit points */
				opponent.take_damage (total_damage);
			}
		}
		else
			cout << "You miss!" << endl;

		cout << endl;
		break;

	case 2: /* Run */
		/* 25% chance of being able to run */
		int roll = random (1, 4);

		if (roll == 1)
		{
			cout << "You run away!" << endl;
			return true;
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}

	}

	return false;
}

/*
 * This function tests whether or not the player has experience enough to level
 * up.
 */
void
player::level_up ()
{
	using std::cout;
	using std::endl;

	if (exp_points_ == next_level_exp_)
	{
		cout << "You gained a level!" << endl;

		level_++;

		/* Set experience points required. */
		next_level_exp_ = level_ * level_ * 1000;

		/* Increase stats randomly. */
		accuracy_ += random (1, 3);
		max_hit_points_ += random (2, 6);
		armor_ += random (1, 2);

		/* Give player full hit_points when they level up. */
		level_ = max_hit_points_;
	}
}

/*
 * The function allows the player to rest.
 */
void
player::rest ()
{
	using std::cout;
	using std::endl;

	cout << "Resting..." << endl;

	hit_points_ = max_hit_points_;
}

/*
 * The function displays the player's statistics.
 */
void
player::view_stats ()
{
	using std::cout;
	using std::endl;

	cout << "PLAYER STATS" << endl;
	cout << "============" << endl << endl;

	cout << "Name             = " << name_ << endl;
	cout << "Class            = " << class_name_ <<  endl;
	cout << "Accuracy         = " << accuracy_ << endl;
	cout << "Hitpoints        = " << hit_points_ << endl;
	cout << "Max Hitpoints    = " << max_hit_points_ << endl;
	cout << "Experience       = " << exp_points_ << endl;
	cout << "Exp for Next Lvl = " << next_level_exp_ << endl;
	cout << "Gold             = " << gold_ << endl;
	cout << "Level            = " << level_ << endl;
	cout << "Armor            = " << armor_ << endl;
	cout << "Weapon Name      = " << weapon_.name_ << endl;
	cout << "Weapon Damage    = "
	     << weapon_.damage_range_.low_ << " - "
	     << weapon_.damage_range_.high_ << endl;

	cout << endl
	     << "END PLAYER STATS" << endl;
	cout << "================" << endl <<  endl;
}

/*
 * This function is called when the player has won the battle
 */
void
player::victory (int experience)
{
	using std::cout;
	using std::endl;

	int gold = random (1, experience);
	cout << "You won the battle!" << endl;
	cout << "You win " <<  experience
	     << " experience points and " << gold
	     << " gold coins!"
	     << endl << endl;

	exp_points_ += experience;
	gold_ += gold;
}

/*
 * This function is called if the player dies in the game.
 */
void
player::gameover ()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "You died in battle..." << endl << endl;
	cout << "==========" << endl;
	cout << "GAME OVER!" << endl;
	cout << "==========" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout <<  endl;
}

/*
 *
 */
void
player::display_hit_points ()
{
	using std::cout;
	using std::endl;

	cout << name_ << "'s hitpoints = " << hit_points_ << endl;
}

/*>- EOF -<*/
