#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "GetConlWin.h"

#include "Game.h"
#include "MegaBatShip.h"
#include "ArmorPiercing.h"
#include "Cumulative.h"
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
//HDC hdc7;
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
		//hdc7 = GetWindowDC(hwnd);
		hdc8 = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{

			bool EndOfGame = 0;
			BattleShip ABatle(100, 400, 8);
			SuperBatShip ASuper(430, 400, 8);
			MegaBatShip AMega(760, 400, 8);
			BattleShip ABatle2(100, 400, -8);
			SuperBatShip ASuper2(430, 400, -8);
			MegaBatShip AMega2(760, 400, -8);

			Game g;
			ArmorPiercing ap;
			Cumulative cum;
			Fragmentation fr;
			int bord = 80;
			bool choose = 1;

			HPEN Pen5 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			SelectObject(hdc, Pen5);	//сделаем перо активным
			Rectangle(hdc, 0, 0, 1980, 1080);
			cout << "\n\n\t\t\t\t\t\t Player 1, choose your ship";
			cout << "\n\n\n\n\n\n" << "\t\t (Tab 1)" << "\t\t\t\t (Tab 2)" << "\t\t\t\t (Tab 3)" << endl;
			cout << "\t\t HealthPoint = 150" << "\t\t\t HealthPoint = 150" << "\t\t\t HealthPoint = 150\n";
			cout << "\t\t Armor = 0" << "\t\t\t\t Armor = 7" << "\t\t\t\t Armor = 15\n";
			cout << "\t\t Speed = 7" << "\t\t\t\t Speed = 5" << "\t\t\t\t Speed = 3\n";
			ABatle.Show();
			ASuper.Show();
			AMega.Show();

			while (choose)
			{
				if (KEY_DOWN(49)) 
				{
					vector_of_objects.push_back(&ABatle);
					choose = 0;
				}

				if (KEY_DOWN(50))
				{
					vector_of_objects.push_back(&ASuper);
					choose = 0;
				}

				if (KEY_DOWN(51))
				{
					vector_of_objects.push_back(&AMega);
					choose = 0;
				}
			}
			choose = 1;
			SelectObject(hdc, Pen5);	//сделаем перо активным
			Rectangle(hdc, 0, 0, 1980, 1080);
			vector_of_objects[0]->Show();
			Sleep(1000);
			Rectangle(hdc, 0, 0, 1980, 1080);

			COORD position = { 0,0 }; //позиция x и y
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hConsole, position);
			cout << "\n\n\t\t\t\t\t\t Player 2, choose your ship";
			cout << "\n\n\n\n\n\n" << "\t\t (Tab 1)" << "\t\t\t\t (Tab 2)" << "\t\t\t\t (Tab 3)" << endl;
			cout << "\t\t HealthPoint = 150" << "\t\t\t HealthPoint = 150" << "\t\t\t HealthPoint = 150\n";
			cout << "\t\t Armor = 0" << "\t\t\t\t Armor = 7" << "\t\t\t\t Armor = 15\n";
			cout << "\t\t Speed = 7" << "\t\t\t\t Speed = 5" << "\t\t\t\t Speed = 3\n";
			ABatle.Show();
			ASuper.Show();
			AMega.Show();
			while (choose)
			{
				if (KEY_DOWN(49))
				{
					vector_of_objects.push_back(&ABatle2);
					choose = 0;
				}

				if (KEY_DOWN(50))
				{
					vector_of_objects.push_back(&ASuper2);
					choose = 0;
				}

				if (KEY_DOWN(51))
				{
					vector_of_objects.push_back(&AMega2);
					choose = 0;
				}
			}
			choose = 1;
			SelectObject(hdc, Pen5);	//сделаем перо активным
			Rectangle(hdc, 0, 0, 1980, 1080);
			vector_of_objects[1]->Show();
			Sleep(1000);
			Rectangle(hdc, 0, 0, 1980, 1080);

			while (1)
				if (KEY_DOWN(50))   //цифра 2
					break;
			thread T1(&Game::Gamer1, g, vector_of_objects[0], ref(bord), ref(EndOfGame));
			//thread T2(&Game::Shoot1, g, &ap, ref(bord), ref(EndOfGame));
			//thread T3(&Game::Shoot2, g, &ap, ref(bord), ref(EndOfGame));
			thread T2(&Game::Shoot1, g, &cum, ref(bord), ref(EndOfGame));
			thread T3(&Game::Shoot2, g, &cum, ref(bord), ref(EndOfGame));
			
			//thread T2(&Game::Shoot1, g, &fr, ref(bord), ref(EndOfGame));
			//thread T3(&Game::Shoot2, g, &fr, ref(bord), ref(EndOfGame));
			g.Gamer2(vector_of_objects[1], bord, EndOfGame);
			T1.join();
			T2.join();
			T3.join();

			while (1)
				if (KEY_DOWN(51))   //цифра 3
					break;
			//* * * * * * * *

		}
	}
}