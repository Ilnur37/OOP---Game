#pragma once
#include "Location.h"
#include <mutex>
#include <cmath>
#include <thread>

class Point : public Location
{
public:
	Point();
	Point(int X1, int Y1, int coeff);
	~Point();

	virtual void Show();
	virtual void Hide();

	void MoveTo(int X1, int Y1);
	void Drag1();			//буксировка фигуры

	void Gamer1(Point* object1, bool& End);
	void Gamer2(Point* object2, bool& End);
};