#include <iostream>
#include "Table.h"

using namespace std;

Table::Table(int rows, int cols) {

	this->rows = rows;
	this->cols = cols;

	this->table = new int* [rows];

	for (int i = 0; i < rows; i++) {

		this->table[i] = new int [cols];

		for (int j = 0; j < cols; j++) {

			this->table[i][j] = 0;
		}
	}
}

Table::~Table() {

	for (int i = 0; i < rows; i++) {

		delete[] this->table[i];
	}
	delete[] this->table;
}

int Table::get_value(int row, int col) {

	return this->table[row][col];
}

void Table::set_value(int row, int col, int value) {

	this->table[row][col] = value;
}

int Table::n_rows() {

	return this->rows;
}

int Table::n_cols() {

	return this->cols;
}

void Table::print() {
	
	cout << "Table:" << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			cout << this->table[i][j] << " ";
		}
		cout << endl;
	}
}

double Table::average() {

	double sum = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			sum += this->table[i][j];
		}
	}

	return sum / rows / cols;
}