#pragma once
#include "Point.h"

//Класс корпуса корабля
class Carcass : public Point
{
public:
	Carcass(int X1, int Y1, int coeff);
	~Carcass();

	void Show() override;
	void Hide() override;
};