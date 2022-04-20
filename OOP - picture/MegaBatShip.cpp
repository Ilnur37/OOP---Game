#include "MegaBatShip.h"

MegaBatShip::MegaBatShip(int X1, int Y1, int coeff) : SuperBatShip(X1, Y1, coeff)
{
}

MegaBatShip::~MegaBatShip()
{
}

void MegaBatShip::Show()
{
	SuperBatShip::Show();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным


	Rectangle(hdc, X1 - 3 * coeff, Y1 - 10.5 * abs(coeff), X1 + 1 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 - 7 * coeff, Y1 - 10 * abs(coeff), X1 - 3 * coeff, Y1 - 9 * abs(coeff));

	DeleteObject(PenR);
}

void MegaBatShip::Hide()
{
	SuperBatShip::Hide();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(245, 245, 245));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 - 3 * coeff, Y1 - 10.5 * abs(coeff), X1 + 1 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 - 7 * coeff, Y1 - 10 * abs(coeff), X1 - 3 * coeff, Y1 - 9 * abs(coeff));

	DeleteObject(PenR);
}
