#include "cmath"
#include "Weapon.h"

Weapon::Weapon() {

	this->name = new string("Nofing");
	this->damage = new int(0);
	this->range = new int(0);
}
Weapon::Weapon(string name, int damage, int range){

	this->name = new string(name);
	this->damage = new int(damage);
	this->range = new int(range);
}
Weapon::~Weapon(){

	delete name;
	delete damage;
	delete range;
}

int Weapon::get_damage() {
	return *this->damage;
}

void Weapon::hit(BaseCharacter& actor, BaseCharacter& target){

	if (!target.is_alive()) {
		
		if (*this->name == "Sword" || *this->name == "Bow") {
			cout << "The enemy has already been defeated" << endl;
		}
	}
	else {
		int act_x = actor.get_x(), act_y = actor.get_y(),
			tar_x = target.get_x(), tar_y = target.get_y();

		if (act_x < 0) {
			act_x *= -1;
		}
		else if (act_y < 0) {
			act_y *= -1;
		}
		else if (tar_x < 0) {
			tar_x *= -1;
		}
		else if (tar_y < 0) {
			tar_y *= -1;
		}

		if (act_x > tar_x) {
			act_x -= tar_x;
		}
		else {
			act_x = tar_x - act_x;
		}
		if (act_y > tar_y) {
			act_y -= tar_y;
		}
		else {
			act_y = tar_y - act_y;
		}
		int x_range = sqrt((act_x * act_x) + (act_y * act_y));
		
		if (x_range > *this->range) {
			if (*this->name == "Sword" || *this->name == "Bow") {
				cout << "The enemy is too far for the weapon <" << *this->name << ">" << endl;
			}
		}
		else {
			if (*this->name == "Sword" || *this->name == "Bow") {
				cout << "Enemy damaged by weapon <" << *this->name << "> in the amount <" << *this->damage << ">" << endl;
			}
			else {
				cout << "You have damaged by weapon <" << *this->name << "> in the amount <" << *this->damage << ">" << endl;
			}
			target.get_damage(*this->damage);
		}
	}
}

string Weapon::name_weapon() {

	return *this->name;
}

Weapon& Weapon::operator= (Weapon& cop) {

	this->name = new string(*cop.name);
	this->damage = new int(*cop.damage);
	this->range = new int(*cop.range);

	return *this;
}

istream& operator>> (istream& in, Weapon& cop){

	string name; int damage, range;
	in >> name >> damage >> range;

	cop.name = new string(name);
	cop.damage = new int(damage);
	cop.range = new int(range);

	return in;
}
ostream& operator<< (ostream& cou, Weapon& cop){

	cou << *cop.name;

	return cou;
}