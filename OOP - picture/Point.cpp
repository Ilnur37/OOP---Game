#include "Point.h"

Point::Point(int X1, int Y1) : Location(X1, Y1)
{
	//this->speed = speed;
}

Point::~Point()
{
}

void Point::Show()
{
	SetPixel(hdc, X1, Y1, RGB(255, 0, 0));
}

void Point::Hide()
{
	SetPixel(hdc, X1, Y1, RGB(250, 250, 250));
}

void Point::MoveTo(int X1, int Y1)
{
	Hide();
	this->X1 = X1;
	this->Y1 = Y1;
	Show();
}

void Point::Drag(int Step)
{
	int FigX1, FigY1;   //����� ���������� ������

	FigX1 = GetX1();    //�������� ��������� ��������� ������
	FigY1 = GetY1();

	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
			break;

		//����������� �������� �������

		if (KEY_DOWN(VK_LEFT)) //������� �����  37
		{
			for (int i = 0; i < Step; i++)
			{
				FigX1--;
				MoveTo(FigX1, FigY1);
				Sleep(30);
			}
		}

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			for (int i = 0; i < Step; i++)
			{
				FigX1++;
				MoveTo(FigX1, FigY1);
				Sleep(30);
			}
		}

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			for (int i = 0; i < Step; i++)
			{
				FigY1++;
				MoveTo(FigX1, FigY1);
				Sleep(30);
			}
		}

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			for (int i = 0; i < Step; i++)
			{
				FigY1--;
				MoveTo(FigX1, FigY1);
				Sleep(30);
			}
		}
	}
}