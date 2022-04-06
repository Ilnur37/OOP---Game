#pragma once
#include "Point.h"

class Line : public Point
{
protected:
	int X2, Y2;
public:
	Line(int X1, int Y1, int X2, int Y2);
	~Line();

	int GetX2();
	int GetY2();
	virtual void Show();
	virtual void Hide();

	void MoveTo(int X1, int Y1, int X2, int Y2);
	void Drag(int Step) override;			//буксировка фигуры
};