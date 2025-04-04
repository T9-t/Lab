#pragma once
#include "Animal.h"

class Bird :public Animal {

public:

	void lay_eggs();

	void breathe() override;

	void eat() override;
};