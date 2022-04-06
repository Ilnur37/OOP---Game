#include "Rectan.h"

Rectan::Rectan(int X1, int Y1, int X2, int Y2) : Line(X1, Y1, X2, Y2)
{
}

Rectan::~Rectan()
{
}

void Rectan::Show()
{
	// ������� ���� � ���� ���� - �������
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//������� ���� ��������

	Rectangle(hdc, X1, Y1, X2, Y2);

	// ��������� ���� ��������� �������  
	DeleteObject(PenR);
}

void Rectan::Hide()
{
	// ������� ���� � ���� ���� - �������
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenR);	//������� ���� ��������

	Rectangle(hdc, X1, Y1, X2, Y2);

	// ��������� ���� ��������� �������  
	DeleteObject(PenR);
}