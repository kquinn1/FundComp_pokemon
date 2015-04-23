//Paul Dowling
//Battle.h
//header file for the Battle screen

#ifndef BATTLE_H
#define BATTLE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
using namespace std;


class Battle {
	public:
		Battle(); //costructor
		~Battle(); //deconstructor call when the battle ends?
		void choose_pokemon(); //select a pokemon
		void fight(); //select attack move
		void evolve(); //show increased stats
		void set_battle_clips();
		void update();


}

	private:
		SDL_Surface *Battle_Background;  //Sprite clipping that has it store background
		SDL_Surface *User_poke; //Sprite for user pokemon
		SDL_Surface *enemy; //Sprite 
		SDL_Rect Battle_clip[11]; //clips for sprite shhet

}

#endif
