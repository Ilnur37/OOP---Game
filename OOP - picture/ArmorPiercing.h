#pragma once
#include <vector>
#include "Point.h"

extern std::vector <Point*> vector_of_objects; 

class ArmorPiercing : public Point
{
public:
	//void ShootApFromLeft(int a1, int b1);
	void ShootApFromLeft();
	void ShootApFromRight();
	void CrushAP(int x, int y);
};