#include "world.h"



void world::draw()
{
	//очистка кадра
	window_main.clear(Color::Green);

	//отрисовка стен и фона
	draw_world();
	

	//отрисовка бомб
	draw_bombs();


	//отрисовка бомбера
	window_main.draw(main_character.get_sprite());

	//отрисовка крипов
	draw_creeps();


	//отрисовка взрывов
	draw_explosions();

	//отрисовка интерфейса
	draw_interface();

	//отображение всего нарисованного
	window_main.display();
}