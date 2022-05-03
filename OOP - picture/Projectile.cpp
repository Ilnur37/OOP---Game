#include "Projectile.h"

std::mutex mtx3;

int Projectile::GetDamage() { return damage; }

void Projectile::Crush(Point* object, int x, int y, bool& End, bool placeHP)
{
	mtx3.lock();
	int place;
	HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 255, 0)); //задаём сплошную кисть
	HBRUSH hBrush2 = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hBrush3 = CreateSolidBrush(RGB(255, 255, 255));
	HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

	//Рассчет здоровья
	(placeHP) ? place = 40 : place = 1730;
	SelectObject(hdc4, hBrush3);
	Rectangle(hdc4, place, 40, place + object->GetHealth(), 80);

	object->SetHealth(object->GetHealth() - GetDamage() + object->GetArmor());
	if (object->GetHealth() > 0) {
		Rectangle(hdc6, place, 40, place + object->GetHealth(), 80);
	}
	else Rectangle(hdc6, place, 40, place, 80);

	//Взрыв
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

	//Большой взрыв
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

		// Уничтожим нами созданные объекты  
		DeleteObject(PenR);
		DeleteObject(hBrush1);
		DeleteObject(hBrush2);
		DeleteObject(hBrush3);
		DeleteObject(Pen);
	}
	mtx3.unlock();
}