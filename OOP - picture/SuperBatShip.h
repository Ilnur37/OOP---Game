#pragma once
#include "BattleShip.h"

class SuperBatShip : public BattleShip
{
public:
	SuperBatShip(int X1, int Y1, int coeff);
	~SuperBatShip();

	void Show() override;
	void Hide() override;
};