#pragma once
#include "BattleShip.h"

//����� ������� �2
class SuperBatShip : public BattleShip
{
public:
	SuperBatShip(int X1, int Y1, int coeff);
	~SuperBatShip();

	void Show() override;
	void Hide() override;
};