#pragma once
#include "Cumulative.h"

class Fragmentation : public Cumulative
{
public:
	void ShootFragmFromLeft();
	void ShootFragmFromRight();
	void CrushFragm(int x, int y);
};