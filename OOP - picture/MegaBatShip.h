#pragma once
#include "SuperBatShip.h"

//Класс корабля №3
class MegaBatShip : public SuperBatShip
{
public:
	MegaBatShip(int X1, int Y1, int coeff);
	~MegaBatShip();

	void Show() override;
	void Hide() override;
};