#include <iostream>
#include "Bell.h"
#include "OddEvenSeparator.h"
#include "Complex.h"
#include "Table.h"
#include "Stock.h"

int main() {

	// 1 
	cout << "*****************************************" << endl;
	Bell bell;
	bell.sound();
	bell.sound();


	// 2
	cout << "*****************************************" << endl;
	OddEvenSeparator separator;

	separator.add_number(9);
	separator.add_number(2);
	separator.add_number(1);
	separator.add_number(3);
	separator.add_number(5);
	separator.add_number(6);
	separator.add_number(4);

	separator.even();
	separator.odd();


	// 3
	cout << "*****************************************" << endl;
	int rows = 3, cols = 4;
	Table table(rows, cols);

	table.print();
	table.average();
	table.set_value(1, 2, 5);
	cout << table.get_value(1, 2) << endl;
	cout << table.n_cols() << endl;
	cout << table.n_rows() << endl;
	table.print();

	// 4
	cout << "*****************************************" << endl;
	Complex c_number(4, 5);

	cout << c_number.get_im() << endl;
	cout << c_number.get_re() << endl;
	cout << c_number.abs() << endl;
	cout << c_number.arg() << endl;

	c_number.print();
	c_number.trig_print();
	c_number.exp_print();

	Complex f_number(10, 3);
	c_number.add(f_number);
	c_number.sub(f_number);
	c_number.mult(f_number);
	c_number.div(f_number);

	// 5
	cout << "*****************************************" << endl;
	Stock list;
	list.add(4, 5);
	list.add(8, 3);
	list.add(4, 4);
	list.add(5, 1);
	list.add(4, 10);
	list.print();
	cout << "" << endl;
	cout << "Box number(min_w): " << list.get_by_w(4) << endl;
	cout << "Box number(min_v): " << list.get_by_v(3) << endl;
	cout << "Box number(min_v): " << list.get_by_v(2) << endl;
	cout << "" << endl;
	list.print();

	return 0;
}