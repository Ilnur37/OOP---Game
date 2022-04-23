#include "Carcass.h"

Carcass::Carcass(int X1, int Y1, int coeff):Point(X1, Y1, coeff)
{
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
	LineTo(hdc, X1 + 22 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 + 22 * coeff, Y1 - 8 * abs(coeff), NULL);
	LineTo(hdc, X1 - 4 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 - 4 * coeff, Y1 - 8 * abs(coeff), NULL);
	LineTo(hdc, X1, Y1);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Carcass::Hide()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 18 * coeff, Y1);
	MoveToEx(hdc, X1 + 18 * coeff, Y1, NULL);
	LineTo(hdc, X1 + 22 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 + 22 * coeff, Y1 - 8 * abs(coeff), NULL);
	LineTo(hdc, X1 - 4 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 - 4 * coeff, Y1 - 8 * abs(coeff), NULL);
	LineTo(hdc, X1, Y1);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}