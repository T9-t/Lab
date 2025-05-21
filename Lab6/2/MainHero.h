#pragma once
#include <vector>
#include "BaseEnemy.h"
#include "Weapon.h"
#include "BaseCharacter.h"

class BaseEnemy;

class MainHero :public BaseCharacter {

	string* name;
	vector<Weapon*> inventory;
	int invent_weapon = 0;
	
public:
	
	MainHero(int& pos_x, int& pos_y, string& name);

	~MainHero();
	
	void hit(BaseEnemy& target);

	string get_name();

	string get_veapon_name();

	int get_size();
	
	void add_weapon(Weapon& weapon);
	
	void next_weapon();
	
	void heal(int amount);
};