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

Complex& Complex::operator= (const Complex& cop){

	if (this != &cop) {

		this->re = new double(*cop.re);
		this->im = new double(*cop.im);
	}
	return *this;
}

Complex::~Complex() {

	delete this->re;
	delete this->im;
}

double Complex::get_re() const {

	return *re;
}

double Complex::get_im() const {

	return *im;
}

double Complex::abs() const{

	return sqrt((*re * *re) + (*im * *im));
}

Complex& Complex::operator+ (const Complex& z) const{

	double new_re = *this->re + *z.re;
	double new_im = *this->im + *z.im;

	Complex* result = new Complex(new_re, new_im);

	return *result;
}
Complex Complex::operator* (int z) {

	double new_re = *this->re * z;
	double new_im = *this->im * z;

	Complex* result = new Complex(new_re, new_im);

	return *result;
}

Complex& Complex::operator+ (int r) const {

	Complex* result = new Complex(*re+r,*im);

	return *result;
}

Complex& Complex::operator++ () {

	*this->re += 1;
	*this->im += 1;

	return *this;
}

Complex& Complex::operator++ (int) {

	Complex copy( *this );
	++(*this);
	return copy;
}

Complex& Complex::operator- (const Complex& z) const{

	double new_re = *this->re - *z.re;
	double new_im = *this->im - *z.im;

	Complex* result = new Complex(new_re, new_im);

	return *result;
}

Complex  Complex::operator- () const{

	Complex new_com{ -*re,-*im };
	return new_com;
}

Complex& Complex::operator-- (){

	*this->re -= 1;
	*this->im -= 1;

	return *this;
}

Complex Complex::operator-- (int) {

	Complex copy( *this );
	--(*this);
	return copy;
}

Complex Complex::operator* (const Complex& z) const{
	
	double new_re = *this->re * *z.re - *this->im * *z.im;
	double new_im = *this->re - *z.im - *this->im * *z.re;

	Complex* result = new Complex(new_re, new_im);

	return *result;
}

Complex Complex::operator/ (const Complex& z) const{

	double del = *z.re * *z.re + *z.im * *z.im;
	double new_re = *this->re * *z.re + *this->im * *z.im;
	new_re /= del;

	double new_im = *this->im * *z.re + *this->re * *z.re;
	new_im /= del;

	Complex* result = new Complex(new_re, new_im);

	return *result;
}

bool Complex::operator > (const Complex& z) const{

	if ((*this).abs() > z.abs()) {

		return true;
	}
	return false;
}

bool Complex::operator < (const Complex& z) const{

	if ((*this).abs() < z.abs()) {

		return true;
	}
	return false;
}

bool Complex::operator == (const Complex& z) const{
	
	if ((*this).abs() == z.abs()) {

		return true;
	}
	else {
		return false;
	}
}

bool Complex::operator != (const Complex& z) const{

	if ((*this).abs() != z.abs()) {

		return true;
	}
	else {
		return false;
	}
}

istream& operator>> (istream& in, Complex& z) {

	cout << "re and im: ";
	in >> *z.re >> *z.im;

	return in;
}

ostream& operator<< (ostream& out, Complex& z) {

	double re = z.get_re();
	double im = z.get_im();
	out << re << " + i * " << im;

	return out;
}