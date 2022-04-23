#pragma once
#include <vector>
#include "Fragmentation.h"
#include <vector>


class Player : public Fragmentation
{
public:
	void ShowAll();
	void HideAll();

	void Gamer1(Point* object1);
	void Gamer2(Point* object2);
};