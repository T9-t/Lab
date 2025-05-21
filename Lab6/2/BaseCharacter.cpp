#include <iostream>
#include "Errors_list.h"
#include "BaseCharacter.h"

using namespace std;

BaseCharacter::BaseCharacter(int& pos_x, int& pos_y, int hp){

	this->pos_x = new int(pos_x);
	this->pos_y = new int(pos_y);
	this->hp = new int(hp);
}
BaseCharacter::~BaseCharacter(){

	delete pos_x;
	delete pos_y;
	delete hp;
}

void BaseCharacter::move(int& delta_x, int& delta_y){

	try {
		if (*this->pos_x + delta_x <= 5 && *this->pos_x + delta_x >= 0) {
			this->pos_x = new int(*this->pos_x + delta_x);
		}
		else {
			throw Error_move();
		}
		if (*this->pos_y + delta_y <= 5 && *this->pos_y + delta_y >= 0) {
			this->pos_y = new int(*this->pos_y + delta_y);
		}
		else {
			throw Error_move();
		}
	}
	catch (Error_move& er) {
		cerr << "   " << er.message << endl;
	}
}

bool BaseCharacter::is_alive() {

	if (*hp > 0) {
		return true;
	}
	else{
		return false;
	}
}

void BaseCharacter::get_damage(int& amount){

	if (amount < 0) {
		this->hp = new int(*this->hp - amount);
		if (*hp > 200) {
			this->hp = new int(200);
		}
		cout << "I got treatment and now I'm healthy <" << *hp << ">" << endl;
	}
	else {
		this->hp = new int(*this->hp - amount);
	}
}

int BaseCharacter::get_hp() {
	return *hp;
}

int BaseCharacter::get_x(){

	return *pos_x;
}

int BaseCharacter::get_y(){

	return *pos_y;
}