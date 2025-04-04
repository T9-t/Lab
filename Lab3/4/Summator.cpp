#include "Summator.h"

int Summator::transform(int i) {

	return i;
}

int Summator::sum(int N) {

	int sum = 0;

	for (int i = 1; i <= N; i++) {

		sum += transform(i);
	}

	return sum;
}