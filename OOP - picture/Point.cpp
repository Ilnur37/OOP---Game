#include "Point.h"
std::mutex mtx1;

Point::Point()
{
}

Point::Point(int X1, int Y1, int coeff) : Location(X1, Y1, coeff)
{
}

void Point::Show()
{
	SetPixel(hdc, X1, Y1, RGB(255, 0, 0));
}

Point::~Point()
{
}

void Point::Hide()
{
	SetPixel(hdc, X1, Y1, RGB(255, 255, 255));
}

void Point::MoveTo(int X1, int Y1)
{
	mtx1.lock();
	Hide();
	this->X1 = X1;
	this->Y1 = Y1;
	Show();
	mtx1.unlock();
}

void Point::Gamer1(Point* object1, int& borders, bool& End)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 222, 173));
	SelectObject(hdc8, hBrush);	//сделаем перо активным

	int FigX1, FigY1;   //новые координаты фигуры
	int speed1;
	FigX1 = object1->GetX1();    //получаем начальное положение фигуры
	FigY1 = object1->GetY1();
	speed1 = object1->GetSpeed();
	while (!End)	//бесконечный цикл буксировки фигуры
	{
		Rectangle(hdc8, 0, 0, 1980, 0 + borders);
		Rectangle(hdc8, 0, 1080 - borders, 1980, 1080);
		if (KEY_DOWN(0x41)) //стрелка влево  37
		{
			FigX1 -= speed1;
			if (FigX1 - 40 < 0) FigX1 += speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x44)) //стрелка вправо  39
		{
			FigX1 += speed1;
			if (FigX1 + 220 > 1980) FigX1 -= speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x53)) //стрелка вниз  40
		{
			FigY1 += speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x57)) //стрелка вверх  38
		{
			FigY1 -= speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}
		if (FigY1 > 1080 - borders) FigY1 = 1080 - borders;
		if (FigY1 - 180 < 0 + borders) FigY1 = 180 + borders;
	}
}

void Point::Gamer2(Point* object2, int& borders, bool& End)
{
	int FigX2, FigY2;   //новые координаты фигур
	int speed2;
	bool flag = 0;

	FigX2 = object2->GetX1();    //получаем начальное положение фигуры
	FigY2 = object2->GetY1();
	speed2 = object2->GetSpeed();

	while (!End)	//бесконечный цикл буксировки фигуры
	{
		//направление движения объекта

		if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			FigX2 -= speed2;
			if (FigX2 - 220 < 0) FigX2 += speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			FigX2 += speed2;
			if (FigX2 + 40 > 1980) FigX2 -= speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			FigY2 += speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			FigY2 -= speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}
		if (FigY2 > 1080 - borders) FigY2 = 1080 - borders;
		if (FigY2 - 180 < 0 + borders) FigY2 = 180 + borders;
	}
}