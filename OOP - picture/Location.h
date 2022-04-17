#pragma once
#include <iostream>
#include <Windows.h>

extern HDC hdc;      // объявим  контекст устройства
extern HDC hdc2;
extern HDC hdc3;

// Макрос для проверки состояния клавиатуры – из ШАБЛОНА
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

class Location
{
protected:
	int X1, Y1;
public:
	Location();
	Location(int X1, int Y1);
	~Location();

	int GetX1();
	int GetY1();
};