#include "Ellips.h"

Ellips::Ellips(int X1, int Y1, int RadiusX, int RadiusY) : Point(X1, Y1)
{
	this->RadiusX = RadiusX;
	this->RadiusY = RadiusY;
}

Ellips::Ellips(int X1, int Y1, int Radius) : Point(X1, Y1)
{
	RadiusX = Radius;
	RadiusY = Radius;
}

Ellips::~Ellips()
{
}

void Ellips::Show()
{
	// Зададим перо и цвет пера - красный
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	//HDC dc = GetDC(hwnd);
	//SelectObject(dc, GetStockObject(DC_BRUSH));
	//SetDCBrushColor(dc, RGB(255, 0, 255));
	// 
	// Нарисуем круг установленным цветом
	Ellipse(hdc, X1 - RadiusX, Y1 - RadiusY, X1 + RadiusX, Y1 + RadiusY);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);
}

void Ellips::Hide()
{
	// Зададим перо и цвет пера
	HPEN PenB = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenB);

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X1 - RadiusX, Y1 - RadiusY, X1 + RadiusX, Y1 + RadiusY);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenB);
}

void Ellips::Expand(int DeltaRad)
{

	while (1)   //цикл опроса клавиатуры
	{
		if (KEY_DOWN(VK_ESCAPE))        //конец работы
			break;

		//направление изменения толщины кольца
		if (KEY_DOWN(107))     //серый +      увеличение
		{
			Hide();
			RadiusX += DeltaRad; //изменить радиус 
			RadiusY += DeltaRad;
			Show();
			Sleep(200);
		}

		if (KEY_DOWN(109))     //серый -      уменьшение
		{
			Hide();
			RadiusX -= DeltaRad; //изменить радиус 
			RadiusY -= DeltaRad;
			if ((RadiusX < 0) || (RadiusY < 0)) {
				RadiusX += DeltaRad; //изменить радиус 
				RadiusY += DeltaRad;
			}
			Show();
			Sleep(200);
		}
	}

	//Hide();             //спрятать окружность со старым радиусом
	//RadiusX += DeltaRad; //изменить радиус 
	//RadiusY += DeltaRad;
	//if ((RadiusX < 0) || (RadiusY < 0)) {     //для отрицательного приращения радиуса
	//	RadiusX = 5;
	//	RadiusY = 5;
	//}
	//Show();             //показать окружность с новым радиусом
}

void Ellips::Reduce(int DeltaRad)
{
	Expand(-DeltaRad); //отрицательное приращение радиуса
}
