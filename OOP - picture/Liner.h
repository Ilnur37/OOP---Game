#pragma once
#include "Deck.h"
class Liner : public Deck
{
public:
	Liner(int X1, int Y1, int coeff);
	~Liner();

	void Show() override;
	void Hide() override;
};