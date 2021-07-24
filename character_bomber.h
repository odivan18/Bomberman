#pragma once
#include "alives.h"
#include "bomb_planter.h"


//�������� ����� �������� ���������
//���������� � ����������
//
//������������� ����� � ��������� �� ��������� �������� ������
//�.�. �����, ��� ��� �����
// 
//������������� ��� �� �������
//� ������� ������ ������������� ���� � ������� �� ��������� �����������
//���� ���������� ������ �� �������� ���� ������� � ���� ���������,
//���������� �������� � ����������� �������� ���� �� ������ �� "�����" ������ �����������
class bomber:virtual public alives,virtual public bomb_planter, virtual public basic_common
{
protected:
	

public:
	bomber();

	bomber(sf::Vector2i pos) :alives(BOMBERMAN, pos),
		bomb_planter( BOMBERMAN, pos),
		basic_common( pos,BOMBERMAN){}
	//bomber(const bomber& ob);

	//������������� ��� �� �������
	//� ������� ������ ������������� ���� � ������� �� ��������� �����������
	//���� ���������� ������ �� �������� ���� ������� � ���� ���������,
	//���������� �������� � ����������� �������� ���� �� ������ �� "�����" ������ �����������
	void move(float etlapsed_time);
	int update(float elapsed_time);

	void delete_bomb(int bomb_n);

	bomber operator=(bomber* orig);
};