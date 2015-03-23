// test to load image

// Include SDL functions and datatypes
#include "SDL/SDL.h"

int main() 
{
  // Images
  SDL_Surface* background = NULL; // declare a pointer for background image
  SDL_Surface* screen = screen; // what is visible on the screen

  // Start SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  
  // setting up the screen
  screen = SDL_SetVideoMode(700,530,32,SDL_SWSURFACE);

  // Load the image
  background = SDL_LoadBMP("Pokemon_town.bmp");

  // apply image to screen
  SDL_BlitSurface(background, NULL, screen, NULL);
  //update
  SDL_Flip(screen);
  // Pause
  SDL_Delay(3000);
  // Free image
  SDL_FreeSurface(background);
  // Quit
  SDL_Quit();

  return 0;


}
