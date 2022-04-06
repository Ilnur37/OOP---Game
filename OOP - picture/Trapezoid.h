#pragma once
#include "Line.h"
class Trapezoid : public Line
{
protected:
	int X3, Y3, X4, Y4;
public:
	Trapezoid(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	~Trapezoid();

	int GetX3();
	int GetY3();
	int GetX4();
	int GetY4();
	virtual void Show();
	virtual void Hide();

	void MoveTo(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void Drag(int Step) override;			//буксировка фигуры
};