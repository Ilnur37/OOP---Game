#include "Rectan.h"

Rectan::Rectan(int X1, int Y1, int X2, int Y2) : Line(X1, Y1, X2, Y2)
{
}

Rectan::~Rectan()
{
}

void Rectan::Show()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1, Y1, X2, Y2);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Rectan::Hide()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//сделаем перо активным

	Rectangle(hdc, X1, Y1, X2, Y2);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}