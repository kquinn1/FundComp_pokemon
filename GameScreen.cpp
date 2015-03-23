//Katie Quinn
//Loads the game screen (draft)
// Created based on SDL Tutorial 1, modified with later tutorials
// Include SDL functions and datatypes
#include "SDL/SDL.h"
#include <string>
#include <iostream> //for error checking
using namespace std;

// Declare screen attributes as constant
const int WIDTH = 700;
const int HEIGHT = 530;
const int BPP = 32;

// SDL_Surfaces/Images
SDL_Surface* background = NULL; // declare a pointer for background image
SDL_Surface* screen = screen; // what is visible on the screen

SDL_Event event;
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
bool init() //initialize function from lesson 4
{
  // Start SDL and error handle
  if( SDL_Init(SDL_INIT_EVERYTHING) == -1) return false;
  
  // setting up the screen
  screen = SDL_SetVideoMode(WIDTH,HEIGHT,BPP,SDL_SWSURFACE);
  // if error occurred
  if(screen==NULL) return false;

  // set window caption
  SDL_WM_SetCaption("Pokemon Game", NULL); // from Lazy-Foo Lesson02
  return true;
}

bool load_files()//load files from lesson 4
{
  background = load_image("Pokemon_town.bmp");
  if(background==NULL) return false;
  return true;

}
void clean()
{
// free background
  SDL_FreeSurface(background);
// quit SDL-frees screen 
  SDL_Quit();

}
int main(int argc, char* args[]) 
{
  bool quit = false; // continue until the user quits

  if(init()==false) return 1; // if fail to initialize

  // Load the file
  if(load_files()==false) return 1;

  // apply image to screen
  SDL_BlitSurface(background, NULL, screen, NULL);

  //update the screen and error check
  if( SDL_Flip(screen) == -1) return 1;


  while(quit==false){
    // while there is an event
    while(SDL_PollEvent(&event)){
      if(event.type==SDL_QUIT) quit = true;
    }
  }
  // Pause 3 seconds in order to show screen
 // SDL_Delay(3000);

  clean(); // quit SDL
  return 0;
}
