#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

Circle::Circle() {

	this->radius = new double;
}

Circle::Circle(double radius) {

	this->radius = new double(radius);
}

Circle::~Circle() {

	delete this->radius;
}

double Circle::calc_area() {

	return 2 * *radius * *radius * M_PI;
}

void Circle::show() {

	cout << "Circle is" << endl;
	cout << "\tradius:" << *radius << endl;
	cout << "\tarea:" << calc_area() << endl;
}