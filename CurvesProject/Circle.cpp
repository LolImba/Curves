#include "stdafx.h"
#include "Circle.h"


Circle::Circle(const double radius) : r(radius)
{
}

Point3D Circle::getPointAtAngle(const double angle)
{
	return Point3D(r * cos(angle), r * sin(angle), 0);
}

Point3D Circle::getDerivativeAtAngle(const double angle)
{
	return Point3D(-r * sin(angle), r * cos(angle), 0);
}

