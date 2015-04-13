//Katie Quinn
//4-12-15
//
//Fight header file
#ifndef FIGHT_H
#define FIGHT_H
#include "Player.h"
#include "Enemy.h"
#include "Pokemon.h"
#include <string>

class Fight{
  public:
	Fight(Player*, Enemy*);
//	Fight(Player*, Enemy*, Pokemon*, int); //constructor
        void battle(); //fight
	void wildBattle(); //fight if not enemt 
        int isWinner(); //determine who wins
        //will return a 1 if there is a winner, 0 if no winner
	int Damage(int,int,int,int,int,string,string,string,int); //calculate the damage
	float typeCalc(string, string); //calculate the type modifier
	void choosePoke();//allows the user to choose which pokemon to battle with 
	void battleMenu(); //displays a menu for the player to choose battle 
	int showAttacks(); //show attacks & choose an attack
	void setEnemyPoke(); //set enemy pokemon at start of battle, if fainted:
	void playerTurn();
	void enemyTurn(); //the player turn or the enemy turn functions
  private:
	Player* myPlayer;
	Enemy* myEnemy;
	Pokemon* myWild;
};
#endif
