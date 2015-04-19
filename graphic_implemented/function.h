#ifndef FUNCTION_H
#define FUNCTION_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

 void apply_surface( int x, int y, SDL_Surface* &source, SDL_Surface* &destination, SDL_Rect* clip = NULL );
 bool check_collision(SDL_Rect A, SDL_Rect B);
 bool init(int, int, int, SDL_Surface*);
// SDL_Surface* load_image(std::string);
#endif
