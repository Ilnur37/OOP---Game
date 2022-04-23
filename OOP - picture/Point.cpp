#include "Point.h"

std::mutex mtx1;

Point::Point()
{
}

Point::Point(int X1, int Y1, int coeff) : Location(X1, Y1, coeff)
{
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
	SetPixel(hdc, X1, Y1, RGB(255, 255, 255));
}

void Point::MoveTo(int X1, int Y1)
{
	mtx1.lock();
	Hide();
	this->X1 = X1;
	this->Y1 = Y1;
	Show();
	mtx1.unlock();
}

void Point::Drag1()
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
			FigX1--;
			MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			FigX1++;
			MoveTo(FigX1, FigY1);
			Sleep(10);
		}

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			FigY1++;
			MoveTo(FigX1, FigY1);
			Sleep(10);
			
		}

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			FigY1--;
			MoveTo(FigX1, FigY1);
			Sleep(10);
		}
	}
}