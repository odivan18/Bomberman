#pragma once
#include "creeps.h"

class ghost_creep : virtual public creeps, virtual public alives, virtual public basic_common
{
protected:


public:
	ghost_creep(sf::Vector2i pos) :creeps(GHOST, pos), alives(GHOST, pos), basic_common(pos, GHOST){}

	void move(float elapsed_time);
	int update(float elapsed_time);

	ghost_creep operator=(ghost_creep* orig);
};