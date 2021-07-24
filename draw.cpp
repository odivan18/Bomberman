#include "world.h"



void world::draw()
{
	//������� �����
	window_main.clear(Color::Green);

	//��������� ���� � ����
	draw_world();
	

	//��������� ����
	draw_bombs();


	//��������� �������
	window_main.draw(main_character.get_sprite());

	//��������� ������
	draw_creeps();


	//��������� �������
	draw_explosions();

	//��������� ����������
	draw_interface();

	//����������� ����� �������������
	window_main.display();
}