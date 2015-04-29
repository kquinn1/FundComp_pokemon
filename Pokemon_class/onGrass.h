//Katie Quinn
// onGrass.h
//4-15-15
//
//onGrass battle header file
#ifndef ONGRASS_H
#define ONGRASS_H
#include "Battle.h"
#include "Player.h"
#include "Pokemon.h"
#include <string>

class onGrass : public Battle {
  public:
	onGrass(Player*);
        Pokemon* pickEnemy(); //randomly picks an enemy
	void battle(); //onGrass battle 
        int isWinner(); //determine who wins
        //will return a 1 if there is a winner, 0 if no winner
        int Damage(string, int);
	int playerTurn();
	void enemyTurn(); //the player turn or the enemy turn functions
	void setExperience(); //add the stats earned to the pokemon in battle
	int isCaught(); // function that determines whether or not pokemon is caught
	bool hasItem(); //check to see if has a pokeball to catch pokemon with
	void battleMenu(); // slightly different battle menu than inherited
	// this is to accomadate catching pokemon in the grass
  private:
	Pokemon* myWild;
};
#endif
