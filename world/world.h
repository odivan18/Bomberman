#pragma once

#include "common_settings.h"
#include "alives.h"
#include "creeps.h"
#include "melee_creep.h"
#include "ghost_creep.h"
#include "wall.h"

#include "bomba.h"
#include "bomb_planter.h"

#include "character_bomber.h"
#include "explosion.h"

#include <typeinfo>
#include <thread>


class world
{
protected:
	//основное игровое окно
	sf::RenderWindow window_main;
	//фоновые спрайт и текстура
	sf::Sprite bg_sprite;
	sf::Texture bg_texture;

	std::vector<basic_common> interf;

	//размеры игрового мира
	sf::Vector2i world_size;
	//игровое поле
	basic_common*** world_map;


	//объекты, требующие посто€нного обновлени€

	//основной игровой персонаж - бомберман
	bomber main_character;
	//монстры на поле
	std::vector<creeps> creeps_on_map;	
	std::vector<explosion> explosions;
	

public:
	world();
	//~world();

	void place_walls();
	void place_creeps();
	void create_interface();

	void poihali();

	//ввод дл€ управлени€ игровым персонажем
	void input();

	//вызываетс€ на каждый кадр
	//обновление игровой обстановки
	void update(float elapsed_time);
	void update_bombs(float elapsed_time);
	void update_explosions(float elapsed_time);
	void update_creeps(float elapsed_time);




	void draw();
	void draw_world();
	void draw_bombs();
	void draw_explosions();
	void draw_interface();
	void draw_creeps();


	void console_logs(float elapsed_time);

	


	//группа функций дл€ рассчета возможности передвижени€ в 4 направлени€х дл€ переданного персонажа====================

	//основна€ функци€, возвращающа€ вектор размера 4,
	//описывающий возможности передвижеин€ персонажа по направлени€м
	std::vector<bool> moveability(alives* character);
	//функци€, высчитываю
	std::vector<bool> moveability_borders(std::vector<bool> vec, alives* character);
	std::vector<bool> moveability_walls(std::vector<bool> vec, alives* character);
	std::vector<bool> moveability_bomb(std::vector<bool> vec, alives* character);

	//возвращает зону поражени€ от взрыва переданной бомбы
	//зона рассчитываетс€ в логических координатах
	std::vector<sf::Vector2i> damage_zone(bomb bomba);

	std::vector<explosion> make_explosn(bomb bomba);
	void push_back_explosion(std::vector<explosion> explos);

	//прописывает урон по клетке
	void hit(Vector2i pos, int damage);


	



	
};