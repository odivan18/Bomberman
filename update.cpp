#include "world.h"

#include <iostream>
using namespace std;

void world::update(float elapsed_time)
{
	Clock clock;
	clock.restart();

	//обновление бомбера
	//его передвижение и таймеры на бомбах
	main_character.update(elapsed_time);
	cout << "nc " << clock.getElapsedTime().asMilliseconds() << ' ';

	//проверка бомб
	//если таймер вышел, то бомба уничтожаетс€, оставл€€ после себ€ взрыв
	update_bombs(elapsed_time);
	cout << "bombs " << clock.getElapsedTime().asMilliseconds() << ' ';

	//обновление взрывов
	update_explosions(elapsed_time);
	cout << "expl " << clock.getElapsedTime().asMilliseconds() << ' ';

	//обновление крипов
	update_creeps(elapsed_time);
	cout << "creeps " << clock.getElapsedTime().asMilliseconds() << endl;
}