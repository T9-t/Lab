#pragma once

using namespace std;

class Rational {

	int* numerator;
	int* denominator;

public:

	Rational();

	Rational(int num, int den);

	Rational(const Rational& cop);

	Rational& operator= (const Rational& cop);

	~Rational();

	double doub();

	void irreducible();
	
	int get_numerator() const;

	int get_denominator() const;

	void set_numerator(int x);

	void set_denominator(int x);

	Rational& operator+ (const Rational& cop) const;

	Rational& operator- (const Rational& cop) const;

	Rational& operator* (const Rational& cop) const;

	Rational& operator/ (const Rational& cop) const;

	Rational& operator- (int x) const;

	Rational& operator+ (int x) const;

	Rational& operator* (int x) const;

	Rational& operator/ (int x) const;

	Rational operator+ () const;

	Rational operator- () const;

	Rational& operator+= (const Rational& cop);

	Rational& operator-= (const Rational& cop);

	Rational& operator*= (const Rational& cop);

	Rational& operator/= (const Rational& cop);

	bool operator== (const Rational& cop) const;

	bool operator!= (const Rational& cop) const;
	
	int gcd(int a, int b);//Макс. общий делитель
};
istream& operator>> (istream& in, Rational& cop);
	
ostream& operator << (ostream& out, Rational& cop);