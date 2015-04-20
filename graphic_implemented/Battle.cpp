//Paul Dowling
// Loads the battle screen against misty, need sprites for other trainers

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
using namespace std;

	const int SCREEN_WIDTH = 432;
	const int SCREEN_HEIGHT = 603;
	const int SCREEN_BPP = 32;
	SDL_Event event;
	//The Surfaces
	SDL_Surface *background = NULL;		
	SDL_Surface *image_trainer = NULL; //stores trainer sprite or active pokemon
	SDL_Surface *image_enemy = NULL; //store enemy sprite or active pokemon
	SDL_Surface *screen = NULL;
	//Sprite map to be clipped
	SDL_Rect clip[16]; //What size shall it be? need lots of different size clips. Sprite sheet isn't linear
	
	
void set_display();

SDL_Surface *load_image( std::string filename ) 
{
    //The image that's loaded
        SDL_Surface* loadedImage = NULL;
            
    //The optimized image that will be used
        SDL_Surface* optimizedImage = NULL;
                     
    //Load the image
        loadedImage = IMG_Load( filename.c_str() );
        
    //If the image loaded
        if( loadedImage != NULL )
        {
     //Create an optimized image
           optimizedImage = SDL_DisplayFormat( loadedImage );
    //Free the old image
         SDL_FreeSurface( loadedImage );
       }

	if( optimizedImage!=NULL){
	//Include a line that will color key the image
		Uint32 colorkey = SDL_MapRGB( optimizedImage->format,0,0,0);
		SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );

	}
    //Return the optimized image
         return optimizedImage;
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
	SDL_WM_SetCaption( "Cerulean Gym", NULL);
	//IF
	return true;
}

bool load_files()
{
  //Load the background
   background = load_image( "Pokemongym.bmp" );
   //If error loading background
    if( background == NULL ){
	return false;
    }
  //Load the image
   image_trainer = load_image( "Battle_user.png" );
   //If there was an error in loading the image
    if( image_trainer == NULL )
    {
	return false;    
    }
    //If everything loaded fine
      return true;    
}
void clean_up()
{
	//free surfaces 
	SDL_FreeSurface( image_trainer );
	SDL_FreeSurface( image_enemy );
	SDL_FreeSurface( background );
	SDL_FreeSurface( screen );
	//Quit SDL
	SDL_Quit();
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

int main(int argc, char* args[] ){
	bool quit = false;	
	//initialize
	if( init() == false )
	{
		return 1;
	}
	//load the files
	if( load_files() == false )
	{
		return 1;
	}
	//Update the screen
	if( SDL_Flip( screen ) == -1 )
	{
		return 1;
	}

	set_display();
   	//Apply the surface
   	apply_surface(0, 0, background, screen ); //simplify to a white screen
		
	
	while( quit == false ){
		while( SDL_PollEvent( &event )){
			if(event.type == SDL_QUIT )
			{
				quit = true;
			}
		
		}
		//Apply all of the clips
		apply_surface(100, 500, image_trainer, screen, &clip[0] );
		//Update the screen 
		if( SDL_Flip( screen ) == -1 ){ 
			return 1;
		}
		SDL_Delay(50);
	}
	clean_up();
	
	return 0;
}

void set_display(){
//Set clips for user
	//guess for trainer
	clip[0].x = 0;
	clip[0].y = 0;
	clip[0].w = 70;
	clip[0].h = 100;
	//clip for trainer health bar

	//clip for enemy health
	
	//clip for enemy pokeball count

	//clip for text bar

	//clip for text bar w/ wild pokemon

	//choose action

	//attack type	
	
//Set clips for enemy sprite sheet
	//probably not as many clips on this sheet
	

}
