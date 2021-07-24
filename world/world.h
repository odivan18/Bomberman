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
	//�������� ������� ����
	sf::RenderWindow window_main;
	//������� ������ � ��������
	sf::Sprite bg_sprite;
	sf::Texture bg_texture;

	std::vector<basic_common> interf;

	//������� �������� ����
	sf::Vector2i world_size;
	//������� ����
	basic_common*** world_map;


	//�������, ��������� ����������� ����������

	//�������� ������� �������� - ���������
	bomber main_character;
	//������� �� ����
	std::vector<creeps> creeps_on_map;	
	std::vector<explosion> explosions;
	

public:
	world();
	//~world();

	void place_walls();
	void place_creeps();
	void create_interface();

	void poihali();

	//���� ��� ���������� ������� ����������
	void input();

	//���������� �� ������ ����
	//���������� ������� ����������
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

	


	//������ ������� ��� �������� ����������� ������������ � 4 ������������ ��� ����������� ���������====================

	//�������� �������, ������������ ������ ������� 4,
	//����������� ����������� ������������ ��������� �� ������������
	std::vector<bool> moveability(alives* character);
	//�������, ����������
	std::vector<bool> moveability_borders(std::vector<bool> vec, alives* character);
	std::vector<bool> moveability_walls(std::vector<bool> vec, alives* character);
	std::vector<bool> moveability_bomb(std::vector<bool> vec, alives* character);

	//���������� ���� ��������� �� ������ ���������� �����
	//���� �������������� � ���������� �����������
	std::vector<sf::Vector2i> damage_zone(bomb bomba);

	std::vector<explosion> make_explosn(bomb bomba);
	void push_back_explosion(std::vector<explosion> explos);

	//����������� ���� �� ������
	void hit(Vector2i pos, int damage);


	



	
};