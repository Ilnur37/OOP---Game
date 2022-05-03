#pragma once
#include <vector>
#include "Point.h"

extern std::vector <Point*> vector_of_objects;

class Projectile
{
protected:
	int damage;
public:
	int GetDamage();
	virtual void ShootFromLeft(int& borders, bool& End) = 0;
	virtual void ShootFromRight(int& borders, bool& End) = 0;
	void Crush(Point* object, int x, int y, bool& End, bool placeHP);
};