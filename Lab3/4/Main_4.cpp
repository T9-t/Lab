#include <iostream>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

using namespace std;

int main()
{
	Summator t;
	cout << t.sum(5) << endl;

	Summator* t2 = new SquareSummator;
	cout << t2->sum(2) << endl;

	Summator* t3 = NULL;
	
	char input;
	cout << "Input summator type (s-squareSummator, c-cubeSummator): ";
	cin >> input;
	
	switch (input)
	{
	case 's':

		t3 = new SquareSummator();
		break;

	case 'c':

		t3 = new CubeSummator();
		break;

	default:
		cout << "Enter summator type:\n";
		return -1;
	}
	
	cout << t3->sum(4) << endl;

	delete t2;
	delete t3;

	return 0;
}
