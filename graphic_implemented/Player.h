#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
class Player{
  public:
        Player();
	void set_clips();
        void handle_events();
        int move();
        void show();
	void updateBox();
  private:
	SDL_Rect myBox;
        int xOffset;
        int yOffset;
        int xvel; //rate of movement
        int yvel;
        int Aframe;
        int Pframe; // the current Pframe
        int status; // status of animation
};

#endif
