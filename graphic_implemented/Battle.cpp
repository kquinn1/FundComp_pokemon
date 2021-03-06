//Paul Dowling
//Battle.cpp
//.cpp file for battle graphics. May need to merge this with the battle algorithm.

#include "Battle.h"

using namespace std;

Battle::Battle(){ //constructor probably ran when the battle starts



}
Battle::~Battle(){	


}
SDL_Surface* Battle::load_image( string filename){
	
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_LOAD( filename.c_str() );
	
	if(loadedImage != NULL){
		optimizedImage = SDL_DisplayFormat( loadedImage);
		SDL_FreeSurface( loadedImage );
	}
	if( optimizedImage != NULL){
		SDL_FreeSurface( loadedImage);
	}

	return optimizedImage;

}
void Battle::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
bool Battle::load_files()
{
  //Load the background
   Battle_Background = load_image( "Battle_user.png" );
   //If error loading background
    if( Battle_Background == NULL ){
	return false;
    }
      //If everything loaded fine
      return true;    
}
bool Battle::init()
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
	SDL_WM_SetCaption( "Battle Screen test", NULL);
	//IF
	 //Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
	return true;
}

void Battle::choose_pokemon(){
	apply_surface(0,0, Battle_Background, screen, &Battle_clip[2]);
	//while variable != Enter pressed	
		//apply_surface(x,y, Battle_Background, screen, &Battle_clip[A]); //apply the surface of the arrow
	
	

}
void Battle::fight(){
	apply_surface(0,0, Battle_Background, screen, &Battle_clip[4]);



}

void Battle::level_up(){
	apply_surface(0,0, Battle_Background, screen, &Battle_clip[3]);



}

void Battle::set_battle_clips(){
	//Initial for fights
	Battle_clip[0].x = 0;
	Battle_clip[0].y = 0;
	Battle_clip[0].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[0].h = SCREEN_HEIGHT;
	
	Battle_clip[1].x = 860;
	Battle_clip[1].y = 0;
	Battle_clip[1].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[1].h = SCREEN_HEIGHT;

	Battle_clip[2].x = 1720;
	Battle_clip[2].y = 0;
	Battle_clip[2].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[2].h = SCREEN_HEIGHT;

	Battle_clip[3].x = 0;
	Battle_clip[3].y = 654;
	Battle_clip[3].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[3].h = SCREEN_HEIGHT;

	Battle_clip[4].x = 860;
	Battle_clip[4].y = 654;
	Battle_clip[4].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[4].h = SCREEN_HEIGHT;

	Battle_clip[5].x = 1720;
	Battle_clip[5].y = 654;
	Battle_clip[5].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[5].h = SCREEN_HEIGHT;

	Battle_clip[6].x = 0;
	Battle_clip[6].y = 0;
	Battle_clip[6].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[6].h = SCREEN_HEIGHT;

	Battle_clip[7].x = 0;
	Battle_clip[7].y = 0;
	Battle_clip[7].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[7].h = SCREEN_HEIGHT;

	Battle_clip[8].x = 0;
	Battle_clip[8].y = 0;
	Battle_clip[8].w = SCREEN_WIDTH; //these may change based on screen size, want to fill screen with this clip
	Battle_clip[8].h = SCREEN_HEIGHT;





}
void Battle::clean_up()
{
	//free surfaces 
	SDL_FreeSurface( Battle_background );
	SDL_FreeSurface( screen );
	//Quit SDL
	SDL_Quit();
}
