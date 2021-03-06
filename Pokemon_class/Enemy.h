// Katie Quinn:
// CSE 20212
// This will be an Enemy class
// An enemy has various different pokemon, need to be instantiated separately
//
#ifndef ENEMY_H
#define ENEMY_H
#include "Pokemon.h"
#include <vector>
#include <string>
using namespace std;

class Enemy{
  public:
	Enemy(string, int, string, int, string, int); 
        // need a way to set the pokemon the player has
        // current a max of 2 pokemon with their two levels 
	//int getX(){ return X; }; // return x coordinate
//	int getY(){ return Y; }; //return y coordinate 
	void setPokemon(string, int); //push_back different pokemon 
        void setCurrentPokemon(Pokemon*);
        Pokemon* getPokemon(int i);
	Pokemon* getCurrentPokemon();
        void deletePokemon(); //is this needed
	int getMoney(){ return prizeMoney; };
        int isDefeated(); //return if defeated
	int getNumPoke(){return numPoke; };
	string getName(){return name; };
	//should a similar function be included in player?
  private:
	string name;
//	int X;
//	int Y; // player location
	int prizeMoney; // the number of coins they give to player if defeated
        vector<Pokemon*> myPoke;
	Pokemon* inAction; //set current pokemon
	int numPoke;

};
#endif

