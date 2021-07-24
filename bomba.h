#pragma once

class bomb;
class bomb_planter;

#include "common_settings.h"
#include "bomb_planter.h"



//бомба
//утанавливается персонажем и заряжается в зависимости от него
class bomb:virtual public basic_common
{
protected:
	//время, через которое бомба взорвется
	float timer = 0;

	//радиус взрыва бомбы в клетках
	int power = 0;

	//урон от взрыва бомбы
	int damage = 0;

	//взорволась ли уже
	bool is_active = true;

	//установивший бомбу персонаж
	//bomb_planter* planter;

public:
	/*bomb(bomb_planter* plant, sf::Vector2i pos) :basic_common( pos, BOMB)
	{
		position.x = logic_pos.x*place_size_x;
		position.y = logic_pos.y * place_size_y;
		sprite.setPosition(position.x, position.y);

		planter = plant;
		timer = plant->get_timer();
		power = plant->get_boom_size();
		damage = plant->get_bomb_damage();
	}*/

	bomb(obj_types planter, sf::Vector2i pos) :basic_common(pos, BOMB)
	{
		position.x = logic_pos.x * place_size_x;
		position.y = logic_pos.y * place_size_y;
		sprite.setPosition(position.x, position.y);

		timer = bomb_timer_default[planter];
		power = bomb_range_default[planter];
		damage = bomb_damage_default[planter];
	}
	bomb(const bomb& ob) :basic_common(ob)
	{
		timer = ob.timer;
		power = ob.power;
		damage = ob.damage;
	}

	//~bomb();

	//void kostyl(bomb_planter plant);

	int update(float elapsed_time);

	float get_timer() { return timer; }
	int get_power() { return power; }
	int get_damage() { return damage; }
	//bomb_planter* get_owner() { return planter; }

	bomb operator=(bomb* orig);
};