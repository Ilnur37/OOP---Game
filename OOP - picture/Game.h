#pragma once
#include "ILocation.h"
#include "Projectile.h"

//����
class Game
{
public:
	//��� ������� ���������� ��������� ��� ���� �������������
	void Gamer1(ILocation* object1, int& borders, bool& End);
	void Gamer2(ILocation* object2, int& borders, bool& End);

	//������� �������� ��� ���� ��������
	void Shoot1(Projectile* proj, int& borders, bool& End);
	void Shoot2(Projectile* proj, int& borders, bool& End);
};