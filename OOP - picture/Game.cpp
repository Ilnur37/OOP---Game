#include "Game.h"

//Управление кораблем
void Game::Gamer1(Point* object1, int& borders, bool& End)
{
	int FigX1, FigY1;   //новые координаты фигуры
	int speed1;			//скорость передвижения

	FigX1 = object1->GetX1();
	FigY1 = object1->GetY1();
	speed1 = object1->GetSpeed();

	while (!End)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(0x41)) //клавиша A
		{
			FigX1 -= speed1;
			if (FigX1 - 40 < 0) FigX1 += speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x44)) //клавиша D
		{
			FigX1 += speed1;
			if (FigX1 + 220 > 1980) FigX1 -= speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x53)) //клавиша S
		{
			FigY1 += speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x57)) //клавиша W
		{
			FigY1 -= speed1;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}
		
		//проверка выхода корабля за границы карты
		if (FigY1 > 1080 - borders) FigY1 = 1080 - borders;
		if (FigY1 - 165 < 0 + borders) FigY1 = 165 + borders;
	}
}

//Управление кораблем
void Game::Gamer2(Point* object2, int& borders, bool& End)
{
	int FigX2, FigY2;   //новые координаты фигур
	int speed2;			//скорость передвижения

	FigX2 = object2->GetX1();
	FigY2 = object2->GetY1();
	speed2 = object2->GetSpeed();

	while (!End)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_LEFT)) //стрелка влево
		{
			FigX2 -= speed2;
			if (FigX2 - 220 < 0) FigX2 += speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо
		{
			FigX2 += speed2;
			if (FigX2 + 40 > 1980) FigX2 -= speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз
		{
			FigY2 += speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_UP)) //стрелка вверх
		{
			FigY2 -= speed2;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		//проверка выхода корабля за границы карты
		if (FigY2 > 1080 - borders) FigY2 = 1080 - borders;
		if (FigY2 - 180 < 0 + borders) FigY2 = 180 + borders;
	}
}

void Game::Shoot1(Projectile* proj, int& borders, bool& End)
{
	proj->ShootFromLeft(borders, End);
}

void Game::Shoot2(Projectile* proj, int& borders, bool& End)
{
	proj->ShootFromRight(borders, End);
}