#pragma once
#include <iostream>
#include "Weapon.h"
#include "BaseCharacter.h"

using namespace std;

class Weapon {

	string* name;
	int* damage;
	int* range;

public:

	Weapon();

	Weapon(string name, int damage, int range);

	~Weapon();

	int get_damage();
	
	void hit(BaseCharacter& actor, BaseCharacter& target);

	string name_weapon();

	Weapon& operator= (Weapon& cop);
	 
	friend istream& operator>> (istream& in, Weapon& cop);
	
	friend ostream& operator<< (ostream& cou, Weapon& cop);
};