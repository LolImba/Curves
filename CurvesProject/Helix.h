#pragma once
#include "Curve.h"
class Helix :
	public Curve
{
public:
	Point3D virtual getPointAtAngle(const double angle) override final;
	Point3D virtual getDerivativeAtAngle(const double angle) override final;
	explicit Helix(const double radius, const double step);
private:
	double r, step;
};

