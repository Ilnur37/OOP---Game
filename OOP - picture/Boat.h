#pragma once
#include "Carcass.h"

class Boat : public Carcass
{
public:
	Boat(int X1, int Y1, int coeff);
	~Boat();

	void Show() override;
	void Hide() override;
};