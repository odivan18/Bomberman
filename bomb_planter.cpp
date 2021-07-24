#include "bomb_planter.h"

bomb_planter::bomb_planter()
{

}

bool bomb_planter::is_plant_free()
{
	for (int i = 0; i < planted_bombs.size(); i++)
	{
		if (logic_pos == planted_bombs[i].get_log_pos())
			return false;
	}
	return true;
}

bomb bomb_planter::plant_bomb()
{
	bomb bomba(BOMBERMAN, position);

	if (is_plant_free())
		planted_bombs.push_back(bomba);

	return bomba;
}


int bomb_planter::get_boom_size() 
{ 
	return boom_size;
}

int bomb_planter::get_bomb_damage()
{ 
	return bomb_damage;
}

float bomb_planter::get_timer()
{ 
	return bomb_timer;
}

int bomb_planter::get_max_bombs_possible() 
{ 
	return max_bombs_planted;
}

std::vector<bomb> bomb_planter::get_planted_bombs() 
{ 
	return planted_bombs; 
}