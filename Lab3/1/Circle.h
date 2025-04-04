#pragma once
#include "Figure.h"

class Circle: public Figure {

	double* radius;

public:

	Circle();

	Circle(double radius);

	virtual ~Circle() override;

	virtual double calc_area() override;

	virtual void show() override;
};