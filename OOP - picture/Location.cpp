#include "Location.h"


Location::Location()
{
}

Location::Location(int X1, int Y1, int coeff)
{
	this->X1 = X1;
	this->Y1 = Y1;
	this->coeff = coeff;
}

Location::~Location()
{
}

int Location::GetX1() { return X1; }

int Location::GetY1() { return Y1; }

int Location::GetCoeff() { return coeff; }
