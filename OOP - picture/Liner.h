#pragma once
#include "Carcass.h"
class Liner : public Carcass
{
public:
	Liner(int X1, int Y1, int coeff);
	~Liner();

	void Show() override;
	void Hide() override;
};