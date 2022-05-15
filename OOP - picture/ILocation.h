#pragma once
#include <iostream>
#include <Windows.h>

extern HDC hdc;
extern HDC hdc2;
extern HDC hdc3;
extern HDC hdc4;
extern HDC hdc5;
extern HDC hdc6;
//extern HDC hdc7;
extern HDC hdc8;

// Макрос для проверки состояния клавиатуры – из ШАБЛОНА
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

class ILocation
{
public:

	virtual void Show() = 0;					//Показать объект
	virtual void Hide() = 0;					//Скрыть объект
	virtual void MoveTo(int X1, int Y1) = 0;	//Перемещение объекта

	virtual int GetX1() = 0;
	virtual int GetY1() = 0;
	virtual int GetCoeff() = 0;
	virtual int GetHealth() = 0;
	virtual int GetArmor() = 0;
	virtual int GetSpeed() = 0;
	virtual void SetHealth(int point) = 0;
};