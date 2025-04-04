#include <iostream>
#include <vector>
#include "Human.h"
#include "Student.h"

using namespace std;

Student::Student() {

	this->score = new vector<int>();
}

Student::Student(vector<int>& input_score, string Name, string Last_name, string Surmame):Human(Name, Last_name, Surmame){

	this->score = new vector<int>(input_score);
}

Student::~Student() {

	delete score;
}

void Student::add_score(int new_score) {

	this->score->push_back(new_score);
}

double Student::get_average_score() {

	int sum = 0.00;

	for (int i = 0; i < this->score->size(); i++) {
		
		sum += (*this->score)[i];
	}

	return sum / this->score->size();
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
}