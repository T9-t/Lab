#pragma once
#include <string>
#include <vector>
#include "Human.h"

using namespace std;

class Student :public Human {

	vector<double>* score;

public:

	Student();

	Student(vector<double>& input_score, string Name, string Last_name, string Surmame);

	Student(const Student& p);

	~Student();

	void add_score(double new_score);

	double get_average_score();

	void get_short_student_info();

	void get_full_student_info();

	int size_score();

	double score_num(int j);
};