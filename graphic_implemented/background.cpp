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
	SDL_Surface *image = NULL; //for the player
	SDL_Surface *screen = NULL;
	SDL_Surface *image2 = NULL; //for pikachu
	//Sprite map to be clipped
	SDL_Rect clip[12]; //for the player
	SDL_Rect clipPika[10];//for pikachu

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
   image = load_image( "test.png" );

   image2 = load_image("Pikachu.png"); // to have the pikachu walking behind

   //If there was an error in loading the image
    if( image == NULL | image2 == NULL)
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
	SDL_FreeSurface( image2);
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

void set_clips(){
    int width, height, pWidth, pHeight;
    width = 31; //clip parameters
    height = 32;
    pWidth = 50;
    pHeight = 35;
	//Clip range for the top left
    clip[ 0 ].x = 0;
    clip[ 0 ].y = 0;
    clip[ 0 ].w = width;
    clip[ 0 ].h = height;

    //Clip range for the top middle
    clip[ 1 ].x = 32;
    clip[ 1 ].y = 0;
    clip[ 1 ].w = width;
    clip[ 1 ].h = height;

    //Clip range for the top right
    clip[ 2 ].x = 64;
    clip[ 2 ].y = 0;
    clip[ 2 ].w = width;
    clip[ 2 ].h = height;

    //Clip range for the middle left
    clip[ 3 ].x = 0;
    clip[ 3 ].y = 33;
    clip[ 3 ].w = width;
    clip[ 3 ].h = height;
	//Clip range for the middle
    clip[ 4 ].x = 34;
    clip[ 4 ].y = 33;
    clip[ 4 ].w = width;
    clip[ 4 ].h = height;

    //Clip range for the middle right
    clip[ 5 ].x = 66;
    clip[ 5 ].y = 33;
    clip[ 5 ].w = width;
    clip[ 5 ].h = height;

    //Clip range for the bottom left
    clip[ 6 ].x = 0;
    clip[ 6 ].y = 66;
    clip[ 6 ].w = width;
    clip[ 6 ].h = height;

    //Clip range for the bottom middle
    clip[ 7 ].x = 33;
    clip[ 7 ].y = 66;
    clip[ 7 ].w = width;
    clip[ 7 ].h = height;
    //Clip range for the bottom right
    clip[ 8 ].x = 66;
    clip[ 8 ].y = 66;
    clip[ 8 ].w = width;
    clip[ 8 ].h = height;
	//Clip range for the bottom left
    clip[ 9 ].x = 0;
    clip[ 9 ].y = 98;
    clip[ 9 ].w = width;
    clip[ 9 ].h = height;

    //Clip range for the bottom middle
    clip[ 10 ].x = 33;
    clip[ 10 ].y = 98;
    clip[ 10 ].w = width;
    clip[ 10 ].h = height;
    //Clip range for the bottom right
    clip[ 11 ].x = 66;
    clip[ 11 ].y = 98;
    clip[ 11 ].w = width;
    clip[ 11 ].h = height;		

    clipPika[0].x = 0;
    clipPika[0].y = 0;
    clipPika[0].w = pWidth;
    clipPika[0].h = pHeight;

    clipPika[1].x = pWidth;
    clipPika[1].y = 0;
    clipPika[1].w = pWidth;
    clipPika[1].h = pHeight;
    
    clipPika[2].x = pWidth*2;
    clipPika[2].y = 0;
    clipPika[2].w = pWidth;
    clipPika[2].h = pHeight;
	
    clipPika[3].x = pWidth*3;
    clipPika[3].y = 0;
    clipPika[3].w = pWidth;
    clipPika[3].h = pHeight;
    
    clipPika[4].x = pWidth*4;
    clipPika[4].y = 0;
    clipPika[4].w = pWidth;
    clipPika[4].h = pHeight;
    
    clipPika[5].x = pWidth*5;
    clipPika[5].y = 0;
    clipPika[5].w = pWidth;
    clipPika[5].h = pHeight;
    
    clipPika[6].x = pWidth*6;
    clipPika[6].y = 0;
    clipPika[6].w = pWidth-6;
    clipPika[6].h = pHeight;
    
    clipPika[7].x = pWidth*7-5;
    clipPika[7].y = 0;
    clipPika[7].w = pWidth-10;
    clipPika[7].h = pHeight;
   
    clipPika[8].x = pWidth*8-5;
    clipPika[8].y = 0;
    clipPika[8].w = pWidth-10;
    clipPika[8].h = pHeight;

    clipPika[9].x = pWidth*9-5;
    clipPika[9].y = 0;
    clipPika[9].w = pWidth-10;
    clipPika[9].h = pHeight;
}

int main(int argc, char* args[] ){
	//initialize surface to start in the middle
	int xpos, ypos, xvel, yvel; 
	xvel = 3; //set speed
	yvel = 3; //set speed
	xpos = 200;
	ypos = 550;
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
// clips should be in a separate function
	set_clips();

   	//Apply the surface
   	apply_surface(0, 0, background, screen );	
	
	while( quit == false ){
		while( SDL_PollEvent( &event )){
			if(event.type == SDL_QUIT )
			{
				quit = true;
			}
		
		}
	//detect collision with if statements

		//If up is pressed
		if( keystates[ SDLK_UP ] ){ //ash walking up 
			apply_surface(0, 0, background, screen );	
			apply_surface( xpos, ypos, image, screen, &clip[ 10 ] );
 			apply_surface(xpos-10, ypos + 30, image2, screen, &clipPika[6] );	
			//increase y position by vel
			if( check_collision( clip[10], xpos, ypos))			
				ypos -= yvel;
			
		} 
		//If down is pressed   #added else ifs so no diagonal movement
		else if( keystates[ SDLK_DOWN ] ){ //ash walking down
			apply_surface(0, 0, background, screen );		
			apply_surface( xpos, ypos , image, screen, &clip[1]); 
			apply_surface(xpos-10, ypos + 30, image2, screen , &clipPika[0]);	
			if( check_collision( clip[1], xpos, ypos))		 	
				ypos += yvel;
		}
		//If left is pressed 
		else if( keystates[ SDLK_LEFT ] ){ //ash walking left
			apply_surface(0, 0, background, screen );
			apply_surface(xpos, ypos, image, screen, &clip[4]);
			apply_surface(xpos, ypos + 30, image2, screen, &clipPika[8] );	
			if( check_collision( clip[4], xpos, ypos))			
				xpos -= xvel;
			
		} 
		//If right is pressed
		else if( keystates[ SDLK_RIGHT ] ){ //ash walking right
			apply_surface(0, 0, background, screen );	
			apply_surface(xpos, ypos, image, screen, &clip[7]);
			apply_surface(xpos-10, ypos + 30, image2, screen, &clipPika[1] );	
			if( check_collision( clip[7], xpos, ypos))			
				xpos += xvel;
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
