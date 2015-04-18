#include "function.h"

void apply_surface( int x, int y, SDL_Surface* &source, SDL_Surface* &destination, SDL_Rect* clip  )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
