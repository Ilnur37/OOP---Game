#pragma once
#include <vector>
#include "Point.h"

extern std::vector <ILocation*> vector_of_objects;

//Абстрактный класс снарядов
class Projectile
{
protected:
	int damage;		//поле урона

public:
	int GetDamage();

	//Выстрел из орудия первого игрока
	virtual void ShootFromLeft(int& borders, bool& End) = 0;
	//Выстрел из орудия второго игрока
	virtual void ShootFromRight(int& borders, bool& End) = 0;
	//Разрушение корабля
	void Crush(ILocation* object, int x, int y, bool& End, bool placeHP);
};