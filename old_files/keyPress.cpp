#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
using namespace std;

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;
	SDL_Event event;
	//The Surfaces
	SDL_Surface *background = NULL;		
	SDL_Surface *image = NULL;
	SDL_Surface *screen = NULL;
	//Sprite map to be clipped
	SDL_Rect clip[12];
	
	

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
	//Include a line that will color key the image
	SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 255, 255 ) );
    //Return the optimized image
         return optimizedImage;
}
bool check_collision(SDL_Rect clip, int xpos, int ypos /*, SDL_Rect border (include later when testing water detection)*/){ //clip should be input of clip[i], border is edge of screen for now
	int boardleft, boardright, boardtop, boardbot; //edges of collision detection
	int spriteleft, spriteright, spritetop, spritebot;
	 	
	spriteleft = xpos;
	spriteright = xpos + clip.w;
	spritetop = ypos;
	spritebot = ypos + clip.h;
	
	boardleft = 0;
	boardright = SCREEN_WIDTH;
	boardtop = 0;
	boardbot = SCREEN_HEIGHT;

	if( spriteleft < boardleft ){		
		return false;
	}
	if( spriteright > boardright ){
		return false;
	}
	if( spritetop < boardtop ){
		return false;
	}
	if( spritebot > boardbot){
		return false;
	}
	
	//If none of the sides from A are outside B
	return true;
		
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
	SDL_WM_SetCaption( "Event test", NULL);
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
   image = load_image( "trainer.png" );
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
	//initialize surface to start in the middle
	int xpos, ypos;
	int xvel, yvel, width, height;
	width = 33; //clip parameters
	height = 30;
	xvel = 3; //set speed
	yvel = 3; //set speed
	xpos = 200;
	ypos = 438;
	//to help determine the image for walking	
	int counter;
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
	//Clip range for the top left
    clip[ 0 ].x = 0;
    clip[ 0 ].y = 0;
    clip[ 0 ].w = width;
    clip[ 0 ].h = height;

    //Clip range for the top middle
    clip[ 1 ].x = 33;
    clip[ 1 ].y = 0;
    clip[ 1 ].w = width;
    clip[ 1 ].h = height;

    //Clip range for the top right
    clip[ 2 ].x = 66;
    clip[ 2 ].y = 0;
    clip[ 2 ].w = width;
    clip[ 2 ].h = height;

    //Clip range for the middle left
    clip[ 3 ].x = 0;
    clip[ 3 ].y = 30;
    clip[ 3 ].w = width;
    clip[ 3 ].h = height;
	//Clip range for the middle
    clip[ 4 ].x = 33;
    clip[ 4 ].y = 30;
    clip[ 4 ].w = width;
    clip[ 4 ].h = height;

    //Clip range for the middle right
    clip[ 5 ].x = 66;
    clip[ 5 ].y = 30;
    clip[ 5 ].w = width;
    clip[ 5 ].h = height;

    //Clip range for the bottom left
    clip[ 6 ].x = 0;
    clip[ 6 ].y = 60;
    clip[ 6 ].w = width;
    clip[ 6 ].h = height;

    //Clip range for the bottom middle
    clip[ 7 ].x = 33;
    clip[ 7 ].y = 60;
    clip[ 7 ].w = width;
    clip[ 7 ].h = height;
    //Clip range for the bottom right
    clip[ 8 ].x = 66;
    clip[ 8 ].y = 60;
    clip[ 8 ].w = width;
    clip[ 8 ].h = height;
	//Clip range for the bottom left
    clip[ 9 ].x = 0;
    clip[ 9 ].y = 90;
    clip[ 9 ].w = width;
    clip[ 9 ].h = height;

    //Clip range for the bottom middle
    clip[ 10 ].x = 33;
    clip[ 10 ].y = 90;
    clip[ 10 ].w = width;
    clip[ 10 ].h = height;
    //Clip range for the bottom right
    clip[ 11 ].x = 66;
    clip[ 11 ].y = 90;
    clip[ 11 ].w = width;
    clip[ 11 ].h = height;		
	
   	//Apply the surface
   	apply_surface(0, 0, background, screen );	
	
	while( quit == false ){
		while( SDL_PollEvent( &event )){
			if(event.type == SDL_QUIT )
			{
				quit = true;
			}
		
		}
		
		//If up is pressed
		if( keystates[ SDLK_UP ] ){ //ash walking up 
			apply_surface(0, 0, background, screen );			
		//if statements to keep sprite out of water			
			if( ypos < 429 && (ypos + height > 429) && (xpos + width) > 257)
				ypos = 431;
			if( ypos < 342 && (ypos + height) > 342 && (xpos + width) > 131 && xpos < 215)
				ypos = 344;
			if( ypos < 219 && (ypos + height) > 219 && xpos > 83 && xpos < 299)
				ypos = 221;
			if( ypos < 138 && (ypos + height) > 138 && xpos > 260 && (xpos + width) < 341)
				ypos = 140;
			if( ypos < 90 && (ypos + height) > 90 && xpos > 176 && (xpos + width) < 260)
				ypos = 92;
			if( ypos < 138 && (ypos + height) > 138 && xpos > 83 && xpos < 176)
				ypos = 140;
			
		
			apply_surface( xpos, ypos, image, screen, &clip[ 10 ] ); 
						
			//increase y position by vel
			if( check_collision( clip[10], xpos, ypos))			
				ypos -= yvel;
			
		} 
		//If down is pressed
		if( keystates[ SDLK_DOWN ] ){ //ash walking down
			apply_surface(0, 0, background, screen );			
			if( ypos < SCREEN_HEIGHT - 2 && (ypos + height) > SCREEN_HEIGHT - 2 && (xpos + width) > 257)
				ypos = SCREEN_HEIGHT - 4 - height;
			if( ypos < 387 && (ypos + height) > 387 && xpos > 83 && xpos < 170)
				ypos = 389 - height;
			if( ypos < 258 && (ypos + height) > 258 && xpos > 128 && xpos < 215)
				ypos = 256 - height;
			if( ypos < 258 && (ypos + height) > 258 && xpos > 257 && xpos < 341)
				ypos = 256 - height;
			if( ypos < 174 && (ypos + height) > 174 && xpos > 83 && xpos< 299)
				ypos = 172 - height;
						
			apply_surface( xpos, ypos , image, screen, &clip[1]); 
			if( check_collision( clip[1], xpos, ypos))		 	
				ypos += yvel;
		}
		//If left is pressed 
		if( keystates[ SDLK_LEFT ] ){ //ash walking left
			apply_surface(0, 0, background, screen );
			if( xpos < 170 && (xpos + width > 170) && (ypos + height) > 387)
				xpos = 172;
			if( xpos < 86 && (xpos + width) > 86 && ypos > 215 && ypos < 388)
				xpos = 88;
			if( xpos < 215 && (xpos + width) > 214 && (ypos + height) > 255 && ypos < 343)
				xpos = 217;
			if( xpos < 301 && (xpos + width) > 301 && ypos < 219 && (ypos + height) > 174)
				xpos = 140;
			if( xpos < 176 && (xpos + width) > 176 && ypos > 90 && ypos < 138)
				xpos = 178;
			if( xpos < 86 && (xpos + width) > 86 && ypos > 135 && ypos < 174)
				xpos = 88;			
			apply_surface(xpos, ypos, image, screen, &clip[4]);
			if( check_collision( clip[4], xpos, ypos))			
				xpos -= xvel;
			
		} 
		//If right is pressed
		if( keystates[ SDLK_RIGHT ] ){ //ash walking right
			apply_surface(0, 0, background, screen );	
			if( xpos <  296 && (xpos + width) > 296 && ypos > 432)
				xpos = 294 - width;
			if( xpos < 257 && (xpos + width) > 257 && (ypos + height) > 258 && ypos < 432)
				xpos = 255 - width;
			if( xpos < 131 && (xpos + width) > 131 && (ypos + height) > 258 && ypos < 342)
				xpos = 129 - width;
			if( xpos < 341 && (xpos + width) > 341 && ypos > 138 && (ypos + height) < 258)
				xpos = 339 - width;
			if( xpos < 260 && (xpos + width) > 260 && ypos > 0 && ypos < 138)
				xpos = 258 - width;		
			apply_surface(xpos, ypos, image, screen, &clip[7]);
			if( check_collision( clip[7], xpos, ypos))			
				xpos += xvel;
		}
		//cout << "X: " << xpos << endl << "Y: " << ypos << endl; //get the coordinates of sprite 
		//Update the screen 
		if( SDL_Flip( screen ) == -1 ){ 
			return 1;
		}
		SDL_Delay(50);
	}
	clean_up();

	return 0;
}
