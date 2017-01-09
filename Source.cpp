#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PLAYER_SIZE = 6;
const int LOOT_SIZE = 4;
void player()
{

	// HP_potion(0), MP potion(1), attack_increase_potion(2), revival_potion(3)
	int loot[LOOT_SIZE] = { 0, 0, 0, 0 };


}

// returns player level
int player_level(int player_stats[])
{
	return player_stats[5];
}
/*
Int type function;
takes player_stats array from player function as a parameter;
takes the players level and uses it to give the appropriate experience for the next level
returns the needed experience
*/
int next_level_exp(int player_stats[])
{
	int next_lvl = player_stats[5] * 100;
	return next_lvl;
}
/*
takes player_stats array from player function as a parameter,
checks if the player has enough experience to advance to the next level
returns true if its enough, else it returns false;
*/
bool level_up(int player_stats[])
{
	bool level_up = false;
	if (player_stats[4] >= next_level_exp(player_stats))
	{
		player_stats[5]++;
		level_up = true;
	}
	return level_up;
}
//randomly spawns a creature to fight
bool encounters()
{
	return rand() & 2;
}
void print_screen(int player_stats[])
{
	cout << "HP:" << player_stats[0] << "		Mana:" << player_stats[1] << "		Exp:" << player_stats[4] << "		Level:" << player_stats[5];
	for (int i = 0; i < 11; i++)
		cout << endl;
	cout << "		WHERE DO YOU WANT TO GO?";
	for (int i = 0; i < 11; i++)
		cout << endl;
	if (encounters)
		cout << "1.Attack    	2.Potions		3.Flee		4.Defend" << endl;

}
void ManaPotion(int player_stats[])
{
    for(int i = 0;i < 15;i++){
        player_stats[1]++;
    }
}
void HealthPotion(int player_stats[])
{
    for(int i = 0;i < 15;i++){
        player_stats[1]++;
    }
}
void AttackDMGincrese(int player_stats[])
{
    for(int i = 0;i < 15;i++){
        player_stats[2]++;
    }
}
void RevivePotion(int player_stats[])
{
    for(int i = 0;i < 100;i++){
        player_stats[1]++;
    }
}
int main()
{
	// HP(0), Mana(1),  ATK(2); defense(3), player_exp(4), player_level(5)
	int player_stats[PLAYER_SIZE] = { 100, 100, 15, 1, 0, 1 };
	srand(time(0));
	print_screen(player_stats);
	ManaPotion(player_stats[]);
	HealthPotion(player_stats[]);
	AttackDMGincrese(player_stats[]);
	RevivePotion(player_stats[]);
    if (AttackDMGincrese() == true && /* 3 Moves are done */){
        player_stats[2] == 15;
    }
    return 0;
}
