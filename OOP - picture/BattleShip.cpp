#include "BattleShip.h"

BattleShip::BattleShip(int X1, int Y1, int coeff) : Carcass(X1, Y1, coeff)
{
	this->HealthPoint = 150;
	this->Armor = 0;
	this->Speed = 7;
}

BattleShip::~BattleShip()
{
}

void BattleShip::Show()
{
	Carcass::Show();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 2 * coeff, Y1 - 12 * abs(coeff), X1 + 6 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 + 6 * coeff, Y1 - 18 * abs(coeff), X1 + 10 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 + 10 * coeff, Y1 - 16 * abs(coeff), X1 + 14 * coeff, Y1 - 8 * abs(coeff));

	Rectangle(hdc, X1 + 17 * coeff, Y1 - 11 * abs(coeff), X1 + 21 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 + 21 * coeff, Y1 - 10 * abs(coeff), X1 + 26 * coeff, Y1 - 9 * abs(coeff));

	Ellipse(hdc, X1 + 7 * coeff, Y1 - 6 * abs(coeff), X1 + 11 * coeff, Y1 - 2 * abs(coeff));
	Ellipse(hdc, X1 + 2 * coeff, Y1 - 6 * abs(coeff), X1 + 6 * coeff, Y1 - 2 * abs(coeff));
	Ellipse(hdc, X1 + 12 * coeff, Y1 - 6 * abs(coeff), X1 + 16 * coeff, Y1 - 2 * abs(coeff));

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void BattleShip::Hide()
{
	Carcass::Hide();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 2 * coeff, Y1 - 12 * abs(coeff), X1 + 6 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 + 6 * coeff, Y1 - 18 * abs(coeff), X1 + 10 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 + 10 * coeff, Y1 - 16 * abs(coeff), X1 + 14 * coeff, Y1 - 8 * abs(coeff));

	Rectangle(hdc, X1 + 17 * coeff, Y1 - 11 * abs(coeff), X1 + 21 * coeff, Y1 - 8 * abs(coeff));
	Rectangle(hdc, X1 + 21 * coeff, Y1 - 10 * abs(coeff), X1 + 26 * coeff, Y1 - 9 * abs(coeff));

	Ellipse(hdc, X1 + 7 * coeff, Y1 - 6 * abs(coeff), X1 + 11 * coeff, Y1 - 2 * abs(coeff));
	Ellipse(hdc, X1 + 2 * coeff, Y1 - 6 * abs(coeff), X1 + 6 * coeff, Y1 - 2 * abs(coeff));
	Ellipse(hdc, X1 + 12 * coeff, Y1 - 6 * abs(coeff), X1 + 16 * coeff, Y1 - 2 * abs(coeff));

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}