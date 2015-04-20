//Katie Quinn
// Player.h
// Player class file
#ifndef PLAYER_H
#define PLAYER_H
#include "SDL/SDL.h"

//Player
class Player{
  public:
	Player();
	void handle_events();
	void set_clips();
	int move();//return whether to switch
	void show(); //show the sprite
	void updateBox(); //for collisions
	void movePlayer(int, int);
  private:
	int xOffset; //x and y positions
	int yOffset;
	int xvel; //rate of movement in both directions
	int yvel;
	SDL_Rect myBox; //for collisions have a bounding box
	int Aframe;
	int Pframe; // the current Pframe
	int status; // status of animation
};
	
#endif
