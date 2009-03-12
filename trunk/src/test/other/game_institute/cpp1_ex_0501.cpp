
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

/* Snow Leopard headers */
#include "cpp1_prg_0504_05.hpp"
#include "cpp1_prg_0504_06.hpp"

/*
 * This program is a simple RPG game.
 */
int
main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::srand;
	using std::time;

	srand ( time (0));

	map game_map;

	player main_player;

	main_player.create_class ();

	bool done = false;

	while (!done)
	{
		game_map.print_player_pos ();

		int selection = 1;
		cout << "1)Move 2)Rest 3)View Stats 4)Quit: ";
		cin >> selection;

		switch (selection)
		{
		case 1: /* Move */
 		    {
			    monster* opponent = 0;
			    
			    /* Move the player */
			    game_map.move_player ();
			    
			    /* Check for random encounter */
			    opponent = game_map.check_random_encounter ();
			    
			    if (opponent != 0)
			    {
				    /* Loop until a break statement */
				    while (true)
				    {
					    main_player.display_hit_points ();
					    opponent->display_hit_points ();
					    cout << endl;

					    /* Allow player to attack first */
					    if (main_player.attack (*opponent))
						    break;

					    if (opponent->is_dead ())
					    {
						    main_player.victory (
							    opponent->get_xpreward ()
							    );
						    main_player.level_up ();
						    break;
					    }
					    
					    opponent->attack (main_player);
					    
					    if (main_player.is_dead ())
					    {
						    main_player.gameover ();
						    done = true;
						    break;
					    }
				    }
			    }
			    delete opponent;
			    opponent = 0;
		    }
		    break;
			
		case 2: /* Rest */
			main_player.rest ();
			break;
			
		case 3: /* View Stats */
			main_player.view_stats ();
			break;

		case 4: /* Quit */
			done = true;
			break;
			
		}
	}
}

/*>- EOF -<*/
