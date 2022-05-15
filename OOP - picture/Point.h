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

	virtual void Show();			//Показать объект
	virtual void Hide();			//Скрыть объект

	void MoveTo(int X1, int Y1);	//Перемещение объекта
};