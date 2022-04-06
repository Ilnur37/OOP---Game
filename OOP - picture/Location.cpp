#include "Location.h"

Location::Location(int X1, int Y1)
{
	this->X1 = X1;
	this->Y1 = Y1;
}

Location::~Location()
{
}

int Location::GetX1() { return X1; }

int Location::GetY1() { return Y1; }