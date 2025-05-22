#include <iostream>
#include "Errors_list.h"
#include "PasswordError.h"
#include "BaseCharacter.h"
#include "Weapon.h"
#include "MainHero.h"
#include "BaseEnemy.h"

using namespace std;

string get_password();
void map_print(MainHero& Hero, BaseEnemy& Enemy_1, BaseEnemy& Enemy_2);
void enemy_do(MainHero& Hero, BaseEnemy& Enemy, int& do_en);

string name_input() {

    string name;
    int count_spacep = 0;

    cout << "Enter the name of your hero: ";
    try {
        cin >> name;

        if (int(name[0]) <= 64 || int(name[0]) >= 91) {

            throw Error_name();
        }
    }
    catch (Error_name& error_1) {

        cerr << "   " << error_1.message << endl;
        name = name_input();
    };
    return name;
}

int main()
{
    string pass;

    try {
      pass = get_password();
       cout << pass << endl;
    }
    catch (PasswordError& error) {
       cerr << "Error: " << error.message << endl;
       return 1;
    }
    //*************************************************************************

    Weapon* weapon_hero_1 = new Weapon("Sword", 45, 2);
    Weapon* weapon_hero_2 = new Weapon("Bow", 30, 5);
    Weapon* weapon_enemy_1 = new Weapon("Knife", 55, 1);
    Weapon* weapon_enemy_2 = new Weapon("Spear", 40, 2);
    int start = 0, hero_x = 0;

    do {
        int func = 0;
        cout << "-----------------------------------------" << endl;
        cout << "*Start - 1" << "        *Enemy (1, 2)" << endl;
        cout << "*Exit - 2" << "    *You (+)  *Weapon (/, -)" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Select an act: ";
        cin >> start;

        if (start == 1) {

            string name;

            name = name_input();

            bool weapon_bool = 0, win = 0;
            int enemy_count_do = 0, enemy_1_num = 1, enemy_2_num = 1;
            MainHero* Hero = new MainHero(hero_x, hero_x, name);
            BaseEnemy* Enemy_1 = new BaseEnemy(0, 5, 120, *weapon_enemy_2);
            BaseEnemy* Enemy_2 = new BaseEnemy(5, 5, 200, *weapon_enemy_1);

            cout << "------------------START------------------" << endl;
            while (func != 10) {

                if (!Hero->is_alive()) {
                    func = 10; win = 0;
                }
                if (func != 10) {
                    map_print(*Hero, *Enemy_1, *Enemy_2);

                    cout << "-----------------------------------------" << endl;
                    cout << "*Move - 1" << "               *Healing - 4" << endl;
                    cout << "*Pick up a weapon - 2" << "   *Change weapon - 5" << endl;
                    cout << "*Hit the enemy - 3" << endl;
                    
                    cout << "-----------------------------------------" << endl;
                    cout << "Select an act: ";
                    cin >> func;
                }
                if (func == 1) {// Идти/Move

                    int x = 1, y = 0, x_2 = -1;
                    int hero_x = Hero->get_x(), hero_y = Hero->get_y(), enemy1_x = Enemy_1->get_x(), enemy1_y = Enemy_1->get_y(), enemy2_x = Enemy_2->get_x(), enemy2_y = Enemy_2->get_y();

                    char move_x_y;

                    cout << "Where to go(l-left, d-down, u-up, r-right): ";
                    cin >> move_x_y;

                    if (move_x_y == 'd') {//down

                        if ((hero_y != enemy1_y && hero_x != enemy1_x - 1) || (hero_y != enemy2_y && hero_x != enemy2_x - 1)) {

                            Hero->move(x, y);
                        }
                        else {
                            cout << "The place is occupied" << endl;
                        }
                    }
                    else if (move_x_y == 'u') {//up

                        if ((hero_y != enemy1_y && hero_x != enemy1_x + 1) || (hero_y != enemy2_y && hero_x != enemy2_x + 1)) {

                            Hero->move(x_2, y);
                        }
                        else {
                            cout << "The place is occupied" << endl;
                        }
                    }
                    else if (move_x_y == 'r') {//right

                        if ((hero_y != enemy1_y - 1 && hero_x != enemy1_x) || (hero_y != enemy2_y - 1 && hero_x != enemy2_x)) {

                            Hero->move(y, x);
                        }
                        else {
                            cout << "The place is occupied" << endl;
                        }
                    }
                    else if (move_x_y == 'l') {//left

                        if ((hero_y != enemy1_y + 1 && hero_x != enemy1_x) || (hero_y != enemy2_y + 1 && hero_x != enemy2_x)) {

                            Hero->move(y, x_2);
                        }
                        else {
                            cout << "The place is occupied" << endl;
                        }
                    }
                }
                if (func == 2) {// Подобрать оружие/Pick up a weapon

                    char y_n;
                    Weapon* cop = new Weapon();

                    if (Hero->get_x() == 0 && Hero->get_y() == 1) {

                        cout << "Pick up a weapon <Sword> ";
                        cop = weapon_hero_1;
                    }
                    else if (Hero->get_x() == 3 && Hero->get_y() == 2) {

                        cout << "Pick up a weapon <Bow> ";
                        cop = weapon_hero_2;
                    }
                    if (cop->name_weapon() == "Sword" || cop->name_weapon() == "Bow") {

                        cout << "yes/no (y/n): ";
                        cin >> y_n;

                        if (y_n == 'y') {

                            Hero->add_weapon(*cop);
                        }
                    }
                    else {
                        cout << "There are no weapons here" << endl;
                    }
                }
                if (func == 3) {// Ударить противника/Hit the enemy
                    
                    int enemy_int;

                    cout << "Which enemy to attack(1,2): ";
                    cin >> enemy_int;

                    if (enemy_int == 1) {
                        Hero->hit(*Enemy_1);
                    }
                    else if (enemy_int == 2) {
                        Hero->hit(*Enemy_2);
                    }
                }
                if (func == 4) {// Исциление/Healing

                    int heal_int;

                    cout << "Healing by: " << endl;
                    cin >> heal_int;

                    Hero->heal(heal_int);
                }
                if (func == 5) {// Сменить оружие/Change weapon

                    Hero->next_weapon();
                }
                cout << "-----------------------------------------" << endl;

                //Действие противников
                if ((enemy_count_do == 0 && Enemy_1->is_alive()) || (Enemy_1->is_alive() && !Enemy_2->is_alive())) {

                    enemy_do(*Hero, *Enemy_1, enemy_1_num);
                    enemy_count_do++;
                }
                else if ((enemy_count_do == 1 && Enemy_2->is_alive()) || (!Enemy_1->is_alive() && Enemy_2->is_alive())) {

                    enemy_do(*Hero, *Enemy_2, enemy_2_num);
                    enemy_count_do = 0;
                }
                else if (!Enemy_1->is_alive() && !Enemy_2->is_alive()) {
                    func = 10;
                    win = 1;
                }
            }
            cout << "-----------------------------------------" << endl;
            cout << "--------------Hero: " << Hero->get_name() << "-------------------" << endl;
            if (win) {
                cout << "-------------------WIN-------------------" << endl;
            }
            else {
                cout << "------------------LOSE-------------------" << endl;
            }
            delete Hero;
            delete Enemy_1;
            delete Enemy_2;

            cout << endl;
        }
        else if (start == 2){
            cout << "-------------------END-------------------" << endl;
        }
    } while (start != 2);

    delete weapon_hero_1;
    delete weapon_hero_2;
    delete weapon_enemy_1;
    delete weapon_enemy_2;

    return 0;
}

string get_password() {

    string pass;
    int count_num = 0, count_A = 0, count_L = 0, count_l = 0, count_I = 0, count_i = 0, count_1 = 0, count_o= 0, count_O = 0, count_0 = 0;

    cout << " " << endl;
    cin >> pass;

    if (pass.size() < 9) {
        throw LengthError();
    }
    for (int i = 0; i < pass.size(); i++) {

        if (int(pass[i]) > 47 && int(pass[i]) < 58) {
            count_num++;
        }
        if (int(pass[i]) > 64 && int(pass[i]) < 91) {
            count_A++;
        }
        
        if (pass[i] == 'L') {
            count_L++;
        }
        else if (pass[i] == 'l') {
            count_l++;
        }
        else if (pass[i] == 'I') {
            count_I++;
        }
        else if (pass[i] == 'i') {
            count_i++;
        }
        else if (pass[i] == '1') {
            count_1++;
        }
        else if (pass[i] == 'O') {
            count_O++;
        }
        else if (pass[i] == 'o') {
            count_o++;
        }
        else if (pass[i] == '0') {
            count_0++;
        }
    }
    if (count_num == 0) {
        throw DigitError();
    }
    if (count_A == pass.size()) {
        throw RegisterError();
    }
    if (count_L > 0 && count_l > 0 || count_I > 0 && count_i > 0 || count_I > 0 && count_1 > 0 || count_i > 0 && count_1 > 0 
        || count_o > 0 && count_O > 0 || count_o > 0 && count_0 > 0 || count_O > 0 && count_0 > 0) {
        throw ForbiddenLetterError();
    }

    return pass;
}

void enemy_do(MainHero& Hero,BaseEnemy& Enemy, int& do_en) {

    int x = 1, y = 0, x_1 = -1;
    
    if (do_en % 2 != 0 && Hero.get_x()-1 != Enemy.get_x() && Hero.get_x() + 1 != Enemy.get_x()) {

        if (Hero.get_x() > Enemy.get_x() && Hero.get_x() != Enemy.get_x()) {

            Enemy.move(x, y);
        }
        else if (Hero.get_x() < Enemy.get_x() && Hero.get_x() != Enemy.get_x()) {
            Enemy.move(x_1, y);
        }
    }
    else if (do_en % 2 == 0 && Hero.get_y() - 1 != Enemy.get_y() && Hero.get_y() + 1 != Enemy.get_y()) {
        
        if (Hero.get_y() > Enemy.get_y() && Hero.get_y() != Enemy.get_y()) {

            Enemy.move(y, x);
        }
        else if (Hero.get_y() < Enemy.get_y() && Hero.get_y() != Enemy.get_y()) {
            Enemy.move(y,x_1);
        }
    }

    Enemy.hit(Hero);
    do_en++;
}

void map_print(MainHero& Hero,BaseEnemy& Enemy_1, BaseEnemy& Enemy_2) {
    
    cout << "\t***********************" << endl; 
    if (Hero.get_size() == 0) {
        cout << "\tWeapon:Nofing";
    }
    else {
        cout << "\tWeapon: " << Hero.get_veapon_name();
    }
    cout << "    Hp:" << Hero.get_hp() << endl;

    for (int i = 0; i < 6; i++) {

        cout << "\t***********************" << endl;
        cout << "\t";
        for (int j = 0; j < 6; j++) {

            if (Enemy_1.get_x() == i && Enemy_1.get_y() == j) {
                cout << "|1| ";
            }
            else if (Enemy_2.get_x() == i && Enemy_2.get_y() == j) {
                cout << "|2| ";
            }
            else if (Hero.get_x() == i && Hero.get_y() == j) {

                cout << "|+| ";
            }
            else if (i == 0 && j == 1) {
                
               if (Hero.get_x() == i && Hero.get_y() == j) {

                   cout << "|+| ";
               }
               if (Enemy_1.get_x() == i && Enemy_1.get_y() == j) {
                   cout << "|1| ";
               }
               else if (Enemy_2.get_x() == i && Enemy_2.get_y() == j) {
                   cout << "|2| ";
               }
               else {
                   if (Hero.get_size() == 1 && Hero.get_veapon_name() == "Sword" || Hero.get_size() == 2) {

                       cout << "| | ";
                   }
                   else {

                        cout << "|-| ";
                   }
               }
            }
            else if (i == 3 && j == 2) {

                if (Hero.get_x() == i && Hero.get_y() == j) {

                    cout << "|+| ";
                }
                if (Enemy_1.get_x() == i && Enemy_1.get_y() == j) {
                    cout << "|1| ";
                }
                else if (Enemy_2.get_x() == i && Enemy_2.get_y() == j) {
                    cout << "|2| ";
                }
                else {
                    if (Hero.get_size() == 1 && Hero.get_veapon_name() == "Bow" || Hero.get_size() == 2) {

                        cout << "| | ";
                    }
                    else {

                        cout << "|/| ";
                    }
                }
            }
            else {
                cout << "| | ";
            }
        }
        cout << endl;
    }
    cout << "\t***********************" << endl;
}