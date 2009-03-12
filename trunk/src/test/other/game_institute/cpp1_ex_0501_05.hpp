
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

#ifndef _SL_TEST_OTHER_GAME_INSTITUTE_CPP1_PRG_0504_05_HPP_
#define _SL_TEST_OTHER_GAME_INSTITUTE_CPP1_PRG_0504_05_HPP_

/* Standard C++ headers */
#include <string>

/* Snow Leopard headers */
#include "cpp1_prg_0504_03.hpp"
#include "cpp1_prg_0504_04.hpp"

/*
 * Player class.
 */
class player
{
public:
	player ();

	bool is_dead ();

	std::string get_name ();
	int get_armor ();

	void take_damage (int);

	void create_class ();
	bool attack (monster&);
	void level_up ();
	void rest ();
	void view_stats ();
	void victory (int);
	void gameover ();
	void display_hit_points ();

private:
	std::string name_;
	std::string class_name_;
	int accuracy_;
	int hit_points_;
	int max_hit_points_;
	int exp_points_;
	int next_level_exp_;
	int level_;
	int armor_;
	weapon weapon_;

};

#endif /* !_SL_TEST_OTHER_GAME_INSTITUTE_CPP1_PRG_0504_05_HPP_ */

/*>- EOF -<*/
