#pragma once
#include "Line.h"

class Rectan : public Line
{
public:
	Rectan(int X1, int Y1, int X2, int Y2);
	~Rectan();

	void Show() override;
	void Hide() override;
};