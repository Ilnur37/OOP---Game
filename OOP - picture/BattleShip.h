#pragma once
#include "Deck.h"

class BattleShip : public Deck
{
public:
	BattleShip(int X1, int Y1, int coeff);
	~BattleShip();

	void Show() override;
	void Hide() override;
};