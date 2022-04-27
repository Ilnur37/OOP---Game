#pragma once
#include "ArmorPiercing.h"

extern std::mutex mtx3;

class Cumulative : public ArmorPiercing
{
public:
	void ShootCumFromLeft(bool& End);
	void ShootCumFromRight(bool& End);
	void CrushCum(int x, int y);
};