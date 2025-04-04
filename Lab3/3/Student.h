#pragma once
#include <string>
#include <vector>
#include "Human.h"

using namespace std;

class Student :public Human {

	vector<int>* score;

public:

	Student();

	Student(vector<int>& input_score, string Name, string Last_name, string Surmame);

	~Student();

	void add_score(int new_score);

	double get_average_score();

	void get_short_student_info();

	void get_full_student_info();
};