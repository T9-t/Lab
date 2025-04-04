#pragma once
#include "Figure.h"

class Rectangle : public Figure {

	double* width;
	double* height;

public:

	Rectangle();

	Rectangle(double width, double height);

	virtual ~Rectangle() override;

	virtual double calc_area() override;

	virtual void show() override;
};

