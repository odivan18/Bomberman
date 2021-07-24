#include "world.h"

void world::place_creeps()
{
	int melee_creeps_number = 5;
	int ghost_creeps_number = 5;

	while (melee_creeps_number > 0 || ghost_creeps_number > 0)
	{
		Vector2i pos_w = { 0,0 };

		for (; pos_w.x < world_size.x; pos_w.x++)
			for (pos_w.y = 0; pos_w.y < world_size.y; pos_w.y++)
			{
				//положение на экране
				Vector2i pos = pos_w;
				pos.x *= place_size_x;
				pos.y *= place_size_y;

				if (melee_creeps_number > 0)
				{
					if ((pos_w.x > 1 || pos_w.y > 1))
					{
						if (world_map[pos_w.x][pos_w.y]->get_obj_type() == FLOOR)
						{
							if (rand() % 30 == 0)
							{
								//melee_creep creep(pos);

								creeps_on_map.push_back(melee_creep(pos));

								melee_creeps_number--;
							}
						}
					}
				}

				if (ghost_creeps_number > 0)
				{
					if ((pos_w.x > 1 || pos_w.y > 1))
					{
						if (world_map[pos_w.x][pos_w.y]->get_obj_type() == FLOOR)
						{
							if (rand() % 60 == 0)
							{
								ghost_creep creep(pos);

								creeps_on_map.push_back(creep);

								ghost_creeps_number--;
							}
						}
					}
				}
			}
	}
}
