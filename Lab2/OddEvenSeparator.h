#pragma once
#include <vector>

using namespace std;

class OddEvenSeparator {

	vector<int>evenNumbers;
	vector<int>oddNumbers;

	void printVector(vector<int>& vector);

public:

	void add_number(int number);

	void even();

	void odd();
};