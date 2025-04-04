#include <iostream>
#include <cmath>
#include "Trapezoid.h"

using namespace std;

Trapezoid::Trapezoid() {

	this->width1 = new double;
	this->width2 = new double;
	this->height = new double;
}

Trapezoid::Trapezoid(double width1, double width2, double height) {

	this->width1 = new double(width1);
	this->width2 = new double(width2);
	this->height = new double(height);
}

Trapezoid::~Trapezoid() {

	delete this->width1;
	delete this->width2;
	delete this->height;
}

double Trapezoid::calc_area() {

	return (*height * (*width1 + *width2)) / 2;
}

void Trapezoid::show() {

	cout << "Trapezoid is" << endl;
	cout << "\twidth ¹1:" << *width1 << endl;
	cout << "\twidth ¹2:" << *width2 << endl;
	cout << "\theight:" << *height << endl;
	cout << "\tarea:" << calc_area() << endl;
}