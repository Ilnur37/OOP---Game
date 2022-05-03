#pragma once
#include "Projectile.h"

class Cumulative : public Projectile
{
public:
	Cumulative();
	void ShootFromLeft(int& borders, bool& End) override;
	void ShootFromRight(int& borders, bool& End) override;
};