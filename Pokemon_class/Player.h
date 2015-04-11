// Katie Quinn
// CSE 20212
// This will be a player class
// currently a non working draft of the player class

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
class Player{
  public:
	Player(); // need a way to set the pokemon the player has 
//	int getX(); // return x coordinate
//	int getY(); //return y coordinate 
//	void updateX(int);
//	void updateY(int); // update the coordinates
	void setPokemon(); //push_back different pokemon onto the player's available pokemon
        void setCurrentPokemon( Pokemon* monster);
	void addPokemon(Pokemon* monster, int level);
        void deletePokemon(int i); //is this needed
	int getMoney(){ return money; };
	void setMoney(int i){ money+=i; };
  private:
	int x;
	int y; // player location
	int money;
        vector<Pokemon*> myPoke;
};

int Player::getX(){ return x;}

int Player::getY(){return y;}
#endif

