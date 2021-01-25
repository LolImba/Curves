#include "stdafx.h"
#include "Ellipse.h"


Ellipse::Ellipse(const double radius1, const double radius2) : r1(radius1), r2(radius2)
{
}

Point3D Ellipse::getPointAtAngle(const double angle)
{
	return Point3D(r1 * cos(angle), r2 * sin(angle), 0);
}

Point3D Ellipse::getDerivativeAtAngle(const double angle)
{
	return Point3D(-r1 * sin(angle), r2 * cos(angle), 0);
}

