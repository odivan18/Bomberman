#pragma once
#include "common_settings.h"

//�������� ����� ��� ���������� � ��������
class alives:virtual public basic_common
{
protected:

	
	//�������� ������������ ���������
	float move_speed = 0;

	//������������ ����� �����
	bool can_pass_walls = false;

	//���� ���������
	int hand_damage = 0;

	//���������� ��� ����������� ��������
	//�����, ����, ����� � ���� �� ������� � 0 �� 3
	std::vector<bool> move_dirs;

	//����� ��������� ����� ����������� ������������
	float invul_time_left = 0;
	
public:
	alives();
	alives( obj_types type, sf::Vector2i pos) :basic_common(pos, type)
	{
		//���������� ������ �������� ����������� ��������
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

	//����������� ������� ������������ ��������
	virtual void move(float elapsed_time) = 0;
	//������������� ��������� �� "������", ���� �� ��� ������� 3 � ������ ��������
	void go_on_rails();

	//������������� ������� ��������� �����
	void hit(int damage);

	void move_right();
	void move_left();
	void move_up();
	void move_down();

	void stop_left();
	void stop_right();
	void stop_up();
	void stop_down();
	//��������� �������� �� ���� ������������
	void stop_moveing();

	bool is_on_rails();

	//���� ��������
	float get_move_speed();
	bool get_passability();
	int get_hp();
	int get_hand_damage();
	bool get_move_dir(int dir);
	std::vector<bool> get_move_dir();
	float get_invul_time_left();


	void blinking();
	

};