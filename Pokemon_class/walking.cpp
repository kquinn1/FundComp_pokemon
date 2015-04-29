//Katie Quinn
//walking.cpp
//main program file
// includes the graphics classes & functions and uses Pokemon/place classes
// A combination of graphics and user input from the terminal

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Fight.h"
#include "Enemy.h"
#include "Battle.h"
#include "onGrass.h"
#include "Player.h"
#include "Heal.h"
#include "Shop.h"
#include <string>
#include "Timer.h"//include all classes to be initialized
#include <iostream> // cout, etc
using namespace std; //std :: cout

//Screen attributes for the main window
const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 654;
const int SCREEN_BPP = 32;

//Pframes per second : how animation is implemented
const int FRAMES_PER_SECOND = 10;

//Dimensions of the sprites Pikachu and Red(the user)
const int PIKA_HEIGHT = 35;
const int PIKA_WIDTH = 50;
const int A_HEIGHT = 32;
const int A_WIDTH = 31;
const int IMG_OFFSET = 7;

//direction status of sprite, determines Pikachus direction
const int ASH_RIGHT = 0;
const int ASH_LEFT = 1;
const int ASH_DOWN = 2;
const int ASH_UP = 3;

//states for collision
const int STAY = 0;
const int TO_SHOP = 1;
const int TO_PC = 2;
const int TO_GYM = 3;
const int TO_HOME = 4;
const int TO_GRASS = 5;

// to reset player positions
const int X_PC = 95;
const int Y_PC = 550;
const int X_SHOP = 310;
const int Y_SHOP = 550;
const int X_GYM = 710;
const int Y_GYM = 150;
const int X_HOME = 680;// the intial x, and y positions for the character
const int Y_HOME = 580;

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
SDL_Rect Store;
SDL_Rect Home;
SDL_Rect Gym;
SDL_Rect Grass;

//SDL Functions : using LazyFoo tutorial on animation
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
void set_clips(){ //set the sprite clips
    int aWidth, aHeight;
    int pWidth, pHeight;
    aWidth = 31;
    aHeight = 32;
    pWidth = 50;
    pHeight = 35;

// downward motion
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
// left
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

// right
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

// up
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
// Pikachu clips
// Right
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

//Left 
//the hard coded values that don't make much sense have to do with 
//uneven image editing on my part
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

//Down
    PclipsDown[0].x = 0;
    PclipsDown[0].y = 0;
    PclipsDown[0].w = pWidth;
    PclipsDown[0].h = pHeight;
  
    PclipsDown[1].x = pWidth*4;
    PclipsDown[1].y = 0;
    PclipsDown[1].w = pWidth;
    PclipsDown[1].h = pHeight;

//Up
    PclipsUp[0].x = pWidth*5;
    PclipsUp[0].y = 0;
    PclipsUp[0].w = pWidth;
    PclipsUp[0].h = pHeight;

    PclipsUp[1].x = pWidth*6;
    PclipsUp[1].y = 0;
    PclipsUp[1].w = pWidth-6;
    PclipsUp[1].h = pHeight;
}

void set_Rect(){
//set the coordinates of the rectangles
  PC.x = 80;
  PC.y = 500;
  PC.w = 50;
  PC.h = 40; //PC door dimensions roughly

  Store.x = 300;
  Store.y = 500;
  Store.w = 50;
  Store.h = 40; //shop door dimensions roughly

  Home.x = 670;
  Home.y = 530;
  Home.w = 40;
  Home.h = 40; //home door dimensions roughly

  Gym.x = 700;
  Gym.y = 100;
  Gym.w = 50;
  Gym.h = 40; //gym door dimensions roughly

  Grass.x = 30;
  Grass.y = 40;
  Grass.w = 310;
  Grass.h = 200; // grass dimensions roughly

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

//User class starts here
//Known issue: separating classes with SDL - issue with SDL_Surfaces
class User{
  public:
	User();
	void handle_events();
	int move();//return whether to switch
	void show(); //show the sprite
	void updateBox(); //for collisionus
	void updatePos(int, int); // move the player out of collision range
  private:
	int xOffset; //x and y positions
	int yOffset;
	int xvel; //rate of movement in both directions
	int yvel;
	SDL_Rect myBox; //for collisions have a bounding box
	int Aframe;
	int Pframe; // the current Pframe
	int status; // status of animation
};

// constructor for user class
User::User(){
  xOffset = X_HOME;//set the initial x and y positions
  yOffset = Y_HOME;
  xvel = 0;//set the initial velocities
  yvel = 0;
  Pframe = 0;//set the initial frames
  Aframe = 0; 
  status = ASH_DOWN;//set initial status
  myBox.w = A_WIDTH;//set the box dimensions
  myBox.h = A_HEIGHT;
  updateBox();
}

void User::updateBox(){//update the position of box used for collisions
  myBox.x = xOffset;
  myBox.y = yOffset;

}

void User::updatePos(int x, int y){//update the user position
   xOffset = x;
   yOffset = y;
   updateBox();
   show(); // show the user at updated position
}

void User::handle_events(){//handle the events for the user aka sprite
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
int User::move(){ //move the sprite by xvel or yvel
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

  updateBox(); //update the x and y coordinates of the box

//check collisions and return the state to main for event handling
  if(check_collision(myBox, Store)){
	return TO_SHOP;
  }
  else if(check_collision(myBox, PC)) {
	return TO_PC;
  }
  else if(check_collision(myBox, Home)){
 	return TO_HOME;
   }
  else if(check_collision(myBox, Gym)){
	 return TO_GYM;
  }
  else if(check_collision(myBox, Grass)){
	return TO_GRASS;
  }
  else {
	return STAY;
  }

}


void User::show(){//show the appropriate sprite frame on the screen
// The frame shown is based on direction user is going
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
// loop animation, reset the frame count if gone over
  if((Pframe >= 3 && (status == ASH_LEFT || status == ASH_RIGHT)) || (Pframe>=2 && (status == ASH_UP || status == ASH_DOWN)) ){
	Pframe = 0;
  }
  if(Aframe >= 3) Aframe = 0;

//depending on the direction, apply the appropriate sprites to the screen
//weird hard coded values e.g. -2 due to my uneven image editing of Pikachu
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
// End of User class //


int main(){
// declare the Player class
  Player Ash(0,0);// originally player was designed to store x and y
  Enemy swimmer("Swimmer",80,"Shellder",16,"Horsea",16);
  //swimmer has two pokemon, cash prize of 80
  Enemy jrTrainer("Junior Trainer",380,"Goldeen",19,"",0);
  //junior trainer has one pokemon, cash prize of 380
  Enemy misty("Misty",2079,"Starmie",21,"Staryu",18);
  //Misty (gym leader) has two pokemon, higher levels. Prize of 2079
//declare pointers to each enemy and the player in order to edit their pokemon
  Enemy *first;
  Enemy *second;
  Enemy *third;
  first = &swimmer;
  second = &jrTrainer;
  third = &misty;
  Player *myplay;
  myplay = &Ash;
// used to determine if the gym has already been fought
  bool hasFought = false;

// the state where the player is 
   int state; 

// to quit or not to quit
   bool quit = false;

//Initialize 
   if( init() == false) return 1;
   if ( load_files() == false) return 1;
//clip the sheet
   set_clips();

   set_Rect();
//Frame rate regulator
   Timer fps;
// The player
   User red;
   while( quit == false )// while the user has not quit
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
// detection collision with state variable in order to handle events
// PC: Heal your pokemon
	    if (state == TO_PC){
		Heal healing(myplay);
// move player so collision does not repeat	
         	red.updatePos(X_PC,Y_PC);
	   }
// Gym: Go to the gym
	    else if (state ==  TO_GYM){
//Gym logic can only beat the gym leader once (hasFought variable)
//can only encounter the next gym leader if the previous has been fought
		if(hasFought == false){
		 cout << endl << "Welcome to the Cerlulean gym!" << endl;
                 cout << "There are three trainers you can battle against once."<< endl;
		 cout << "If you fail to beat all three, heal at the PC," << endl<< "gain experience battling pokemon in the grass, and come back!" << endl ;
		 if(first->isDefeated() == 0){
                        Fight myfight(myplay , first );
                  } else cout << first->getName() << " has already been defeated!" << endl;
                 if(first->isDefeated() == 1){
		    if(second->isDefeated() == 0){
                          Fight myfight2(myplay, second);
                    } else cout << second->getName() << " has already been defeated!" << endl;
                }  
		 if(second->isDefeated() == 1){ 
		    if(third->isDefeated() == 0 ){
                         Fight myfight3(myplay, third);
                         if(third->isDefeated() == 1) hasFought = true;
                    }
		    else cout << "Already beat gym leader! " << endl;
		  }

		}
// move player so collision does not repeat	
		red.updatePos(X_GYM,Y_GYM);
	  }
// Shop: buy pokeballs to catch pokemon if player has money
	    else if (state ==  TO_SHOP){
		Shop myS(myplay);
// move player so collision does not repeat	
		red.updatePos(X_SHOP,Y_SHOP);
	   }
// Home: quit the game
	    else if (state == TO_HOME){
		quit = true;
	}
// Grass: maybe battle with a wild pokemon
// The user stays in the grass until they move out of it
	    else if (state ==  TO_GRASS){
		onGrass m1(myplay);	
	   } //else quit = false; //not really necessary
	
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

// Clean up SDL Surfaces
    clean_up();

// Display personal message to the user
// userName is set up in the player constructor using stdin
    cout << Ash.getUserName() <<  " thank you for playing!" << endl;
    return 0;
}
