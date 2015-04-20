//Katie Quinn
//function.h
#ifndef FUNCTION_H
#define FUNCTION_H
#include "SDL/SDL.h"
#include <string>
#include "SDL/SDL_image.h"
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
SDL_Surface* load_image( std::string filename ) ;
bool check_collision( SDL_Rect A, SDL_Rect B );

#endif
