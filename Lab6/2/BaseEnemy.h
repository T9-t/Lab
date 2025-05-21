#pragma once
#include "Weapon.h"
#include "MainHero.h"
#include "BaseCharacter.h"

class MainHero;

class BaseEnemy :public BaseCharacter {

	Weapon* weapon;

public:

	BaseEnemy(int pos_x, int pos_y, int hp, Weapon& weapon);

	~BaseEnemy();
	
	void hit(MainHero& target);
	
	friend ostream& operator<< (ostream& cou, BaseEnemy& cop);
};