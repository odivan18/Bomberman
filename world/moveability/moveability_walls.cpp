#include "world.h"

//принимает верктор минимум из 4х значений
//
std::vector<bool> world::moveability_walls(std::vector<bool> vec, alives* character)
{
	//если персонаж на вертикальных "рельсах"
	if (character->get_position().x % place_size_x == 0)
	{
		//если персонаж не у левого края карты
		if (character->get_log_pos().x > 0)
		{
			//если слева от персонажа стена
			if (typeid(*world_map[character->get_log_pos().x - 1][character->get_log_pos().y]).name() == typeid(wall).name())
			{
				//если персонаж может ходить через стены и стена разрушаема
				//то ничего не проиходит
				//если же нет, то в этом направлении двигаться нельзя
				if (!(world_map[character->get_log_pos().x - 1][character->get_log_pos().y]->get_obj_type() == WALL_COMMON
					&& wall_pass_default[character->get_obj_type()]))
					vec[LEFT] = false;
			}
		}

		if (character->get_log_pos().x < world_size.x - 1)
		{
			if (typeid(*world_map[character->get_log_pos().x + 1][character->get_log_pos().y]).name() == typeid(wall).name())
			{
				if (!(world_map[character->get_log_pos().x + 1][character->get_log_pos().y]->get_obj_type() == WALL_COMMON
					&& wall_pass_default[character->get_obj_type()]))
					vec[RIGHT] = false;
			}
		}
	}

	if (character->get_position().y % place_size_y == 0)
	{
		if (character->get_log_pos().y > 0)
		{
			if (typeid(*world_map[character->get_log_pos().x][character->get_log_pos().y - 1]).name() == typeid(wall).name())
			{
				if (!(world_map[character->get_log_pos().x][character->get_log_pos().y - 1]->get_obj_type() == WALL_COMMON
					&& wall_pass_default[character->get_obj_type()]))
					vec[UP] = false;
			}
		}

		if (character->get_log_pos().y < world_size.y - 1)
		{
			if (typeid(*world_map[character->get_log_pos().x][character->get_log_pos().y + 1]).name() == typeid(wall).name())
			{
				if (!(world_map[character->get_log_pos().x][character->get_log_pos().y + 1]->get_obj_type() == WALL_COMMON
					&& wall_pass_default[character->get_obj_type()]))
					vec[DOWN] = false;
			}
		}
	}


	return vec;
}