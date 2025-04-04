#pragma once
#include "Animal.h"


class Fish :public Animal {

public:

	void swim();

	void breathe() override;

	void eat() override;
};