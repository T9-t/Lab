#pragma once
#include "Figure.h"

class Triangle:public Figure {

	double* width;
	double* height;

public:

	Triangle();

	Triangle(double width, double height);

	virtual ~Triangle() override;

	virtual double calc_area() override;

	virtual void show() override;
};