#pragma once

class Complex {

	double* re;
	double* im;

public:
	
	Complex();

	Complex(double x, double y);

	Complex(const Complex& cop);

	~Complex();

	double get_re() const;

	void set_re(double re);

	double get_im() const;

	void set_im(double im);

	double abs();

	double arg();

	void print();

	void trig_print();

	void exp_print();

	Complex add(Complex z);

	Complex sub(Complex z);

	Complex mult(Complex z);

	Complex div(Complex z);
};