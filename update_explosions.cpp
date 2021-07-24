#include "world.h"

void world::update_explosions(float elapsed_time)
{
	for (int i = 0; i < explosions.size(); i++)
	{
		//урон по клетке
		if(explosions[i].get_time_left()>0.9)
		hit(explosions[i].get_log_pos(), explosions[i].get_damage());

		explosions[i].update(elapsed_time);

		if (explosions[i].get_time_left() < 0)
		{
			explosions.erase(explosions.begin() + i);
			i--;
		}
	}
}