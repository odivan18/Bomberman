#pragma once
#include "common_settings.h"

//основной класс для бомбермана и монстров
class alives:virtual public basic_common
{
protected:

	
	//скорость передвижения персонажа
	float move_speed = 0;

	//проходимость через стены
	bool can_pass_walls = false;

	//урон персонажа
	int hand_damage = 0;

	//переменные для определения движения
	//право, лево, вверх и вниз по порядку с 0 до 3
	std::vector<bool> move_dirs;

	//после получения урона срабатывает неуязвимость
	float invul_time_left = 0;
	
public:
	alives();
	alives( obj_types type, sf::Vector2i pos) :basic_common(pos, type)
	{
		//заполнение набора активных направлений движения
		for (int i = 0; i < 4; i++)
			move_dirs.push_back(false);

		move_speed = move_speed_default[type];
		can_pass_walls = wall_pass_default[type];
		hand_damage = hand_damage_default[type];
	}
	alives(const alives& ob) :basic_common(ob)
	{
		move_speed = ob.move_speed;
		can_pass_walls = ob.can_pass_walls;
		hand_damage = ob.hand_damage;
		move_dirs = { false,false,false,false };
	}

	//виртуальная функция передвижения существа
	virtual void move(float elapsed_time) = 0;
	//устанавливает персонажа на "рельсы", если до них оталось 3 и меньше пикселей
	void go_on_rails();

	//универсальная формула получения урона
	void hit(int damage);

	void move_right();
	void move_left();
	void move_up();
	void move_down();

	void stop_left();
	void stop_right();
	void stop_up();
	void stop_down();
	//остановка движения во всех направлениях
	void stop_moveing();

	bool is_on_rails();

	//куча геттеров
	float get_move_speed();
	bool get_passability();
	int get_hp();
	int get_hand_damage();
	bool get_move_dir(int dir);
	std::vector<bool> get_move_dir();
	float get_invul_time_left();


	void blinking();
	

};