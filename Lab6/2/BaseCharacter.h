#pragma once

class BaseCharacter {
	
	int* pos_x;
	int* pos_y;
	int* hp;

public:

	BaseCharacter(int& pos_x, int& pos_y, int hp);

	~BaseCharacter();
	
	void move(int& delta_x, int& delta_y);
	
	bool is_alive();
	
	void get_damage(int& amount);

	int get_hp();
	
	int get_x();
	
	int get_y();
};