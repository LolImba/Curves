#pragma once
#include "Point3D.h"
#include <cmath>

#define pi 3.14159265358979323846


class Curve
{
public:
	Curve();
	virtual ~Curve();
	Point3D virtual getPointAtAngle(const double angle) = 0;
	Point3D virtual getDerivativeAtAngle(const double angle) = 0;

};

