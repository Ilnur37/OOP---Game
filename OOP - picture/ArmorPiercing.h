#pragma once
#include <vector>
#include "Point.h"

extern std::vector <Point*> vector_of_objects; 

class ArmorPiercing : public Point
{
public:
	void ShootApFromLeft(bool& End);
	void ShootApFromRight(bool& End);
	void CrushAP(Point* object, int x, int y, bool& End);
};