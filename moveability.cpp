#include "world.h"

using namespace std;

//���������� ������ ��������� ���������� �������� ��������� ���������
//true - ���� � ���� ����������� �������� ��������
//false - ���� � ��� ������� ��������� ������
//������� ����������� �� ������� � enum �� common_settings
vector<bool> world::moveability(alives* character)
{
	//��������� ����))))0)
	vector<bool> ans;
	for (int i = 0; i < 4; i++)
		ans.push_back(true);

	//����������� ������ ����================================================

	ans = moveability_borders(ans, character);

	//���� � �����=====================================================

	ans = moveability_walls(ans, character);

	//���� � �����=====================================================
	
	ans = moveability_bomb(ans, character);

	return ans;
}