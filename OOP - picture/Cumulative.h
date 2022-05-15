#pragma once
#include "Projectile.h"

//Класс кумулятивных снарядов
class Cumulative : public Projectile
{
public:
	Cumulative();

	//Выстрел из орудия первого игрока
	void ShootFromLeft(int& borders, bool& End) override;
	//Выстрел из орудия второго игрока
	void ShootFromRight(int& borders, bool& End) override;
};