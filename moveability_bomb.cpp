#include "world.h"

std::vector<bool> world::moveability_bomb(std::vector<bool> vec, alives* character)
{
	for (int i = 0; i < main_character.get_planted_bombs().size(); i++)
	{
		if (character->get_position().x % place_size_x == 0 && character->get_position().y % place_size_y == 0)
		{
			dirs_en tmp = is_neighbours(character, &(main_character.get_planted_bombs()[i]));

			if (tmp != NOT_EXIST)
				vec[tmp] = false;
		}
	}

	return vec;
}