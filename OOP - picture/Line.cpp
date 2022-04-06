#include "Line.h"

Line::Line(int X1, int Y1, int X2, int Y2) : Point(X1, Y1)
{
	this->X2 = X2;
	this->Y2 = Y2;
}

Line::~Line()
{
}

int Line::GetX2() { return X2; }

int Line::GetY2() { return Y2; }

void Line::Show()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным
	
	MoveToEx(hdc, X1, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X2, Y2);
	
	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Line::Hide()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X2, Y2);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Line::MoveTo(int X1, int Y1, int X2, int Y2)
{
	Hide();
	this->X1 = X1;
	this->Y1 = Y1;
	this->X2 = X2;
	this->Y2 = Y2;
	Show();
}

void Line::Drag(int Step)
{
	int FigX1, FigY1, FigX2, FigY2;   //новые координаты фигуры

	FigX1 = GetX1();    //получаем начальное положение фигуры
	FigY1 = GetY1();
	FigX2 = GetX2();
	FigY2 = GetY2();

	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
			break;

		//направление движения объекта

		if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			for (int i = 0; i < Step; i++) {
				FigX1--;
				FigX2--;

				MoveTo(FigX1, FigY1, FigX2, FigY2);
				Sleep(50);
			}
		}

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			for (int i = 0; i < Step; i++) {
				FigX1++;
				FigX2++;

				MoveTo(FigX1, FigY1, FigX2, FigY2);
				Sleep(50);
			}
		}

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			for (int i = 0; i < Step; i++) {
				FigY1++;
				FigY2++;

				MoveTo(FigX1, FigY1, FigX2, FigY2);
				Sleep(50);
			}
		}

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			for (int i = 0; i < Step; i++) {
				FigY1--;
				FigY2--;

				MoveTo(FigX1, FigY1, FigX2, FigY2);
				Sleep(50);
			}
		}
	}
}
