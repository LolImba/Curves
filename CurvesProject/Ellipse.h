#pragma once
#include "Curve.h"
class Ellipse :
	public Curve
{
public:
	Point3D virtual getPointAtAngle(const double angle) override final;
	Point3D virtual getDerivativeAtAngle(const double angle) override final;
	explicit Ellipse(const double radius1, const double radius2);
private:
	double r1, r2;
};

