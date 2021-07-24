#pragma once
#include "common_settings.h"
#include "bomba.h"

class explosion: virtual public basic_common
{
protected:
	//радиус взрыва
	int power;

	//урон от взрыва
	int damage;

	//время жизни/отрисовки взрыва
	float lifetime = 1;

public:
	explosion(bomb sorce, sf::Vector2i pos) :basic_common(pos, EXPLOSION)
	{
		power = sorce.get_power();
		damage = sorce.get_damage();

		set_texture(textures_names[EXPLOSION]);
	}
	explosion(const explosion& ob) :basic_common(ob)
	{
		damage = ob.damage;
		lifetime = ob.lifetime;
	}

	int update(float elapsed_time);

	int get_power();
	int get_damage();
	float get_time_left();

	explosion operator=(explosion orig);
};