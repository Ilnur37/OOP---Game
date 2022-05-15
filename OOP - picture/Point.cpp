#include "Point.h"

/* Мьютекс используется
для блокировки одного из потоков
в функции MoveTo */
std::mutex mtx1;

Point::Point()
{
}

Point::Point(int X1, int Y1, int coeff)
{
	this->X1 = X1;
	this->Y1 = Y1;
	this->coeff = coeff;
}

Point::~Point()
{
}

//Показать объект
void Point::Show()
{
	SetPixel(hdc, X1, Y1, RGB(255, 0, 0));
}

//Скрыть объект
void Point::Hide()
{
	SetPixel(hdc, X1, Y1, RGB(255, 255, 255));
}

//Перемещение объекта
void Point::MoveTo(int X1, int Y1)
{
	mtx1.lock();		
	Hide();
	this->X1 = X1;
	this->Y1 = Y1;
	Show();
	mtx1.unlock();
}

int Point::GetX1() { return X1; }

int Point::GetY1() { return Y1; }

int Point::GetCoeff() { return coeff; }

int Point::GetHealth() { return HealthPoint; }

int Point::GetArmor() { return Armor; }

int Point::GetSpeed() { return Speed; }

void Point::SetHealth(int point) { this->HealthPoint = point; }