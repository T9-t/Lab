#include <iostream>
#include "Bell.h"

using namespace std;

void Bell::sound() {
	
	if (isDing) {
		cout << "ding" << endl;
	}
	else {
		cout << "dong" << endl;
	}

	isDing = !isDing;
}