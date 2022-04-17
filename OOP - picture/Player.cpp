#include "Player.h"

void Player::ShowAll(std::vector<Point*>& vector_of_objects)
{
	for (int i = 0; i < vector_of_objects.size(); i++)
	{
		vector_of_objects[i]->Show();
	}
}

void Player::HideAll(std::vector<Point*>& vector_of_objects)
{
	for (int i = 0; i < vector_of_objects.size(); i++)
	{
		vector_of_objects[i]->Hide();
	}
}

void Player::DragAll(std::vector<Point*>& vector_of_objects)
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

void Player::Gamer1(std::vector <Point*>& vector_of_objects)
{
	int FigX1, FigY1;   //����� ���������� ������

	FigX1 = vector_of_objects[0]->GetX1();    //�������� ��������� ��������� ������
	FigY1 = vector_of_objects[0]->GetY1();
	
	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
			break;

		//����������� �������� �������

		if (KEY_DOWN(VK_LEFT)) //������� �����  37
		{
			FigX1--;
			vector_of_objects[0]->MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			FigX1++;
			vector_of_objects[0]->MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			FigY1++;
			vector_of_objects[0]->MoveTo(FigX1, FigY1);
			Sleep(10);

		}

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			FigY1--;
			vector_of_objects[0]->MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_SHIFT))
		{
			Sleep(10);
			int startX = FigX1 + 260;
			int startY = FigY1 - 100;
			Player::Shooter1(startX, startY, vector_of_objects);
		}
	}
}

void Player::Shooter1(int a, int b, std::vector<Point*>& vector_of_objects)
{
	HPEN PenR = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
	SelectObject(hdc2, PenR);	//������� ���� ��������

	HPEN PenW = CreatePen(PS_SOLID, 3, RGB(250, 250, 250));
	SelectObject(hdc3, PenW);	//������� ���� ��������

	while (a < 1800) {
		Rectangle(hdc2, a, b, a + 20, b + 10);
		Sleep(1);
		for (int i = 1; i < vector_of_objects.size(); i++)
		{
			if ((a > (vector_of_objects[i]->GetX1() + 90)) &&
				(a < (vector_of_objects[i]->GetX1() + 110)) &&
				(b > (vector_of_objects[i]->GetY1() - 180)) &&
				(b < (vector_of_objects[i]->GetY1() )) ) {
				Ellipse(hdc2, a - 50, b - 50, a + 20, b + 10);
			}
		}
		Rectangle(hdc3, a, b, a + 20, b + 10);
		a += 15;

		Sleep(1);
	}

	DeleteObject(PenR);
	DeleteObject(PenW);

	Sleep(10);
}