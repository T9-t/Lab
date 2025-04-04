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

	Teacher(char input_subjects, vector<string>& input_score, string Name, string Last_name, string Surmame);

	~Teacher();

	void add_subject(string new_subject);

	void get_short_teacher_info();

	void get_full_teacher_info();
};