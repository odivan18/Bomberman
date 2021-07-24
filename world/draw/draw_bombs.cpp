#include "world.h"

void world::draw_bombs()
{
	for (int i = 0; i < main_character.get_planted_bombs().size(); i++)
	{
		window_main.draw(main_character.get_planted_bombs()[i].get_sprite());
	}
}