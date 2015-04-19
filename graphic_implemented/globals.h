#ifndef GLOBALS_H
#define GLOBALS_H
#include "SDL/SDL.h"

//Screen attributes for now
static int SCREEN_WIDTH = 860;
static int SCREEN_HEIGHT = 654;
static int SCREEN_BPP = 32;
// want to be able to change the screen width and height in different states
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

const int STAY = 0;
const int TO_SHOP = 1;
const int TO_PC = 2;
const int TO_GYM = 3;
const int TO_HOME = 4;
const int TO_GRASS = 5;

static SDL_Surface *ash;
static SDL_Surface *pika;
static SDL_Surface *screen;
static SDL_Surface *background;

// to check collision on the screen
static SDL_Rect PC;
static SDL_Rect Shop;
static SDL_Rect Home;
static SDL_Rect Gym;
static SDL_Rect Grass;


#endif 
