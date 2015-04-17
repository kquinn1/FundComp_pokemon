// Katie Quinn
// CSE 20212
// This will be a player class
//tested using playertest.cpp

#ifndef PLAYER_H
#define PLAYER_H
#include "Pokemon.h"
#include "Item.h"
//need to include types and species headers?
//figure out what header files needed in each program
#include <vector>
#include <string>
using namespace std;
class Player{
  public:
	Player(int, int); // need a way to set the pokemon the player has 
	int getX(){ return X; }; // return x coordinate
	int getY(){ return Y; }; //return y coordinate 
	string getUserName(){ return name; };
	void updateX(int);;
	void updateY(int); // update the coordinates
	void setPokemon(); //push_back different pokemon onto the player's available pokemon
        void setCurrentPokemon(Pokemon*);
        Pokemon* getPokemon(int i);
	Pokemon* getCurrentPokemon();
	Item* getItem(int);
	void deleteItem(int);
	void addPokemon(Pokemon*);
        void deletePokemon(int); //is this needed
	int getMoney(){ return money; };
	int getNumPoke(){return numPoke;}
	int isDefeated(); //determine if defeated
	void setMoney(int i){ money+=i; };
  private:
	string name;
	int X;
	int Y; // player location
	int money;
 	vector<Item*> myItem;
        vector<Pokemon*> myPoke;
	int numPoke;
	Pokemon* inAction; //set current pokemon
};
#endif

