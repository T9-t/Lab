#pragma once
#include <vector>
#include <string>
#include "Human.h"

using namespace std;

enum class Job_title {

	Unknown,
	Assistant, 
	Senior_lecturer,
	Associate_professor, 
	Professor
};

class Teacher:public Human{

	vector<string>* subjects_taught;
	Job_title teach_title;

public:

	Teacher();

	Teacher(char input_title, vector<string>& input_subjects, string Name, string Last_name, string Surmame);

	Teacher(const Teacher& p);

	~Teacher();

	void add_subject(string new_subject);

	void get_short_teacher_info();

	void get_full_teacher_info();

	int size_subjects();

	char title();

	string subjects(int j);
};