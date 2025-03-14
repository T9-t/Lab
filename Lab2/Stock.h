#pragma once
#include <vector>
#include "Box.h"

using namespace std;

class Stock {

	vector<Box> Box_List;

public:

	void add(int w, int v);

	int get_by_w(int min_w);

	int get_by_v(int min_v);

	void print();
};