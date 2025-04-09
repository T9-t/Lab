#include <iostream>
#include "Human.h"

using namespace std;

Human::Human() {

	*this->Name = "Unknown";
	*this->Last_name = "Unknown";
	*this->Surmame = "Unknown";
}

Human::Human(string Name, string Last_name, string Surmame) {

	this->Name = new string(Name);
	this->Last_name = new string(Last_name);
	this->Surmame = new string(Surmame);
}

Human::Human(const Human& p) {

	this->Name = new string(*p.Name);
	this->Last_name = new string(*p.Last_name);
	this->Surmame = new string(*p.Surmame);
}

Human::~Human(){
	
	delete Name;
	delete Last_name;
	delete Surmame;
}

void Human::get_surname_and_initials() {

	cout << *this->Last_name << " " << (*this->Name)[0] << ". " << (*this->Surmame)[0] << ". ";
}

void Human::get_full_name() {

	cout << *this->Last_name << " " << *this->Name << " " << *this->Surmame;
}

string Human::get_name() {

	return *this->Name;
}

string Human::get_last_name() {

	return *this->Last_name;
}

string Human::get_surmame() {

	return *this->Surmame;
}