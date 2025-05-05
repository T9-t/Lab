#pragma once

using namespace std;

class Complex {

	double* re;
	double* im;

public:

	Complex();

	Complex(double x, double y);

	Complex(const Complex& cop);

	Complex& operator= (const Complex&);

	~Complex();

	double get_re() const;

	double get_im() const;

	double abs() const;

	Complex& operator+ (const Complex& z) const;

	Complex& operator+ (int) const;

	Complex& operator++ ();

	Complex& operator++ (int);

	Complex& operator- (const Complex& z) const;

	Complex operator- () const;

	Complex& operator-- ();

	Complex operator-- (int);

	Complex operator* (const Complex& z) const;
	Complex operator* (int z);

	Complex operator/ (const Complex& z) const;

	bool operator > (const Complex& z) const;

	bool operator < (const Complex& z) const;

	bool operator == (const Complex & z) const;

	bool operator != (const Complex& z) const;

	friend istream& operator>> (istream&, Complex&);
	
	friend ostream& operator<< (ostream&, Complex&);
};