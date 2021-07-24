#include "world.h"

void world::update_creeps(float elapsed_time)
{
	for (int i = 0; i < creeps_on_map.size(); i++)
	{
		if (creeps_on_map[i].is_on_rails())
		{
			creeps_on_map[i].stop_moveing();
			std::vector<bool> can_creep_move = moveability(&creeps_on_map[i]);

			if (is_any_true(can_creep_move))
			{
				while (!is_only_one_true(can_creep_move))
				{
					dirs_en dir = (dirs_en)(rand() % 4);
					if (can_creep_move[dir])
					{
						for (int j = 0; j < can_creep_move.size(); j++)
						{
							if (j != (int)dir)
								can_creep_move[(dirs_en)j] = false;
						}
					}
				}

				if (can_creep_move[UP])
				{
					creeps_on_map[i].move_up();
				}
				if (can_creep_move[DOWN])
				{
					creeps_on_map[i].move_down();
				}
				if (can_creep_move[LEFT])
				{
					creeps_on_map[i].move_left();
				}
				if (can_creep_move[RIGHT])
				{
					creeps_on_map[i].move_right();
				}
			}
		}	

		creeps_on_map[i].update(elapsed_time);

		if (creeps_on_map[i].get_lives() <= 0)
		{
			creeps_on_map.erase(creeps_on_map.begin() + i);
			i--;
		}
		else
		{
			if (creeps_on_map[i].get_log_pos() == main_character.get_log_pos())
			{
				main_character.hit(creeps_on_map[i].get_hand_damage());
			}
		}
	}
}