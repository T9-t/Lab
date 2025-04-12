#include <iostream>
#include "Rational.h"

using namespace std;

int main(){

	Rational r1(5,15);
	Rational r2;
	Rational r3;

	cout << r1;
	cin >> r2;
	cout << r2 << endl;
	cout << "******** r3 = r1" << endl;
	r3 = r1;
	cout << r3 << endl;

	cout << "******** r1 + r2" << endl;
	cout << r1 + r2 << endl;
	cout << "******** r1 - r2" << endl;
	cout << r1 - r2 << endl;
	cout << "******** r1 * r2" << endl;
	cout << r1 * r2 << endl;
	cout << "******** r1 / r2" << endl;
	cout << r1 / r2 << endl;

	cout << "******** r1 + 4" << endl;
	cout << r1 + 4 << endl;
	cout << "******** r1 - 2" << endl;
	cout << r1 - 2 << endl;
	cout << "******** r1 * 3" << endl;
	cout << r1 * 3 << endl;
	cout << "******** r1 / 2" << endl;
	cout << r1 / 2 << endl;

	cout << "******** -r1" << endl;
	-r1;
	cout << r1 << endl;
	cout << "******** +r1" << endl;
	+r1;
	cout << r1 << endl;

	cout << "******** r1 += r2" << endl;
	r1 += r2;
	cout << r1 << endl;
	cout << "******** r1 -= r2" << endl;
	r1 -= r2;
	cout << r1 << endl;
	cout << "******** r1 *= r2" << endl;
	r1 *= r2;
	cout << r1 << endl;
	cout << "******** r1 /= r2" << endl;
	r1 /= r2;
	cout << r1 << endl;

	cout << "******** r1 == r2" << endl;
	bool a = r1 == r2;
	cout << a << endl;
	cout << "******** r1 != r2" << endl;
	a = r1 != r2;
	cout << a << endl;

	return 0;
}