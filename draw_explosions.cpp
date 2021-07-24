#include "world.h"

void world::draw_explosions()
{
	for (int i = 0; i < explosions.size(); i++)
	{
		window_main.draw(explosions[i].get_sprite());
	}
}