#pragma once


class Point3D
{
public:
	double x, y, z;
	~Point3D();
	Point3D(const double x, const double y, const double z);
	void getXYZ();
};

