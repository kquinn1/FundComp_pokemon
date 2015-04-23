//Katie Quinn
//Fight.h
//4-12-15
//
//Fight header file
#ifndef FIGHT_H
#define FIGHT_H
#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include "Pokemon.h"
#include <string>

class Fight : public Battle{
  public:
	Fight(Player*, Enemy*);
        void battle(); //fight
        int isWinner(); //determine who wins
        //will return a 1 if there is a winner, 0 if no winner
        int Damage(string, int);
	void setEnemyPoke(); //set enemy pokemon at start of battle, if fainted:
	void playerTurn();
	void enemyTurn(); //the player turn or the enemy turn functions
	void setExperience(); //add the stats earned to the pokemon in battle
  private:
	Enemy* myEnemy;
};
#endif
