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
	int FigX1, FigY1;   //����� ���������� ������

	FigX1 = object1->GetX1();    //�������� ��������� ��������� ������
	FigY1 = object1->GetY1();
	//std::thread T2;
	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
			break;


		if (KEY_DOWN(0x41)) //������� �����  37
		{
			FigX1 -= 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x44)) //������� ������  39
		{
			FigX1 += 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}

		if (KEY_DOWN(0x53)) //������� ����  40
		{
			FigY1 += 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);

		}

		if (KEY_DOWN(0x57)) //������� �����  38
		{
			FigY1 -= 3;
			object1->MoveTo(FigX1, FigY1);
			Sleep(5);
		}
	}
}

void Player::Gamer2(Point* object2)
{
	int FigX2, FigY2;   //����� ���������� �����
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
	}
}