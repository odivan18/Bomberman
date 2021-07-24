#include "world.h"

void world::draw_creeps()
{
	for (int i = 0; i < creeps_on_map.size(); i++)
	{
		window_main.draw(creeps_on_map[i].get_sprite());
	}
}
