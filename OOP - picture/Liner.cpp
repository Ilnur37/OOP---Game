#include "Liner.h"

Liner::Liner(int X1, int Y1, int coeff) : Deck(X1, Y1, coeff)
{
}

Liner::~Liner()
{
}

void Liner::Show()
{
	Deck::Show();
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1 + 3 * coeff, Y1 - 11 * coeff, X1 + 5 * coeff, Y1 - 10 * coeff);
	Rectangle(hdc, X1 + 3 * coeff, Y1 - 9 * coeff, X1 + 5 * coeff, Y1 - 8 * coeff);

	Rectangle(hdc, X1 + 7 * coeff, Y1 - 17 * coeff, X1 + 9 * coeff, Y1 - 16 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 15 * coeff, X1 + 9 * coeff, Y1 - 14 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 13 * coeff, X1 + 9 * coeff, Y1 - 12 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 11 * coeff, X1 + 9 * coeff, Y1 - 10 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 9 * coeff, X1 + 9 * coeff, Y1 - 8 * coeff);
	
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 15 * coeff, X1 + 13 * coeff, Y1 - 14 * coeff);
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 13 * coeff, X1 + 13 * coeff, Y1 - 12 * coeff);
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 11 * coeff, X1 + 13 * coeff, Y1 - 10 * coeff);
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 9 * coeff, X1 + 13 * coeff, Y1 - 8 * coeff);

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Liner::Hide()
{
	Deck::Hide();
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//сделаем перо активным

	

	// ”ничтожим нами созданные объекты  
	DeleteObject(PenR);
}
