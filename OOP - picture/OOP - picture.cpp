#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <vector>

#include "Player.h"

#include "GetConlWin.h"
#include "Location.h"
#include "Point.h"

#include "Carcass.h"
#include "BattleShip.h"
#include "Liner.h"
#include "Boat.h"
#include "SuperBatShip.h"

HDC hdc;

HDC hdc2;

HDC hdc3;

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
		hdc2 = GetWindowDC(hwnd);
		hdc3 = GetWindowDC(hwnd);
		//если контекст существует - можем работать
		if (hdc != 0)
		{
			//* * * * * * * 
			//vector <Point*> vector_of_objects;

			//SuperBatShip ASuper(200, 300, 10);
			//BattleShip ABattleShip(650, 450, 10);
			//Boat ACar(300, 500, 10);
			//
			//vector_of_objects.push_back(&ASuper);
			//vector_of_objects.push_back(&ABattleShip);
			//vector_of_objects.push_back(&ACar);
			//
			//Player player;
			//player.ShowAll(vector_of_objects);

			//while (1)
			//	if (KEY_DOWN(49))   //цифра 1
			//		break;
			//player.DragAll(vector_of_objects);
			//* * * * * * * *

			//* * * * * * * *
			vector <Point*> vector_of_objects;

			Liner Aliner(1600, 300, 8);
			SuperBatShip ASuper(200, 500, 10);
			BattleShip ABattleShip(1600, 500, 8);
			Boat Aboat(1600, 700, 8);
			Boat Bboat(1200, 700, 8);

			vector_of_objects.push_back(&ASuper);
			vector_of_objects.push_back(&Aliner);
			vector_of_objects.push_back(&ABattleShip);
			vector_of_objects.push_back(&Aboat);
			vector_of_objects.push_back(&Bboat);
			Player player;

			while (1)
				if (KEY_DOWN(49))   //цифра 1
					break;
			player.ShowAll(vector_of_objects);

			while (1)
			if (KEY_DOWN(50))   //цифра 2
			break;
			player.Gamer1(vector_of_objects);
			
			while (1)
				if (KEY_DOWN(51))   //цифра 3
					break;
			player.HideAll(vector_of_objects);

			while (1)
				if (KEY_DOWN(52))   //цифра 4
					break;
			player.ShowAll(vector_of_objects);
		}
	}
}