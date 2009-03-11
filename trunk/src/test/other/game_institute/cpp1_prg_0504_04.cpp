
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
#include "cpp1_prg_0504_01.hpp"
#include "cpp1_prg_0504_02.hpp"
#include "cpp1_prg_0504_03.hpp"
#include "cpp1_prg_0504_04.hpp"
#include "cpp1_prg_0504_05.hpp"

/*
 * Monster contructor.
 */
monster::monster (
	const std::string& name, int hp, int acc, int xpreward,
	int armor, const std::string& weaponname, int low_damage,
	  int high_damage
	)
  : name_ (name), hit_points_ (hp), accuracy_ (acc), exp_reward_ (xpreward),
    armor_ (armor)
{
	weapon_.name_ = weaponname;
	weapon_.damage_range_.low_ = low_damage;
	weapon_.damage_range_.high_ = high_damage;
}

/*
 * is_dead function, return true if the monster is dead.
 */
bool
monster::is_dead ()
{
	return hit_points_ <= 0;
}

/*
 * get_xpreward function, returns the experience reward for this monster.
 */
int
monster::get_xpreward ()
{
	return exp_reward_;
}

/*
 * get_name function, returns the name of this monster.
 */
std::string
monster::get_name ()
{
	return name_;
}

/*
 * get_armor function, returns the armor of this monster.
 */
int
monster::get_armor ()
{
	return armor_;
}

/*
 * attack function, makes this attack its opponent.
 */
void
monster::attack (player& opponent)
{
	using std::cout;
	using std::endl;

	cout << "A " << name_ << " attack you with a " << weapon_.name_ << endl;

	if (random (0, 20) < accuracy_)
	{
		int damage = random (weapon_.damage_range_);

		int total_damage = damage - opponent.get_armor ();

		if (total_damage <= 0)
			cout << "The monsters attack failed to penetrate your armor!" << endl;
		else
		{
			cout << "You are hit for " << total_damage << " damage!" << endl;
			opponent.take_damage (total_damage);
		}
	}
	else
		cout << "The " << name_ << " missed!" << endl;

	cout << endl;
}

/*
 * take_damage function, sets the hit_points_ according to the damage taken.
 */
void
monster::take_damage (int damage)
{
	hit_points_ -= damage;
}

/*
 * display_hit_points function, displays the remaining hit_points for the monster.
 */
void
monster::display_hit_points ()
{
	using std::cout;
	using std::endl;

	cout << name_ << "'s hitpoints = " << hit_points_ << endl;
}

/*>- EOF -<*/
