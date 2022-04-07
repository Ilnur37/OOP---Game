#include "Deck.h"

Deck::Deck(int X1, int Y1, int coeff) : Carcass(X1, Y1, coeff)
{
}

Deck::~Deck()
{
}

void Deck::Show()
{
	Carcass::Show();
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 2 * coeff, Y1 - 12 * coeff, X1 + 6 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 6 * coeff, Y1 - 18 * coeff, X1 + 10 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 10 * coeff, Y1 - 16 * coeff, X1 + 14 * coeff, Y1 - 8 * coeff);

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Deck::Hide()
{
	Carcass::Hide();
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 2 * coeff, Y1 - 12 * coeff, X1 + 6 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 6 * coeff, Y1 - 18 * coeff, X1 + 10 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 10 * coeff, Y1 - 16 * coeff, X1 + 14 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 17 * coeff, Y1 - 11 * coeff, X1 + 21 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 21 * coeff, Y1 - 10 * coeff, X1 + 26 * coeff, Y1 - 9 * coeff);

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}
