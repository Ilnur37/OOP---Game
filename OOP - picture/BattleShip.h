#pragma once
#include "Carcass.h"

//����� ������� �1
class BattleShip : public Carcass
{
public:
	BattleShip(int X1, int Y1, int coeff);
	~BattleShip();

	void Show() override;
	void Hide() override;
};