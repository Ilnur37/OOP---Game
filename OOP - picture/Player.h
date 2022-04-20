#pragma once
#include <vector>
#include "Point.h"
#include <vector>

extern std::vector <Point*> vector_of_objects;

class Player : public Point
{
public:
	void ShowAll();
	void HideAll();
	void DragAll();

	void Gamer1(Point* object1);
	void Gamer2(Point* object2);
	void Shooter1(int a, int b, bool flag);
	void Shooter2(int a2, int b2, bool flag);

	void Crush(Point* object);
};