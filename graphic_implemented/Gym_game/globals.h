//Katie Quinn
// globals.h represent global variables
#ifndef GLOBALS_H
#define GLOBALS_H
#include "SDL/SDL.h"

const int SCREEN_WIDTH = 432;
const int SCREEN_HEIGHT = 603;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 10;


static SDL_Event event;


//The Surfaces
static SDL_Surface *background;		
static SDL_Surface *ash;
static SDL_Surface *pika;
static SDL_Surface *screen;

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

//to fight or not
const int FIRST_FIGHT = 1;
const int SECOND_FIGHT = 2;
const int THIRD_FIGHT = 3;
const int IDLE = 0;
const int FIGHT = 1; // have already battled
const int NO_FIGHT = 0;

static SDL_Rect Trainer;
static SDL_Rect Swimmer;
static SDL_Rect Misty;

#endif
