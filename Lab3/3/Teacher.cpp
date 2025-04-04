#include <iostream>
#include <string>
#include "Teacher.h"

Teacher::Teacher() {

	this->subjects_taught = new vector<string>();
	this->teach_title = Job_title::Unknown;
}

Teacher::Teacher(char input_subjects, vector<string>& input_score, string Name, string Last_name, string Surmame):Human(Name, Last_name, Surmame) {

	this->subjects_taught = new vector<string>(input_score);
	
	this->teach_title = Job_title::Unknown;
	
	if (input_subjects == 'A') {
		this->teach_title = Job_title::Assistant;
	}
	else if (input_subjects == 'S') {
		this->teach_title = Job_title::Senior_lecturer;
	}
	else if (input_subjects == 'O') {
		this->teach_title = Job_title::Associate_professor;
	}
	else if (input_subjects == 'P') {
		this->teach_title = Job_title::Professor;
	}
}

Teacher::~Teacher(){

	delete subjects_taught;
}

void Teacher::add_subject(string new_subject){

	this->subjects_taught->push_back(new_subject);
}

void Teacher::get_short_teacher_info(){

	get_surname_and_initials();

	if (teach_title == Job_title::Assistant) {
		cout << "Assistant: ";
	}
	else if (teach_title == Job_title::Senior_lecturer) {
		cout << "Senior lecturer: ";
	}
	else if (teach_title == Job_title::Associate_professor) {
		cout << "Associate professor: ";
	}
	else if (teach_title == Job_title::Professor) {
		cout << "Professor: ";
	}

	cout << subjects_taught->size() << endl;
}

void Teacher::get_full_teacher_info(){

	get_full_name();

	if (teach_title == Job_title::Assistant) {
		cout << "Assistant: ";
	}
	else if (teach_title == Job_title::Senior_lecturer) {
		cout << "Senior lecturer: ";
	}
	else if (teach_title == Job_title::Associate_professor) {
		cout << "Associate professor: ";
	}
	else if (teach_title == Job_title::Professor) {
		cout << "Professor: ";
	}

	for (int i = 0; i < this->subjects_taught->size(); i++) {

		cout << (*this->subjects_taught)[i] << ", ";
	}
}