#include "world.h"

void world::update_bombs(float elapsed_time)
{
	for (int i = 0; i < main_character.get_planted_bombs().size(); i++)
	{
		if (main_character.get_planted_bombs()[i].get_timer() < 0)
		{
			push_back_explosion(make_explosn(main_character.get_planted_bombs()[i]));
			main_character.delete_bomb(i);
			i--;
		}
	}
}