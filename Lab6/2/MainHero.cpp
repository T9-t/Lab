#include "MainHero.h"

MainHero::MainHero(int& pos_x, int& pos_y, string& name) :BaseCharacter(pos_x, pos_y, 200) {

	this->name = new string(name);
}
MainHero::~MainHero(){

	delete name;
}

void MainHero::hit(BaseEnemy& target){

	if (this->inventory.size() == 0) {
		cout << "I am unarmed" << endl;
	}
	else {
		this->inventory[invent_weapon]->hit(*this, target);
	}
}

string MainHero::get_name() {

	return *this->name;
}

string MainHero::get_veapon_name() {

	return  this->inventory[invent_weapon]->name_weapon();
}

int MainHero::get_size() {

	return inventory.size();
}

void MainHero::add_weapon(Weapon& weapon){

	inventory.push_back(new Weapon(weapon));

	if (inventory.size() == 1) {

		invent_weapon = 0;
	}
	cout << "Picked up <" << *this->inventory[(inventory.size()-1)] << ">" << endl;
}

void MainHero::next_weapon(){

	if (inventory.size() == 0) {
		cout << "I am unarmed" << endl;
	}
	else if (inventory.size() == 1) {
		cout << "I only have one weapon" << endl;
	}
	else if (invent_weapon != (inventory.size()-1)) {
		invent_weapon += 1;
		cout << "Changed weapons to <" << *this->inventory[invent_weapon] << ">" << endl;
	}
	else if (invent_weapon == (inventory.size() - 1)) {
		invent_weapon = 0;
		cout << "Changed weapons to <" << *this->inventory[invent_weapon] << ">" << endl;
	}
}

void MainHero::heal(int amount){

	int am = amount * -1;
	this->get_damage(am);
}