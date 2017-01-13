#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
#include <fstream>
#include <string>
using namespace std;

int ID, HP, Mana, ATK, ability_dmg, Defense, magic_resist, player_exp, player_level;
string Name, Class;
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
void credits();
void main_menu();
void new_player();
void load_game();
void save_game();
//void print_screen(int player_stats[])
//{
//	cout << "HP:" << player_stats[0] << "		Mana:" << player_stats[1] << "		Exp:" << player_stats[4] << "		Level:" << player_stats[5];
//	for (int i = 0; i < 11; i++)
//		cout << endl;
//	cout << "		WHERE DO YOU WANT TO GO?";
//	for (int i = 0; i < 11; i++)
//		cout << endl;
//	if (encounters)
//		cout << "1.Attack    	2.Potions		3.Flee		4.Defend" << endl;
//
//}

//fully functional
int main()
{
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
			new_player();
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
void new_player()
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
	cout << "Choose your class:" << endl;
	cout << "1. Warrior(Warrior has high hp, defense and magic resistance but average damage and ability damage and low mana)" << endl;
	cout << endl << "2. Archer (Archer has very high attack damage but has average ability damage, hp and mana but low defense and magic resistance." << endl;
	cout << endl << "3. Mage (Mage has very high ability damage, mana and magic resistance, average hp but has low attack and defense." << endl;
	int choice;
	cin >> choice;
	system("cls");

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