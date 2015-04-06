// Katie Quinn
// CSE 20212
// This will be a player class
// currently a non working draft of the player class

#ifndef PLAYER_H
#define PLAYER_H
class Player{
  public:
	Player(); // need a way to set the pokemon the player has 
	int getX(); // return x coordinate
	int getY(); //return y coordinate 
	void updateX(int);
	void updateY(int); // update the coordinates

  private:
	int x;
	int y; // player location
	Pokemon p1;// should be different species of pokemon
	Pokemon p2;// need a way to set the pokemon the player has
	Pokemon p3;// should they decide or be pre set?
	Pokemon p4;
	Pokemon p5;
	Pokemon p6;
};

int Player::getX(){ return x;}

int Player::getY(){return y;}
#endif

