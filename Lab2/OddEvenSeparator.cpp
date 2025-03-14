#include <iostream>
#include "OddEvenSeparator.h"

using namespace std;

void OddEvenSeparator::printVector(vector<int>& vector) {

	for (int element : vector) {
		cout << element << endl;
	}
}

void OddEvenSeparator::add_number(int number) {

	if (number % 2 == 0) {
		evenNumbers.push_back(number);
	}
	else {
		oddNumbers.push_back(number);
	}
}

void OddEvenSeparator::even() {

	cout << "\even numbers:" << endl;
	printVector(evenNumbers);
}

void OddEvenSeparator::odd() {

	cout << "\odd numbers:" << endl;
	printVector(oddNumbers);
}