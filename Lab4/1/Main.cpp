#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	Complex a_number(4, 5);
	cout << a_number;
	Complex b_number(10, 3);
	cout << b_number << endl;
	Complex c_number;
	Complex d_number;
	Complex e_number;
	

	cout << "********cin >> d_number" << endl;
	cin >> d_number;
	cout << d_number << endl;
	cout << "********c_number = -b_number" << endl;
	c_number = - b_number;
	cout << c_number << endl;
	
	cout << "********a_number + b_number" << endl;
	cout << a_number + b_number << endl;
	cout << "********a_number + 5" << endl;
	cout << a_number + 5 << endl;
	cout << "********a_number - b_number" << endl;
	cout << a_number - b_number << endl;
	cout << "********a_number * b_number" << endl;
	e_number = a_number * b_number;
	cout << e_number << endl;
	cout << "********a_number / b_number" << endl;
	e_number = a_number / b_number;
	cout << e_number << endl;

	cout << "********a_number--" << endl;
	a_number--;
	cout << a_number << endl;
	cout << "********--a_number" << endl;
	cout << --a_number << endl;
	cout << "********++a_number" << endl;
	cout << ++a_number << endl;
	cout << "********a_number++" << endl;
	a_number++;
	cout << a_number << endl;

	bool a;
	cout << "********a_number < b_number" << endl;
	a = a_number < b_number;
	cout << a << endl;
	cout << "********a_number > b_number" << endl;
	a = a_number > b_number;
	cout << a << endl;
	cout << "********a_number != b_number" << endl;
	a = a_number != b_number;
	cout << a << endl;
	cout << "********a_number == b_number" << endl;
	a = a_number == b_number;
	cout << a << endl;

	return 0;
}