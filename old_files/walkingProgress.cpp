// walking.cpp 
// Testing sprite animation: getting the player to look like it is moving

//Headers needed
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
using namespace std;
//#include "Player.h"
//#include "function.h"
//#include "globals.h"

//Screen attributes for now
const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 654;
const int SCREEN_BPP = 32;

//Pframes per second
const int FRAMES_PER_SECOND = 10;


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

// surfaces
SDL_Surface *ash = NULL;
SDL_Surface *pika = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

// event structure
SDL_Event event;

//sprite sheet 
SDL_Rect AclipsRight[3];
SDL_Rect AclipsLeft[3];
SDL_Rect AclipsUp[3];
SDL_Rect AclipsDown[3];
SDL_Rect PclipsRight[3];
SDL_Rect PclipsLeft[3];
SDL_Rect PclipsDown[2];
SDL_Rect PclipsUp[2];

// to check collision on the screen
SDL_Rect PC;
SDL_Rect Shop;
SDL_Rect Home;
SDL_Rect Gym;

//Plyaer
class Player{
  public:
	Player();
	void handle_events();
	void move();
	void show();
	void updateBox();
  private:
	int xOffset;
	int yOffset;
	SDL_Rect box;
	int xvel; //rate of movement
	int yvel;
	int Aframe;
	int Pframe; // the current Pframe
	int status; // status of animation
};

// The timer
class Timer{
   public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	int get_ticks(); //get timers time
	bool is_started();
	bool is_paused();
  private:
	int startTicks; //clock time at start
	int pausedTicks; //ticks stored when timer is paused
	bool paused;
	bool started;
};
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
bool check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

void set_Rect(){
//set the coordinates of the rectangles
  PC.x = 80;
  PC.y = 500;
  PC.w = 50;
  PC.h = 60;

  Shop.x = 300;
  Shop.y = 500;
  Shop.w = 50;
  Shop.h = 60;

  Home.x = 670;
  Home.y = 530;
  Home.w = 40;
  Home.h = 60;

  Gym.x = 700;
  Gym.y = 100;
  Gym.w = 50;
  Gym.h = 70;
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
        SDL_FreeSurface( pika );
        SDL_FreeSurface( ash );
        SDL_FreeSurface( background );
        SDL_FreeSurface( screen );
        //Quit SDL
        SDL_Quit();
}

Player::Player(){
  xOffset = 200;
  yOffset = 200;
 // box.x = xOffset;
 // box.y = yOffset;
 // box.w = A_WIDTH;
 // box.h = A_HEIGHT;
  xvel = 0;
  Pframe = 0;
  Aframe = 0; 
  status = ASH_RIGHT;
}

void Player::handle_events(){
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Set the xvel
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xvel += A_WIDTH / 4; break;
            case SDLK_LEFT: xvel -= A_WIDTH / 4; break;
	    case SDLK_DOWN: yvel += A_HEIGHT / 4; break;
	    case SDLK_UP: yvel -= A_HEIGHT / 4; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Set the xvel
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xvel -= A_WIDTH / 4; break;
            case SDLK_LEFT: xvel += A_WIDTH / 4; break;
	    case SDLK_DOWN: yvel -= A_HEIGHT/4; break;
	    case SDLK_UP: yvel += A_HEIGHT / 4; break;
        }
    }
}
void Player::move(){
//move
  if(status == ASH_LEFT || status == ASH_RIGHT){
    xOffset += xvel;
  } else  yOffset += yvel;
// keep in bounds
  if((xOffset<0) || (xOffset + A_WIDTH > SCREEN_WIDTH)){
	xOffset -= xvel;
  }
  if((yOffset < 0) || (yOffset + A_HEIGHT > SCREEN_HEIGHT)){
	yOffset -= yvel;
   }
 // updateBox();
//check collisions
//  if(check_collision(box, Shop)) cout << "Shop!" << endl;
 // if(check_collision(box, Gym)) cout << "Gym!" << endl;
 // if(check_collision(box, Home)) cout << "Home! " << endl;
 // if(check_collision(box, PC)) cout << "PC" << endl;

}

void Player::updateBox(){
  box.x = xOffset;
  box.y = yOffset;
  box.w = A_WIDTH;
  box.h = A_HEIGHT;
}
void Player::show(){
   //if moving to left
   if(xvel < 0){
	status = ASH_LEFT; //set animation to left
	Pframe++; // next Pframe
   	Aframe++;
    }
  //if moving to the right
  else if(xvel > 0){
	status = ASH_RIGHT;
	Pframe++;
   	Aframe++;
  }
  else if(yvel < 0){
 	status = ASH_UP;
	Pframe++;
   	Aframe++;
  }
  else if(yvel > 0 ) {
	status = ASH_DOWN;
	Pframe++;
   	Aframe++;
  }
  else{ //standing still
	Pframe = 0;
   	Aframe = 0;
  }
// loop animation
  if((Pframe >= 4 && (status == ASH_LEFT || status == ASH_RIGHT)) || (Pframe>=2 && (status == ASH_UP || status == ASH_DOWN)) ){
	Pframe = 0;
  }
  if(Aframe >= 3) Aframe = 0;

  if(status == ASH_LEFT){
	apply_surface(xOffset,yOffset, ash, screen, &AclipsLeft[Aframe]);
	apply_surface(xOffset + A_WIDTH, yOffset, pika, screen, &PclipsLeft[Pframe]);
  } else if( status == ASH_RIGHT){
	apply_surface(xOffset,yOffset, ash, screen, &AclipsRight[Aframe]);
	apply_surface(xOffset - A_HEIGHT -2, yOffset, pika, screen, &PclipsRight[Pframe]);
  } else if(status == ASH_UP){
	apply_surface(xOffset,yOffset, ash, screen, &AclipsUp[Aframe]);
	apply_surface(xOffset - IMG_OFFSET, yOffset + A_HEIGHT, pika, screen, &PclipsUp[Pframe]);
  }  else if(status == ASH_DOWN){
	apply_surface(xOffset, yOffset, ash, screen, &AclipsDown[Aframe]);
	apply_surface(xOffset - IMG_OFFSET,  yOffset - A_HEIGHT, pika, screen, &PclipsDown[Pframe]);
  }
}
Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;
}
void Timer::pause()
{
    //If the timer is running and isn't already paused
    if( ( started == true ) && ( paused == false ) )
    {
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    //If the timer is paused
    if( paused == true )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
   }
}

int Timer::get_ticks()
{
    //If the timer is running
    if( started == true )
    {
        //If the timer is paused
        if( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
 }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}


int main(){

   bool quit = false;
//Initialize 
   if( init() == false) return 1;
   if ( load_files() == false) return 1;
//clip the sheet
  set_clips();
//set the collision rectangles
//  set_Rect();
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
	red.move();
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


