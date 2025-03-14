#include <iostream>
#include "Stock.h"

using namespace std;

void Stock::add(int w, int v) {

	int number = 38;
	Box box(number, w, v);

	Box_List.push_back(box);

	for (int i = 0; i < Box_List.size(); i++) {
		Box_List[i].set_number(i);
	}
}

int Stock::get_by_w(int min_w) {

	int min_box = 0, min_number, max_number = -1;
	
	for (int i = 0; i < Box_List.size(); i++) {
		
		min_number = Box_List[i].comparison_w(min_w);

		if (min_number != -1) {

			if (max_number < i) {

				max_number = i;
			}
			min_box++;
		}
	}
	if (min_box >= 1) {

		int max = Box_List[max_number].comparison_w(min_w);

		int num = max_number - 100;
		Box_List[max_number].set_number(num);

		return max;
	}
	else if (min_box == 0) {

		return -1;
	}
}

int Stock::get_by_v(int min_v) {

	int min_box = 0, min_number, max_number = -1;

	for (int i = 0; i < Box_List.size(); i++) {

		min_number = Box_List[i].comparison_v(min_v);

		if (min_number != -1) {

			if (max_number < i) {

				max_number = i;
			}
			min_box++;
		}
	}
	if (min_box >= 1) {

		int max = Box_List[max_number].comparison_v(min_v);

		int num = max_number - 100;
		Box_List[max_number].set_number(num);

		return max;
	}
	else if (min_box == 0) {

		return -1;
	}
}

void Stock::print() {

	cout << "Stock: " << endl;
	for (int i = 0; i < Box_List.size(); i++) {
		Box_List[i].print_box();
	}
}