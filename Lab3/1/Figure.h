#pragma once

class Figure {

public:

	virtual ~Figure() = default;

	virtual double calc_area() = 0;

	virtual void show() = 0;
};