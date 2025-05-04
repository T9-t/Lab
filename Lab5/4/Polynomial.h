#pragma once

#include <vector>
#include "Rational.h"
#include "Complex.h"

using namespace std;

template <typename T>
class Polynomial {//(x^3+x^2+x+1)

	T* x3;
	T* x2;
	T* x1;
	T* x0;
	double not_zero = true;

public:

	Polynomial(vector<T>& cof) {
	
		x0 = new T(cof[0]);
		x1 = new T(cof[1]);
		x2 = new T(cof[2]);
		x3 = new T(cof[3]);
	}
	Polynomial(T& c) {
	
		x0 = new T(c);
		x1 = new T(c);
		x2 = new T(c);
		x3 = new T(c);
		not_zero = false;
	}
	Polynomial(const Polynomial<T>& cop) {
	
		this->x0 = new T(*cop.x0);
		this->x1 = new T(*cop.x1);
		this->x2 = new T(*cop.x2);
		this->x3 = new T(*cop.x3);
		this->not_zero = cop.not_zero;
	}
	Polynomial& operator= (const Polynomial<T>& cop) {

		if (*this != cop) {
			this->x0 = new T(*cop.x0);
			this->x1 = new T(*cop.x1);
			this->x2 = new T(*cop.x2);
			this->x3 = new T(*cop.x3);
			this->not_zero = cop.not_zero;
		}
		return *this;
	}
	~Polynomial() {
	
		delete x0;
		delete x1;
		delete x2;
		delete x3;
	}

	int degree(T& cop) {

		if (cop == *this->x0) {
			return 0;
		}
		else if (cop == *this->x1 && not_zero == true) {
			return 1;
		}
		else if (cop == *this->x2 && not_zero == true) {
			return 2;
		}
		else if (cop == *this->x3 && not_zero == true) {
			return 3;
		}
		else if (cop != *this->x0 && cop != *this->x1 && cop != *this->x2 && cop != *this->x3) {
			return -1;
		}
	}

	double scalar(int x) { return x; }
	double scalar(Rational& x) { return x.doub(); }
	double scalar(Complex& x) { return x.abs(); }

	bool operator== (Polynomial<T>& cop){
	
		return (this->scalar(x0) == cop.scalar(x0) && this->scalar(x1) == cop.scalar(x1) && this->scalar(x2) == cop.scalar(x2) && this->scalar(x3) == cop.scalar(x3));
	}
	bool operator!= (Polynomial<T>& cop) {
	
		return (this->scalar(x0) != cop.scalar(x0) && this->scalar(x1) != cop.scalar(x1) && this->scalar(x2) != cop.scalar(x2) && this->scalar(x3) != cop.scalar(x3));
	}

	Polynomial<T>& operator+ (Polynomial<T>& cop) {
	
		Polynomial<T>* new_pol;
		vector<T> vec;
		bool not_bool;

		if (this->not_zero == cop.not_zero) {

			T x0_vec = *this->x0 + *cop.x0;
			vec.push_back(x0_vec);
			T x1_vec = *this->x1 + *cop.x1;
			vec.push_back(x1_vec);
			T x2_vec = *this->x2 + *cop.x2;
			vec.push_back(x2_vec);
			T x3_vec = *this->x3 + *cop.x3;
			vec.push_back(x3_vec);

			not_bool = this->not_zero;
		}
		else {
			if (this->not_zero == false) {

				vec.push_back(*this->x0 + *cop.x0);
				vec.push_back(*cop.x1);
				vec.push_back(*cop.x2);
				vec.push_back(*cop.x3);
			}
			else {
				vec.push_back(*this->x0 + *cop.x0);
				vec.push_back(*this->x1);
				vec.push_back(*this->x2);
				vec.push_back(*this->x3);
			}
			not_bool = true;
		}
		new_pol = new Polynomial(vec);
		vec.clear();
		new_pol->not_zero = not_bool;

		return *new_pol;
	}
	Polynomial<T>& operator- (Polynomial<T>& cop) {
	
		Polynomial<T>* new_pol;
		vector<T> vec;
		bool not_bool;

		if (this->not_zero == cop.not_zero) {

			T x0_vec = *this->x0 - *cop.x0;
			vec.push_back(x0_vec);
			T x1_vec = *this->x1 - *cop.x1;
			vec.push_back(x1_vec);
			T x2_vec = *this->x2 - *cop.x2;
			vec.push_back(x2_vec);
			T x3_vec = *this->x3 - *cop.x3;
			vec.push_back(x3_vec);

			not_bool = this->not_zero;
		}
		else {
			if (this->not_zero == false) {

				vec.push_back(*this->x0 - *cop.x0);
				vec.push_back(*cop.x1);
				vec.push_back(*cop.x2);
				vec.push_back(*cop.x3);
			}
			else {
				vec.push_back(*this->x0 - *cop.x0);
				vec.push_back(*this->x1);
				vec.push_back(*this->x2);
				vec.push_back(*this->x3);
			}
			not_bool = true;
		}
		new_pol = new Polynomial(vec);
		vec.clear();
		new_pol->not_zero = not_bool;

		return *new_pol;
	}
	Polynomial<T>& operator* (Polynomial<T>& cop) {
	
		Polynomial<T>* new_pol;
		vector<T> vec;
		bool not_bool;

		if (this->not_zero == cop.not_zero) {

			T x0_vec = *this->x0 * *cop.x0;
			vec.push_back(x0_vec);
			T x1_vec = *this->x1 * *cop.x1;
			vec.push_back(x1_vec);
			T x2_vec = *this->x2 * *cop.x2;
			vec.push_back(x2_vec);
			T x3_vec = *this->x3 * *cop.x3;
			vec.push_back(x3_vec);

			not_bool = this->not_zero;
		}
		else {
			if (this->not_zero == false) {

				vec.push_back(*this->x0 * *cop.x0);
				vec.push_back(*cop.x1);
				vec.push_back(*cop.x2);
				vec.push_back(*cop.x3);
			}
			else {
				vec.push_back(*this->x0 * *cop.x0);
				vec.push_back(*this->x1);
				vec.push_back(*this->x2);
				vec.push_back(*this->x3);
			}
			not_bool = true;
		}
		new_pol = new Polynomial(vec);
		vec.clear();
		new_pol->not_zero = not_bool;

		return *new_pol;
	}
	Polynomial<T>& operator+= (Polynomial<T>& cop) {
	
		if (this->not_zero == cop.not_zero) {
			
			*this->x0 = *this->x0 + *cop.x0;
			*this->x1 = *this->x1 + *cop.x1;
			*this->x2 = *this->x2 + *cop.x2;
			*this->x3 = *this->x3 + *cop.x3;
			
		}else {
			if (this->not_zero == false) { 
				
				*this->x0 = *this->x0 + *cop.x0;
				*this->x1 = *cop.x1;
				*this->x2 = *cop.x2;
				*this->x3 = *cop.x3;
			}
			else {
				*this->x0 = *this->x0 + *cop.x0;
			}
			this->not_zero = true;
		}
		return *this;
	}
	Polynomial<T>& operator*= (Polynomial<T>& cop) {
	
		if (this->not_zero == cop.not_zero) {

			*this->x0 = *this->x0 * *cop.x0;
			*this->x1 = *this->x1 * *cop.x1;
			*this->x2 = *this->x2 * *cop.x2;
			*this->x3 = *this->x3 * *cop.x3;
		}
		else {
			if (this->not_zero == false) {

				*this->x0 = *this->x0 * *cop.x0;
				*this->x1 = *cop.x1;
				*this->x2 = *cop.x2;
				*this->x3 = *cop.x3;
			}
			else {
				*this->x0 = *this->x0 * *cop.x0;
			}
			this->not_zero = true;
		}
		return *this;
	}

	Polynomial<T>& operator+ (T& cop) {

		vector<T> vec;
		vec.push_back(*this->x0 + cop);
		vec.push_back(*this->x1);
		vec.push_back(*this->x2);
		vec.push_back(*this->x3);

		Polynomial<T>* new_pol = new Polynomial(vec);
		new_pol->not_zero = this->not_zero;

		return *new_pol;
	}
	Polynomial<T>& operator- (T& cop) {

		vector<T> vec;
		vec.push_back(*this->x0 - cop);
		vec.push_back(*this->x1);
		vec.push_back(*this->x2);
		vec.push_back(*this->x3);

		Polynomial<T>* new_pol = new Polynomial(vec);
		new_pol->not_zero = this->not_zero;

		return *new_pol;
	}
	Polynomial<T>& operator* (T& cop) {
	
		vector<T> vec;
		vec.push_back(*this->x0 * cop);
		vec.push_back(*this->x1);
		vec.push_back(*this->x2);
		vec.push_back(*this->x3);

		Polynomial<T>* new_pol = new Polynomial(vec);
		new_pol->not_zero = this->not_zero;

		return *new_pol;
	}

	Polynomial<T>& operator+= (T& cop) {
	
		*this->x0 = *this->x0 + cop;
		return *this;
	}
	Polynomial<T>& operator*= (T& cop) {
	
		*this->x0 = *this->x0 * cop;
		return *this;
	}

	T& operator[] (int& st) {
		
		if (st == 0) {
			return *this->x0;
		}
		else if (st == 1 && not_zero == true) {
			return *this->x1;
		}
		else if (st == 2 && not_zero == true) {
			return *this->x2;
		}
		else if (st == 3 && not_zero == true) {
			return *this->x3;
		}
		else {
			T* a = new T(*this->x0 - *this->x0);
			return *a;
		}
	}
	double operator() (int& cop) {
	
		double sum = 0.0;
		if (not_zero == true) {
			sum = this->scalar(*this->x0) + (this->scalar(*this->x1) * cop) + (this->scalar(*this->x2) * cop * cop) + (this->scalar(*this->x3) * cop * cop * cop);
		}
		else {
			sum = this->scalar(*this->x0);
		}

		return sum;
	}

	friend ostream& operator<< (ostream& cou, Polynomial<T>& cop) {
	
		cou << "Polynomial:" << '\n';
		if (cop.not_zero != true) {
			cou <<"("<< 0 << ")x^3 + " <<"(" << 0 << ")x^2 + " << "(" << 0 << ")x + " << "(" << *cop.x0 << ")" << '\n';
		}
		else {
			cou << "(" << *cop.x3 << ")x^3 + " << "(" << *cop.x2 << ")x^2 + " << "(" << *cop.x1 << ")x + " << "(" << *cop.x0 << ")" << '\n';
		}
		return cou;
	}
};