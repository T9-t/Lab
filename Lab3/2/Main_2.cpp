#include <iostream>
#include "Animal.h"
#include "Bird.h"
#include "FlyingBird.h"
#include "Fish.h"

using namespace std;

int main()
{
	Animal* pip = new Bird();
	pip->eat();
	pip->breathe();
	
	Animal* anim = NULL;

	char animal;
	cout << "Input animal type (b-bird, f-fish, y-flyingBird): ";
	cin >> animal;

	switch (animal)
	{
	case 'b':

		anim = new Bird();
		break;

	case 'f':

		anim = new Fish();
		break;

	case 'y':

		anim = new FlyingBird();
		break;

	default:
		cout << "Enter Animal type:\n";
		return -1;
	}

	anim->breathe();
	anim->eat();

	return 0;
}