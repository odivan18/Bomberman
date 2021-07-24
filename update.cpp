#include "world.h"

#include <iostream>
using namespace std;

void world::update(float elapsed_time)
{
	Clock clock;
	clock.restart();

	//���������� �������
	//��� ������������ � ������� �� ������
	main_character.update(elapsed_time);
	cout << "nc " << clock.getElapsedTime().asMilliseconds() << ' ';

	//�������� ����
	//���� ������ �����, �� ����� ������������, �������� ����� ���� �����
	update_bombs(elapsed_time);
	cout << "bombs " << clock.getElapsedTime().asMilliseconds() << ' ';

	//���������� �������
	update_explosions(elapsed_time);
	cout << "expl " << clock.getElapsedTime().asMilliseconds() << ' ';

	//���������� ������
	update_creeps(elapsed_time);
	cout << "creeps " << clock.getElapsedTime().asMilliseconds() << endl;
}