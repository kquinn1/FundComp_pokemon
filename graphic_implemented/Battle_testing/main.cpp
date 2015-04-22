#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
using namespace std;

	const int SCREEN_WIDTH = 860;
	const int SCREEN_HEIGHT = 654;
	const int SCREEN_BPP = 32;
	SDL_Event event;
	//The Surfaces
	SDL_Surface *background = NULL;		
	SDL_Surface *image = NULL;
	SDL_Surface *screen = NULL;
	//Sprite map to be clipped
	SDL_Rect clip[12];
	
	

SDL_Surface *load_image( string filename ) 
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
	SDL_WM_SetCaption( "Battle testing", NULL);
	//IF
	return true;
}

bool load_files()
{
  //Load the background
   background = load_image( "pokemart.png" );
   //If error loading background
    if( background == NULL ){
	return false;
    }
  //Load the image
   image = load_image( "Battle_user.png" );
   //If there was an error in loading the image
    if( image == NULL )
    {
      return false;    
    }
    //If everything loaded fine
      return true;    
}
void clean_up()
{
	//free surfaces 
	SDL_FreeSurface( image );
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
	//Get the keystates 
	Uint8 *keystates = SDL_GetKeyState( NULL );
	
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
	//Wild Pokemon appears
    clip[ 0 ].x = 0;
    clip[ 0 ].y = 0;
    clip[ 0 ].w = SCREEN_WIDTH;
    clip[ 0 ].h = SCREEN_HEIGHT;

       //Battle options
    clip[ 1 ].x = SCREEN_WIDTH;
    clip[ 1 ].y = 0;
    clip[ 1 ].w = SCREEN_WIDTH;
    clip[ 1 ].h = SCREEN_HEIGHT;

   	//choose pokemon 
    clip[ 2 ].x = 2 * SCREEN_WIDTH;
    clip[ 2 ].y = 0;
    clip[ 2 ].w = SCREEN_WIDTH;
    clip[ 2 ].h = SCREEN_HEIGHT;

    //level-up
    clip[ 3 ].x = 0;
    clip[ 3 ].y = SCREEN_HEIGHT;
    clip[ 3 ].w = SCREEN_WIDTH;
    clip[ 3 ].h = SCREEN_HEIGHT;
	//fight options
    clip[ 4 ].x = SCREEN_WIDTH;
    clip[ 4 ].y = SCREEN_HEIGHT;
    clip[ 4 ].w = SCREEN_WIDTH;
    clip[ 4 ].h = SCREEN_HEIGHT;

    //alphabet and others
    clip[ 5 ].x = 2 * SCREEN_WIDTH;
    clip[ 5 ].y = SCREEN_HEIGHT;
    clip[ 5 ].w = SCREEN_WIDTH;
    clip[ 5 ].h = SCREEN_HEIGHT;

    		
	
   	//Apply the surface
   	//apply_surface(0, 0, background, screen );	
	//Fill the screen white
	 SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
	while( quit == false ){
		while( SDL_PollEvent( &event )){
			if(event.type == SDL_QUIT )
			{
				quit = true;
			}
		
		}
		// initial pokemon
		 
		//apply_surface( 0, 0, image, screen, &clip[ 0 ] ); 
		
		if(keystates[SDLK_DOWN] ){
			apply_surface( 0, 0, image, screen, &clip[ 1 ] );
		}
		if( keystates[ SDLK_LEFT ] ){ 
			apply_surface( 0, 0, image, screen, &clip[ 2 ] ); 
		}
		if(keystates[SDLK_RIGHT] ){
			apply_surface( 0, 0, image, screen, &clip[ 3 ] );
		}
		//Update the screen 
		if( SDL_Flip( screen ) == -1 ){ 
			return 1;
		}
		SDL_Delay(50);
	}
	clean_up();
	
	return 0;
}
