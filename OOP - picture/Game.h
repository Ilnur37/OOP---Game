#pragma once
#include "Point.h"
#include "Projectile.h"

//Игра
class Game
{
public:
	//Две функции управления кораблями для двух пользователей
	void Gamer1(Point* object1, int& borders, bool& End);
	void Gamer2(Point* object2, int& borders, bool& End);

	//Функции выстрела для двух кораблей
	void Shoot1(Projectile* proj, int& borders, bool& End);
	void Shoot2(Projectile* proj, int& borders, bool& End);
};