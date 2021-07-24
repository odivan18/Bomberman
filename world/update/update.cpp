#include "world.h"

void world::update(float elapsed_time)
{
	//обновление бомбера
	//его передвижение и таймеры на бомбах
	main_character.update(elapsed_time);

	//проверка бомб
	//если таймер вышел, то бомба уничтожается, оставляя после себя взрыв
	update_bombs(elapsed_time);

	//обновление взрывов
	update_explosions(elapsed_time);

	//обновление крипов
	update_creeps(elapsed_time);
}
