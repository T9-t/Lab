#pragma once
#include "Animal.h"

class FlyingBird :public Animal {

public:

	void fly();

	void breathe() override;

	void eat() override;
};