#pragma once
#include "Projectile.h"

class ArmorPiercing : public Projectile
{
public:
	ArmorPiercing();
	void ShootFromLeft(int& borders, bool& End) override;
	void ShootFromRight(int& borders, bool& End) override;
};