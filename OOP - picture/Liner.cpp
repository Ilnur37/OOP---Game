#include "Liner.h"

Liner::Liner(int X1, int Y1, int coeff) : Carcass(X1, Y1, coeff)
{
}

Liner::~Liner()
{
}

void Liner::Show()
{
	Carcass::Show();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 0, 0));
	SelectObject(hdc, PenR);	//������� ���� ��������

	Rectangle(hdc, X1 + 2 * coeff, Y1 - 12 * coeff, X1 + 6 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 6 * coeff, Y1 - 18 * coeff, X1 + 10 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 10 * coeff, Y1 - 16 * coeff, X1 + 14 * coeff, Y1 - 8 * coeff);

	Rectangle(hdc, X1 + 3 * coeff, Y1 - 11 * coeff, X1 + 5 * coeff, Y1 - 10 * coeff);
	Rectangle(hdc, X1 + 3 * coeff, Y1 - 9 * coeff, X1 + 5 * coeff, Y1 - 8 * coeff);

	Rectangle(hdc, X1 + 7 * coeff, Y1 - 17 * coeff, X1 + 9 * coeff, Y1 - 16 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 15 * coeff, X1 + 9 * coeff, Y1 - 14 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 13 * coeff, X1 + 9 * coeff, Y1 - 12 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 11 * coeff, X1 + 9 * coeff, Y1 - 10 * coeff);
	Rectangle(hdc, X1 + 7 * coeff, Y1 - 9 * coeff, X1 + 9 * coeff, Y1 - 8 * coeff);
	
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 15 * coeff, X1 + 13 * coeff, Y1 - 14 * coeff);
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 13 * coeff, X1 + 13 * coeff, Y1 - 12 * coeff);
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 11 * coeff, X1 + 13 * coeff, Y1 - 10 * coeff);
	Rectangle(hdc, X1 + 11 * coeff, Y1 - 9 * coeff, X1 + 13 * coeff, Y1 - 8 * coeff);

	// ��������� ���� ��������� �������  
	DeleteObject(PenR);
}

void Liner::Hide()
{
	Carcass::Hide();

	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, PenR);	//������� ���� ��������

	Rectangle(hdc, X1 + 2 * coeff, Y1 - 12 * coeff, X1 + 6 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 6 * coeff, Y1 - 18 * coeff, X1 + 10 * coeff, Y1 - 8 * coeff);
	Rectangle(hdc, X1 + 10 * coeff, Y1 - 16 * coeff, X1 + 14 * coeff, Y1 - 8 * coeff);

	DeleteObject(PenR);
}

//void Liner::MoveTo(int X1, int Y1)
//{
//	Hide();
//	this->X1 = X1;
//	this->Y1 = Y1;
//	Show();
//}
//
//void Liner::Drag()
//{
//	int FigX1, FigY1;   //����� ���������� ������
//
//	FigX1 = GetX1();    //�������� ��������� ��������� ������
//	FigY1 = GetY1();
//
//	while (1)	//����������� ���� ���������� ������
//	{
//		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
//			break;
//
//		//����������� �������� �������
//
//		if (KEY_DOWN(VK_LEFT)) //������� �����  37
//		{
//			FigX1--;
//			MoveTo(FigX1, FigY1);
//			Sleep(10);
//		}
//
//		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
//		{
//			FigX1++;
//			MoveTo(FigX1, FigY1);
//			Sleep(10);
//		}
//
//		if (KEY_DOWN(0x53)) //������� ����  40
//		{
//			FigY1++;
//			MoveTo(FigX1, FigY1);
//			Sleep(10);
//		}
//
//		if (KEY_DOWN(0x57)) //������� �����  38
//		{
//			FigY1--;
//			MoveTo(FigX1, FigY1);
//			Sleep(10);
//		}
//	}
//}
