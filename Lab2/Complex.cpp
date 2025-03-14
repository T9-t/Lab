#include <math.h>
#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() {

	this->re = new double;
	this->im = new double;
}

Complex::Complex(double x, double y) {

	this->re = new double(x);
	this->im = new double(y);
}

Complex::Complex(const Complex& cop) {

	this->re = new double(*cop.re);
	this->im = new double(*cop.im);
}

Complex::~Complex() {
	
	delete this->re;
	delete this->im;
}

double Complex::get_re() const {

	cout << "re = ";
	return *re;
}

void Complex::set_re(double re) {

	*this->re = re;
}

double Complex::get_im() const {

	cout << "im = ";
	return *im;
}

void Complex::set_im(double im) {

	*this->im = im;
}

double Complex::abs() {

	return sqrt((*re * *re) + (*im * *im));
} 

double Complex::arg() {

	return atan2(*im, *re);
}

void Complex::print() {

	cout << "complex number: " << *re << " + i * " << *im << endl;
}

void Complex::trig_print() {

	double len = abs();
	double phi = arg();

	cout << len << " * (cos(" << phi << ") + i*sin(" << phi << ")" << endl;
}

void Complex::exp_print() {

	double len = abs();
	double phi = arg();

	cout << len << " * e^(i*" << phi << ")" << endl;
}

Complex Complex::add(Complex z) {

	double new_re = *this->re + *z.re;
	double new_im = *this->im + *z.im;

	Complex result(new_re, new_im);
	result.print();
	return result;
}

Complex Complex::sub(Complex z) {

	double new_re = *this->re - *z.re;
	double new_im = *this->im - *z.im;

	Complex result(new_re, new_im);
	result.print();
	return result;
}

Complex Complex::mult(Complex z) {

	double new_re = *this->re * *z.re - *this->im * *z.im;
	double new_im = *this->re - *z.im - *this->im * *z.re;

	Complex result(new_re, new_im);
	result.print();
	return result;
}

Complex Complex::div(Complex z) {

	double del = *z.re * *z.re + *z.im * *z.im;
	double new_re = *this->re * *z.re + *this->im * *z.im;
	new_re /= del;

	double new_im = *this->im * *z.re + *this->re * *z.re;
	new_im /= del;

	Complex result(new_re, new_im);
	result.print();
	return result;
}