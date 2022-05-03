#pragma once
#include "Projectile.h"

class Fragmentation : public Projectile
{
public:
	Fragmentation();
	void ShootFromLeft(int& borders, bool& End) override;
	void ShootFromRight(int& borders, bool& End) override;
};