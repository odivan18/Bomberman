#pragma once
#include "common_settings.h"

class wall :public basic_common
{
protected:
	//может ли стена быть сломана
	bool breakable = true;

public:
	wall() {};
	wall( Vector2i pos, obj_types type) :basic_common(pos, type)
	{
		if (type == WALL_COMMON)
			breakable = true;
		if (type == WALL_UNBREAKABLE)
			breakable = false;
	}

	void hit(int damage);

	int update(float elapsed_time);

	bool get_breakability();
	int get_hp();
};