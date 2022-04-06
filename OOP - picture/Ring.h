#pragma once
#include "Ellips.h"

class Ring : public Ellips
{
protected:
	int RingW;       //������� ������
public:
	Ring(int X1, int Y1, int RadiusX, int RadiusY, int RingW);
	Ring(int X1, int Y1, int Radius, int RangW);
	~Ring();

	void Show() override;		 //�������� ������
	void Hide() override;		 //������ ������

	int GetW();					 //�������� ������� ������
	void Width(int DeltaWide);    //�������� ������� ������
};