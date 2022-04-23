#include "Player.h"
#define DEBUG

std::mutex mtx2;

void Player::ShowAll()
{
	for (int i = 0; i < vector_of_objects.size(); i++)
	{
		vector_of_objects[i]->Show();
	}
}

void Player::HideAll()
{
	for (int i = 0; i < vector_of_objects.size(); i++)
	{
		vector_of_objects[i]->Hide();
	}
}

void Player::Gamer1(Point* object1)
{
	int FigX1, FigY1;   //новые координаты фигуры

	FigX1 = object1->GetX1();    //получаем начальное положение фигуры
	FigY1 = object1->GetY1();
	//std::thread T2;
	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
			break;


		if (KEY_DOWN(0x41)) //стрелка влево  37
		{
			FigX1 -= 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x44)) //стрелка вправо  39
		{
			FigX1 += 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x53)) //стрелка вниз  40
		{
			FigY1 += 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);

		}

		if (KEY_DOWN(0x57)) //стрелка вверх  38
		{
			FigY1 -= 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}
	}
}

void Player::Gamer2(Point* object2)
{
	int FigX2, FigY2;   //новые координаты фигур
	bool flag = 0;

	FigX2 = object2->GetX1();    //получаем начальное положение фигуры
	FigY2 = object2->GetY1();
	
	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
			break;

		//направление движения объекта

		if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			FigX2 -= 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			FigX2 += 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			FigY2 += 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);

		}

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			FigY2 -= 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}
	}
}