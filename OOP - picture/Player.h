#pragma once
#include <vector>
#include "Point.h"

class Player : public Point
{
public:
	void ShowAll(std::vector <Point*>& vector_of_objects);
	void HideAll(std::vector <Point*>& vector_of_objects);
	void DragAll(std::vector <Point*>& vector_of_objects);

	void Gamer1(std::vector <Point*>& vector_of_objects);
	void Shooter1(int a, int b, std::vector <Point*>& vector_of_objects);
};