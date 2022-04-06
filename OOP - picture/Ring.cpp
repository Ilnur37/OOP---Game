#include "Ring.h"

Ring::Ring(int X1, int Y1, int RadiusX, int RadiusY, int RingW) : Ellips(X1, Y1, RadiusX, RadiusY)
{
	this->RingW = RingW;
}

Ring::Ring(int X1, int Y1, int Radius, int RingW) : Ellips(X1, Y1, Radius)
{
	this->RingW = RingW;
}

Ring::~Ring()
{
}

void Ring::Show()
{
	// Зададим перо и цвет пера - красный и ТОЛЩИНУ пера
	HPEN Pen = CreatePen(PS_SOLID, RingW, RGB(255, 0, 0));

	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем кольцо установленным цветом
	Ellipse(hdc, X1 - RadiusX, Y1 - RadiusY, X1 + RadiusX, Y1 + RadiusY);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}

void Ring::Hide()
{
	// Зададим перо и цвет пера - красный и ТОЛЩИНУ пера
	HPEN Pen = CreatePen(PS_SOLID, RingW, RGB(250, 250, 250));

	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем кольцо установленным цветом
	Ellipse(hdc, X1 - RadiusX, Y1 - RadiusY, X1 + RadiusX, Y1 + RadiusY);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}

int Ring::GetW()
{
	return RingW;
}

void Ring::Width(int DeltaWide)
{
	while (1)   //цикл опроса клавиатуры
	{
		if (KEY_DOWN(VK_ESCAPE))        //конец работы
			break;

		//направление изменения толщины кольца
		if (KEY_DOWN(107))     //серый +      увеличение
		{
			Hide();
			RingW += DeltaWide;
			Show();
			Sleep(200);
		}

		if (KEY_DOWN(109))     //серый -      уменьшение
		{
		Hide();
		RingW -= DeltaWide;
		if (RingW < 0)
			RingW = 1;
		Show();
		Sleep(200);
		}
	}
}