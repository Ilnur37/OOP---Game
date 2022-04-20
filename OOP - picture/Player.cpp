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

void Player::DragAll()
{
	int FigX1, FigY1;   //����� ���������� ������

	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
			break;

		//����������� �������� �������

		if (KEY_DOWN(VK_LEFT)) //������� �����  37
		{
			for (int i = 0; i < vector_of_objects.size(); i++)
			{
				FigX1 = vector_of_objects[i]->GetX1();    //�������� ��������� ��������� ������
				FigY1 = vector_of_objects[i]->GetY1();
				FigX1--;
				vector_of_objects[i]->MoveTo(FigX1, FigY1);
				Sleep(10);
			}
		}

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			for (int i = 0; i < vector_of_objects.size(); i++)
			{
				FigX1 = vector_of_objects[i]->GetX1();    //�������� ��������� ��������� ������
				FigY1 = vector_of_objects[i]->GetY1();
				FigX1++;
				vector_of_objects[i]->MoveTo(FigX1, FigY1);
				Sleep(10);
			}
		}

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			for (int i = 0; i < vector_of_objects.size(); i++)
			{
				FigX1 = vector_of_objects[i]->GetX1();    //�������� ��������� ��������� ������
				FigY1 = vector_of_objects[i]->GetY1();
				FigY1++;
				vector_of_objects[i]->MoveTo(FigX1, FigY1);
				Sleep(10);
			}
		}

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			for (int i = 0; i < vector_of_objects.size(); i++)
			{
				FigX1 = vector_of_objects[i]->GetX1();    //�������� ��������� ��������� ������
				FigY1 = vector_of_objects[i]->GetY1();
				FigY1--;
				vector_of_objects[i]->MoveTo(FigX1, FigY1);
				Sleep(10);
			}
		}
	}
}

void Player::Gamer1(Point* object1)
{
	int FigX1, FigY1;   //����� ���������� ������
	bool flag = 1;

	FigX1 = object1->GetX1();    //�������� ��������� ��������� ������
	FigY1 = object1->GetY1();
	
	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
			break;


		if (KEY_DOWN(0x41)) //������� �����  37
		{
			FigX1 -= 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(0x44)) //������� ������  39
		{
			FigX1 += 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(0x53)) //������� ����  40
		{
			FigY1 += 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(10);

		}

		if (KEY_DOWN(0x57)) //������� �����  38
		{
			FigY1 -= 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_TAB))
		{
			Sleep(10);
			int startX1 = FigX1 + 260;
			int startY1 = FigY1 - 100;
			Player::Shooter1(startX1, startY1);
		}
	}
}

void Player::Gamer2(Point* object2)
{
	int FigX2, FigY2;   //����� ���������� ������
	bool flag = 0;

	FigX2 = object2->GetX1();    //�������� ��������� ��������� ������
	FigY2 = object2->GetY1();
	
	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
			break;

		//����������� �������� �������

		if (KEY_DOWN(VK_LEFT)) //������� �����  37
		{
			FigX2 -= 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			FigX2 += 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			FigY2 += 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);

		}

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			FigY2 -= 3;
			object2->MoveTo(FigX2, FigY2);
			Sleep(5);
		}

		if (KEY_DOWN(VK_SHIFT))
		{

			Sleep(5);
			int startX2 = FigX2 - 95;
			int startY2 = FigY2 - 100;
			Player::Shooter2(startX2, startY2);
		}
	}
}

void Player::Shooter1(int a1, int b1)
{
	HPEN PenR11 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HPEN PenW11 = CreatePen(PS_SOLID, 3, RGB(245, 245, 245));
	while (a1 < 1800) {
		Sleep(1);
		SelectObject(hdc2, PenR11);	//������� ���� ��������
		Rectangle(hdc2, a1, b1, a1 + 20, b1 + 10);

		Sleep(10);
		SelectObject(hdc2, PenW11);	//������� ���� ��������
		Rectangle(hdc2, a1, b1, a1 + 20, b1 + 10);

		for (int i = 0; i < vector_of_objects.size(); i++)
		{
			if ((a1 > (vector_of_objects[i]->GetX1() + 80)) &&
				(a1 < (vector_of_objects[i]->GetX1() + 100)) &&
				(b1 > (vector_of_objects[i]->GetY1() - 180)) &&
				(b1 < (vector_of_objects[i]->GetY1()))) {
				Crush(vector_of_objects[i]);

				DeleteObject(PenR11);
				DeleteObject(PenW11);
				Sleep(10);
				return;
			}
		}
		a1 += 15;
	}
	DeleteObject(PenR11);
	DeleteObject(PenW11);
	Sleep(10);
}

void Player::Shooter2(int a2, int b2)
{
	HPEN PenR22 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HPEN PenW22 = CreatePen(PS_SOLID, 3, RGB(245, 245, 245));


	while (a2 > 200) {
		Sleep(1);
		SelectObject(hdc3, PenR22);	//������� ���� ��������
		Rectangle(hdc3, a2, b2, a2 + 20, b2 + 10);

		Sleep(10);
		SelectObject(hdc3, PenW22);	//������� ���� ��������
		Rectangle(hdc3, a2, b2, a2 + 20, b2 + 10);

		for (int i = 0; i < vector_of_objects.size(); i++)
		{
			if ((a2 > (vector_of_objects[i]->GetX1() + 80)) &&
				(a2 < (vector_of_objects[i]->GetX1() + 100)) &&
				(b2 > (vector_of_objects[i]->GetY1() - 180)) &&
				(b2 < (vector_of_objects[i]->GetY1()))) {
				Crush(vector_of_objects[i]);

				DeleteObject(PenR22);
				DeleteObject(PenW22);
				Sleep(10);
				return;
			}
		}
		a2 -= 15;
	}
	DeleteObject(PenR22);
	DeleteObject(PenW22);
	Sleep(10);
}

void Player::Crush(Point* object)
{
	int x = object->GetX1() + 90;
	int y = object->GetY1() - 90;
	HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 255, 0)); //����� �������� �����
	HBRUSH hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); //����� �������� �����
	HBRUSH hBrush3 = CreateSolidBrush(RGB(245, 245, 245)); //����� �������� �����
	
	mtx2.lock();

	SelectObject(hdc4, hBrush1); //������ ����� ��������
	for (int i = 20; i <= 100; i += 20)
	{
		Ellipse(hdc4, x - i/2, y - i/2, x + i/2, y + i/2);
		Sleep(30);
	}

	SelectObject(hdc4, hBrush2); //������ ����� ��������
	for (int i = 120; i < 240; i += 20)
	{
		Ellipse(hdc4, x - i / 2, y - i / 2, x + i / 2, y + i / 2);
		Sleep(30);
	}
	Sleep(50);
	SelectObject(hdc4, hBrush3); //������ ����� ��������
	Ellipse(hdc4, x - 160, y - 120, x + 160, y + 120);

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//������� ���� ��������

	MoveToEx(hdc, x - 30, y + 10, NULL);
	LineTo(hdc, x - 130, y + 10);
	MoveToEx(hdc, x - 130, y + 10, NULL);
	LineTo(hdc, x - 90, y + 90);
	MoveToEx(hdc, x - 90, y + 90, NULL);
	LineTo(hdc, x - 30, y + 90);
	MoveToEx(hdc, x - 30, y + 90, NULL);
	LineTo(hdc, x - 50, y + 50);
	MoveToEx(hdc, x - 50, y + 50, NULL);
	LineTo(hdc, x - 30, y + 10);

	MoveToEx(hdc, x, y + 10, NULL);
	LineTo(hdc, x + 100, y + 10);
	MoveToEx(hdc, x + 100, y + 10, NULL);
	LineTo(hdc, x + 60, y + 90);
	MoveToEx(hdc, x + 60, y + 90, NULL);
	LineTo(hdc, x, y + 90);
	MoveToEx(hdc, x, y + 90, NULL);
	LineTo(hdc, x - 20, y + 50);
	MoveToEx(hdc, x - 20, y + 50, NULL);
	LineTo(hdc, x, y + 10);

	// ��������� ���� ��������� �������  
	DeleteObject(PenR);

	mtx2.unlock();
}





//mtx2.lock();
//
//HPEN PenR11 = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
//HPEN PenW11 = CreatePen(PS_SOLID, 3, RGB(245, 245, 245));
//
//if (flag) {
//while (a < 1800) {
//	Sleep(1);
//	SelectObject(hdc2, PenR11);	//������� ���� ��������
//	Rectangle(hdc2, a, b, a + 20, b + 10);
//
//	Sleep(10);
//	SelectObject(hdc2, PenW11);	//������� ���� ��������
//	Rectangle(hdc2, a, b, a + 20, b + 10);
//
//	for (int i = 0; i < vector_of_objects.size(); i++)
//	{
//		if ((a > (vector_of_objects[i]->GetX1() + 80)) &&
//			(a < (vector_of_objects[i]->GetX1() + 100)) &&
//			(b > (vector_of_objects[i]->GetY1() - 180)) &&
//			(b < (vector_of_objects[i]->GetY1()))) {
//			Crush(a + 10, b + 10);
//		}
//	}
//	a += 15;
//}
//}
//else
//{
//	while (a > 200) {
//		Rectangle(hdc2, a, b, a + 20, b + 10);
//		Sleep(1);
//		for (int i = 0; i < vector_of_objects.size(); i++)
//		{
//			if ((a > (vector_of_objects[i]->GetX1() + 90)) &&
//				(a < (vector_of_objects[i]->GetX1() + 110)) &&
//				(b > (vector_of_objects[i]->GetY1() - 180)) &&
//				(b < (vector_of_objects[i]->GetY1()))) {
//				Rectangle(hdc2, a, b, a + 100, b + 100);
//			}
//		}
//		Rectangle(hdc3, a, b, a + 20, b + 10);
//		a -= 15;
//		Sleep(1);
//	}
//	}
//DeleteObject(PenR11);
//DeleteObject(PenW11);
//Sleep(10);
//
//mtx2.unlock();