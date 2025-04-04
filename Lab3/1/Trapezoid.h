#pragma once
#include "Figure.h"

class Trapezoid:public Figure {

	double* width1;
	double* width2;
	double* height;

public:

	Trapezoid();

	Trapezoid(double width1,double width2,double height);

	virtual ~Trapezoid() override;

	virtual double calc_area() override;

	virtual void show() override;
};