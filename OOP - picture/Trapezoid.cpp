#include "Trapezoid.h"

Trapezoid::Trapezoid(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4) : Line(X1, Y1, X2, Y2)
{
	this->X3 = X3;
	this->Y3 = Y3;
	this->X4 = X4;
	this->Y4 = Y4;
}

Trapezoid::~Trapezoid()
{
}

int Trapezoid::GetX3() { return X3; }

int Trapezoid::GetY3() { return Y3; }

int Trapezoid::GetX4() { return X4; }

int Trapezoid::GetY4() { return Y4; }

void Trapezoid::Show()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1, Y1, NULL); 
	LineTo(hdc, X2, Y2);
	MoveToEx(hdc, X2, Y2, NULL); 
	LineTo(hdc, X3, Y3);
	MoveToEx(hdc, X3, Y3, NULL); 
	LineTo(hdc, X4, Y4);
	MoveToEx(hdc, X4, Y4, NULL); 
	LineTo(hdc, X1, Y1);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Trapezoid::Hide()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1, Y1, NULL); 
	LineTo(hdc, X2, Y2);
	MoveToEx(hdc, X2, Y2, NULL); 
	LineTo(hdc, X3, Y3);
	MoveToEx(hdc, X3, Y3, NULL); 
	LineTo(hdc, X4, Y4);
	MoveToEx(hdc, X4, Y4, NULL); 
	LineTo(hdc, X1, Y1);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Trapezoid::MoveTo(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)
{
	Hide();
	this->X1 = X1;
	this->Y1 = Y1;
	this->X2 = X2;
	this->Y2 = Y2;
	this->X3 = X3;
	this->Y3 = Y3;
	this->X4 = X4;
	this->Y4 = Y4;
	Show();
}

void Trapezoid::Drag(int Step)
{
	int FigX1, FigY1, FigX2, FigY2, FigX3, FigY3, FigX4, FigY4;   //новые координаты фигуры

	FigX1 = GetX1(); FigY1 = GetY1();
	FigX2 = GetX2(); FigY2 = GetY2();
	FigX3 = GetX3(); FigY3 = GetY3();
	FigX4 = GetX4(); FigY4 = GetY4();

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
				FigX3--;
				FigX4--;

				MoveTo(FigX1, FigY1, FigX2, FigY2, FigX3, FigY3, FigX4, FigY4);
				Sleep(50);
			}
		}

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			for (int i = 0; i < Step; i++) {
				FigX1++;
				FigX2++;
				FigX3++;
				FigX4++;

				MoveTo(FigX1, FigY1, FigX2, FigY2, FigX3, FigY3, FigX4, FigY4);
				Sleep(50);
			}
		}

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			for (int i = 0; i < Step; i++) {
				FigY1++;
				FigY2++;
				FigY3++;
				FigY4++;

				MoveTo(FigX1, FigY1, FigX2, FigY2, FigX3, FigY3, FigX4, FigY4);
				Sleep(50);
			}
		}

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			for (int i = 0; i < Step; i++) {
				FigY1--;
				FigY2--;
				FigY3--;
				FigY4--;

				MoveTo(FigX1, FigY1, FigX2, FigY2, FigX3, FigY3, FigX4, FigY4);
				Sleep(50);
			}
		}
	}
}