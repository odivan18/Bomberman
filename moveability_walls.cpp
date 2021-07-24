#include "world.h"

//��������� ������� ������� �� 4� ��������
//
std::vector<bool> world::moveability_walls(std::vector<bool> vec, alives* character)
{
	//���� �������� �� ������������ "�������"
	if (character->get_position().x % place_size_x == 0)
	{
		//���� �������� �� � ������ ���� �����
		if (character->get_log_pos().x > 0)
		{
			//���� ����� �� ��������� �����
			if (typeid(*world_map[character->get_log_pos().x - 1][character->get_log_pos().y]).name() == typeid(wall).name())
			{
				//���� �������� ����� ������ ����� ����� � ����� ����������
				//�� ������ �� ���������
				//���� �� ���, �� � ���� ����������� ��������� ������
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