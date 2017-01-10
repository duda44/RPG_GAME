#include<iostream>
#include<string.h>
#include<cstring>
#include<string>
#include<ctime>
#include<cstdlib>
#include <fstream>
using std::string;
using std::getline;
using namespace std;
int get_hero(int& hero_class, string& hero_name, int& hero_hp, int& hero_mana, int& hero_damage, int& hero_defence) {
	
	
	char sure_pick;
	bool class_picked = false;
	do {
		cout << "Please enter your name: ";
		getline(cin, hero_name);
		cout << endl;
	class_selection:cout << "Hello " << hero_name << " and welcome to Short Life" << endl;
		cout << "Chose your class" << endl;
		cout << "Input 1 for warrior" << endl;
		cout << "input 2 for archer" << endl;
		cout << "Input 3 for mage" << endl;
		cin >> hero_class;
		if (hero_class == 1) {
			cout << "Warrior has higher hp and average damage and high def but has low mana" << endl;
			cout << "Input Y if you want to play as a warrior and N if you want to go back" << endl;
			cout << "Starting stats: " << endl;
			cout << "Hp: 100  Mana: 50  Damage:5  Defence: 5" << endl;
			cin >> sure_pick;
			if (sure_pick == 'n')
				goto class_selection;
			/*else if (sure_pick != 'n' || sure_pick != 'y') {
				cout << "Unknow command input again" << endl;
				goto sure_pick_warrior;
			}*/
			else if (sure_pick == 'y') {
				cout << "You chose a warrior" << endl;
				int hero_hp = 100;
				int hero_mana = 40;
				int hero_damage = 6;
				int hero_defence = 6;
				class_picked = true;
			}
		}


		if (hero_class == 2) {
			cout << "Archer has a fast attack(can attack twice in a row)" << endl;
			cout << "but has 1/3 starting attack of warrior,lower hp and 1/2 mana of mage " << endl;
			cout << "Starting stats: " << endl;
			cout << "Hp: 70  Mana: 60  Damage: 3  Defence: 2" << endl;
				cin >> sure_pick;
				if (sure_pick == 'n')
					goto class_selection;
				else if (sure_pick == 'y') {
				cout << "You chose a archer" << endl;
				int hero_hp = 70;
				int hero_mana = 70;
				int hero_damage = 3;
				int hero_defence = 2;
				class_picked = true;
			}
		}
		if (hero_class == 3) {
			cout << "Mage has low hp and low defence but has high mana" << endl;
			cout << "which allows him to use powerfull spells" << endl;
			cout << "Starting stats: " << endl;
			cout << "Hp: 50  Mana: 140  Damage:1  Defence: 1" << endl;
			cin >> sure_pick;
			if (sure_pick == 'n')
				goto class_selection;
			if (sure_pick == 'y') {
				cout << "You chose a mage" << endl;
				int hero_hp = 50;
				int hero_mana = 140;
				int hero_damage = 1;
				int hero_defence = 1;
				class_picked = true;
			}
		}

	} while (class_picked = false);
	return hero_class;
}
void get_mob(int hero_lvl) {
	string mob_name_list[9] = {"mob1", "mob2", "mob3", "mob4" ,"mob5", "mob6", "mob7", "mob8", "mob9"};
	string mob_name;
	int mob_number = rand() % 8 + 1;
	mob_name = mob_name_list[mob_number];
	cout << mob_name<<endl;
	int mob_lvl; 
	int mob_hp; 
	int mob_def;
	int mob_attack; 
	int up_or_low; 
	up_or_low = rand() % 1 + 1;
	if (hero_lvl == 1 || hero_lvl == 2 || hero_lvl == 3) {
		mob_lvl = hero_lvl;
	}
	else if (up_or_low == 1) {
		mob_lvl = hero_lvl - rand() % 2 + 1;
	} 
	else if (up_or_low == 2) {
		mob_lvl = hero_lvl + rand() % 2 + 1;
	}
	mob_hp = mob_lvl * 10 * 1.5;
	mob_attack=
}



	
int main() {



	/*int hero_hp = 0;
	int hero_mana = 0;
	int hero_damage = 0;
	int hero_defence = 0;
	int hero_class = 0;
	int hero_lvl = 1;
	int hero_exp;
	string hero_name;
	get_hero(hero_class, hero_name,hero_hp,hero_mana, hero_damage,hero_defence);
	get_mob(hero_lvl);
	cout << hero_class;
	return 0;*/
	int a = 4.5;
	cout << a;

}