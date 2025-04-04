#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Trapezoid.h"
#include "Rectangle.h"

using namespace std;

double volume(Figure& figure, double height) {

	return figure.calc_area() * height;
}

int main()
{
	//***********************************************************
	// Задание 1

	Rectangle box(1, 3);
	box.show();

	Circle cir(3);
	cir.show();

	Figure* figur_new = NULL;

	char input;
	cout << "Input figure type (c-circle, r-rectangle, t-triangle, z-trapezoid): ";
	cin >> input;

	switch (input)
	{
	case 'c':

		double radius;
		cout << "Input the radius:\n";
		cin >> radius;

		figur_new = new Circle(radius);
		break;

	case 'r':

		double width, height;
		cout << "Input the width:\n";
		cin >> width;
		cout << "Input the height:\n";
		cin >> height;

		figur_new = new Rectangle(width, height);
		break;

	case 't':

		double width_t, height_t;
		cout << "Input the width:\n";
		cin >> width_t;
		cout << "Input the height:\n";
		cin >> height_t;

		figur_new = new Triangle(width_t, height_t);
		break;

	case'z':

		double width1, width2, height_z;
		cout << "Input the width №1:\n";
		cin >> width1;
		cout << "Input the width №2:\n";
		cin >> width2;
		cout << "Input the height:\n";
		cin >> height_z;

		figur_new = new Trapezoid(width1, width2, height_z);
		break;

	default:
		cout << "Enter valid figure type:\n";
		return -1;
	}

	figur_new->show();

	cout << "Imput the height of Cylinder" << endl;
	double height;
	cin >> height;

	cout << "The volume of Cylinder = " << volume(*figur_new, height);

	return 0;
}