#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
/*
//Screen attributes for now
const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 654;
const int SCREEN_BPP = 32;

//Pframes per second
const int FRAMES_PER_SECOND = 10;

//Dimensions of the sprite
const int PIKA_HEIGHT = 35;
const int PIKA_WIDTH = 50;
const int A_HEIGHT = 32;
const int A_WIDTH = 31;
const int IMG_OFFSET = 7;
//direction status of sprite
const int ASH_RIGHT = 0;
const int ASH_LEFT = 1;
const int ASH_DOWN = 2;
const int ASH_UP = 3;

// surfaces
SDL_Surface *ash = NULL;
SDL_Surface *pika = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

SDL_Event event;

SDL_Rect AclipsRight[3];
SDL_Rect AclipsLeft[3];
SDL_Rect AclipsUp[3];
SDL_Rect AclipsDown[3];
SDL_Rect PclipsRight[3];
SDL_Rect PclipsLeft[3];
SDL_Rect PclipsDown[2];
SDL_Rect PclipsUp[2];
*/
class Player{
  public:
        Player();
	void set_clips();
        void handle_events();
        void move();
        void show();
  private:
        int xOffset;
        int yOffset;
        int xvel; //rate of movement
        int yvel;
        int Aframe;
        int Pframe; // the current Pframe
        int status; // status of animation
};

#endif
