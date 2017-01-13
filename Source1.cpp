#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
#include <fstream>
#include <string>
using namespace std;

int ID, HP, Mana, ATK, ability_dmg, Defense, magic_resist, player_exp, player_level, loc_ID, side_ID ;
string Name, Class, location, file_name;
int main_mob_ID, side_mob_ID;
bool side_quest;
//void player()
//{
//	// ID(0), Name(1), Class(2), HP(3), Mana(4),  ATK(5), ability dmg(6) defense(7), magic resist(8) player_exp(9), player_level(10)
//	int player_stats[PLAYER_SIZE] = { 100, 100, 15, 1, 0, 1 };
//
//	// HP_potion(0), MP potion(1), attack_increase_potion(2), revival_potion(3)
//	int loot[LOOT_SIZE] = { 0, 0, 0, 0 };
//
//
//}
void side_encounter_accepted();
void side_encounter_offer();
void main_story_text();
void credits();
void main_menu();
void new_game();
void load_game();
void save_game();
void game_start();
void check_story();
void main_encounter();
void side_encounter();
void attack(int &mob_HP, int mob_Defense, int temp_ATK);
void ability(int &mob_HP, int &temp_mana, int mob_magic_resist, int temp_ability_dmg);
void potion(int &temp_HP, int &temp_Mana, int &temp_ATK, int &temp_ability_dmg);
bool main_battle();
bool side_battle();
int HP_Potion(int &temp_HP);
int Mana_Potion(int &temp_Mana);
int Revive_Potion(int &temp_HP);
int AttackDMG_Boost(int &temp_ATK);
int AbilityPower_Boost(int &temp_ability_dmg);
//fully functional
int main()
{
	srand(time(0));
	main_menu();
	system("pause");
	return 0;


}
//fully functional
void main_menu()
{
	bool menu = true;
	do{
		int choice;
		system("cls");
		cout << "	   The last son of Allheaven				" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "                 1.New Game                        " << endl;
		cout << "                 2.Load Game                       " << endl;
		cout << "                 3.Credits                         " << endl;
		cout << "                 4.Exit Game                         " << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << endl << "Enter a number to access one of the above options: ";
		cin >> choice;
		system("cls");
		if (choice < 1 || choice > 4)
			cout << "Invalid choice! Try again!" << endl;
		switch (choice)
		{
		case 1:
			new_game();
			break;
		case 2:
			load_game();
			break;
		case 3:
			credits();
			break;
		case 4:
			menu = false;
		}
	} while (menu);
}
//fully functional
void credits()
{
	int choice;
	do{
		cout << "	   The last son of Allheaven				" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "                 Made by:                       " << endl;
		cout << "                 Alem Tuzlak                      " << endl;
		cout << "                 Mehmed Nevesinjac                      " << endl;
		cout << "                 Ahmed Nurovic                      " << endl;
		cout << "                 Haris Kovacevic                    " << endl;
		cout << "          Press 1 to return to main menu!            " << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cin >> choice;
	} while (choice != 1);
	system("cls");
	main_menu();
}
//fully functional
void new_game()
{
	ifstream new_player_input("Players.txt") ;
	ofstream new_player_output;
	new_player_output.open("Players.txt" , ios::app);
	int counter = 0;
	new_player_input.clear();
	new_player_input.seekg(0, new_player_input.beg);
	while (new_player_input >> ID >> Name >> Class >> HP >> Mana >> ATK >> ability_dmg >> Defense >> magic_resist >> player_exp >> player_level)
	{
		counter++;
	}

	new_player_output << counter << ' ';
	cout << "	   The last son of Allheaven				" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "Enter your name: ";
	cin >> Name;
	new_player_output << Name;
	cout << "Hello " << Name << " you have successfully entered your name! Now to the next quest!";
	cout << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	system("pause");
	system("cls");
	int choice;
	bool sure = true;
	do{
		cout << "Choose your class:" << endl;
		cout << "1. Warrior(Warrior has high hp, defense and magic resistance but average damage and ability damage and low mana)" << endl;
		cout << endl << "2. Archer (Archer has very high attack damage but has average ability damage, hp and mana but low defense and magic resistance." << endl;
		cout << endl << "3. Mage (Mage has very high ability damage, mana and magic resistance, average hp but has low attack and defense." << endl;
		cin >> choice;
		cout << "Are you sure? yes|no : ";
		string ch;
		cin >> ch;
		if (ch == "yes" || ch == "YES" || ch == "Yes" || ch == "y" || ch == "Y")
			sure = false;
		system("cls");
	} while (sure);

	switch (choice)
	{
	case 1:
		new_player_output << ' ' << "Warrior" << ' ' << 150 << ' ' << 60 << ' ' << 20 << ' ' << 20 << ' ' << 5 << ' ' << 5 << ' ' << 0 << ' ' << 1 << endl;
		break;
	case 2:
		new_player_output << ' ' << "Archer" << ' ' << 100 << ' ' << 100 << ' ' << 40 << ' ' << 20 << ' ' << 1 << ' ' << 1 << ' ' << 0 << ' ' << 1 << endl;
		break;
	case 3:
		new_player_output << ' ' << "Mage" << ' ' << 100 << ' ' << 200 << ' ' << 10 << ' ' << 60 << ' ' << 1 << ' ' << 7 << ' ' << 0 << ' ' << 1 << endl;
		break;
	default:
		cout << "You have entered an invalid choice";
	}
	new_player_input.close();
	new_player_output.close();
	cout << "You have successfully created a new characher, enjoy the game!" << endl;
	game_start();
}
//fully functional
void load_game()
{
	bool loading = true;
	do{
		ifstream in_stream("Players.txt");
		cout << "	   The last son of Allheaven				" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		char ch;
		in_stream.clear();
		in_stream.seekg(0, in_stream.beg);
		while (in_stream.get(ch))
		{
			cout << ch;
		}
		cout << "         Enter -1 to return to main menu                      " << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << endl << "Enter a number to access one of the above options: ";
		in_stream.clear();
		in_stream.seekg(0, in_stream.beg);
		int choice;
		cin >> choice;
		while (in_stream >> ID >> Name >> Class >> HP >> Mana >> ATK >> ability_dmg >> Defense >> magic_resist >> player_exp >> player_level)
		{
			if (choice == ID)
			{
				/*game_start();*/
				loading = false;
				break;
			}
			else if (choice == -1)
			{
				system("cls");
				loading = false;
				main_menu();
			}
			else if (choice > ID && in_stream.eof())
			{
				cout << endl << "Error! Invalid ID !" << endl;
				system("cls");
				in_stream.clear();
				in_stream.seekg(0, in_stream.beg);
			}
			else
				system("cls");
		}
		in_stream.close();
	} while (loading);
}
//has to be tested
void save_game()
{
	ifstream in_stream("Players.txt");
	ofstream out_stream("Players.txt");
	ifstream temp_in("temp.txt");
	ofstream temp_out("temp.txt");

	int temp_ID, temp_HP, temp_Mana, temp_ATK, temp_Defense, temp_player_exp, temp_player_level;
	char temp_Name[50], temp_Class[15];
	while (in_stream >> temp_ID >> temp_Name >> temp_Class >> temp_HP >> temp_Mana >> temp_ATK >> temp_Defense >> temp_player_exp >>temp_player_level)
	{
		if (ID == temp_ID)
			temp_out << ID << ' ' << Name << ' ' << Class << ' ' << HP << ' ' << Mana << ' ' << ATK << ' ' << Defense << ' ' << player_exp << ' ' << player_level;
		
		else
			temp_out << ID << ' ' << Name << ' ' << Class << ' ' << temp_HP << ' ' << temp_Mana << ' ' << temp_ATK << ' ' << temp_Defense << ' ' << temp_player_exp << ' ' << temp_player_level;
		
	}
	
	in_stream.close();
	out_stream.close();

	ofstream ostream;
	ostream.open("Players.txt", std::ofstream::out | std::ofstream::trunc);
	char ch;
	while (temp_in.get(ch))
	{
		ostream << ch;
	}

	ostream.close();
	temp_in.close();
	temp_out.close();

}
// work in progress
void game_start()
{

	check_story();
	ifstream main_story("Main story locations.txt");
	ifstream side_story("Side story locations.txt");
	while (main_story >> loc_ID >> location >> side_quest)
	{
		main_encounter();
		if (side_quest == true)
			side_encounter();
	}
	
}
void check_story()
{
	ifstream main_story("Main story locations.txt");
	ifstream side_story("Side story locations.txt");
	ifstream main_mobs("Main story mobs.txt");
	ifstream side_mobs("Side story mobs.txt");
	int temp_loc_ID, temp_side_loc_ID;
	string temp_location;
	
	while (main_story >> temp_loc_ID >> temp_location >> side_quest)
	{
		if (temp_loc_ID == loc_ID)
		{
			int temp_main_mob_ID, temp_main_HP, temp_main_Mana, temp_main_ATK, temp_main_ability_dmg, temp_main_Defense, temp_main_magic_resist, temp_main_exp ;
			string temp_main_name;
			while (main_mobs >> temp_main_mob_ID >> temp_main_name >> temp_main_HP >> temp_main_Mana >> temp_main_ATK >> temp_main_ability_dmg >> temp_main_Defense >> temp_main_magic_resist >> temp_main_exp)
			{
				if (main_mob_ID == temp_main_mob_ID)
					break;
			}
			break;
		}
	}
	while (side_story >> temp_side_loc_ID >> temp_location)
	{
		if (temp_side_loc_ID = side_ID)
		{
			int temp_side_mob_ID, temp_side_HP, temp_side_Mana, temp_side_ATK, temp_side_ability_dmg, temp_side_Defense, temp_side_magic_resist, temp_side_exp;
			string temp_side_name;
			while (main_mobs >> temp_side_mob_ID >> temp_side_name >> temp_side_HP >> temp_side_Mana >> temp_side_ATK >> temp_side_ability_dmg >> temp_side_Defense >> temp_side_magic_resist >> temp_side_exp)
			{
				if (main_mob_ID == temp_side_mob_ID)
					break;
			}
		}
		break;
	}
	main_story.close();
	side_story.close();
	main_encounter();
	if (side_quest = true)
		side_encounter();
}
void main_encounter()
{
	bool defeat = true;
	do{
		main_story_text();
		defeat = main_battle();
	} while (defeat);
}
void side_encounter()
{
	bool defeat = true;
	do{
		side_encounter_offer();
		string choice;
		cin >> choice;

		if (choice == "yes" || choice == "YES" || choice == "Yes" || choice == "y" || choice == "Y")
		{
			side_encounter_accepted();
			defeat = side_battle();
		}
	} while (defeat);
}
bool main_battle()
{
	ifstream enemy("Main story mobs.txt");
	int mob_ID, mob_HP, mob_Mana, mob_ATK, mob_ability_dmg, mob_Defense, mob_magic_resist, mob_level;
	string mob_Name;

	int temp_ID, temp_HP, temp_Mana, temp_ATK, temp_ability_dmg, temp_Defense, temp_magic_resist, temp_player_exp, temp_player_level;

	enemy >> mob_ID >> mob_Name >> mob_HP >> mob_Mana >> mob_ATK >> mob_ability_dmg >> mob_Defense >> mob_magic_resist >> mob_level;
	bool battle = true;
	int counter = 1;
	do
	{
		if (temp_HP == 0)
		{
			cout << "Revival potion? yes|no ";
			string decision;
			cin >> decision;
			if (decision == "yes" || decision == "YES" || decision == "Yes" || decision == "y" || decision == "Y")
				Revive_Potion(temp_HP);
			else
				return true;
		}
		if (counter % 2 == 1)
		{
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1: 
				attack(mob_HP, mob_Defense, temp_ATK);
				break;
			case 2:
				ability(mob_HP, temp_Mana, mob_magic_resist, temp_ability_dmg);
				break;
			case 3:
				potion(temp_HP, temp_Mana, temp_ATK, temp_ability_dmg);
				break;
			case 4:
				return true;
			}
		}
		else if (counter % 2 == 0)
		{
			int choice = rand() % 2 + 1;
			switch (choice)
			{
			case 1:
				attack(temp_HP, temp_Defense, mob_ATK);
				break;
			case 2:
				ability(temp_HP, mob_Mana, temp_magic_resist, mob_ability_dmg);
				break;
			}
		}
		counter++;
	} while (mob_HP != 0);
	return false;
}
bool side_battle()
{
	ifstream enemy("Side story mobs.txt");
	int mob_ID, mob_HP, mob_Mana, mob_ATK, mob_ability_dmg, mob_Defense, mob_magic_resist, mob_level;
	string mob_Name;

	int temp_ID, temp_HP, temp_Mana, temp_ATK, temp_ability_dmg, temp_Defense, temp_magic_resist, temp_player_exp, temp_player_level;

	enemy >> mob_ID >> mob_Name >> mob_HP >> mob_Mana >> mob_ATK >> mob_ability_dmg >> mob_Defense >> mob_magic_resist >> mob_level;
	bool battle = true;
	int counter = 1;
	do
	{
		if (temp_HP == 0)
		{
			cout << "Revival potion? yes|no ";
			string decision;
			cin >> decision;
			if (decision == "yes" || decision == "YES" || decision == "Yes" || decision == "y" || decision == "Y")
				Revive_Potion(temp_HP);
			else
				return true;
		}
		if (counter % 2 == 1)
		{
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				attack(mob_HP, mob_Defense, temp_ATK);
				break;
			case 2:
				ability(mob_HP, temp_Mana, mob_magic_resist, temp_ability_dmg);
				break;
			case 3:
				potion(temp_HP, temp_Mana, temp_ATK, temp_ability_dmg);
				break;
			case 4:
				return true;
			}
		}
		else if (counter % 2 == 0)
		{
			int choice = rand() % 2 + 1;
			switch (choice)
			{
			case 1:
				attack(temp_HP, temp_Defense, mob_ATK);
				break;
			case 2:
				ability(temp_HP, mob_Mana, temp_magic_resist, mob_ability_dmg);
				break;
			}
		}
		counter++;
	} while (mob_HP != 0);
	return false;
}
void attack(int &mob_HP, int mob_Defense, int temp_ATK)
{
	temp_ATK = temp_ATK - (mob_Defense * 2);
	mob_HP -= temp_ATK;
}
void ability(int &mob_HP,int &temp_mana, int mob_magic_resist, int temp_ability_dmg)
{
	temp_ability_dmg -= (mob_magic_resist * 2);
	mob_HP -= temp_ability_dmg;
	temp_mana -= 30;
}
void potion(int &temp_HP, int &temp_Mana, int &temp_ATK, int &temp_ability_dmg)
{
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: 
		HP_Potion(temp_HP);
		break;
	case 2:
		Mana_Potion(temp_Mana);
		break;
	case 3:
		Revive_Potion(temp_HP);
		break;
	case 4:
		AttackDMG_Boost(temp_ATK);
		break;
	case 5:
		AbilityPower_Boost(temp_ability_dmg);
		break;
	}
}
int HP_Potion(int &temp_HP)
{
	int counter = 15;
	while (temp_HP < HP && counter >= 0) {
		temp_HP++;
		counter--;
	}
	return temp_HP;
}
int Mana_Potion(int &temp_Mana)
{
	int counter = 15;
	while (temp_Mana < Mana && counter >= 0) {
		temp_Mana++;
		counter--;
	}
	return temp_Mana;
}
int Revive_Potion(int &temp_HP)
{
	int counter = 100;
	while (counter >= 0) {
		temp_HP++;
		counter--;
	}
	return temp_HP;
}
int AttackDMG_Boost(int &temp_ATK)
{
	int counter = 15;
	while (temp_ATK < ATK && counter >= 0) {
		temp_ATK++;
		counter--;
	}
	return temp_ATK;
}
int AbilityPower_Boost(int &temp_ability_dmg)
{
	int counter = 15;
	while (temp_ability_dmg >= 0) {
		temp_ability_dmg++;
		counter--;
	}
	return temp_ability_dmg;
}