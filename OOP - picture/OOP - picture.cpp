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
HDC hdc8;

vector <Point*> vector_of_objects;				//массив для хранения кораблей
vector <Projectile*> vector_of_projectile;			//массив для хранения снарядов

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
			bool EndOfGame = 0;						//флаг конца игры(= 1 когда 1 из кораблей будет уничтожен)
			
			//инициализация кораблей
			BattleShip ABatle(100, 500, 8);
			SuperBatShip ASuper(430, 500, 8);
			MegaBatShip AMega(760, 500, 8);
			BattleShip ABatle2(100, 500, -8);
			SuperBatShip ASuper2(430, 500, -8);
			MegaBatShip AMega2(760, 500, -8);

			//инициализация снарядов
			ArmorPiercing ap;
			Cumulative cum;
			Fragmentation fr;

			Game g;
			int bord = 80;							//ничальные границы карты
			bool choose = 1;

			while (1)
				if (KEY_DOWN(VK_RETURN))
					break;
			HPEN Pen5 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			SelectObject(hdc, Pen5);
			Rectangle(hdc, 0, 0, 1980, 1080);
			cout << "\n\n\t\t\t\t\t Player 1, choose your ship";
			cout << "\n\n\n\n\n\n" << "\t\t (Tab 1)" << "\t\t\t\t (Tab 2)" << "\t\t\t\t (Tab 3)" << endl;
			cout << "\t\t HealthPoint\t = 150" << "\t\t\t HealthPoint\t = 150" << "\t\t\t HealthPoint\t = 150\n";
			cout << "\t\t Armor\t\t = 0" << "\t\t\t Armor\t\t = 7" << "\t\t\t Armor\t\t = 15\n";
			cout << "\t\t Speed\t\t = 7" << "\t\t\t Speed\t\t = 5" << "\t\t\t Speed\t\t = 3\n";
			ABatle.Show();
			ASuper.Show();
			AMega.Show();

			//выбор корабля первым игроком
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
			SelectObject(hdc, Pen5);
			Rectangle(hdc, 0, 0, 1980, 1080);
			vector_of_objects[0]->Show();
			Sleep(1000);
			Rectangle(hdc, 0, 0, 1980, 1080);

			COORD position = { 0,0 }; //позиция x и y
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hConsole, position);
			cout << "\n\n\t\t\t\t\t Player 2, choose your ship";
			cout << "\n\n\n\n\n\n" << "\t\t (Tab 1)" << "\t\t\t\t (Tab 2)" << "\t\t\t\t (Tab 3)" << endl;
			cout << "\t\t HealthPoint\t = 150" << "\t\t\t HealthPoint\t = 150" << "\t\t\t HealthPoint\t = 150\n";
			cout << "\t\t Armor\t\t = 0" << "\t\t\t Armor\t\t = 7" << "\t\t\t Armor\t\t = 15\n";
			cout << "\t\t Speed\t\t = 7" << "\t\t\t Speed\t\t = 5" << "\t\t\t Speed\t\t = 3\n";
			ABatle.Show();
			ASuper.Show();
			AMega.Show();

			//выбор корабля вторым игроком
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
			SelectObject(hdc, Pen5);
			Rectangle(hdc, 0, 0, 1980, 1080);
			vector_of_objects[1]->Show();
			Sleep(1000);
			Rectangle(hdc, 0, 0, 1980, 1080);

			cout << "\n\t\t\t\t\t\t Player 1, select projectile type ";
			cout << "\n\n\n\n\n\n" << "\t\t (Tab 1)" << "\t\t\t\t (Tab 2)" << "\t\t\t\t (Tab 3)" << endl;
			cout << "\t\t Damage\t = 50" << "\t\t\t\t Damage\t = 62" << "\t\t\t\t Damage\t = 75\n";
			cout << "\t\t Flight speed = 25" << "\t\t\t Flight speed = 20" << "\t\t\t Flight speed = 17\n";

			//выбор типа снаряда первым игроком 
			while (choose)
			{
				if (KEY_DOWN(49))
				{
					vector_of_projectile.push_back(&ap);
					choose = 0;
				}

				if (KEY_DOWN(50))
				{
					vector_of_projectile.push_back(&cum);
					choose = 0;
				}

				if (KEY_DOWN(51))
				{
					vector_of_projectile.push_back(&fr);
					choose = 0;
				}
			}
			choose = 1;
			SelectObject(hdc, Pen5);
			Rectangle(hdc, 0, 0, 1980, 1080);
			Sleep(1000);

			cout << "\n\n\t\t\t\t\t\t Player 2, select projectile type ";
			cout << "\n\n\n\n" << "\t\t (Tab 1)" << "\t\t\t\t (Tab 2)" << "\t\t\t\t (Tab 3)" << endl;
			cout << "\t\t Damage\t = 50" << "\t\t\t\t Damage\t = 62" << "\t\t\t\t Damage\t = 75\n";
			cout << "\t\t Flight speed = 25" << "\t\t\t Flight speed = 20" << "\t\t\t Flight speed = 17\n";

			//выбор типа снаряда вторым игроком
			while (choose)
			{
				if (KEY_DOWN(49))
				{
					vector_of_projectile.push_back(&ap);
					choose = 0;
				}

				if (KEY_DOWN(50))
				{
					vector_of_projectile.push_back(&cum);
					choose = 0;
				}

				if (KEY_DOWN(51))
				{
					vector_of_projectile.push_back(&fr);
					choose = 0;
				}
			}
			SelectObject(hdc, Pen5);
			Rectangle(hdc, 0, 0, 1980, 1080);
			for (int i = 0; i < 40; i++) { cout << endl; }
			while (1)
				if (KEY_DOWN(VK_RETURN))
					break;

			SelectObject(hdc, Pen5);
			Rectangle(hdc, 0, 0, 1980, 1080);
			vector_of_objects[0]->MoveTo(300, 500);
			vector_of_objects[1]->MoveTo(1500, 500);
			vector_of_objects[0]->Show();
			vector_of_objects[1]->Show();
			Sleep(10);
			thread T1(&Game::Gamer1, g, vector_of_objects[0], ref(bord), ref(EndOfGame));		//поток для управления 1 кораблем 
			thread T2(&Game::Shoot1, g, vector_of_projectile[0], ref(bord), ref(EndOfGame));	//поток для стрельбы 1 корабля
			thread T3(&Game::Shoot2, g, vector_of_projectile[1], ref(bord), ref(EndOfGame));	//поток для стрельбы 2 корабля
			g.Gamer2(vector_of_objects[1], bord, EndOfGame);									//в main - управление 2 кораблем
			T1.join();
			T2.join();
			T3.join();
		}
	}
}