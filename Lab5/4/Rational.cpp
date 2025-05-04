#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational(){

	this->numerator = new int(0);
	this->denominator = new int(1);
}

Rational::Rational(int num, int den){

	this->numerator = new int(num);
	this->denominator = new int(den);

	this->irreducible();
}

Rational::Rational(const Rational& cop){

	this->numerator = new int(*cop.numerator);
	this->denominator = new int(*cop.denominator);
}

Rational& Rational::operator= (const Rational& cop){

	if (*this != cop) {

		this->numerator = new int(*cop.numerator);
		this->denominator = new int(*cop.denominator);
	}
	return *this;
}

Rational::~Rational(){

	delete this->numerator;
	delete this->denominator;
}

double Rational::doub() {

	return *numerator / *denominator;
}

//Сокращение дроби если это возможно
void Rational::irreducible() {

	int divider = gcd(*this->numerator, *this->denominator);

	if (*this->denominator< 0) {
		
		*this->numerator *= -1;
		*this->denominator *= -1;
	}
	*this->numerator /= divider;
	*this->denominator /= divider;
}

int Rational::get_numerator() const{

	return *this->numerator;
}

int Rational::get_denominator() const{

	return *this->denominator;
}

void Rational::set_numerator(int x){

	*this->numerator = x;
}

void Rational::set_denominator(int x){

	*this->denominator = x;
}

//Сложение дробей
Rational& Rational::operator+ (const Rational& cop) const {

	int new_denom = *this->denominator, new_num;

	if (*this->denominator != *cop.denominator) {

		new_denom = *this->denominator * *cop.denominator;
		new_num = (*this->numerator * *cop.denominator) + (*cop.numerator * *this->denominator);
	}
	else {
		new_num = *this->numerator + *cop.numerator;
	}
	Rational* rat_cop = new Rational(new_num, new_denom);
	rat_cop->irreducible();

	return *rat_cop;
}

//Вычитание из дроби дробь
Rational& Rational::operator- (const Rational& cop) const {

	int new_denom = *this->denominator, new_num;

	if (*this->denominator != *cop.denominator) {

		new_denom = *this->denominator * *cop.denominator;
		new_num = (*this->numerator * *cop.denominator) - (*cop.numerator * *this->denominator);
	}
	else {
		new_num = *this->numerator - *cop.numerator;
	}
	Rational* rat_cop = new Rational(new_num, new_denom);
	rat_cop->irreducible();

	return *rat_cop;
}

//Перемножение дробей
Rational& Rational::operator* (const Rational& cop) const {

	Rational* rat_cop = new Rational(*this->numerator * *cop.numerator, *this->denominator * *cop.denominator);
	rat_cop->irreducible();

	return *rat_cop;
}

//Деление между дробями
Rational& Rational::operator/ (const Rational& cop) const {

	Rational* rat_cop = new Rational(*this->numerator * *cop.denominator, *this->denominator * *cop.numerator);
	rat_cop->irreducible();

	return *rat_cop;
}

//Сложение дроби и числа
Rational& Rational::operator+ (int x) const {

	Rational* rat_cop = new Rational(*this->numerator + (x * *this->denominator), *this->denominator);
	rat_cop->irreducible();

	return *rat_cop;
}

//Вычитание из дроби числа
Rational& Rational::operator- (int x) const {

	Rational* rat_cop = new Rational(*this->numerator - (x * *this->denominator), *this->denominator);
	rat_cop->irreducible();

	return *rat_cop;
}

//Перемноение дроби и числа
Rational& Rational::operator* (int x) const {

	Rational* rat_cop = new Rational(*this->numerator * x, *this->denominator);
	rat_cop->irreducible();

	return *rat_cop;
}

//Деление дроби на число
Rational& Rational::operator/ (int x) const {

	Rational* rat_cop = new Rational(*this->numerator, *this->denominator * x);
	rat_cop->irreducible();

	return *rat_cop;
}

//Сделать положительным
Rational Rational::operator+ () const {

	if (*this->numerator < 0) {

		Rational* rat_cop = new Rational(-1 * *this->numerator, *this->denominator);
		rat_cop->irreducible();

		return *rat_cop;
	}
	return *this;
}

//Сделать отрицательным
Rational Rational::operator- () const {

	Rational* rat_cop = new Rational(-1 * *this->numerator, *this->denominator);
	rat_cop->irreducible();

	return *rat_cop;
}

Rational& Rational::operator+= (const Rational& cop){

	if (*this->denominator != *cop.denominator) {

		*this->denominator *= *cop.denominator;
		*this->numerator *= *cop.denominator; 
		*this->numerator += (*cop.numerator * *this->denominator);
	}
	else {
		*this->numerator += *cop.numerator;
	}
	this->irreducible();

	return *this;
}

Rational& Rational::operator-= (const Rational& cop){

	if (*this->denominator != *cop.denominator) {

		*this->denominator *= *cop.denominator;
		*this->numerator *= *cop.denominator;
		*this->numerator -= (*cop.numerator * *this->denominator);
	}
	else {
		*this->numerator -= *cop.numerator;
	}
	this->irreducible();

	return *this;
}

Rational& Rational::operator*= (const Rational& cop){

	*this->numerator *= *cop.numerator;
	*this->denominator *= *cop.denominator;
	this->irreducible();

	return *this;
}

Rational& Rational::operator/= (const Rational& cop){

	*this->numerator *= *cop.denominator;
	*this->denominator *= *cop.numerator;
	this->irreducible();

	return *this;
}

bool Rational::operator== (const Rational& cop) const{

	if (*this->numerator == *cop.numerator && *this->denominator == *cop.denominator) {

		return true;
	}
	else {
		return false;
	}
}

bool Rational::operator!= (const Rational& cop) const{

	if (*this->numerator != *cop.numerator && *this->denominator != *cop.denominator) {

		return true;
	}
	else {
		return false;
	}
}

istream& operator>> (istream& in, Rational& cop){

	int num, den;
	cout << "Input numerator and denominator: ";
	in >> num >> den;

	cop.set_numerator(num);
	cop.set_denominator(den);

	return in;
}

ostream& operator << (ostream& out, Rational& cop){

	out << cop.get_numerator() << "/" << cop.get_denominator();
	return out;
}

int Rational::gcd(int a, int b) {

	int max_a = 1, max_b = 1, max = 1, min_number;
	
	if (a < 0) {
		a *= -1;
	}
	if (b < 0) {
		b *= -1;
	}
	if (a < b) {
		min_number = a;
	}
	else {
		min_number = b;
	}
	for (int i = 1; i <= min_number; i++) {
		if (a % i == 0) {
			max_a = i;
		}
		if (b % i == 0) {
			max_b = i;
		}
		if (max_a == max_b) {
			max = max_a;
		}
	}
	return max;
}