#pragma once
#include "ArmorPiercing.h"

extern std::mutex mtx3;

class Cumulative : public ArmorPiercing
{
public:
	void ShootCumFromLeft();
	void ShootCumFromRight();
	void CrushCum(int x, int y);
};

