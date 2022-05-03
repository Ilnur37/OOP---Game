#include "Fragmentation.h"

Fragmentation::Fragmentation()
{
	this->damage = 75;
}

void Fragmentation::ShootFromLeft(int& borders, bool& End)
{
	Sleep(10);
	HPEN PenR11 = CreatePen(PS_SOLID, 3, RGB(139, 69, 19));
	HPEN PenW11 = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hBrush4 = CreateSolidBrush(RGB(255, 222, 173));

	SelectObject(hdc6, hBrush);	//сделаем перо активным
	SelectObject(hdc8, hBrush4);
	Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[1]->GetHealth(), 80);
	Rectangle(hdc6, 40, 40, 40 + vector_of_objects[0]->GetHealth(), 80);
	while (!End) 	//бесконечный цикл буксировки фигуры
	{
		bool flag;
		if (KEY_DOWN(VK_TAB)) {
			int a1 = vector_of_objects[0]->GetX1() + 26.5 * vector_of_objects[0]->GetCoeff();
			int b1 = vector_of_objects[0]->GetY1() - 10 * abs(vector_of_objects[0]->GetCoeff());
			static int countShoot = 0;
			flag = 0;

			countShoot++;
			if ((countShoot > 2) && (countShoot % 3 == 0)) borders += 30;

			while (a1 < 1850) {
				//ѕолет снар€да
				Sleep(1);
				SelectObject(hdc2, PenR11);	//сделаем перо активным
				Rectangle(hdc2, a1, b1, a1 + 30, b1 + 13);
				Sleep(10);
				SelectObject(hdc2, PenW11);	//сделаем перо активным
				Rectangle(hdc2, a1, b1, a1 + 30, b1 + 13);

				//√раницы карты
				Rectangle(hdc8, 0, 0, 1980, 0 + borders);
				Rectangle(hdc8, 0, 1080 - borders, 1980, 1080);

				//Ўлала здоровь€
				if (vector_of_objects[1]->GetHealth() > 0) Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[1]->GetHealth(), 80);
				if (vector_of_objects[0]->GetHealth() > 0) Rectangle(hdc6, 40, 40, 40 + vector_of_objects[0]->GetHealth(), 80);

				int tempC1 = vector_of_objects[1]->GetCoeff();
				int tempX1 = vector_of_objects[1]->GetX1();
				int tempY1 = vector_of_objects[1]->GetY1();
				if (((a1 + 30 > tempX1 + 18 * tempC1) && (a1 < tempX1) &&
					(b1 < tempY1) && (b1 + 13 > tempY1 + 8 * tempC1)) ||
					((a1 + 30 > tempX1 + 13 * tempC1) && (a1 < tempX1 + 3 * tempC1) &&
						(b1 < tempY1 + 8 * tempC1) && (b1 + 13 > tempY1 + 18 * tempC1)))
				{
					Crush(vector_of_objects[1], tempX1 + 9 * tempC1, tempY1 - 9 * abs(tempC1), End, 0);
					flag = 1;
				}
				if (flag) break;
				a1 += 17;
			}
		}
	}
	DeleteObject(PenR11);
	DeleteObject(PenW11);
	DeleteObject(hBrush);
	DeleteObject(hBrush4);
	Sleep(10);
}

void Fragmentation::ShootFromRight(int& borders, bool& End)
{
	HPEN PenR22 = CreatePen(PS_SOLID, 3, RGB(139, 69, 19));
	HPEN PenW22 = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hBrush4 = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc6, hBrush);	//сделаем перо активным
	SelectObject(hdc8, hBrush4);
	Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[1]->GetHealth(), 80);
	Rectangle(hdc6, 40, 40, 40 + vector_of_objects[0]->GetHealth(), 80);
	while (!End) 	//бесконечный цикл буксировки фигуры
	{
		bool flag;
		if (KEY_DOWN(VK_SHIFT)) {
			int a2 = vector_of_objects[1]->GetX1() + 29.5 * vector_of_objects[1]->GetCoeff();
			int b2 = vector_of_objects[1]->GetY1() - 10 * abs(vector_of_objects[1]->GetCoeff());
			static int countShoot = 0;
			flag = 0;

			countShoot++;
			if ((countShoot > 2) && (countShoot % 3 == 0)) borders += 30;

			while (a2 > 100) {
				//ѕолет снар€да
				Sleep(1);
				SelectObject(hdc3, PenR22);	//сделаем перо активным
				Rectangle(hdc3, a2, b2, a2 + 30, b2 + 13);
				Sleep(10);
				SelectObject(hdc3, PenW22);	//сделаем перо активным
				Rectangle(hdc3, a2, b2, a2 + 30, b2 + 13);

				//√раницы карты
				Rectangle(hdc8, 0, 0, 1980, 0 + borders);
				Rectangle(hdc8, 0, 1080 - borders, 1980, 1080);

				//Ўлала здоровь€
				if (vector_of_objects[1]->GetHealth() > 0) Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[1]->GetHealth(), 80);
				if (vector_of_objects[0]->GetHealth() > 0) Rectangle(hdc6, 40, 40, 40 + vector_of_objects[0]->GetHealth(), 80);
			
				int tempC2 = vector_of_objects[0]->GetCoeff();
				int tempX2 = vector_of_objects[0]->GetX1();
				int tempY2 = vector_of_objects[0]->GetY1();
				if (((a2 < tempX2 + 18 * tempC2) && (a2 + 30 > tempX2) &&
					(b2 < tempY2) && (b2 + 13 > tempY2 - 8 * tempC2)) ||
					((a2 < tempX2 + 13 * tempC2) && (a2 + 30 > tempX2 + 3 * tempC2) &&
						(b2 < tempY2 - 8 * tempC2) && (b2 + 13 > tempY2 - 18 * tempC2)))
				{
					Crush(vector_of_objects[0], tempX2 + 9 * tempC2, tempY2 - 9 * abs(tempC2), End, 1);
					flag = 1;
				}
				if (flag) break;
				a2 -= 17;
			}
		}
	}
	DeleteObject(PenR22);
	DeleteObject(PenW22);
	DeleteObject(hBrush);
	DeleteObject(hBrush4);
	Sleep(10);
}