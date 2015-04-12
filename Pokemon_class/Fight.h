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
	Fight(Player*, Enemy*, Pokemon*, int); //constructor
        void Battle(); //fight
	void wildBattle(); //fight if not enemt 
        int isWinner(); //determine who wins
        //will return a 1 if player wins, a 0 if the enemy wins
	int calcDamage(int,int,int,int,int,string,string,string,int); //calculate the damage
	float typeCalc(string, string); //calculate the type 
 
  private:
	Player* myPlayer;
	Enemy* myEnemy;
	Pokemon* myWild;
};
#endif
