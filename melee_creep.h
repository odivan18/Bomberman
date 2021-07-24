#pragma once
#include "creeps.h"


//обычный крип
//упирается в стены
//бъет слабенько
class melee_creep :virtual public creeps, virtual public alives, virtual public basic_common
{
protected:


public:
	melee_creep(){}
	melee_creep( sf::Vector2i pos) :creeps(MELEE, pos),alives(MELEE, pos), basic_common(pos, MELEE)
	{

	}

	void move(float elapsed_time);
	int update(float elapsed_time);

	melee_creep operator=(melee_creep* orig);
};