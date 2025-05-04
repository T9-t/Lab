#include <iostream>
#include <string>
#include <vector>
#include "Contains.h"
#include "Change.h"
#include "Matrix.h"
#include "Polynomial.h"

using namespace std;

int main() {

	// 1, 2
	int n = 4;
	int* array{ new int[n] { 1,2,3,4 } };
	
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "*********--1--**********" << endl;
	cout << Contains<int>(1, array, n) << endl;
	cout << Contains<int>(6, array, n) << endl;
	cout << "*********--2--*********" << endl;

	cout << Change<int>(2, 3, array, n) << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < n; i++) {
		//cout << array[i] << " ";
	}
	cout << endl;
	cout << "***********************" << endl;

	cout << Change<int>(0, 3, array, n) << endl;

	delete[] array;
	//************************************************************************
	// 3
	int j = 4;
	Matrix<int>* new_mat = new Matrix<int>(2, 2);
	Matrix<int>* new_mat2;
	Matrix<string>* new_mat_a = new Matrix<string>(2, 2);

	cout << "***********************" << endl;
	cin >> *new_mat;
	cout << *new_mat;
	cout << "***********************" << endl;
	cin >> *new_mat_a;
	cout << *new_mat_a;
	cout << "***********************" << endl;

	new_mat2 = new_mat;
	cout << *new_mat2;
	cout << "***********************" << endl;

	new_mat->set_data(0,0,j);
	cout << *new_mat;
	cout << new_mat->get_data(1, 1) << endl;
	cout << "***********************" << endl;

	cout << *new_mat + *new_mat2;
	cout << "***********************" << endl;
	cout << *new_mat * *new_mat2;
	cout << "***********************" << endl;

	cout << *new_mat_a + *new_mat_a;
	cout << "***********************" << endl;
	
	//************************************************************************
	// 4 

	int a = 5;
	vector<int> vec{ 5,6,1,3 };
	Polynomial<int>* new_pol = new Polynomial<int>(a);
	Polynomial<int>* new_pol2 = new Polynomial<int>(vec);

	Rational* new_rat = new Rational(2,-5);
	Polynomial<Rational>* new_rat_2 = new Polynomial<Rational>(*new_rat);

	Complex* new_com = new Complex(1, 3);
	Polynomial<Complex>* new_com_1 =  new Polynomial<Complex>(*new_com);

	cout << "***********************" << endl;
	cout << *new_pol;
	cout << *new_pol2;
	cout << *new_rat_2;
	cout << *new_com_1;
	cout << "***********************" << endl;

	cout << "Rational == Rational" << endl;
	bool a1 = new_rat_2 == new_rat_2;
	cout << a1 << endl;
	cout << "Rational != Rational" << endl;
	a1 = new_rat_2 != new_rat_2;
	cout << a1 << endl;
	cout << "***********************" << endl;

	int b_1 = new_rat_2->degree(*new_rat);
	cout <<"Degree of polynomial: " <<  b_1 << endl;

	cout << "********--+--**********" << endl;
	cout << *new_rat_2 + *new_rat_2;
	cout << *new_pol + *new_pol2;
	cout << *new_com_1 + *new_com_1;
	cout << "*********----**********" << endl;
	cout << *new_rat_2 - *new_rat_2;
	cout << *new_pol - *new_pol2;
	cout << *new_com_1 - *new_com_1;
	cout << "********--*--**********" << endl;
	cout << *new_rat_2 * *new_rat_2;
	cout << *new_pol * *new_pol2;
	cout << *new_com_1 * *new_com_1;
	cout << "********-+=--**********" << endl;
	*new_rat_2 += *new_rat_2;
	cout << *new_rat_2;
	*new_pol += *new_pol2;
	cout << *new_pol;
	*new_com_1 += *new_com_1;
	cout << *new_com_1;
	cout << "********-*=--**********" << endl;
	*new_rat_2 *= *new_rat_2;
	cout << *new_rat_2;
	*new_pol *= *new_pol2;
	cout << *new_pol;
	*new_com_1 *= *new_com_1;
	cout << *new_com_1;
	cout << "********************************************************" << endl;
	cout << "********--+--**********" << endl;
	cout << *new_rat_2 + *new_rat;
	cout << *new_pol + a;
	cout << *new_com_1 + *new_com;
	cout << "*********----**********" << endl;
	cout << *new_rat_2 - *new_rat;
	cout << *new_pol - a;
	cout << *new_com_1 - *new_com;
	cout << "********--*--**********" << endl;
	cout << *new_rat_2 * *new_rat;
	cout << *new_pol * a;
	cout << *new_com_1 * *new_com;
	cout << "********-+=--**********" << endl;
	*new_rat_2 += *new_rat;
	cout << *new_rat_2;
	*new_pol += a;
	cout << *new_pol;
	*new_com_1 += *new_com;
	cout << *new_com_1;
	cout << "********-*=--**********" << endl;
	*new_rat_2 *= *new_rat;
	cout << *new_rat_2;
	*new_pol *= a;
	cout << *new_pol;
	*new_com_1 *= *new_com;
	cout << *new_com_1;
	cout << "***********************" << endl;
	int c = 0, p = 3, pp = 1;
	cout << new_rat_2->operator[](c) << endl;
	cout << new_pol->operator[](p) << endl;
	cout << new_com_1->operator[](c) << endl;
	cout << "***********************" << endl;
	cout << new_rat_2->operator()(pp) << endl;
	cout << new_pol->operator()(pp) << endl;
	cout << new_com_1->operator()(pp) << endl;

	delete new_mat;
	delete new_mat2;

	delete new_pol2;
	delete new_rat;
	delete new_com;
	delete new_com_1;
	delete new_rat_2;
	delete new_pol;
	
	return 0;
}