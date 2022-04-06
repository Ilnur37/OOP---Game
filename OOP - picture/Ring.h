#pragma once
#include "Ellips.h"

class Ring : public Ellips
{
protected:
	int RingW;       //толщина кольца
public:
	Ring(int X1, int Y1, int RadiusX, int RadiusY, int RingW);
	Ring(int X1, int Y1, int Radius, int RangW);
	~Ring();

	void Show() override;		 //показать фигуру
	void Hide() override;		 //скрыть фигуру

	int GetW();					 //получить толщину  ќЋ№÷ј
	void Width(int DeltaWide);    //изменить толщину  ќЋ№÷ј
};