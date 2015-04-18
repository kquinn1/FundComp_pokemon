#ifndef GLOBALS_H
#define GLOBALS_H
#include "SDL/SDL.h"

//Screen attributes for nowe
extern int SCREEN_WIDTH = 860;
extern int SCREEN_HEIGHT = 654;
extern int SCREEN_BPP = 32;

//Pframes per second
extern int FRAMES_PER_SECOND = 10;

//Dimensions of the sprite
extern int PIKA_HEIGHT = 35;
extern int PIKA_WIDTH = 50;
extern int A_HEIGHT = 32;
extern int A_WIDTH = 31;
extern int IMG_OFFSET = 7;
//direction status of sprite
extern int ASH_RIGHT = 0;
extern int ASH_LEFT = 1;
extern int ASH_DOWN = 2;
extern int ASH_UP = 3;

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

#endif 
