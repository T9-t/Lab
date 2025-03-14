#pragma once

class Box {

	int* number;
	int* w;
	int* v;

public:

	Box();

	Box(int number, int w, int v);

	Box(const Box& cop);

	~Box();
	
	void set_number(int number);

	int comparison_w(int w);

	int comparison_v(int v);

	void print_box();
};