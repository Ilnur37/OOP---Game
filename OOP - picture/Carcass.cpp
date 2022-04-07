#include "Carcass.h"

Carcass::Carcass(int X1, int Y1, int coeff):Point(X1, Y1)
{
	this->coeff = coeff;
}

Carcass::~Carcass()
{
}

void Carcass::Show()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 18 * coeff, Y1);
	MoveToEx(hdc, X1 + 18 * coeff, Y1, NULL);
	LineTo(hdc, X1 + 22 * coeff, Y1 - 8 * coeff);
	MoveToEx(hdc, X1 + 22 * coeff, Y1 - 8 * coeff, NULL);
	LineTo(hdc, X1 - 4 * coeff, Y1 - 8 * coeff);
	MoveToEx(hdc, X1 - 4 * coeff, Y1 - 8 * coeff, NULL);
	LineTo(hdc, X1, Y1);

	Ellipse(hdc, X1 + 7 * coeff, Y1 - 6 * coeff, X1 + 11 * coeff, Y1 - 2 * coeff);
	Ellipse(hdc, X1 + 2 * coeff, Y1 - 6 * coeff, X1 + 6 * coeff, Y1 - 2 * coeff);
	Ellipse(hdc, X1 + 12 * coeff, Y1 - 6 * coeff, X1 + 16 * coeff, Y1 - 2 * coeff);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Carcass::Hide()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 18 * coeff, Y1);
	MoveToEx(hdc, X1 + 18 * coeff, Y1, NULL);
	LineTo(hdc, X1 + 22 * coeff, Y1 - 8 * coeff);
	MoveToEx(hdc, X1 + 22 * coeff, Y1 - 8 * coeff, NULL);
	LineTo(hdc, X1 - 4 * coeff, Y1 - 8 * coeff);
	MoveToEx(hdc, X1 - 4 * coeff, Y1 - 8 * coeff, NULL);
	LineTo(hdc, X1, Y1);

	Ellipse(hdc, X1 + 7 * coeff, Y1 - 6 * coeff, X1 + 11 * coeff, Y1 - 2 * coeff);
	Ellipse(hdc, X1 + 20, Y1 - 6 * coeff, X1 + 6 * coeff, Y1 - 2 * coeff);
	Ellipse(hdc, X1 + 12 * coeff, Y1 - 6 * coeff, X1 + 16 * coeff, Y1 - 2 * coeff);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}