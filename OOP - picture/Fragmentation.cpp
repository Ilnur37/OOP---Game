#include "Fragmentation.h"

void Fragmentation::ShootFragmFromLeft()
{
	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_TAB))
		{
			Sleep(5);
			HPEN PenR11 = CreatePen(PS_SOLID, 3, RGB(139, 69, 19));
			HPEN PenW11 = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));

			int a1 = vector_of_objects[0]->GetX1() + 29.5 * vector_of_objects[0]->GetCoeff();
			int b1 = vector_of_objects[0]->GetY1() - 10 * abs(vector_of_objects[0]->GetCoeff());
			bool flag = 0;

			while (a1 < 1800) {

				Sleep(1);
				SelectObject(hdc2, PenR11);	//сделаем перо активным
				Rectangle(hdc2, a1, b1, a1 + 30, b1 + 13);

				Sleep(10);
				SelectObject(hdc2, PenW11);	//сделаем перо активным
				Rectangle(hdc2, a1, b1, a1 + 30, b1 + 13);

				for (int i = 0; i < vector_of_objects.size(); i++)
				{
					int tempC1 = vector_of_objects[i]->GetCoeff();
					int tempX1 = vector_of_objects[i]->GetX1();
					int tempY1 = vector_of_objects[i]->GetY1();
					if ((((a1 + 20 < (tempX1 + 10 * tempC1)) && (a1 + 20 > (tempX1 + 8 * tempC1))) ||
						((a1 + 20 > (tempX1 + 10 * tempC1)) && (a1 + 20 < (tempX1 + 8 * tempC1)))) &&
						(b1 > (tempY1 - 18 * abs(tempC1))) &&
						(b1 < (tempY1))) {

						CrushAP(tempX1 + 9 * tempC1, tempY1 - 9 * abs(tempC1));
						flag = 1;
					}
				}
				if (flag) break;
				a1 += 5;
			}
			DeleteObject(PenR11);
			DeleteObject(PenW11);
			Sleep(10);
		}
	}
}

void Fragmentation::ShootFragmFromRight()
{
	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_SHIFT))
		{
			Sleep(5);
			HPEN PenR22 = CreatePen(PS_SOLID, 3, RGB(139, 69, 19));
			HPEN PenW22 = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));

			int a2 = vector_of_objects[1]->GetX1() + 26.5 * vector_of_objects[1]->GetCoeff();
			int b2 = vector_of_objects[1]->GetY1() - 10 * abs(vector_of_objects[1]->GetCoeff());
			bool flag = 0;

			while (a2 > 200) {
				Sleep(1);
				SelectObject(hdc3, PenR22);	//сделаем перо активным
				Rectangle(hdc3, a2, b2, a2 + 30, b2 + 13);

				Sleep(10);
				SelectObject(hdc3, PenW22);	//сделаем перо активным
				Rectangle(hdc3, a2, b2, a2 + 30, b2 + 13);

				for (int i = 0; i < vector_of_objects.size(); i++)
				{
					int tempC2 = abs(vector_of_objects[i]->GetCoeff());
					int tempX2 = vector_of_objects[i]->GetX1();
					int tempY2 = vector_of_objects[i]->GetY1();
					if ((a2 > (tempX2 + 8 * tempC2)) &&
						(a2 < (tempX2 + 10 * tempC2)) &&
						(b2 > (tempY2 - 18 * tempC2)) &&
						(b2 < (tempY2))) {
						CrushAP(tempX2 + 9 * tempC2, tempY2 - 9 * tempC2);
						flag = 1;
					}
				}
				if (flag) break;
				a2 -= 5;
			}
			DeleteObject(PenR22);
			DeleteObject(PenW22);
			Sleep(10);
		}
	}
}

void Fragmentation::CrushFragm(int x, int y)
{
	HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 255, 0)); //задаём сплошную кисть
	HBRUSH hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); //задаём сплошную кисть
	HBRUSH hBrush3 = CreateSolidBrush(RGB(245, 245, 245)); //задаём сплошную кисть

	mtx3.lock();

	SelectObject(hdc4, hBrush1); //делаем кисть активной
	for (int i = 20; i <= 100; i += 20)
	{
		Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
		Sleep(30);
	}

	SelectObject(hdc4, hBrush2); //делаем кисть активной
	for (int i = 120; i < 240; i += 20)
	{
		Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
		Sleep(30);
	}
	Sleep(50);
	SelectObject(hdc4, hBrush3); //делаем кисть активной
	Ellipse(hdc4, x - 160, y - 120, x + 160, y + 120);

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//сделаем перо активным

	MoveToEx(hdc, x - 30, y + 10, NULL);
	LineTo(hdc, x - 130, y + 10);
	MoveToEx(hdc, x - 130, y + 10, NULL);
	LineTo(hdc, x - 90, y + 90);
	MoveToEx(hdc, x - 90, y + 90, NULL);
	LineTo(hdc, x - 30, y + 90);
	MoveToEx(hdc, x - 30, y + 90, NULL);
	LineTo(hdc, x - 50, y + 50);
	MoveToEx(hdc, x - 50, y + 50, NULL);
	LineTo(hdc, x - 30, y + 10);

	MoveToEx(hdc, x, y + 10, NULL);
	LineTo(hdc, x + 100, y + 10);
	MoveToEx(hdc, x + 100, y + 10, NULL);
	LineTo(hdc, x + 60, y + 90);
	MoveToEx(hdc, x + 60, y + 90, NULL);
	LineTo(hdc, x, y + 90);
	MoveToEx(hdc, x, y + 90, NULL);
	LineTo(hdc, x - 20, y + 50);
	MoveToEx(hdc, x - 20, y + 50, NULL);
	LineTo(hdc, x, y + 10);

	// Уничтожим нами созданные объекты  
	DeleteObject(PenR);

	mtx3.unlock();
}