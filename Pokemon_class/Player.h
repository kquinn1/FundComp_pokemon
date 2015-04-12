// Katie Quinn
// CSE 20212
// This will be a player class
//tested using playertest.cpp

#ifndef PLAYER_H
#define PLAYER_H
#include "Pokemon.h"
//need to include types and species headers?
//figure out what header files needed in each program
#include <vector>
class Player{
  public:
	Player(int, int); // need a way to set the pokemon the player has 
	int getX(){ return X; }; // return x coordinate
	int getY(){ return Y; }; //return y coordinate 
	void updateX(int);;
	void updateY(int); // update the coordinates
	void setPokemon(); //push_back different pokemon onto the player's available pokemon
        void setCurrentPokemon(Pokemon*);
        Pokemon* getPokemon(int i);
	Pokemon* getCurrentPokemon();
	void addPokemon(Pokemon*, int level);
        void deletePokemon(int); //is this needed
	int getMoney(){ return money; };
	void setMoney(int i){ money+=i; };
  private:
	int X;
	int Y; // player location
	int money;
        vector<Pokemon*> myPoke;
	Pokemon* inAction; //set current pokemon
};
#endif

