#pragma once
#include "ILocation.h"
#include <mutex>
#include <cmath>
#include <chrono>
#include <thread>

class Point : public ILocation
{
protected:
	//���������� �������, ����. �������, ���-�� ��������, �����, ��������
	int X1, Y1, coeff, HealthPoint, Armor, Speed;

public:
	Point();
	Point(int X1, int Y1, int coeff);
	~Point();

	void Show() override;						//�������� ������
	void Hide() override;						//������ ������
	void MoveTo(int X1, int Y1) override;		//����������� �������

	int GetX1() override;
	int GetY1() override;
	int GetCoeff() override;
	int GetHealth() override;
	int GetArmor() override;
	int GetSpeed() override;
	void SetHealth(int point) override;
};