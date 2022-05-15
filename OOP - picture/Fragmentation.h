#pragma once
#include "Projectile.h"

//Класс осколочных снарядов
class Fragmentation : public Projectile
{
public:
	Fragmentation();

	//Выстрел из орудия первого игрока
	void ShootFromLeft(int& borders, bool& End) override;
	//Выстрел из орудия второго игрока
	void ShootFromRight(int& borders, bool& End) override;
};