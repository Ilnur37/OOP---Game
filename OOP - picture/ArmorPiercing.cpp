#include "ArmorPiercing.h"

std::mutex mtx3;

ArmorPiercing::ArmorPiercing()
{
	this->damage = 50;
}

int ArmorPiercing::GetDamage() { return damage; }

void ArmorPiercing::ShootFromLeft(int& borders, bool& End)
{
	Sleep(10);
	HPEN PenR11 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
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
				Rectangle(hdc2, a1, b1, a1 + 20, b1 + 7);
				Sleep(10);
				SelectObject(hdc2, PenW11);	//сделаем перо активным
				Rectangle(hdc2, a1, b1, a1 + 20, b1 + 7);

				//√раницы карты
				Rectangle(hdc8, 0, 0, 1980, 0 + borders);
				Rectangle(hdc8, 0, 1080 - borders, 1980, 1080);

				//Ўлала здоровь€
				if (vector_of_objects[1]->GetHealth() > 0) Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[1]->GetHealth(), 80);
				if (vector_of_objects[0]->GetHealth() > 0) Rectangle(hdc6, 40, 40, 40 + vector_of_objects[0]->GetHealth(), 80);

				int tempC1 = vector_of_objects[1]->GetCoeff();
				int tempX1 = vector_of_objects[1]->GetX1();
				int tempY1 = vector_of_objects[1]->GetY1();
				if (((a1 + 20 > tempX1 + 18 * tempC1) && (a1 < tempX1) &&
					(b1 < tempY1) && (b1 + 7 > tempY1 + 8 * tempC1)) ||
					((a1 + 20 > tempX1 + 13 * tempC1) && (a1 < tempX1 + 3 * tempC1) &&
					(b1 < tempY1 + 8 * tempC1) && (b1 + 7 > tempY1 + 18 * tempC1)))
				{
					Crush(vector_of_objects[1], tempX1 + 9 * tempC1, tempY1 - 9 * abs(tempC1), End, 0);
					flag = 1;
				}
				if (flag) break;
				a1 += 25;
			}
		}
	}
	DeleteObject(PenR11);
	DeleteObject(PenW11);
	DeleteObject(hBrush);
	DeleteObject(hBrush4);
	Sleep(10);
}

void ArmorPiercing::ShootFromRight(int& borders, bool& End)
{
	HPEN PenR22 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HPEN PenW22 = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hBrush4 = CreateSolidBrush(RGB(255, 222, 173));

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
				Rectangle(hdc3, a2, b2, a2 + 20, b2 + 7);
				Sleep(10);
				SelectObject(hdc3, PenW22);	//сделаем перо активным
				Rectangle(hdc3, a2, b2, a2 + 20, b2 + 7);

				//√раницы карты
				Rectangle(hdc8, 0, 0, 1980, 0 + borders);
				Rectangle(hdc8, 0, 1080 - borders, 1980, 1080);

				//Ўлала здоровь€
				if (vector_of_objects[1]->GetHealth() > 0) Rectangle(hdc6, 1730, 40, 1730 + vector_of_objects[1]->GetHealth(), 80);
				if (vector_of_objects[0]->GetHealth() > 0) Rectangle(hdc6, 40, 40, 40 + vector_of_objects[0]->GetHealth(), 80);
				
				int tempC2 = vector_of_objects[0]->GetCoeff();
				int tempX2 = vector_of_objects[0]->GetX1();
				int tempY2 = vector_of_objects[0]->GetY1();
				if (((a2 < tempX2 + 18 * tempC2) && (a2 + 20 > tempX2) &&
					(b2 < tempY2) && (b2 + 7 > tempY2 - 8 * tempC2)) ||
					((a2 < tempX2 + 13 * tempC2) && (a2 + 20 > tempX2 + 3 * tempC2) &&
					(b2 < tempY2 - 8 * tempC2) && (b2 + 7 > tempY2 - 18 * tempC2)))
				{
					Crush(vector_of_objects[0], tempX2 + 9 * tempC2, tempY2 - 9 * abs(tempC2), End, 1);
					flag = 1;
				}
				if (flag) break;
				a2 -= 25;
			}
		}
	}
	DeleteObject(PenR22);
	DeleteObject(PenW22);
	DeleteObject(hBrush);
	DeleteObject(hBrush4);
	Sleep(10);
}

void ArmorPiercing::Crush(Point* object, int x, int y, bool& End, bool placeHP)
{
	mtx3.lock();
	int place;
	HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 255, 0)); //задаЄм сплошную кисть
	HBRUSH hBrush2 = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hBrush3 = CreateSolidBrush(RGB(255, 255, 255));
	HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

	//–ассчет здоровь€
	(placeHP) ? place = 40 : place = 1730;
	SelectObject(hdc4, hBrush3);	
	Rectangle(hdc4, place, 40, place + object->GetHealth(), 80);

	object->SetHealth(object->GetHealth() - GetDamage() + object->GetArmor());
	if (object->GetHealth() > 0) {
		Rectangle(hdc6, place, 40, place + object->GetHealth(), 80);
	}
	else Rectangle(hdc6, place, 40, place, 80);

	//¬зрыв
	SelectObject(hdc4, hBrush1); //делаем кисть активной
	for (int i = 10; i <= 40; i += 10) {
		Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
		Sleep(10);
	}
	SelectObject(hdc4, hBrush2); 
	for (int i = 50; i < 90; i += 10) {
		Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
		Sleep(10);
	}
	Sleep(25);
	SelectObject(hdc5, Pen);	
	Ellipse(hdc5, x - 50, y - 50, x + 50, y + 50);

	//Ѕольшой взрыв
	if (object->GetHealth() <= 0) {
		End = 1;
		SelectObject(hdc4, hBrush1); 
		for (int i = 20; i <= 100; i += 20) {
			Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
			Sleep(40);
		}

		SelectObject(hdc4, hBrush2); //делаем кисть активной
		for (int i = 120; i < 240; i += 20) {
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

		// ”ничтожим нами созданные объекты  
		DeleteObject(PenR);
		DeleteObject(hBrush1);
		DeleteObject(hBrush2);
		DeleteObject(hBrush3);
		DeleteObject(Pen);
	}
	mtx3.unlock();
}