//Katie Quinn
//Battle.h
//This class will be the top level class for two derived classes
// onGrass & Fight
// onGrass- battle with a wild pokemon
// Fight - battle against a trainer that might have multiple pokemon
#ifndef BATTLE_H
#define BATTLE_H
#include "Player.h" // The battle references a player pointer
#include <string>

class Battle{
  public:
	Battle(Player*); // this will set myPlayer
	virtual void battle() = 0; //pure virtual function - abstract class
	virtual void enemyTurn() = 0;
	virtual	int Damage(std::string, int) {return 1;}; // needs to be in other classes
	void choosePoke(); //sets the current pokemon of the player
	void battleMenu(); //same for both clases
	virtual void setExperience() = 0; //add the stats to pokemon in battle
	virtual int isWinner() {return 1;};
	int showAttacks(); // choose the attack
	float typeCalc(std::string, std::string); 
  protected: // I need the derived class to have access to this pointer, ideally this should be hidden data
	Player* myPlayer; 
// player pointer allows its pokemon and their attacks to be changed
// provides flexibility for the program
};

#endif
