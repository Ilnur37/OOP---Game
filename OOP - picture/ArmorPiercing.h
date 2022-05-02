#pragma once
#include <vector>
#include "Point.h"

extern std::vector <Point*> vector_of_objects; 

class ArmorPiercing : public Point
{
protected:
	int damage;
public:
	ArmorPiercing();
	int GetDamage();
	void ShootFromLeft(int& borders, bool& End);
	void ShootFromRight(int& borders, bool& End);
	void Crush(Point* object, int x, int y, bool& End, bool placeHP);
};