#pragma once
#include "Point.h"
#include <cmath>

class Carcass : public Point
{
protected:
	int coeff;
public:
	Carcass(int X1, int Y1, int coeff);
	~Carcass();

	void Show() override;
	void Hide() override;
};