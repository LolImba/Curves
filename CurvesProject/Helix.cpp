#include "stdafx.h"
#include "Helix.h"


Helix::Helix(const double radius, const double step_) : r(radius), step(step_)
{
}

Point3D Helix::getPointAtAngle(const double angle)
{
	return Point3D(r * cos(angle), r * sin(angle), step * angle / (2 * pi));
}

Point3D Helix::getDerivativeAtAngle(const double angle)
{
	return Point3D(-r * sin(angle), r * cos(angle), step / (2 * pi));
}


