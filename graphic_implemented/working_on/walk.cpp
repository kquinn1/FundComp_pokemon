//Katie Quinn
//File shows background- Pikachu follows ash around

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "globals.h"
#include "Player.h"
#include "Timer.h"
#include <iostream>
#include "function.h"
using namespace std;

//SDL_event event;
/*
SDL_Surface *load_image( std::string filename ){
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );
        //Free the old surface
        SDL_FreeSurface( loadedImage );
        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
	    Uint32 colorkey = SDL_MapRGB(optimizedImage->format,0,0,0);
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}*/
/*
void apply_surface2( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}*/
void set_Rect(){
//set the coordinates of the rectangles
  PC.x = 80;
  PC.y = 500;
  PC.w = 50;
  PC.h = 60; //shop door dimensions roughly

  Shop.x = 300;
  Shop.y = 500;
  Shop.w = 50;
  Shop.h = 60; //shop door dimensions roughly

  Home.x = 670;
  Home.y = 530;
  Home.w = 40;
  Home.h = 60; //home door dimensions roughly

  Gym.x = 700;
  Gym.y = 100;
  Gym.w = 50;
  Gym.h = 70; //gym door dimensions roughly

  Grass.x = 30;
  Grass.y = 40;
  Grass.w = 310;
  Grass.h = 210; // grass dimensions

}

bool init()
{
        //Initialize all SDL subsystems
        if( SDL_Init( SDL_INIT_EVERYTHING ) == -1)
        {
                return false;
        }

        //Set up the screen
        screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
        //If there was an error
        if( screen == NULL)
        {
                return false;
        }
        //Set window caption
        SDL_WM_SetCaption( "Pokemon Town", NULL);
        //IF
        return true;
}


bool load_files()
{
  //Load the background
   background = load_image( "Pokemon_town.bmp" );
   //If error loading background
    if( background == NULL ){
        return false;
    }
  //Load the image
   ash = load_image("test.png"); //ash
   pika = load_image( "Pikachu.png" );//pikachu

   //If there was an error in loading the image
    if( ash == NULL || pika == NULL)
    {
      return false;
    }
    //If everything loaded fine
      return true;
}

void clean_up()
{
        //free surfaces 
        SDL_FreeSurface( pika ); //free all the surfaces
        SDL_FreeSurface( ash );
        SDL_FreeSurface( background );
        SDL_FreeSurface( screen );
        //Quit SDL
        SDL_Quit();
}

int main(){

   int state;
   bool quit = false;
//Initialize 
   if( init() == false) return 1;
   if ( load_files() == false) return 1;
//clip the sheet
   //set_clips();

   set_Rect();
//Frame rate regulator
   Timer fps;
// The player
   Player red;;
   while( quit == false )
    {
        //Start the Pframe timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the player
            red.handle_events();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
	// Move pikachu and ash
	state = red.move();

	switch(state){// need a way to transition from state to state
	    case TO_PC:
		quit = true;
		break;
	    case TO_GYM:
		quit = true;
		break;
	    case TO_SHOP:
		quit = true;
		break;
	    case TO_HOME:
		quit = true;
		break;
	    case TO_GRASS:
		//determine if fight, then quit
		quit = false;
		break;
	    case STAY:
		quit = false;
		break;
	}
	// Fill the background screen
	apply_surface(0, 0, background, screen );
	// show pika and ash
	red.show(); //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the Pframe rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    clean_up();
    return 0;
}
