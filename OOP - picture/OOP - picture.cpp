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

vector<Point*> vector_of_objects;

//void CreateShip(int x, int y, int coeff);
//
//void CreateShip(int x, int y, int coeff)
//{
//	Trapezoid ATrapezoid(x, y, x + 18 * coeff, y, x + 22 * coeff, y - 8 * coeff, x - 4 * coeff, y - 8 * coeff);
//	ATrapezoid.Show();
//
//	Rectan rec1(x + 2 * coeff, y - 12 * coeff, x + 6 * coeff, y - 8 * coeff);
//	rec1.Show();
//	Rectan rec2(x + 6 * coeff, y - 18 * coeff, x + 10 * coeff, y - 8 * coeff);
//	rec2.Show();
//	Rectan rec3(x + 10 * coeff, y - 16 * coeff, x + 14 * coeff, y - 8 * coeff);
//	rec3.Show();
//
//	Rectan rec4(x + 17 * coeff, y - 11 * coeff, x + 21 * coeff, y - 8 * coeff);
//	rec4.Show();
//	Rectan rec5(x + 21 * coeff, y - 10 * coeff, x + 26 * coeff, y - 9 * coeff);
//	rec5.Show();
//
//	Ellips ring1(x + 9 * coeff, y - 4 * coeff, 2 * coeff, 0.4 * coeff);
//	ring1.Show();
//	Ellips ring2(x + 4 * coeff, y - 4 * coeff, 2 * coeff, 0.4 * coeff);
//	ring2.Show();
//	Ellips ring3(x + 14 * coeff, y - 4 * coeff, 2 * coeff, 0.4 * coeff);
//	ring3.Show();
//}

int main()
{
	system("color F0");
	setlocale(LC_ALL, "ru");

	int x0 = 130, y0 = 250;		//стартовые координаты центра
	int Radius0 = 50;			//начальное значение радиуса
	int DeltaRad = 30;		//начальное изменение радиуса
	int RingW0 = 20;		//начальное значение толщины кольца
	int DeltaWide0 = 10;	//начальное изменение толщины КОЛЬЦА


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

			//***********   Т О Ч К А   ********

			//Point APoint(x0, y0);            //инициализация точки
			//APoint.Show();  //показать точку 
			//
			//APoint.MoveTo(x0, y0 + 2 * Radius0);
			//while (1)
			//	if (KEY_DOWN(32))   //ПРОБЕЛ
			//		break;
			//APoint.Drag(10);


			////***********   К Р У Г   ***********

			//Ellips  AEllips(x0 + 3 * Radius0, y0 + 2 * Radius0, Radius0, Radius0 +15);  //инициализация окружности
			//AEllips.Show();  //показать окружность
			//while (1)
			//	if (KEY_DOWN(49))   //цифра 1
			//		break;
			//
			//AEllips.ChangeRad(DeltaRad);  //изменить радиус окружности на DeltaRad
			//while (1)
			//	if (KEY_DOWN(50))   //цифра 2
			//		break;
			//
			//AEllips.MoveTo(x0, y0-2*Radius0);  //показать окружность на новом месте, Esc
			//while (1)
			//	if (KEY_DOWN(51))   //цифра 3          
			//		break;
			//
			//AEllips.Drag(10);


			/////////****************  Л И Н И Я 

			//Line ALine(x0 + 50, y0 + 50, x0 + 100, y0 + 100);
			//ALine.Show();
			//while (1)
			//	if (KEY_DOWN(49))   //цифра 1
			//		break;
			//
			//ALine.MoveTo(x0 + 50 + 30, y0 + 50 + 30, x0 + 100 + 30, y0 + 100 + 30);
			//while (1)
			//	if (KEY_DOWN(50))   //цифра 2
			//		break;
			//ALine.Drag(10);


			// **********   К О Л Ь Ц О   *******

			//Ring ARing(2 * x0, y0, Radius0, Radius0 + 15, RingW0);  //инициализация кольц
			//ARing.Show();  //показать кольцо
			//			   //	Sleep(1000);
			//
			//while (1)
			//	if (KEY_DOWN(53))   //цифра 5
			//		break;
			//
			//ARing.Drag(10);  //двигать кольцо  , Esc
			//while (1)
			//	if (KEY_DOWN(54))   //цифра 6
			//		break;
			//
			//ARing.Hide();  //спрятать кольцо
			//while (1)
			//	if (KEY_DOWN(55))   //цифра 7
			//		break;
			//
			//ARing.Drag(40);  //двигать кольцо ,Esc
			//while (1)
			//	if (KEY_DOWN(56))   //цифра 8
			//		break;
			//
			//ARing.Expand(2 * DeltaRad);  //увеличить радиус окружности кольца на 2*DeltaRad
			//							 //	Sleep(1000);
			//ARing.Drag(80);  //двигать кольцо , Esc
			//
			//ARing.Reduce(DeltaRad);  //уменьшить радиус окружности на DeltaRad
			//						 //	Sleep(1000);
			//while (1)
			//	if (KEY_DOWN(57))   //цифра 9
			//		break;
			//
			//ARing.Width(10);     //увеличить толщину кольца Серый +, Esc
			//Sleep(1000);


			///////******** П Р Я М О У Г О Л Ь Н И К 

			//Rectan ARectan(x0 + 50, y0 + 50, x0 + 100, y0 + 100);
			//ARectan.Show();
			//while (1)
			//	if (KEY_DOWN(49))   //цифра 1
			//		break;
			//
			//ARectan.MoveTo(x0 + 50 + 30, y0 + 50 + 30, x0 + 100 + 30, y0 + 100 + 30);
			//while (1)
			//	if (KEY_DOWN(50))   //цифра 2
			//		break;
			//ARectan.Drag(10);

			/////// *********  Т Р А П Е Ц И Я

			//Trapezoid ATrapezoid(300, 450, 480, 450, 520, 370, 260, 370);
			//ATrapezoid.Show();
			//while (1)
			//if (KEY_DOWN(49))   //цифра 1
			//break;
			//
			//ATrapezoid.MoveTo(300 - 50, 450 - 50, 480 - 50, 450 - 50, 520 - 50, 370 - 50, 260 - 50, 370 - 50);
			//while (1)
			//if (KEY_DOWN(50))   //цифра 2
			//break;
			//ATrapezoid.Drag(10);


			/*Line bottomL(300, 450, 480, 450);
			bottomL.Show();
			Line leftL(300, 450, 260, 370);
			leftL.Show();
			Line rightL(480, 450, 520, 370);
			rightL.Show();
			Line topL(260, 370, 520, 370);
			topL.Show();

			Rectan rec1(320, 330, 360, 370);
			rec1.Show();
			Rectan rec2(360, 270, 400, 370);
			rec2.Show();
			Rectan rec3(400, 290, 440, 370);
			rec3.Show();

			Rectan rec4(470, 340, 510, 370);
			rec4.Show();
			Rectan rec5(510, 350, 560, 360);
			rec5.Show();

			Ring ring1(390, 410, 20, 4);
			ring1.Show();
			Ring ring2(340, 410, 20, 4);
			ring2.Show();
			Ring ring3(440, 410, 20, 4);
			ring3.Show();*/

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

			//Carcass ACarcass(300, 450);
			//ACarcass.Show();

			//while (1)
			//	if (KEY_DOWN(49))   //цифра 1
			//		break;

			//ACarcass.Drag(10);

			//CreateShip(300, 450, 10);

			//CreateShip(600, 300, 5);


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
