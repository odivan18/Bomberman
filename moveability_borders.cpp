#include "world.h"



std::vector<bool> world::moveability_borders(std::vector<bool> vec, alives* character)
{
	if (character->get_position().x <= 0)
	{
		vec[LEFT] = false;
		if (character->get_position().x < 0)
		character->set_position({ 0, character->get_log_pos().y * place_size_y });
	}
	if (character->get_position().x >= (world_size.x - 1) * place_size_x)
	{
		vec[RIGHT] = false;
		if (character->get_position().x > (world_size.x - 1) * place_size_x)
		character->set_position({ character->get_log_pos().x*place_size_x, character->get_log_pos().y * place_size_y });
	}
	if (character->get_position().y <= 0)
	{
		vec[UP] = false;
		if (character->get_position().y < 0)
		character->set_position({ character->get_log_pos().x * place_size_x, 0 });
	}
	if (character->get_position().y >= (world_size.y - 1) * place_size_y)
	{
		vec[DOWN] = false;
		if (character->get_position().y > (world_size.y - 1) * place_size_y)
		character->set_position({ character->get_log_pos().x * place_size_x, character->get_log_pos().y * place_size_y });
	}

	return vec;
}