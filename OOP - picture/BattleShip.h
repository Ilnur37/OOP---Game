#pragma once
#include "Carcass.h"

class BattleShip : public Carcass
{
public:
	BattleShip(int X1, int Y1, int coeff);
	~BattleShip();

	void Show() override;
	void Hide() override;
};