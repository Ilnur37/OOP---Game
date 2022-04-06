#include "Ellips.h"

Ellips::Ellips(int X1, int Y1, int RadiusX, int RadiusY) : Point(X1, Y1)
{
	this->RadiusX = RadiusX;
	this->RadiusY = RadiusY;
}

Ellips::Ellips(int X1, int Y1, int Radius) : Point(X1, Y1)
{
	RadiusX = Radius;
	RadiusY = Radius;
}

Ellips::~Ellips()
{
}

void Ellips::Show()
{
	// ������� ���� � ���� ���� - �������
	HPEN PenR = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, PenR);	//������� ���� ��������

	//HDC dc = GetDC(hwnd);
	//SelectObject(dc, GetStockObject(DC_BRUSH));
	//SetDCBrushColor(dc, RGB(255, 0, 255));
	// 
	// �������� ���� ������������� ������
	Ellipse(hdc, X1 - RadiusX, Y1 - RadiusY, X1 + RadiusX, Y1 + RadiusY);

	// ��������� ���� ��������� �������  
	DeleteObject(PenR);
}

void Ellips::Hide()
{
	// ������� ���� � ���� ����
	HPEN PenB = CreatePen(PS_SOLID, 2, RGB(250, 250, 250));
	SelectObject(hdc, PenB);

	// �������� ���� ������������� ������
	Ellipse(hdc, X1 - RadiusX, Y1 - RadiusY, X1 + RadiusX, Y1 + RadiusY);

	// ��������� ���� ��������� �������  
	DeleteObject(PenB);
}

void Ellips::Expand(int DeltaRad)
{

	while (1)   //���� ������ ����������
	{
		if (KEY_DOWN(VK_ESCAPE))        //����� ������
			break;

		//����������� ��������� ������� ������
		if (KEY_DOWN(107))     //����� +      ����������
		{
			Hide();
			RadiusX += DeltaRad; //�������� ������ 
			RadiusY += DeltaRad;
			Show();
			Sleep(200);
		}

		if (KEY_DOWN(109))     //����� -      ����������
		{
			Hide();
			RadiusX -= DeltaRad; //�������� ������ 
			RadiusY -= DeltaRad;
			if ((RadiusX < 0) || (RadiusY < 0)) {
				RadiusX += DeltaRad; //�������� ������ 
				RadiusY += DeltaRad;
			}
			Show();
			Sleep(200);
		}
	}

	//Hide();             //�������� ���������� �� ������ ��������
	//RadiusX += DeltaRad; //�������� ������ 
	//RadiusY += DeltaRad;
	//if ((RadiusX < 0) || (RadiusY < 0)) {     //��� �������������� ���������� �������
	//	RadiusX = 5;
	//	RadiusY = 5;
	//}
	//Show();             //�������� ���������� � ����� ��������
}

void Ellips::Reduce(int DeltaRad)
{
	Expand(-DeltaRad); //������������� ���������� �������
}
