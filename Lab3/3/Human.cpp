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

Human::~Human(){
	
	delete this->Name;
	delete this->Last_name;
	delete this->Surmame;
}

void Human::get_surname_and_initials() {

	cout << *this->Last_name << " " << (*this->Name)[0] << ". " << (*this->Surmame)[0] << ". ";
}

void Human::get_full_name() {

	cout << *this->Last_name << " " << *this->Name << " " << *this->Surmame << " ";
}