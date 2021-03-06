// CurvesProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <random>
#include <numeric>
#include <iostream>
#include <omp.h>
#include <chrono>


using namespace std;

int main()
{
	vector<shared_ptr<Curve>> curves;
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distributionInt(1, 10);
	uniform_real_distribution<> distributionReal(1, 10);
	int randomSize = distributionInt(generator);
	for (size_t i = 0; i < randomSize; i++)
	{
		curves.emplace_back(new Circle(distributionReal(generator)));
	}

	randomSize = distributionInt(generator);
	for (size_t i = 0; i < randomSize; i++)
	{
		double r1 = distributionReal(generator);
		double r2 = distributionReal(generator);
		if(r1 > r2)
			curves.emplace_back(new Ellipse(r1, r2));
		else
			curves.emplace_back(new Ellipse(r2, r1));
	}


	randomSize = distributionInt(generator);
	uniform_real_distribution<> stepDistr(1, 3);
	for (size_t i = 0; i < randomSize; i++)
	{
		curves.emplace_back(new Helix(distributionReal(generator), stepDistr(generator)));
	}

	for (size_t i = 0; i < curves.size(); i++)
	{
		cout << typeid(*curves[i]).name() << endl;
		cout << "Point at angle: " << endl;
		curves[i]->getPointAtAngle(pi / 4).getXYZ();
		cout << "Derivative: " << endl;
		curves[i]->getDerivativeAtAngle(pi / 4).getXYZ();
	}


	vector<shared_ptr<Circle>> circles;
	for (size_t i = 0; i < curves.size(); i++)
	{
		if (typeid(*curves[i]) == typeid(Circle))
		{
			circles.emplace_back(dynamic_pointer_cast<Circle>(curves[i]));
		}
	}

	sort(circles.begin(), circles.end(), [](shared_ptr<Circle>& circle1, shared_ptr<Circle>& circle2) {
		return circle1->getRadius() < circle2->getRadius();
	});

//	auto start = std::chrono::high_resolution_clock::now();

	//standart sum of radii

	/*double result = accumulate(circles.begin(), circles.end(), 0.0, [](double sum, shared_ptr<Circle>& circle) {
		return sum + circle->getRadius();
	});*/

	double result = 0;

	size_t threadNum = min(static_cast<size_t>(omp_get_max_threads()), circles.size());
	omp_set_num_threads(threadNum);

	//parallel sum of radii
	#pragma omp parallel for
	for (int i = 0; i < circles.size(); ++i)
	{
		result += circles[i]->getRadius();
	}

	//std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
	cout << "Sum = " << result << endl;
	//cout << "Code time: " << elapsed.count() << endl;
	system("pause");
    return 0;
}

