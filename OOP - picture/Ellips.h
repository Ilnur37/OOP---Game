#pragma once
#include "Point.h"

class Ellips : public Point
{
protected:
	int RadiusX;
	int RadiusY;
public:
	Ellips(int X1, int Y1, int RadiusX, int RadiusY);
	Ellips(int X1, int Y1, int Radius);
	~Ellips();

	void Show() override;
	void Hide() override;

	//void MoveTo(int X1, int Y1);

	void Expand(int DeltaRad);
	void Reduce(int DeltaRad);
};