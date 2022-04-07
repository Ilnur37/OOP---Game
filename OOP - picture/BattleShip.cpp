#include "BattleShip.h"

BattleShip::BattleShip(int X1, int Y1, int coeff) : Deck(X1, Y1, coeff)
{
}

BattleShip::~BattleShip()
{
}

void BattleShip::Show()
{
	Deck::Show();
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 17 * coeff, Y1 - 11 * coeff, X1 + 21 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 21 * coeff, Y1 - 10 * coeff, X1 + 26 * coeff, Y1 - 9 * coeff);

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void BattleShip::Hide()
{
	Deck::Hide();
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 17 * coeff, Y1 - 11 * coeff, X1 + 21 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 21 * coeff, Y1 - 10 * coeff, X1 + 26 * coeff, Y1 - 9 * coeff);

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}
