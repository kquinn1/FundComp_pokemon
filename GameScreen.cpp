//Katie Quinn
//Loads the game screen (draft)
// Created based on SDL Tutorial 1, modified with later tutorials
// Include SDL functions and datatypes
#include "SDL/SDL.h"
#include <string>
using namespace std;

// Declare screen attributes as constant
const int WIDTH = 700;
const int HEIGHT = 530;
const int BPP = 32;

// In order to have an optimized image/faster speed
// Function based on lazy-foo tutorial lesson 02
SDL_Surface *load_image(string file)
{
  // temporary store image that is not optimized
  SDL_Surface* loadedImage = NULL;
  // optimized image
  SDL_Surface* optimized = NULL;

  // Load image
  loadedImage = SDL_LoadBMP(file.c_str());

  //if there was no error
  if(loadedImage!=NULL){
     // create an optimized image
     optimized = SDL_DisplayFormat(loadedImage);
     // free old 24 bit image
     SDL_FreeSurface(loadedImage);
  }

  return optimized;

}
int main() 
{
  // Images
  SDL_Surface* background = NULL; // declare a pointer for background image
  SDL_Surface* screen = screen; // what is visible on the screen

  // Start SDL and error handle
  if( SDL_Init(SDL_INIT_EVERYTHING) == -1) return 1;
  
  // setting up the screen
  screen = SDL_SetVideoMode(WIDTH,HEIGHT,BPP,SDL_SWSURFACE);
  // if error occurred
  if(screen==NULL) return 1;

  // set window caption
  SDL_WM_SetCaption("Pokemon Game", NULL); // from Lazy-Foo Lesson02

  // Load the optimized images
  background = load_image("Pokemon_town.bmp");

  // apply image to screen
  SDL_BlitSurface(background, NULL, screen, NULL);

  //update the screen and error check
  if( SDL_Flip(screen) == -1) return 1;

  // Pause 3 seconds in order to show screen
  SDL_Delay(3000);

  // Free background
  SDL_FreeSurface(background);
  // Quit - frees the screen
  SDL_Quit();

  return 0;


}
