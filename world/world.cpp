#include "world.h"
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

const char* dirs[] = { "left", "right", "up", "down" };

world::world()
{
	//разрешени
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	//создание игрового окна
	window_main.create(VideoMode(resolution.x, resolution.y),
		"Simple Game Engine",
		Style::Fullscreen);

	//размеры мира под мой монитор
	world_size.x = resolution.x / place_size_x - 2;
	world_size.y = resolution.y / place_size_y - 1;

	//объявление клеток мира
	world_map = new basic_common * *[world_size.x];
	for (int i = 0; i < world_size.x; i++)
	{
		world_map[i] = new basic_common * [world_size.y];
	}


	//конструктор здорового персонажа
	Vector2i bomber_position = { 0,0 };
	main_character = new bomber(bomber_position);

	//
	place_walls();
	place_creeps();
	create_interface();
}

void world::poihali()
{
	Clock clock;
	float elapsed_time = 0;

	_sleep(3);

	while (window_main.isOpen())
	{
		clock.restart();		

		input();
		update(elapsed_time);		
		draw();
		
		//ожидание до 60fps
		//чтобы персонаж мог нормально двигаться
		do	elapsed_time = clock.getElapsedTime().asSeconds();
		while (clock.getElapsedTime().asSeconds() < 1. / 60);


		//console_logs(elapsed_time);
	}
}



void world::console_logs(float elapsed_time)
{
	//if (main_character.get_planted_bombs().size() > 0)
	cout << 1/elapsed_time << ' ';

	

	
	
}

std::vector<explosion> world::make_explosn(bomb bomba)
{
	std::vector<sf::Vector2i> damage_z = damage_zone(bomba);
	damage_z = logic2screen(damage_z);

	std::vector<explosion> ans;

	for (int i = 0; i < damage_z.size(); i++)
	{
		explosion explos(bomba, damage_z[i]);
		ans.push_back(explos);
	}

	return ans;
}

void world::push_back_explosion(std::vector<explosion> explos)
{
	for (int i = 0; i < explos.size(); i++)
	{
		bool flag = true;

		for (int j = 0; j < explosions.size(); j++)
		{
			if (explos[i].get_log_pos() == explosions[j].get_log_pos())
			{
				explosions[j] = explos[i];
				flag = false;
			}
		}

		if (flag)
			explosions.push_back(explos[i]);
	}
}

void world::hit(Vector2i pos, int damage)
{
	//урон по стене, если есть
	if (world_map[pos.x][pos.y]->get_obj_type() == WALL_COMMON)
	{
		world_map[pos.x][pos.y]->hit(damage);

		if (world_map[pos.x][pos.y]->get_lives() <= 0)
		{
			sf::Vector2i w_pos = { pos.x * place_size_x,pos.y * place_size_y };
			world_map[pos.x][pos.y] = new basic_common(w_pos, FLOOR);
		}
	}

	//урон по персонажу
	if (main_character.get_log_pos() == pos)
	{
		main_character.hit(damage);
	}

	//подрыв звдетых бомб
	for (int i = 0; i < main_character.get_planted_bombs().size(); i++)
	{
		if (pos == main_character.get_planted_bombs()[i].get_log_pos())
		{
			push_back_explosion(make_explosn(main_character.get_planted_bombs()[i]));
			main_character.delete_bomb(i);
			i--;
		}
	}

	//урон по крипам
	for (int i = 0; i < creeps_on_map.size(); i++)
	{
		if (creeps_on_map[i].get_log_pos() == pos)
		{
			creeps_on_map[i].hit(damage);
		}
	}
}

void world::create_interface()
{
	basic_common tmp({ 0, place_size_y * world_size.y }, "textures\\interface_down.bmp");
	interf.push_back(tmp);

	basic_common tmp1({ place_size_x * world_size.x,0 }, "textures\\interface_right.bmp");
	interf.push_back(tmp1);

	basic_common tmp2({ place_size_x * (world_size.x + 1) + 5,0 }, num_textures_names[main_character.get_lives()]);
	interf.push_back(tmp2);

	basic_common tmp3({ place_size_x * (world_size.x + 1) + 5,place_size_y }, num_textures_names[main_character.get_max_bombs_possible()]);
	interf.push_back(tmp3);
}




