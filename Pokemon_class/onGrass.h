//Katie Quinn
//4-15-15
//
//onGrass battle header file
#ifndef ONGRASS_H
#define ONGRASS_H
#include "Player.h"
//#include "Enemy.h"
#include "Pokemon.h"
#include <string>

class onGrass{
  public:
	onGrass(Player*);
        Pokemon* pickEnemy(); //randomly picks an enemy
	void battle(); //onGrass battle 
        int isWinner(); //determine who wins
        //will return a 1 if there is a winner, 0 if no winner
        int Damage(string, int);
	float typeCalc(string, string); //calculate the type modifier
	void choosePoke();//allows the user to choose which pokemon to battle with 
	void battleMenu(); //displays a menu for the player to choose battle 
	int showAttacks(); //show attacks & choose an attack
	int playerTurn();
	void enemyTurn(); //the player turn or the enemy turn functions
	void setExperience(); //add the stats earned to the pokemon in battle
  private:
	Player* myPlayer;
	Pokemon* myWild;
};
#endif
