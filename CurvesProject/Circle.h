#pragma once
#include "Curve.h"
class Circle :
	public Curve
{
public:
	Point3D getPointAtAngle(const double angle) override final;
	Point3D virtual getDerivativeAtAngle(const double angle) override final;
	explicit Circle(double radius);
	inline double getRadius() const { return r; }
private:
	double r;
};

