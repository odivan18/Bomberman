#include "common_settings.h"

bool is_only_one_true(std::vector<bool> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i])
		{
			for (int j = i + 1; j < data.size(); j++)
				if (data[j])
					return false;
			return true;
		}		
	}
	return false;
}

bool is_any_true(std::vector<bool> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i])
		{
			return true;
		}
	}

	return false;
}

dirs_en is_neighbours(basic_common* first, basic_common* second)
{
	if (first->get_log_pos().x == second->get_log_pos().x)
	{
		if (first->get_log_pos().y - second->get_log_pos().y == 1)
		{
			return UP;
		}
		if (first->get_log_pos().y - second->get_log_pos().y == -1)
		{
			return DOWN;
		}
	}

	if (first->get_log_pos().y == second->get_log_pos().y)
	{
		if (first->get_log_pos().x - second->get_log_pos().x == 1)
		{
			return LEFT;
		}
		if (first->get_log_pos().x - second->get_log_pos().x == -1)
		{
			return RIGHT;
		}
	}


	return NOT_EXIST;
}


std::vector<sf::Vector2i> logic2screen(std::vector<sf::Vector2i> log_coords)
{
	std::vector<sf::Vector2i> ans;

	for (int i = 0; i < log_coords.size(); i++)
	{
		ans.push_back(log_coords[i]);

		ans[i].x *= place_size_x;
		ans[i].y *= place_size_y;
	}

	return ans;
}