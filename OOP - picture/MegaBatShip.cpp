#include "MegaBatShip.h"

MegaBatShip::MegaBatShip(int X1, int Y1, int coeff) : SuperBatShip(X1, Y1, coeff)
{
	this->Armor = 15;
	this->Speed = 3;
}

MegaBatShip::~MegaBatShip()
{
}

void MegaBatShip::Show()
{
	SuperBatShip::Show();

	Rectangle(hdc, X1 - 3 * coeff, Y1 - 10.5 * abs(coeff), X1 + 1 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 - 7 * coeff, Y1 - 10 * abs(coeff), X1 - 3 * coeff, Y1 - 9 * abs(coeff));
}

void MegaBatShip::Hide()
{
	SuperBatShip::Hide();

	Rectangle(hdc, X1 - 3 * coeff, Y1 - 10.5 * abs(coeff), X1 + 1 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 - 7 * coeff, Y1 - 10 * abs(coeff), X1 - 3 * coeff, Y1 - 9 * abs(coeff));
}
