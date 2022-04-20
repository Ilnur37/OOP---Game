#pragma once
#include "Location.h"
#include <mutex>
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
};