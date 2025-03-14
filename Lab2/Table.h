#pragma once

class Table {
	int** table;
	int rows;
	int cols;

public:
	Table(int rows, int cols);

	~Table();

	int get_value(int row, int col);

	void set_value(int row, int col, int value);

	int n_rows();

	int n_cols();

	void print();

	double average();
};