#include <iostream>
#include "Triangle.h"

using namespace std;

Triangle::Triangle() {

	this->width = new double;
	this->height = new double;
}

Triangle::Triangle(double width, double height) {

	this->width = new double(width);
	this->height = new double(height);
}

Triangle::~Triangle() {

	delete this->width;
	delete this->height;
}

double Triangle::calc_area() {

	return (*width * *height) / 2;
}

void Triangle::show() {

	cout << "Triangle is" << endl;
	cout << "\twidth:" << *width << endl;
	cout << "\theight:" << *height << endl;
	cout << "\tarea:" << calc_area() << endl;
}