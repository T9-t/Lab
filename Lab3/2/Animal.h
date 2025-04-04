#pragma once

class Animal {

public:
	virtual ~Animal() = default;

	virtual void breathe() = 0;

	virtual void eat() = 0;
};