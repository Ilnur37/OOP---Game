#pragma once
#include "Carcass.h"
#include <wincrypt.h>

class Deck : public Carcass
{
public:
	Deck(int X1, int Y1, int coeff);
	~Deck();

	void Show() override;
	void Hide() override;
};