#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

#include "GetConlWin.h"
#include "Location.h"
#include "Point.h"

#include "Carcass.h"
#include "Deck.h"
#include "BattleShip.h"
#include "Liner.h"



HDC hdc;

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;


int main()
{
	system("color F0");
	setlocale(LC_ALL, "ru");

	
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует - можем работать
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{

			

			Deck ADeck(300, 500, 10);
			Liner ALiner(200, 300, 10);
			BattleShip ABattleShip(650, 450, 15);
			ADeck.Show();
			ALiner.Show();
			ABattleShip.Show();
			while (1)
			if (KEY_DOWN(49))   //цифра 1
			break;

			ALiner.Drag(20);

			/*int x = 300, y = 450, coeff = 10;

			Line bottomL(x, y, x + 18 * coeff, y);
			bottomL.Show();
			vector_of_objects.push_back(&bottomL);

			Line leftL(x, y, x - 4 * coeff, y - 8 * coeff);
			leftL.Show();
			vector_of_objects.push_back(&leftL);

			Line rightL(x + 18 * coeff, y, x + 22 * coeff, y - 8 * coeff);
			rightL.Show();
			vector_of_objects.push_back(&rightL);

			Line topL(x - 4 * coeff, y - 8 * coeff, x + 22 * coeff, y - 8 * coeff);
			topL.Show();
			vector_of_objects.push_back(&topL);


			Rectan rec1(x + 2 * coeff, y - 12 * coeff, x + 6 * coeff, y - 8 * coeff);
			rec1.Show();
			vector_of_objects.push_back(&rec1);

			Rectan rec2(x + 6 * coeff, y - 18 * coeff, x + 10 * coeff, y - 8 * coeff);
			rec2.Show();
			vector_of_objects.push_back(&rec2);

			Rectan rec3(x + 10 * coeff, y - 16 * coeff, x + 14 * coeff, y - 8 * coeff);
			rec3.Show();
			vector_of_objects.push_back(&rec3);


			Rectan rec4(x + 17 * coeff, y - 11 * coeff, x + 21 * coeff, y - 8 * coeff);
			rec4.Show();
			vector_of_objects.push_back(&rec4);

			Rectan rec5(x + 21 * coeff, y - 10 * coeff, x + 26 * coeff, y - 9 * coeff);
			rec5.Show();
			vector_of_objects.push_back(&rec5);

			Ring ring1(x + 9 * coeff, y - 4 * coeff, 2 * coeff, 0.4 * coeff);
			ring1.Show();
			vector_of_objects.push_back(&ring1);

			Ring ring2(x + 4 * coeff, y - 4 * coeff, 2 * coeff, 0.4 * coeff);
			ring2.Show();
			vector_of_objects.push_back(&ring2);

			Ring ring3(x + 14 * coeff, y - 4 * coeff, 2 * coeff, 0.4 * coeff);
			ring3.Show();
			vector_of_objects.push_back(&ring3);

			while (1)	//бесконечный цикл буксировки фигуры
			{
				if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
					break;
				for (int i = 0; i < vector_of_objects.size(); i++)
				{
					vector_of_objects[i]->Drag(10);
				}
			}*/
			while (1)
				if (KEY_DOWN(49))   //цифра 1
					break;

		}
	}
}
