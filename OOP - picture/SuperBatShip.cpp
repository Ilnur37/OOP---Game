#include "SuperBatShip.h"

SuperBatShip::SuperBatShip(int X1, int Y1, int coeff) : BattleShip(X1, Y1, coeff)
{
	this->Armor = 7;
	this->Speed = 5;
}

SuperBatShip::~SuperBatShip()
{
}

void SuperBatShip::Show()
{
	BattleShip::Show();

	//HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	//SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1 + 2 * coeff, Y1 - 11 * abs(coeff), NULL);
	LineTo(hdc, X1 - 2 * coeff, Y1 - 13 * abs(coeff));
	MoveToEx(hdc, X1 + 2 * coeff, Y1 - 10.5 * abs(coeff), NULL);
	LineTo(hdc, X1 - 2 * coeff, Y1 - 12.5 * abs(coeff));
	MoveToEx(hdc, X1 - 2 * coeff, Y1 - 12.5 * abs(coeff), NULL);
	LineTo(hdc, X1 - 2 * coeff, Y1 - 13 * abs(coeff));

	MoveToEx(hdc, X1 + 14 * coeff, Y1 - 15 * abs(coeff), NULL);
	LineTo(hdc, X1 + 19 * coeff, Y1 - 17 * abs(coeff));
	MoveToEx(hdc, X1 + 14 * coeff, Y1 - 14.5 * abs(coeff), NULL);
	LineTo(hdc, X1 + 19 * coeff, Y1 - 16.5 * abs(coeff));
	MoveToEx(hdc, X1 + 19 * coeff, Y1 - 17 * abs(coeff), NULL);
	LineTo(hdc, X1 + 19 * coeff, Y1 - 16.5 * abs(coeff));

	//DeleteObject(PenR);
}

void SuperBatShip::Hide()
{
	BattleShip::Hide();

	//HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, X1 + 2 * coeff, Y1 - 11 * abs(coeff), NULL);
	LineTo(hdc, X1 - 2 * coeff, Y1 - 13 * abs(coeff));
	MoveToEx(hdc, X1 + 2 * coeff, Y1 - 10.5 * abs(coeff), NULL);
	LineTo(hdc, X1 - 2 * coeff, Y1 - 12.5 * abs(coeff));
	MoveToEx(hdc, X1 - 2 * coeff, Y1 - 12.5 * abs(coeff), NULL);
	LineTo(hdc, X1 - 2 * coeff, Y1 - 13 * abs(coeff));

	MoveToEx(hdc, X1 + 14 * coeff, Y1 - 15 * abs(coeff), NULL);
	LineTo(hdc, X1 + 19 * coeff, Y1 - 17 * abs(coeff));
	MoveToEx(hdc, X1 + 14 * coeff, Y1 - 14.5 * abs(coeff), NULL);
	LineTo(hdc, X1 + 19 * coeff, Y1 - 16.5 * abs(coeff));
	MoveToEx(hdc, X1 + 19 * coeff, Y1 - 17 * abs(coeff), NULL);
	LineTo(hdc, X1 + 19 * coeff, Y1 - 16.5 * abs(coeff));

	//DeleteObject(PenR);
}