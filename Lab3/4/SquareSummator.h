#pragma once
#include "Summator.h"

class SquareSummator :public Summator {

public:

	virtual int transform(int i) override;
};