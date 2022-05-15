#pragma once
#include "Projectile.h"

//Класс бронебойных снарядов
class ArmorPiercing : public Projectile
{
public:
	ArmorPiercing();

	//Выстрел из орудия первого игрока
	void ShootFromLeft(int& borders, bool& End) override;
	//Выстрел из орудия второго игрока
	void ShootFromRight(int& borders, bool& End) override;
};