#pragma once
#include "Location.h"
#include <mutex>
#include <cmath>
#include <chrono>
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

	void Gamer1(Point* object1, int& borders, bool& End);
	void Gamer2(Point* object2, int& borders, bool& End);
};