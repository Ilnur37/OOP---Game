#include "Boat.h"

Boat::Boat(int X1, int Y1, int coeff) : Carcass(X1, Y1, coeff)
{
}

Boat::~Boat()
{
}

void Boat::Show()
{
	Carcass::Show();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 10 * coeff, Y1 - 18 * abs(coeff), X1 + 11 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 + 10 * coeff, Y1 - 17 * abs(coeff), NULL);
	LineTo(hdc, X1 + 6 * coeff, Y1 - 14 * abs(coeff));
	MoveToEx(hdc, X1 + 10 * coeff, Y1 - 11 * abs(coeff), NULL);
	LineTo(hdc, X1 + 6 * coeff, Y1 - 14 * abs(coeff));

	Rectangle(hdc, X1 + 3 * coeff, Y1 - 15 * abs(coeff), X1 + 4 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 + 3 * coeff, Y1 - 15 * abs(coeff), NULL);
	LineTo(hdc, X1 , Y1 - 13 * abs(coeff));
	MoveToEx(hdc, X1 + 3 * coeff, Y1 - 11 * abs(coeff), NULL);
	LineTo(hdc, X1 , Y1 - 13 * abs(coeff));

	DeleteObject(PenR);
}

void Boat::Hide()
{
	Carcass::Hide();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 10 * coeff, Y1 - 17 * abs(coeff), X1 + 11 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 + 10 * coeff, Y1 - 17 * abs(coeff), NULL);
	LineTo(hdc, X1 + 6 * coeff, Y1 - 14 * abs(coeff));
	MoveToEx(hdc, X1 + 10 * coeff, Y1 - 11 * abs(coeff), NULL);
	LineTo(hdc, X1 + 6 * coeff, Y1 - 14 * abs(coeff));

	Rectangle(hdc, X1 + 3 * coeff, Y1 - 15 * abs(coeff), X1 + 4 * coeff, Y1 - 8 * abs(coeff));
	MoveToEx(hdc, X1 + 3 * coeff, Y1 - 15 * abs(coeff), NULL);
	LineTo(hdc, X1, Y1 - 13 * abs(coeff));
	MoveToEx(hdc, X1 + 3 * coeff, Y1 - 11 * abs(coeff), NULL);
	LineTo(hdc, X1, Y1 - 13 * abs(coeff));

	DeleteObject(PenR);
}