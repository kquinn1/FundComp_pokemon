#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "globals.h"
#include "function.h"
#include "Player.h"
#include "Timer.h"
#include <string>
#include <iostream>
using namespace std;



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
	SDL_WM_SetCaption( "Cerulean Gym", NULL);
	//IF
	return true;
}

bool load_files()
{
  //Load the background
   background = load_image( "Pokemon_gym.bmp" );
  //Load the image
   ash = load_image( "test.png" );
   pika = load_image("Pikachu.png");
   //If there was an error in loading the image
    if( ash  == NULL || pika == NULL || background == NULL)
    {
      return false;    
    }
    //If everything loaded fine
      return true;    
}
void clean_up()
{
	//free surfaces 
	SDL_FreeSurface( background );
	SDL_FreeSurface( screen );
	SDL_FreeSurface( pika );
        SDL_FreeSurface( ash );
	SDL_Quit();
}


void set_Rect(){
//set the collision rectangles for the trainers
// these need to be edited
	Trainer.x = 175;
	Trainer.y = 110;
	Trainer.w = 30;
	Trainer.h=  35;

	Swimmer.x = 170;
	Swimmer.y = 235;
	Swimmer.w = 100;
	Swimmer.h = 35;

	Misty.x =  140;
	Misty.y = 75;
	Misty.w = 30;
	Misty.h = 80;
} 


int main(int argc, char* args[] ){
	//initialize surface to start in the middle
	int state;
   bool quit = false;   
   int first = 0;
   int second = 0;
   int third = 0;
	
	//initialize
	if( init() == false ) return 1;
	//load the files
	if( load_files() == false ) return 1;
	//Update the screen
	if( SDL_Flip( screen ) == -1 )return 1;

	set_Rect();

   Player red;
   Timer fps;
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
	if( state == FIRST_FIGHT && first == NO_FIGHT){
			cout << "Swimmer wants to fight! " << endl; //for test
			first = FIGHT;
	}		
   else if( state==SECOND_FIGHT && second == NO_FIGHT){
		   cout << "Trainer wants to fight!" << endl;
			second = FIGHT; // denotes that the battle has occurred
   }
	else if(state == THIRD_FIGHT && third == NO_FIGHT){
		    cout << "Misty wants to fight! " << endl;
			 third = FIGHT;
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
