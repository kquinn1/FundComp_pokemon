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
SDL_Surface *ash = NULL;
SDL_Surface *pika = NULL;
SDL_Surface *screen = NULL;

//Dimensions of the sprite
const int PIKA_HEIGHT = 35;
const int PIKA_WIDTH = 50;
const int A_HEIGHT = 32;
const int A_WIDTH = 31;
const int IMG_OFFSET = 7;
//direction status of sprite
const int ASH_RIGHT = 0;
const int ASH_LEFT = 1;
const int ASH_DOWN = 2;
const int ASH_UP = 3;	

//sprite sheet 
SDL_Rect AclipsRight[3];
SDL_Rect AclipsLeft[3];
SDL_Rect AclipsUp[3];
SDL_Rect AclipsDown[3];
SDL_Rect PclipsRight[3];
SDL_Rect PclipsLeft[3];
SDL_Rect PclipsDown[2];
SDL_Rect PclipsUp[2];
	
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
	SDL_WM_SetCaption( "Cerulean Gym", NULL);
	//IF
	return true;
}

bool load_files()
{
  //Load the background
   background = load_image( "Pokemongym.bmp" );
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
    int aWidth, aHeight;
    int pWidth, pHeight;
    aWidth = 31;
    aHeight = 32;
    pWidth = 50;
    pHeight = 35;

    AclipsDown[0].x = 0;
    AclipsDown[0].y = 0;
    AclipsDown[0].w = aWidth;
    AclipsDown[0].h = aHeight;

    //Clip range for the top middle
    AclipsDown[1].x = aWidth;
    AclipsDown[1].y = 0;
    AclipsDown[1].w = aWidth;
    AclipsDown[1].h = aHeight;

    //Clip range for the top right
    AclipsDown[2].x = aWidth*2;
    AclipsDown[2].y = 0;
    AclipsDown[2].w = aWidth;
    AclipsDown[2].h = aHeight;

   //Clip range for the middle left
    AclipsLeft[0].x = 0;
    AclipsLeft[0].y = aHeight+2;
    AclipsLeft[0].w = aWidth;
    AclipsLeft[0].h = aHeight;

 //Clip range for the middle
    AclipsLeft[1].x = aWidth;
    AclipsLeft[1].y = aHeight+2;
    AclipsLeft[1].w = aWidth;
    AclipsLeft[1].h = aHeight;

    //Clip range for the middle right
    AclipsLeft[2].x = aWidth*2;
    AclipsLeft[2].y = aHeight+2;
    AclipsLeft[2].w = aWidth;
    AclipsLeft[2].h = aHeight;

    AclipsRight[0].x = 0;
    AclipsRight[0].y = aHeight*2+2;
    AclipsRight[0].w = aWidth;
    AclipsRight[0].h = aHeight;

    //Clip range for the bottom middle
    AclipsRight[1].x = aWidth;
    AclipsRight[1].y = aHeight*2+2;
    AclipsRight[1].w = aWidth;
    AclipsRight[1].h = aHeight;
    //Clip range for the bottom right
    AclipsRight[2].x = aWidth*2;
    AclipsRight[2].y = aHeight*2+2;
    AclipsRight[2].w = aWidth;
    AclipsRight[2].h = aHeight;

    AclipsUp[0].x = 0;
    AclipsUp[0].y = aHeight*3+2;
    AclipsUp[0].w = aWidth;
    AclipsUp[0].h = aHeight;

    //Clip range for the bottom middle
    AclipsUp[1].x = aWidth;
    AclipsUp[1].y = aHeight*3+2;
    AclipsUp[1].w = aWidth;
    AclipsUp[1].h = aHeight;
    //Clip range for the bottom right
    AclipsUp[2].x = aWidth*2;
    AclipsUp[2].y = aHeight*3+2;
    AclipsUp[2].w = aWidth;
    AclipsUp[2].h = aHeight;
    
    PclipsRight[0].x = pWidth;
    PclipsRight[0].y = 0;
    PclipsRight[0].w = pWidth;
    PclipsRight[0].h = pHeight;

    PclipsRight[1].x = pWidth*2;
    PclipsRight[1].y = 0;
    PclipsRight[1].w = pWidth;
    PclipsRight[1].h = pHeight;

    PclipsRight[2].x = pWidth*3;
    PclipsRight[2].y = 0;
    PclipsRight[2].w = pWidth;
    PclipsRight[2].h = pHeight;

    PclipsLeft[0].x = pWidth*7-5;
    PclipsLeft[0].y = 0;
    PclipsLeft[0].w = pWidth-10;
    PclipsLeft[0].h = pHeight;

    PclipsLeft[1].x = pWidth*8-5;
    PclipsLeft[1].y = 0;
    PclipsLeft[1].w = pWidth-10;
    PclipsLeft[1].h = pHeight;

    PclipsLeft[2].x = pWidth*9-5;
    PclipsLeft[2].y = 0;
    PclipsLeft[2].w = pWidth-10;
    PclipsLeft[2].h = pHeight;

    PclipsDown[0].x = 0;
    PclipsDown[0].y = 0;
    PclipsDown[0].w = pWidth;
    PclipsDown[0].h = pHeight;

    PclipsDown[1].x = pWidth*4;
    PclipsDown[1].y = 0;
    PclipsDown[1].w = pWidth;
    PclipsDown[1].h = pHeight;

    PclipsUp[0].x = pWidth*5;
    PclipsUp[0].y = 0;
    PclipsUp[0].w = pWidth;
    PclipsUp[0].h = pHeight;

    PclipsUp[1].x = pWidth*6;
    PclipsUp[1].y = 0;
    PclipsUp[1].w = pWidth-6;
    PclipsUp[1].h = pHeight;
}

int main(int argc, char* args[] ){
	//initialize surface to start in the middle
	int xpos, ypos;
	int xvel, yvel, width, height;
	width = 31; //clip parameters
	height = 32;
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
	if( init() == false ) return 1;
	//load the files
	if( load_files() == false ) return 1;
	//Update the screen
	if( SDL_Flip( screen ) == -1 )return 1;

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
	//should implement rectangles around the "trainers"
		if( ypos < 270 && ypos > 230 && xpos > 320 && xpos < 360 )
			cout << "Fight!" << endl;		
	//	if( xpos < 	
	

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
		//If down is pressed   #added else ifs so no diagonal movement
		else if( keystates[ SDLK_DOWN ] ){ //ash walking down
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
		else if( keystates[ SDLK_LEFT ] ){ //ash walking left
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
		else if( keystates[ SDLK_RIGHT ] ){ //ash walking right
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
