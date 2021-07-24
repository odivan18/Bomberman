#include "world.h"

std::vector<sf::Vector2i> world::damage_zone(bomb bomba)
{
	std::vector<sf::Vector2i> ans;
	ans.push_back(bomba.get_log_pos());

	sf::Vector2i tmp;

	tmp = ans[0];
	for (int i = 0; i < bomba.get_power() && tmp.y - 1 >= 0; i++)
	{
		tmp.y--;

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_UNBREAKABLE)
		{
			break;
		}

		ans.push_back(tmp);

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_COMMON)
		{
			break;
		}
	}

	tmp = ans[0];
	for (int i = 0; i < bomba.get_power() && tmp.y + 1 <= world_size.y; i++)
	{
		tmp.y++;

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_UNBREAKABLE)
		{
			break;
		}

		ans.push_back(tmp);

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_COMMON)
		{
			break;
		}
	}

	tmp = ans[0];
	for (int i = 0; i < bomba.get_power() && tmp.x - 1 >= 0; i++)
	{
		tmp.x--;

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_UNBREAKABLE)
		{
			break;
		}

		ans.push_back(tmp);

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_COMMON)
		{
			break;
		}
	}

	tmp = ans[0];
	for (int i = 0; i < bomba.get_power() && tmp.x + 1 <= world_size.x; i++)
	{
		tmp.x++;

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_UNBREAKABLE)
		{
			break;
		}

		ans.push_back(tmp);

		if (world_map[tmp.x][tmp.y]->get_obj_type() == WALL_COMMON)
		{
			break;
		}
	}


	return ans;
}
