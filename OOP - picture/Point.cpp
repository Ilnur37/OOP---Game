#include "Point.h"

std::mutex mtx1;

Point::Point()
{
}

Point::Point(int X1, int Y1, int coeff) : Location(X1, Y1, coeff)
{
}

Point::~Point()
{
}

void Point::Show()
{
	SetPixel(hdc, X1, Y1, RGB(255, 0, 0));
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

void Point::Drag1()
{
	int FigX1, FigY1;   //новые координаты фигуры

	FigX1 = GetX1();    //получаем начальное положение фигуры
	FigY1 = GetY1();

	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
			break;

		//направление движения объекта

		if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			FigX1--;
			MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			FigX1++;
			MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			FigY1++;
			MoveTo(FigX1, FigY1);
			Sleep(10);
			
		}

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			FigY1--;
			MoveTo(FigX1, FigY1);
			Sleep(10);
		}
	}
}

void Point::Gamer1(Point* object1, bool& End)
{
	int FigX1, FigY1;   //новые координаты фигуры

	FigX1 = object1->GetX1();    //получаем начальное положение фигуры
	FigY1 = object1->GetY1();

	while (!End)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(0x41)) //стрелка влево  37
		{
			FigX1 -= 5;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x44)) //стрелка вправо  39
		{
			FigX1 += 5;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x53)) //стрелка вниз  40
		{
			FigY1 += 5;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);

		}

		if (KEY_DOWN(0x57)) //стрелка вверх  38
		{
			FigY1 -= 5;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}
	}
}

void Point::Gamer2(Point* object2, bool& End)
{
	int FigX2, FigY2;   //новые координаты фигур
	bool flag = 0;

	FigX2 = object2->GetX1();    //получаем начальное положение фигуры
	FigY2 = object2->GetY1();

	while (!End)	//бесконечный цикл буксировки фигуры
	{
		//направление движения объекта

		if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			FigX2 -= 5;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			FigX2 += 5;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			FigY2 += 5;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			FigY2 -= 5;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}
	}
}