#include "stdafx.h"
#include "Point3D.h"
#include <iostream>


Point3D::Point3D(const double x_ = 0, const double y_ = 0, const double z_ = 0) : x(x_), y(y_), z(z_)
{
}

Point3D::~Point3D()
{
}

void Point3D::getXYZ()
{
	std::cout << "X = " << x << " Y = " << y << " Z = " << z << std::endl;
}
