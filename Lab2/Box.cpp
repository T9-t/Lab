#include <iostream>
#include "Box.h"

using namespace std;

Box::Box() {

	this->number = new int;
	this->w = new int;
	this->v = new int;
}

Box::Box(int number, int w, int v) {

	this->number = new int(number);
	this->w = new int(w);
	this->v = new int(v);
}

Box::Box(const Box& cop) {

	this->number = new int(*cop.number);
	this->w = new int(*cop.w);
	this->v = new int(*cop.v);
}

Box::~Box() {

	delete this->number;
	delete this->w;
	delete this->v;
}

void Box::set_number(int number) {

	this->number = new int(number);
}

int Box::comparison_w(int w) {

	if (*this->w == w) {
		
		return *this->number;
	}
	else {
		return -1;
	}
}

int Box::comparison_v(int v) {

	if (*this->v == v) {

		return *this->number;
	}
	else {
		return -1;
	}
}

void Box::print_box() {

	if (*this->number >= 0) {
		cout << "\tBox number " << *this->number << endl;
		cout << "\tw = " << *this->w << "   " << "\tv = " << *this->v << endl;
	}
	else {
		cout << "\tBox number " << *this->number +100 << " is no longer in stock" << endl;
	}
}