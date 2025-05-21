#include "BaseEnemy.h"

BaseEnemy::BaseEnemy(int pos_x, int pos_y, int hp, Weapon& weapon) :BaseCharacter(pos_x, pos_y, hp) {

	this->weapon = new Weapon(weapon);
}
BaseEnemy::~BaseEnemy(){

	delete weapon;
}

void BaseEnemy::hit(MainHero& target){

	this->weapon->hit(*this, target);
}

ostream& operator<< (ostream& cou, BaseEnemy& cop){

	cou << "The enemy is in position ("<< cop.get_x() << ","  << cop.get_y() << ") with weapons <" << cop.weapon << ">" << endl;
	return cou;
}