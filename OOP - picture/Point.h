#pragma once
#include "ILocation.h"
#include <mutex>
#include <cmath>
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>

extern HDC hdc;
extern HDC hdc2;
extern HDC hdc3;
extern HDC hdc4;
extern HDC hdc5;
extern HDC hdc6;
extern HDC hdc8;

// ������ ��� �������� ��������� ���������� � �� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

class Point //: public ILocation
{
protected:
	//���������� �������, ����. �������, ���-�� ��������, �����, ��������
	int X1, Y1, coeff, HealthPoint, Armor, Speed;

public:
	Point();
	Point(int X1, int Y1, int coeff);
	~Point();

	virtual void Show() ;						//�������� ������
	virtual void Hide() ;						//������ ������
	virtual void MoveTo(int X1, int Y1) ;		//����������� �������

	virtual int GetX1();
	virtual int GetY1();
	virtual int GetCoeff();
	virtual int GetHealth();
	virtual int GetArmor();
	virtual int GetSpeed();
	virtual void SetHealth(int point);
};