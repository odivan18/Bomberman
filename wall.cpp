#include "wall.h"

void wall::hit(int damage)
{
	if (breakable)
	{
		lives -= damage;

		if (lives < 1)
		{
			/*-*/
		}
	}
}

int wall::update(float elapsed_time)
{
	return 1;
}

bool wall::get_breakability() 
{
	return breakable;
}
int wall::get_hp()
{
	return lives;
}