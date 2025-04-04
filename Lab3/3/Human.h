#pragma once
#include <string>

using namespace std;

class Human {

	string* Name;
	string* Last_name;
	string* Surmame;

public:
	
	Human();

	Human(string Name, string Last_name, string Surmame);

	~Human();

	void get_surname_and_initials();

	void get_full_name();
};