#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

Student::Student() {

	this->score = new vector<double>();
}

Student::Student(vector<double>& input_score, string Name, string Last_name, string Surmame):Human(Name, Last_name, Surmame){

	this->score = new vector<double>(input_score);
}

Student::Student(const Student& p):Human(p) {

	score = new vector<double>(*p.score);
}

Student::~Student() {

	delete score;
}

void Student::add_score(double new_score) {

	this->score->push_back(new_score);
}

double Student::get_average_score() {

	double sum = 0, size = 0;

	for (int i = 0; i < this->score->size(); i++) {
		
		sum += (*this->score)[i];
		size++;
	}
	return sum / size;
}

void Student::get_short_student_info() {

	get_surname_and_initials();

	cout << get_average_score() << endl;
}

void Student::get_full_student_info() {

	get_full_name();

	for (int i = 0; i < this->score->size(); i++) {

		cout << " " << (*this->score)[i];
	}
	cout << endl;
}

int Student::size_score() {

	return this->score->size();
}

double Student::score_num(int j) {

	return (*this->score)[j];
}