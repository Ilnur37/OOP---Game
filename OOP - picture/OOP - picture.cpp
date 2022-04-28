#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "GetConlWin.h"

#include "MegaBatShip.h"
#include "Fragmentation.h"
#define DEBUG 3
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
using namespace std;

HDC hdc;
HDC hdc2;
HDC hdc3;
HDC hdc4;
HDC hdc5;
HDC hdc6;
HDC hdc7;
HDC hdc8;

vector <Point*> vector_of_objects;

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
		hdc2 = GetWindowDC(hwnd);
		hdc3 = GetWindowDC(hwnd);
		hdc4 = GetWindowDC(hwnd);
		hdc5 = GetWindowDC(hwnd);
		hdc6 = GetWindowDC(hwnd);
		hdc7 = GetWindowDC(hwnd);
		hdc8 = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			//* * * * * * * * G A M E 1
#if DEBUG == 2

			SuperBatShip ASuper(200, 500, 10);
			MegaBatShip AMega(1300, 500, 10);
			//BattleShip ABattleShip(1600, 500, 10);
			Liner Aliner(1000, 1000, 8);
			Boat Aboat(1600, 700, 8);
			Boat Bboat(1600, 900, 8);

			vector_of_objects.push_back(&ASuper);
			vector_of_objects.push_back(&AMega);
			//vector_of_objects.push_back(&ABattleShip);
			vector_of_objects.push_back(&Aliner);
			vector_of_objects.push_back(&Aboat);
			vector_of_objects.push_back(&Bboat);
			Player player;

			while (1)
				if (KEY_DOWN(49))   //цифра 1
					break;
			player.ShowAll();

			while (1)
			if (KEY_DOWN(50))   //цифра 2
			break;
			thread T1(&Player::Gamer1, player, vector_of_objects[0]);
			//player.Gamer2(vector_of_objects[1]);
			T1.join();
			while (1)
				if (KEY_DOWN(51))   //цифра 3
					break;
			player.HideAll();

			while (1)
				if (KEY_DOWN(52))   //цифра 4
					break;
			player.ShowAll();
			//* * * * * * * *

			//* * * * * * * * G A M E 2

#elif DEBUG == 3

			bool EndOfGame = 0;

			SuperBatShip ASuper(200, 500, 8);
			MegaBatShip AMega(1600, 500, -8);

			Point p;
			ArmorPiercing ap;
			Cumulative cum;
			Fragmentation fr;
			int bord = 0;
			vector_of_objects.push_back(&ASuper);
			vector_of_objects.push_back(&AMega);
			/*vector_of_objects.push_back(&ABattleShip);
			vector_of_objects.push_back(&Aliner);
			vector_of_objects.push_back(&Aboat);
			vector_of_objects.push_back(&Bboat);*/

			while (1)
				if (KEY_DOWN(49))   //цифра 1
					break;
			HPEN Pen5 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			SelectObject(hdc, Pen5);	//сделаем перо активным
			Rectangle(hdc, 0, 0, 1980, 1080);
			DeleteObject(Pen5);
			ASuper.Show();
			AMega.Show();

			while (1)
				if (KEY_DOWN(50))   //цифра 2
					break;
			thread T1(&Point::Gamer1, p, vector_of_objects[0], ref(bord), ref(EndOfGame));
			thread T2(&ArmorPiercing::ShootApFromLeft, ap, ref(bord), ref(EndOfGame));
			thread T3(&ArmorPiercing::ShootApFromRight, ap, ref(bord), ref(EndOfGame));
			//thread T2(&Cumulative::ShootCumFromLeft, cum, ref(EndOfGame));
			//thread T3(&Cumulative::ShootCumFromRight, cum, ref(EndOfGame));
			
			//thread T2(&Fragmentation::ShootFragmFromLeft, fr, ref(EndOfGame));
			//thread T3(&Fragmentation::ShootFragmFromRight, fr, ref(EndOfGame));
			p.Gamer2(vector_of_objects[1], bord, EndOfGame);
			T1.join();
			T2.join();
			T3.join();

			while (1)
				if (KEY_DOWN(51))   //цифра 3
					break;
#endif
			//* * * * * * * *

		}
	}
}