#pragma once

class bomb;
class bomb_planter;

#include "common_settings.h"
#include "bomba.h"
#include <vector>


//класс, наследуемый всеми, кто собирается ставить бомбы
class bomb_planter:virtual public basic_common
{
protected:
	//размер взрыва в клетках
	int boom_size;

	//урон от установленной персонажем бомбы
	int bomb_damage;

	//таймер взрыва бомбы
	float bomb_timer;

	//максимально возможное число бомб, установленных персонажем
	int max_bombs_planted;

	//поставится ли сейчас бомба
	bool planting;

	//массив установленных персонажем бомб
	std::vector<bomb> planted_bombs;

	//std::vector<explosion> explosions;

public:
	bomb_planter();
	bomb_planter( obj_types type, sf::Vector2i pos):basic_common( pos,type)
	{
		boom_size = bomb_range_default[type];
		bomb_damage = bomb_damage_default[type];
		bomb_timer = bomb_timer_default[type];
		max_bombs_planted = max_bombs_planted_default[type];
		planting = false;	
	}

	bool is_plant_free();
	bomb plant_bomb();

	int update(float elapsed_time) { return 1; }

	//гетеры свойств
	int get_boom_size();
	int get_bomb_damage();
	float get_timer();
	int get_max_bombs_possible();
	std::vector<bomb> get_planted_bombs();
};