#include "world.h"

void world::draw_world()
{
	for (int i = 0; i < world_size.x; i++)
	{
		for (int j = 0; j < world_size.y; j++)
		{
			window_main.draw(world_map[i][j]->get_sprite());
		}
	}
}