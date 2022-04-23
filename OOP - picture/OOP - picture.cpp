#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "GetConlWin.h"
#include "Player.h"

#include "Liner.h"
#include "Boat.h"
#include "MegaBatShip.h"

#define DEBUG 3

HDC hdc;
HDC hdc2;
HDC hdc3;
HDC hdc4;
HDC hdc5;
HDC hdc6;

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;

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

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			//* * * * * * * 
			
#if DEBUG == 1

			SuperBatShip ASuper(200, 300, 10);
			BattleShip ABattleShip(650, 450, 10);
			Boat ACar(300, 500, 10);
			
			vector_of_objects.push_back(&ASuper);
			vector_of_objects.push_back(&ABattleShip);
			vector_of_objects.push_back(&ACar);
			
			while (1)
				if (KEY_DOWN(49))   //цифра 1
					break;
			Player player;
			player.ShowAll();

			while (1)
				if (KEY_DOWN(50))   //цифра 2
					break;
			player.DragAll();

			while (1)
				if (KEY_DOWN(51))   //цифра 3
					break;
			player.HideAll();


			while (1)
				if (KEY_DOWN(52))   //цифра 4
					break;
			player.ShowAll();
			//* * * * * * * *

			//* * * * * * * * G A M E 1
#elif DEBUG == 2

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
			SuperBatShip ASuper(200, 500, 8);
			MegaBatShip AMega(1600, 500, -10);
			//BattleShip ABattleShip(1600, 500, 10);
			Liner Aliner(1600, 300, 8);
			Boat Aboat(1600, 700, 8);
			Boat Bboat(1200, 700, 8);
			vector_of_objects.push_back(&ASuper);
			vector_of_objects.push_back(&AMega);
			//vector_of_objects.push_back(&ABattleShip);
			vector_of_objects.push_back(&Aliner);
			vector_of_objects.push_back(&Aboat);
			vector_of_objects.push_back(&Bboat);
			Player player;
			ArmorPiercing ap;
			Cumulative cum;
			Fragmentation fr;
			while (1)
				if (KEY_DOWN(49))   //цифра 1
					break;
			HPEN Pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			SelectObject(hdc, Pen);	//сделаем перо активным2
			Rectangle(hdc, 0, 0, 1980, 1080);
			DeleteObject(Pen);

			player.ShowAll();

			while (1)
				if (KEY_DOWN(50))   //цифра 2
					break;
			thread T1(&Player::Gamer1, player, vector_of_objects[0]);
			thread T2(&ArmorPiercing::ShootApFromLeft, ap);
			thread T3(&ArmorPiercing::ShootApFromRight, ap);

			//thread T2(&Cumulative::ShootCumFromLeft, cum);
			//thread T3(&Cumulative::ShootCumFromRight, cum);
			
			//thread T2(&Fragmentation::ShootFragmFromLeft, fr);
			//thread T3(&Fragmentation::ShootFragmFromRight, fr);
			player.Gamer2(vector_of_objects[1]);
			T1.join();
			T2.join();
			T3.join();

			while (1)
				if (KEY_DOWN(51))   //цифра 3
					break;
			player.HideAll();

			while (1)
				if (KEY_DOWN(52))   //цифра 4
					break;
			player.ShowAll();
#endif
			//* * * * * * * *

		}
	}
}