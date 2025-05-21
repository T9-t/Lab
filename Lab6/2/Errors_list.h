#pragma once
#include <iostream>

using namespace std;

class Error_move {
public:
	string message;
	Error_move() { message = "Error: You can't go beyond the map"; }
};

class Error_name {
public:
	string message;
	Error_name() { message = "Error: The hero's name must start with a capital letter."; }
};