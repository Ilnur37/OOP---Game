#pragma once
#include "Location.h"

class Point : public Location
{
private:
	//int speed;
public:
	Point(int X1, int Y1);
	~Point();

	virtual void Show();
	virtual void Hide();

	void MoveTo(int X1, int Y1);
	void Drag(int Step);			//буксировка фигуры
};