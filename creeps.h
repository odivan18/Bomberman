#pragma once
#include "alives.h"

class creeps :virtual public alives, virtual public basic_common
{
protected:
	//проверка, если крип добрался до точки назначения
	bool moving_finished = false;
public:

	creeps(){}
	creeps(obj_types type, sf::Vector2i pos):alives(type,pos){}
	creeps(const creeps& ob) :alives(ob), basic_common(ob)
	{
		move_speed = ob.move_speed;
		can_pass_walls = ob.can_pass_walls;
		hand_damage = ob.hand_damage;
		move_dirs = ob.move_dirs;
	}

	//характер передвижения мостра
	virtual void pathfinder(){}
	//void move(float elapsed_time) {}
	int update(float elapsed_time);
	void move(float elapsed_time);
	
	creeps operator=(creeps orig);
};