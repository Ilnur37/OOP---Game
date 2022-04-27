#include "ArmorPiercing.h"

std::mutex mtx3;

void ArmorPiercing::ShootApFromLeft(bool& End)
{
	Sleep(10);
	HPEN PenR11 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HPEN PenW11 = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hBrush3 = CreateSolidBrush(RGB(255, 255, 255));
	while (!End)	//бесконечный цикл буксировки фигуры
	{
		SelectObject(hdc6, hBrush);	//сделаем перо активным
		Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[1]->GetHealth(), 80);
		if (KEY_DOWN(VK_TAB))
		{
			int a1 = vector_of_objects[0]->GetX1() + 26.5 * vector_of_objects[0]->GetCoeff();
			int b1 = vector_of_objects[0]->GetY1() - 10 * abs(vector_of_objects[0]->GetCoeff());
			bool flag = 0;

			while (a1 < 1850) {
				Sleep(1);
				SelectObject(hdc2, PenR11);	//сделаем перо активным
				Rectangle(hdc2, a1, b1, a1 + 20, b1 + 7);

				Sleep(10);
				SelectObject(hdc2, PenW11);	//сделаем перо активным
				Rectangle(hdc2, a1, b1, a1 + 20, b1 + 7);

				for (int i = 0; i < vector_of_objects.size(); i++)
				{
					int tempC1 = vector_of_objects[i]->GetCoeff();
					int tempX1 = vector_of_objects[i]->GetX1();
					int tempY1 = vector_of_objects[i]->GetY1();
					if (((a1 + 20 > tempX1 + 18 * tempC1) && (a1 < tempX1) &&
						(b1 < tempY1) && (b1 + 7 > tempY1 + 8 * tempC1)) ||
						((a1 + 20 > tempX1 + 13 * tempC1) && (a1 < tempX1 + 3 * tempC1) &&
						(b1 < tempY1 + 8 * tempC1) && (b1 + 7 > tempY1 + 18 * tempC1)))
					{
						SelectObject(hdc6, hBrush3);	//сделаем перо активным
						Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[i]->GetHealth(), 80);

						vector_of_objects[i]->SetHealth(vector_of_objects[i]->GetHealth() - 50 + vector_of_objects[i]->GetArmor());

						SelectObject(hdc6, hBrush);	//сделаем перо активным
						Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[i]->GetHealth(), 80);

						CrushAP(vector_of_objects[i], tempX1 + 9 * tempC1, tempY1 - 9 * abs(tempC1), End);
						flag = 1;
					}
				}
				if (flag) break;
				a1 += 25;
			}
		}
	}
	DeleteObject(PenR11);
	DeleteObject(PenW11);
	DeleteObject(hBrush);
	DeleteObject(hBrush3);
	Sleep(10);
}

void ArmorPiercing::ShootApFromRight(bool& End)
{
	HPEN PenR22 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HPEN PenW22 = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hBrush3 = CreateSolidBrush(RGB(255, 255, 255));
	while (!End)	//бесконечный цикл буксировки фигуры
	{
		SelectObject(hdc7, hBrush);	//сделаем перо активным
		Rectangle(hdc7, 40, 40, 40 + vector_of_objects[0]->GetHealth(), 80);
		if (KEY_DOWN(VK_SHIFT))
		{
			int a2 = vector_of_objects[1]->GetX1() + 29.5 * vector_of_objects[1]->GetCoeff();
			int b2 = vector_of_objects[1]->GetY1() - 10 * abs(vector_of_objects[1]->GetCoeff());
			bool flag = 0;

			while (a2 > 100) {
				Sleep(1);
				SelectObject(hdc3, PenR22);	//сделаем перо активным
				Rectangle(hdc3, a2, b2, a2 + 20, b2 + 7);

				Sleep(10);
				SelectObject(hdc3, PenW22);	//сделаем перо активным
				Rectangle(hdc3, a2, b2, a2 + 20, b2 + 7);

				for (int i = 0; i < vector_of_objects.size(); i++)
				{
					int tempC2 = vector_of_objects[i]->GetCoeff();
					int tempX2 = vector_of_objects[i]->GetX1();
					int tempY2 = vector_of_objects[i]->GetY1();
					if (((a2 < tempX2 + 18 * tempC2) && (a2 + 20 > tempX2) &&
						(b2 < tempY2) && (b2 + 7 > tempY2 - 8 * tempC2)) ||
						((a2 < tempX2 + 13 * tempC2) && (a2 + 20 > tempX2 + 3 * tempC2) &&
						(b2 < tempY2 - 8 * tempC2) && (b2 + 7 > tempY2 - 18 * tempC2)))
					{
						SelectObject(hdc7, hBrush3);	//сделаем перо активным
						Rectangle(hdc7, 40, 40, 40 + vector_of_objects[i]->GetHealth(), 80);

						vector_of_objects[i]->SetHealth(vector_of_objects[i]->GetHealth() - 50 + vector_of_objects[i]->GetArmor());

						SelectObject(hdc7, hBrush);	//сделаем перо активным
						Rectangle(hdc7, 40, 40, 40 + vector_of_objects[i]->GetHealth(), 80);

						CrushAP(vector_of_objects[i], tempX2 + 9 * tempC2, tempY2 - 9 * abs(tempC2), End);
						flag = 1;
					}
				}
				if (flag) break;
				a2 -= 25;
			}
		}
	}
	DeleteObject(PenR22);
	DeleteObject(PenW22);
	DeleteObject(hBrush);
	DeleteObject(hBrush3);
	Sleep(10);
}

void ArmorPiercing::CrushAP(Point* object, int x, int y, bool& End)
{
	mtx3.lock();
	
	if (object->GetHealth() <= 0) {
		HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 255, 0)); //задаём сплошную кисть
		HBRUSH hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); //задаём сплошную кисть
		HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

		SelectObject(hdc4, hBrush1); //делаем кисть активной
		for (int i = 20; i <= 100; i += 20)
		{
			Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
			Sleep(40);
		}

		SelectObject(hdc4, hBrush2); //делаем кисть активной
		for (int i = 120; i < 240; i += 20)
		{
			Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
			Sleep(40);
		}
		Sleep(50);

		SelectObject(hdc5, Pen);	//сделаем перо активным
		Ellipse(hdc5, x - 172, y - 120, x + 160, y + 120);

		SelectObject(hdc5, PenR);	//сделаем перо активным

		MoveToEx(hdc5, x - 30, y + 10, NULL);
		LineTo(hdc5, x - 130, y + 10);
		MoveToEx(hdc5, x - 130, y + 10, NULL);
		LineTo(hdc5, x - 90, y + 90);
		MoveToEx(hdc5, x - 90, y + 90, NULL);
		LineTo(hdc5, x - 30, y + 90);
		MoveToEx(hdc5, x - 30, y + 90, NULL);
		LineTo(hdc5, x - 50, y + 50);
		MoveToEx(hdc5, x - 50, y + 50, NULL);
		LineTo(hdc5, x - 30, y + 10);

		MoveToEx(hdc5, x, y + 10, NULL);
		LineTo(hdc5, x + 100, y + 10);
		MoveToEx(hdc5, x + 100, y + 10, NULL);
		LineTo(hdc5, x + 60, y + 90);
		MoveToEx(hdc5, x + 60, y + 90, NULL);
		LineTo(hdc5, x, y + 90);
		MoveToEx(hdc5, x, y + 90, NULL);
		LineTo(hdc5, x - 20, y + 50);
		MoveToEx(hdc5, x - 20, y + 50, NULL);
		LineTo(hdc5, x, y + 10);

		// Уничтожим нами созданные объекты  
		DeleteObject(PenR);
		DeleteObject(hBrush1);
		DeleteObject(hBrush2);
		DeleteObject(Pen);
		End = 1;
	}
	mtx3.unlock();
}